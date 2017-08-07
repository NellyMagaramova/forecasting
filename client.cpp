#include "client_header.h"

void sendData::connectToServer(void) {
	WSADATA wsaData; //структура для  хранения сведения об инициализации Windos Sockets
					 //возвращенный вызовом к AfxSocketInit глобальной функции
	int status;

	//int socketFd, n;

	SOCKET socketFd = -1;//or socketFd = INVALID_SOCKET

						 //char sendline[MAX_BUFFER];
						 //char recvline[MAX_BUFFER];

	char *sendbuf = "this is a test";
	char recvbuf[DEFAULT_BUFLEN];
	int recvbuflen = DEFAULT_BUFLEN;


	struct    addrinfo hints;
	struct  addrinfo *servinfo = nullptr, *ptr = nullptr; // servinfo-указатель на результаты вызова.

														  // инициализирую Winsock
	status = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (status != 0) {
		printf("oshibka inicializacii structur WSAStartup : %d\n", status);
		
	}

	memset(&hints, 0, sizeof(hints));
	//bzero(&servaddr,sizeof servaddr);



	hints.ai_family = Domen; //флаг AF_UNSPEC указывает, что  все равно, использовать ли ipv4 или ipv6.  
							 //можно устанавливать этот флаг в AF_INET или AF_INET6

	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	//servaddr.sin_family=AF_INET;
	//servaddr.sin_port=htons(PORT);

	printf("\n gotovimsya k soedineniyu");
	status = getaddrinfo(IP, PORT, &hints, &servinfo);




	//создаем дескриптор сокета для соединения с сервером






	socketFd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
	//socketFd = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);


	if (socketFd == -1) {
		// WSAGetLastError 
		//
		printf("\n soketFd=-1. ne vozmozhno gjlsoedinitsya k serveru: %ld\n", WSAGetLastError);
		WSACleanup();
		


	}




	printf("\n sozdali deskriptor soketa ");
	printf("\n podkluchaemsa k ustroistvu");

	//connect(socketFd, (struct sockaddr *)&servaddr, sizeof(servaddr));

	status = connect(socketFd, servinfo->ai_addr, (int)servinfo->ai_addrlen);
	//status=connect(socketFd, ptr->ai_addr, (int)ptr->ai_addrlen);
	if (status == -1) {
		printf("oshibka podkluchenia k hostu");
		closesocket(socketFd);

	}

	printf("\n !!! uspesho podkluchilis\n");



	// Send an initial buffer
	status = send(socketFd, sendbuf, (int)strlen(sendbuf), 0);
	if (status == -1) {
		printf("oshibka pri otpravke. status=-1: %d\n", WSAGetLastError());
		closesocket(socketFd);
		WSACleanup();
		
	}

	printf("\n \n \n Bytes Sent: %ld\n", status);
	//system("pause");

}
void sendData::disconnect(void) {

}