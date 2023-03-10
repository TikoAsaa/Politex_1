/*
	UDP Server
*/

#include <stdio.h>
#include "UDPServer.h"
#include <iostream>
using namespace std;
#include <string>
#ifndef _WIN32
using SOCKET = int
#define WSAGetLastError() 1
#else
#include <winsock2.h>
#pragma comment(lib,"ws2_32.lib") //Winsock Library
#endif

//#define SERVER "127.0.0.1"	//ip address of udp server
#define BUFLEN 	1024		    //Max length of buffer
#define PORT    8888			//The port on which to listen for incoming data

int main(int argc, char* argv[])
{
	struct sockaddr_in si_other;
	unsigned short porttoservis;
	int slen;
	char buf[BUFLEN];
	char msg[BUFLEN];
	bool a;
	bool b = false;
	bool c = false;
	int n = 7;
	string firststr;
	string secondstr;
	        string loginnn[4] = { "Armenia", "Russian", "Italy", "USA" };
			string password[4] = { "Yerevan", "Moscow", "Rim", "Vashington" };

	porttoservis = (1 == argc) ? PORT : atoi(argv[1]);

	UDPServer server(porttoservis);
	slen = sizeof(si_other);
	cout << "Waiting for login" << endl;
	//keep listening for data
	while (!c)
	{		
		fflush(stdout);
		//clear the buffer by filling null, it might have previously received data
		memset(buf, '\0', BUFLEN);
		
		//try to receive some data, this is a blocking call
		a = false;
		    char* dd;
		server.RecvDatagram(buf, BUFLEN, (struct sockaddr*)&si_other, &slen); //stanuma qcum buf-i vra 
		firststr = buf;

		if (b = true && n < 4)
		{
			if (firststr == password[n])
			{
				cout << "You are in " << endl;
				memset(msg, '\0', BUFLEN);
				memset(msg, 'B', 1);
				server.SendDatagram(msg, (int)strlen(msg), (struct sockaddr*)&si_other, slen);
				c = true;
			}
			else {
				cout << "Wrong password, try again" << endl;
				memset(msg, '\0', BUFLEN);
				memset(msg, 'A', 1);
				server.SendDatagram(msg, (int)strlen(msg), (struct sockaddr*)&si_other, slen);
			}
		}

		for (int i = 0; i < sizeof(loginnn) / sizeof(loginnn[0]); i++)
		{
			if (firststr == loginnn[i])
			{
				a = true;
				n = i;
			}
		}
		if (a == true)
		{   
		
			cout << "Enter your password for login name: " << firststr << endl;
			b = true;
			memset(msg, '\0', BUFLEN);
			memset(msg, 'A', 1);
			server.SendDatagram(msg, (int)strlen(msg), (struct sockaddr*)&si_other, slen);
		}

		else if (a != true && n>4)
		{
			cout << "login is not regestered, try again" << endl;
			memset(msg, '\0', BUFLEN);
			memset(msg, 'A', 1);
			server.SendDatagram(msg, (int)strlen(msg), (struct sockaddr*)&si_other, slen);
			continue;
		}
	
		while (c)
		{
			
			fflush(stdout);
			memset(buf, '\0', BUFLEN);
			server.RecvDatagram(buf, BUFLEN, (struct sockaddr*)&si_other, &slen);
			cout << "client: " << buf << endl;
			gets_s(msg, BUFLEN);
			server.SendDatagram(msg, (int)strlen(msg), (struct sockaddr*)&si_other, slen);


		}
	}

	return 0;
}
