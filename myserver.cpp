#include <winsock2.h>
#include <winsock.h>//windows

#include <sys/types.h>
#include <stdarg.h>
// <sys/socket.h>  //UNIX
//#include <netdb.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <Ws2tcpip.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string>
#include <fcntl.h>
#include <errno.h>
#include <sstream>
#include <vector>
#include <algorithm>


#define DEFAULT_BUFLEN 512
#define MAX_BUFFER 4095
#define PORT "22000"
#define MAX 20
#define Domen AF_INET;
#define IP "127.0.0.1"

#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")
#define PREFIX "SERVER: "
#define MAX_BUFFER 4095


#include <sys/stat.h>

#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#define DEFAULT_BUFLEN 512

using namespace std;


int main(int argc, char **argv)
{
	WSADATA wsaData;

	char str[MAX_BUFFER];
	int recvbuflen = DEFAULT_BUFLEN;
	char recvbuf[DEFAULT_BUFLEN];

	int status;
	/*socket for exchange data (send/recv)*/
	SOCKET socketFd = INVALID_SOCKET;
	//int SocketFd;

	/*a descripter socket for binding to an adress */
	SOCKET listener = INVALID_SOCKET; //INVALID_SOCKET=-1

									  //int listener;
	
	struct addrinfo hints;
	struct addrinfo *addrptr;

	
	

	int sendStatus;

	// Initialize Winsock
	status = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (status != 0)
	{
		printf("WSAStartup failed with error: %d\n", status);
		return 1;
	}

	memset(&hints, 0, sizeof(hints));

	hints.ai_family = Domen;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	//hints.ai_flags = AI_PASSIVE; //sam zapolnyaet IP


	status = getaddrinfo("127.0.0.1", PORT, &hints, &addrptr);
	if (status != 0) {
		printf("error in getaddrinfo: %d\n", status);
		WSACleanup();
		return 1;
	}


	printf("\n   sozdaem ochered zaprosov na soedinenie \n");

	listener = socket(addrptr->ai_family, addrptr->ai_socktype, addrptr->ai_protocol);





	printf("Bind socket \n");
	status = bind(listener, addrptr->ai_addr, (int)addrptr->ai_addrlen);
	if (status == -1)
	{
		printf(" error in bind: %d\n", WSAGetLastError());
		freeaddrinfo(addrptr);
		closesocket(listener);
		WSACleanup();//освобождаем ресурсы
		return 1;
	}

	freeaddrinfo(addrptr);


	printf("Start listen on the socket\n");

	status = listen(listener, MAX);
	if (status == -1) {
		printf("listen failed with error: %d\n", WSAGetLastError());
		closesocket(listener);
		WSACleanup();
		return 1;
	}


	printf("create a new socket,  Accept new connection (wait for it)\n");
	socketFd = accept(listener, NULL, NULL);
	if (socketFd == -1) {
		printf("erroe in accept: %d\n", WSAGetLastError());
		closesocket(socketFd);
		WSACleanup();
		return 1;
	}



	printf("Accepted\n");
	size_t s;
	vector<int>year;
	vector<int>month;
	vector<double>y;
	int j;
	int counts=0;
	string stringOfDigit("");
	double DoubleValue;
	int IntegerValue;
 long int d;
	//string Digit;
	//char Digit[sizeof(int)+1];
 char *Digit;
	do {
		status = recv(socketFd, recvbuf, recvbuflen, 0);
		if (status > 0) {
			printf("Bytes received: %d\n", status);
			printf(" message \n");
			for (int i = 0; i < status; i++) {
				stringOfDigit += recvbuf[i];

			}

			

			//for (int i = 0; i < stringOfDigit.size(); i++) {

			//	//на сервер поток данных приходит с ишними пробелами
			//	//поэтому удаляем пробелы из буфера
			//	if (stringOfDigit[i] == ' ') {
			//		stringOfDigit.erase(i);
			//	}

			//}

			stringOfDigit.erase(remove(stringOfDigit.begin(), stringOfDigit.end(), ' '), stringOfDigit.end());


			j = 0;
			cout << "Digit \n";
			
			for (int i = 0; i <= stringOfDigit.size(); i++) {

				if (stringOfDigit[i] != '\n') {
					//if (stringOfDigit[i] != ',') {
					if(isdigit(stringOfDigit[i])){
						std::string::size_type toIndexInt, toIndexDouble; // Индексы хранящие конец числа в строке.
						

						//Digit = stringOfDigit.substr(i, 1);
						//Digit += stringOfDigit.substr(i);
						//Digit[j] = stringOfDigit[i];
						//Digit = stringOfDigit.append(i);
				/*		j = j + 1;
					}

					else {*/

						//Digit[j] = '\0';
						if (counts == 0) {
							IntegerValue = std::stoi(stringOfDigit.substr(i), &toIndexInt);
							year.emplace_back(IntegerValue);
							i += toIndexInt;
						}
						if (counts == 1) {
							IntegerValue = std::stoi(stringOfDigit.substr(i), &toIndexInt);
							month.emplace_back(IntegerValue);
							i += toIndexInt;
						}
						if (counts == 2) {
							DoubleValue = std::stod(stringOfDigit.substr(i), &toIndexDouble);
							y.emplace_back(DoubleValue);
							i += toIndexDouble;
						}
							//d=atoi(Digit);
						//	cout <<"d= "<<d;
							//year.push_back(stoi(Digit)); }
							//reverse(Digit.begin(), Digit.end()); //переворачиваю строку потому чтобы на выходе получать 2017 а не 7102

							/*for (int j = Digit.; j < Digit.size();j++) {

							}*/


							//		Digit.erase();

						
						
					
					}

				}

				//if (stringOfDigit[i] == '\n') {
				else {
					counts += 1;
				}
			
					


						/*if (counts = 2) {
							month.push_back(stoi(Digit));
							Digit.erase();
							j = 0;
						}
						if (counts = 3) {
							y.push_back(stof(Digit));
							Digit.erase();
							j = 0;
						}*/
				
										


				
				//cout << " " << Digit;
				
			
			//	cout << Digit << "  ";
			
			}  
			
			//cout <<"string after deletev spaces \n"<< stringOfDigit <<"\n"<< endl;
			
		std::cout << "Vector year:"; for (auto &it : year) { std::cout << it << " "; }
		cout << "\n";
			std::cout << "Vector month:"; for (auto &it : month) { std::cout << it << " "; }
			cout << "\n";
			std::cout << "Vector Y:"; for (auto &it : y) { std::cout << it << " "; }
		}
		

		else if (status == 0) {
			printf("Connecting closing... \n");
		}

	} while (status > 0);

	delete recvbuf;
	stringOfDigit.erase();

	closesocket(listener);
	system("pause");


}


