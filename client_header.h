#pragma once
#include <winsock2.h>




#include <sys/types.h>
#include <stdarg.h>
// <sys/socket.h>  //UNIX
//#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <Ws2tcpip.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>


#define DEFAULT_BUFLEN 512
#define MAX_BUFFER 4095
#define PORT "22000"
#define MAX 20
#define Domen AF_INET;
#define IP "127.0.0.1"

#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")


using namespace std;

class sendData {
public:
	void connectToServer(void);
	void disconnect(void);




};