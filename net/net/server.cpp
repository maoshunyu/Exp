#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <WS2tcpip.h>


#pragma comment(lib,"Ws2_32.lib")
#pragma warning(disable:4996)
#define BUFFSIZE 2048
#define DEFAULT_PORT "16555"    // ָ���˿�Ϊ16555

char recvbuf[BUFFSIZE];
char choice[BUFFSIZE];
void print_status();
int main() {
    printf("=====================================\n����Ϊs ʯͷΪr ��Ϊp  ˫������g�鿴��Ϣ  ˫������quit������Ϸ\n");
    printf("�ȴ��С�����");
    int win = 0, lose = 0, tie = 0;

	WSADATA wsaData;
    int iResult;

    SOCKET ListenSocket = INVALID_SOCKET;
    SOCKET ClientSocket = INVALID_SOCKET;

    struct addrinfo* result = NULL;
    struct addrinfo hints;


    int recvbuflen = BUFFSIZE;

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
    hints.ai_flags = AI_PASSIVE;
    iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
    if (iResult != 0) {
        printf("getaddrinfo failed with error: %d\n", iResult);
        WSACleanup();
        return 1;
    }
    ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (ListenSocket == INVALID_SOCKET) {
        printf("socket failed with error: %ld\n", WSAGetLastError());
        freeaddrinfo(result);
        WSACleanup();
        return 1;
    }
    iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        printf("bind failed with error: %d\n", WSAGetLastError());
        freeaddrinfo(result);
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }
    freeaddrinfo(result);

    iResult = listen(ListenSocket, SOMAXCONN);
    if (iResult == SOCKET_ERROR) {
        printf("listen failed with error: %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }
    ClientSocket = accept(ListenSocket, NULL, NULL);
    if (ClientSocket == INVALID_SOCKET) {
        printf("accept failed with error: %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }
    closesocket(ListenSocket);
    printf("\n");
    while (1) {

        printf("������ѡ��:");
        memset(choice, 0, sizeof(choice));
        memset(recvbuf, 0, sizeof(recvbuf));
        scanf("%s", choice);
        iResult = send(ClientSocket, choice, (int)strlen(choice), 0);
        if (iResult == SOCKET_ERROR) {
            printf("send failed with error: %d\n", WSAGetLastError());
            closesocket(ClientSocket);
            WSACleanup();
            return 1;
        }
        iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
        if (strcmp(recvbuf, "quit") == 0 || strcmp(choice, "quit") == 0) {
            break;
        }
        if (iResult > 0) {
            if (choice[0] == 'g' || recvbuf[0] == 'g') {
                printf("=============Game Status=============\n");
                printf("Ӯ��%d  �䣺%d  ƽ��%d  \n�ܼƣ�%d  \n", win, lose, tie, win + lose + tie);
                printf("����Ϊs ʯͷΪr ��Ϊp  ����g�鿴��Ϣ  ˫������quit������Ϸ\n");
            }
            else {
                if ((choice[0] == 'r' && recvbuf[0] == 'r') || (choice[0] == 's' && recvbuf[0] == 's') || (choice[0] == 'p' && recvbuf[0] == 'p')) {
                    print_status();
                    printf("ƽ��\n");
                    tie++;
                }
                else if ((choice[0] == 'r' && recvbuf[0] == 's') || (choice[0] == 's' && recvbuf[0] == 'p') || (choice[0] == 'p' && recvbuf[0] == 'r')) {
                    print_status();
                    printf("������\n");
                    win++;
                }
                else if ((choice[0] == 'r' && recvbuf[0] == 'p') || (choice[0] == 's' && recvbuf[0] == 'r') || (choice[0] == 'p' && recvbuf[0] == 's')) {
                    print_status();
                    printf("��Ӯ��\n");
                    lose++;
                }
                else {
                    printf("�������룡��\n");
                }
            }
            
        }
        else if (iResult == 0)
            printf("Connection closing...\n");
        else {
            printf("recv failed with error: %d\n", WSAGetLastError());
            closesocket(ClientSocket);
            WSACleanup();
            return 1;
        }
        printf("=====================================\n");
    }
        
    printf("=============Game Status=============\n");
    printf("Ӯ��%d  �䣺%d  ƽ��%d  \n�ܼƣ�%d  \n", win, lose, tie, win + lose + tie);

    iResult = shutdown(ClientSocket, SD_SEND);
    if (iResult == SOCKET_ERROR) {
        printf("shutdown failed with error: %d\n", WSAGetLastError());
        closesocket(ClientSocket);
        WSACleanup();
        return 1;
    }
    closesocket(ClientSocket);
    WSACleanup();
    system("pause");
    return 0;

}
void print_status() {
    printf("�ҳ�%s�����%s\n", choice[0] == 'p' ? "��" : (choice[0] == 'r' ? "ʯͷ" : "����"), recvbuf[0] == 'p' ? "��" : (recvbuf[0] == 'r' ? "ʯͷ" : "����"));
}