#include "Buffer.h"
#include <cstring>
#include <sys/uio.h>
#include <sys/types.h>
#include <sys/socket.h>

namespace HttpReactor
{
    Buffer::Buffer(int size) : capacity(size)
    {
        buffer = new char[capacity];
        bzero(buffer, capacity);
    }
    Buffer::~Buffer()
    {
        if (buffer != nullptr)
        {
            free(buffer);
        }
    }
    void Buffer::extendRoom(int size) // 扩展空间
    {
        if (writeableSize() >= size) // 不需要扩展
        {
            return;
        }
        else if (readPos + writeableSize() > size) // 只覆盖掉
        {
            int readSize = readableSize();
            memcpy(buffer, buffer + readPos, readSize);
            readPos = 0;
            writePos = readSize;
        }
        else // 需要扩展
        {
            buffer = (char *)realloc(buffer, size);
            memset(buffer + writePos, 0, size - writePos);
            capacity = size;
        }
    }
    int Buffer::appendString(const char *str, int size)
    {
        if (size < 0 || str == nullptr)
            return -1;
        extendRoom(writePos + size);
        memcpy(buffer + writePos, str, size);
        writePos += size;
        return size; // 返回写入的长度
    }
    int Buffer::appendString(const char *str)
    {
        return appendString(str, strlen(str));
    }
    int Buffer::appendString(const std::string &str)
    {
        return appendString(str.c_str(), str.size());
    }
    int Buffer::sockRead(int sockfd)
    {
        struct iovec iov[2];
        iov[0].iov_base = buffer + writePos;
        iov[0].iov_len = writeableSize();
        char *tmp = (new char[40960]); // 临时缓冲区，防止缓冲区不够用
        iov[1].iov_base = tmp;
        iov[1].iov_len = 40960;
        int result = readv(sockfd, iov, 2);
        if (result < 0)
        {
            return -1;
        }
        if (result > 0)
        {
            if (result > writeableSize()) // 如果缓冲区不够用,扩容缓冲区,将临时缓冲区的内容复制到缓冲区
            {
                writePos = capacity + result - writeableSize();
                appendString(tmp, result - writeableSize());
            }
            else
            {
                writePos += result;
            }
        }
        delete[] tmp;
        return result;
    }

    int Buffer::sendData(int sockfd)
    {
        int readable = readableSize();
        if (readable <= 0)
            return -1;
        int result = send(sockfd, buffer + readPos, readable,MSG_NOSIGNAL);
        if (result < 0)
        {
            return -1;
        }
        if (result > 0)
        {
            readPos += result;
        }
        return result;
    }
};
