#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFSZ       (1024)

static const char send_data[] = "This is TCP Server from RT-Thread."; /* 发送用到的数据 */
int main(int argc, char **argv)
{
    char *recv_data; /* 用于接收的指针，后面会做一次动态分配以请求可用内存 */
    socklen_t sin_size;
    int sock, connected, bytes_received;
    struct sockaddr_in server_addr, client_addr;
    int stop = 0; /* 停止标志 */
    int ret;

    recv_data = malloc(BUFSZ + 1); /* 分配接收用的数据缓冲 */
    if (recv_data == NULL)
    {
        printf("No memory\n");
        return 1;
    }

    /* 一个socket在使用前，需要预先创建出来，指定SOCK_STREAM为TCP的socket */
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        /* 创建失败的错误处理 */
        printf("Socket error\n");

        /* 释放已分配的接收缓冲 */
        free(recv_data);
        return 2;
    }

    /* 初始化服务端地址 */
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(5000); /* 服务端工作的端口 */
    server_addr.sin_addr.s_addr = INADDR_ANY;
    memset(&(server_addr.sin_zero), 0, sizeof(server_addr.sin_zero));

    /* 绑定socket到服务端地址 */
    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) != 0)
    {
        /* 绑定失败 */
        printf("Unable to bind\n");

        /* 释放已分配的接收缓冲 */
        free(recv_data);
        return 3;
    }

    /* 在socket上进行监听 */
    if (listen(sock, 5) != 0)
    {
        printf("Listen error\n");

        /* release recv buffer */
        free(recv_data);
        return 4;
    }

    printf("\nTCPServer Waiting for client on port 5000...\n");
    while (!stop)
    {
        sin_size = sizeof(struct sockaddr_in);

        /* 接受一个客户端连接socket的请求，这个函数调用是阻塞式的 */
        connected = accept(sock, (struct sockaddr *)&client_addr, &sin_size);
        /* 返回的是连接成功的socket */
        if (connected < 0)
        {
            printf("accept connection failed!\n");
            continue;
        }

        /* 客户端连接的处理 */
        while (1)
        {
            /* 发送数据到connected socket */
            ret = send(connected, send_data, strlen(send_data), 0);
            if (ret < 0)
            {
                /* 发送失败，关闭这个连接 */
                shutdown(connected, 0);
                printf("\nsend error,close the socket.\r\n");
                break;
            }
            else if (ret == 0)
            {
                /* 打印send函数返回值为0的警告信息 */
                printf("\n Send warning,send function return 0.\r\n");
            }

            /* 从connected socket中接收数据，接收buffer是1024大小，但并不一定能够收到1024大小的数据 */
            bytes_received = recv(connected, recv_data, BUFSZ, 0);
            if (bytes_received < 0)
            {
                /* 接收失败，关闭这个connected socket */
                shutdown(connected, 0);
                break;
            }
            else if (bytes_received == 0)
            {
                /* 打印recv函数返回值为0的警告信息 */
                printf("\nReceived warning,recv function return 0.\r\n");
                shutdown(connected, 0);
                break;
            }

            /* 有接收到数据，把末端清零 */
            recv_data[bytes_received] = '\0';
            if (strcmp(recv_data, "q") == 0 || strcmp(recv_data, "Q") == 0)
            {
                /* 如果是首字母是q或Q，关闭这个连接 */
                shutdown(connected, 0);
                break;
            }
            else if (strcmp(recv_data, "exit") == 0)
            {
                /* 如果接收的是exit，则关闭整个服务端 */
                shutdown(connected, 0);
                stop = 1;
                break;
            }
            else
            {
                /* 在控制终端显示收到的数据 */
                printf("RECEIVED DATA = %s \n", recv_data);
            }
        }
    }

    /* 退出服务 */
    shutdown(sock, 0);

    /* 释放接收缓冲 */
    free(recv_data);

    return 0;
}
