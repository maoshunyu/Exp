#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>


// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")
#pragma warning(disable:4996)

#define BUFFSIZE 2048
#define DEFAULT_PORT "16555"
void print_status();
char choice[BUFFSIZE];
char recvbuf[BUFFSIZE];
int main(int argc, char** argv)
{
    printf("请输入IP地址:");
    char* addr= (char*)malloc(20 * sizeof(char));
    scanf("%s", addr);
    printf("=====================================\n剪刀为s 石头为r 布为p  输入g查看信息  双方输入quit结束游戏\n");
    WSADATA wsaData;
    SOCKET ConnectSocket = INVALID_SOCKET;
    struct addrinfo* result = NULL,
        * ptr = NULL,
        hints;
    char* sendbuf = (char*)malloc(BUFFSIZE * sizeof(char));
    int iResult;
    int recvbuflen = BUFFSIZE;
    int win = 0, lose = 0, tie = 0;

    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        return 1;
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    // Resolve the server address and port
    iResult = getaddrinfo(addr, DEFAULT_PORT, &hints, &result);
    if (iResult != 0) {
        printf("getaddrinfo failed with error: %d\n", iResult);
        WSACleanup();
        return 1;
    }

    // Attempt to connect to an address until one succeeds
    for (ptr = result; ptr != NULL; ptr = ptr->ai_next) {
        
        // Create a SOCKET for connecting to server
        ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype,
            ptr->ai_protocol);
        if (ConnectSocket == INVALID_SOCKET) {
            printf("socket failed with error: %ld\n", WSAGetLastError());
            WSACleanup();
            return 1;
        }

        // Connect to server.
        iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
        if (iResult == SOCKET_ERROR) {
            closesocket(ConnectSocket);
            ConnectSocket = INVALID_SOCKET;
            continue;
        }
        break;
    }

    freeaddrinfo(result);

    if (ConnectSocket == INVALID_SOCKET) {
        printf("Unable to connect to server!\n");
        WSACleanup();
        return 1;
    }


    while (1) {
        printf("请输入选择：");
        memset(sendbuf, 0, sizeof(sendbuf));
        memset(choice, 0, sizeof(choice));
        scanf("%s", choice);
        
        
        iResult = send(ConnectSocket, choice, (int)strlen(choice), 0);
        if (iResult == SOCKET_ERROR) {
            printf("send failed with error: %d\n", WSAGetLastError());
            closesocket(ConnectSocket);
            WSACleanup();
            return 1;
        }

        iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
        if (strcmp(recvbuf, "quit") == 0 || strcmp(choice, "quit") == 0) {
            break;
        }
        if (iResult > 0) {
            if (choice[0] == 'g' || recvbuf[0] == 'g') {
                printf("=============Game Status=============\n");
                printf("赢：%d  输：%d  平：%d  \n总计：%d  \n", win, lose, tie, win + lose + tie);
                printf("剪刀为s 石头为r 布为p  双方输入g查看信息  双方输入quit结束游戏\n");
            }
            else {
                
                if ((choice[0] == 'r' && recvbuf[0] == 'r') || (choice[0] == 's' && recvbuf[0] == 's') || (choice[0] == 'p' && recvbuf[0] == 'p')) {
                    print_status();
                    printf("平局\n");
                    tie++;
                }
                else if ((choice[0] == 'r' && recvbuf[0] == 's') || (choice[0] == 's' && recvbuf[0] == 'p') || (choice[0] == 'p' && recvbuf[0] == 'r')) {
                    print_status();
                    printf("你输了\n");
                    win++;
                }
                else if ((choice[0] == 'r' && recvbuf[0] == 'p') || (choice[0] == 's' && recvbuf[0] == 'r') || (choice[0] == 'p' && recvbuf[0] == 's')) {
                    print_status();
                    printf("你赢了\n");
                    lose++;
                }
                else {
                    printf("重新输入！！\n");
                }
            }
        }

        else if (iResult == 0)
            printf("Connection closed\n");
        else
            printf("recv failed with error: %d\n", WSAGetLastError());
        printf("=====================================\n");
    }
    printf("=============Game Status=============\n");
    printf("赢：%d  输：%d  平：%d  \n总计：%d  \n", win, lose, tie, win + lose + tie);
        


    iResult = shutdown(ConnectSocket, SD_SEND);
    if (iResult == SOCKET_ERROR) {
        printf("shutdown failed with error: %d\n", WSAGetLastError());
        closesocket(ConnectSocket);
        WSACleanup();
        return 1;
    }
    // cleanup
    closesocket(ConnectSocket);
    WSACleanup();
    system("pause");
    return 0;
}
void print_status() {
    printf("我出%s，你出%s\n", choice[0] == 'p' ? "布" : (choice[0] == 'r' ? "石头" : "剪刀"), recvbuf[0] == 'p' ? "布" : (recvbuf[0] == 'r' ? "石头" : "剪刀"));
}