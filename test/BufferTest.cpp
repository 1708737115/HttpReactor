#include "../src/network/Buffer.h"
#include <iostream>
#include <cstring>
#include <sys/uio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <fcntl.h> 
#include <unistd.h> 

using namespace HttpReactor;

// 创建一个辅助函数用于创建一对非阻塞套接字对，以便模拟读写操作
void createSocketPair(int pair[2]) {
    if (socketpair(AF_UNIX, SOCK_STREAM, 0, pair) == -1) {
        perror("socketpair");
        exit(EXIT_FAILURE);
    }

    // 设置为非阻塞模式
    for (int i = 0; i < 2; ++i) {
        int flags = fcntl(pair[i], F_GETFL, 0);
        if (flags == -1 || fcntl(pair[i], F_SETFL, flags | O_NONBLOCK) == -1) {
            perror("fcntl");
            close(pair[0]);
            close(pair[1]);
            exit(EXIT_FAILURE);
        }
    }
}

int main() {
    try {
        // 测试 Buffer 构造函数
        std::cout << "Testing constructor..." << std::endl;
        Buffer buffer(256);

        // 测试 extendRoom 方法
        std::cout << "Testing extendRoom..." << std::endl;
        buffer.extendRoom(512); // 扩展到512字节
        std::cout << "New capacity: " << buffer.getcapacity() << std::endl;

        // 测试 appendString 方法
        std::cout << "Testing appendString..." << std::endl;
        const char* testData = "Hello, World!";
        buffer.appendString(testData);
        std::cout << "Written string: " << testData << ", new writePos: " << buffer.getWritePos() << std::endl;

        // 测试 sockRead 方法
        std::cout << "Testing sockRead..." << std::endl;
        int socketPair[2];
        createSocketPair(socketPair);

        // 向 socketPair[1] 写入数据
        const char* sendMsg = "This is a test message.";
        ssize_t bytesSent = send(socketPair[1], sendMsg, strlen(sendMsg), MSG_NOSIGNAL);
        if (bytesSent == -1) {
            perror("send");
            close(socketPair[0]);
            close(socketPair[1]);
            return EXIT_FAILURE;
        }

        // 从 socketPair[0] 读取数据到 buffer
        buffer.sockRead(socketPair[0]);

        // 关闭套接字
        close(socketPair[0]);
        close(socketPair[1]);

        // 测试 sendData 方法
        std::cout << "Testing sendData..." << std::endl;
        int tempSocketPair[2];
        createSocketPair(tempSocketPair);

        // 将 buffer 中的数据发送出去
        buffer.sendData(tempSocketPair[1]);

        // 接收数据并打印出来验证
        char recvBuf[1024] = {0};
        ssize_t bytesRead = recv(tempSocketPair[0], recvBuf, sizeof(recvBuf) - 1, MSG_NOSIGNAL);
        if (bytesRead > 0) {
            recvBuf[bytesRead] = '\0'; // null-terminate the received data
            std::cout << "Received message: " << recvBuf << std::endl;
        } else {
            std::cerr << "Failed to receive message." << std::endl;
        }

        // 关闭临时套接字
        close(tempSocketPair[0]);
        close(tempSocketPair[1]);

        // 测试析构函数（通过作用域结束自动触发）
        std::cout << "Testing destructor..." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}