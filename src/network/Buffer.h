#pragma once

#include <string>

namespace HttpReactor
{
    class Buffer
    {
    public:
        Buffer(int size);
        ~Buffer();
        void extendRoom(int size);
        inline int writeableSize() {
            return capacity - writePos;
        }
        inline int readableSize() {
            return writePos - readPos;
        }
        int appendString(const char *str, int size);
        int appendString(const char *str);
        int appendString(const std::string& str);
        int sockRead(int fd);
        int sendData(int fd);
        inline int getcapacity() {
            return capacity;
        }
        inline char* getBuffer() {
            return buffer;
        }
        inline int getWritePos() {
            return writePos;
        }
        inline int getReadPos() {
            return readPos;
        }

    protected:
        char *buffer;
        int capacity;
        int writePos = 0;
        int readPos = 0;
    };
};