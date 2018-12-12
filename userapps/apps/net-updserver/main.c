#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

#define BUFSZ   1024

int main(int argc, char **argv)
{
    int sock;
    int bytes_read;
    char *recv_data;
    socklen_t addr_len;
    struct sockaddr_in server_addr, client_addr;

    recv_data = malloc(BUFSZ);
    if (recv_data == NULL)
    {
        printf("No memory\n");
        return 1;
    }

    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
    {
        printf("Socket error\n");

        free(recv_data);
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(5000);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    memset(&(server_addr.sin_zero), 0, sizeof(server_addr.sin_zero));

    if (bind(sock, (struct sockaddr *)&server_addr,
             sizeof(struct sockaddr)) == -1)
    {
        printf("Bind error\n");

        free(recv_data);
        return 1;
    }

    addr_len = sizeof(struct sockaddr);
    printf("UDPServer Waiting for client on port 5000...\n");

    while (1)
    {
        bytes_read = recvfrom(sock, recv_data, BUFSZ - 1, 0,
                              (struct sockaddr *)&client_addr, &addr_len);

        recv_data[bytes_read] = '\0';

        printf("recv: %s", recv_data);

        if (strcmp(recv_data, "exit") == 0)
        {
            shutdown(sock, 0);

            free(recv_data);
            break;
        }
    }

    return 0;
}
