/*
The MIT License (MIT)

Copyright (c) 2017 Techno Road Inc.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#include "TcpClient.h"
#include <winsock2.h>
#include <ws2tcpip.h>


#pragma comment(lib,"Ws2_32.lib")

//pimpl
class CTcpClient::Impl {
public:
	SOCKET dstSocket;
	fd_set fd_base;
	fd_set fdset;
	Impl(){
	}
};


CTcpClient::CTcpClient()
	: pimpl(new CTcpClient::Impl)
{
}

CTcpClient::~CTcpClient(){
	this->Close();
	WSACleanup();
}

bool CTcpClient::Connect(const char *dst_ipadr, int dst_port){

	WSADATA data;
	WSAStartup(MAKEWORD(2, 0), &data);

	// setting
	struct sockaddr_in dstAddr;
	memset(&dstAddr, 0, sizeof(dstAddr));
	dstAddr.sin_port = htons(dst_port);
	dstAddr.sin_family = AF_INET;
	int ret_pton = inet_pton(AF_INET, dst_ipadr, &dstAddr.sin_addr.s_addr);
	if (ret_pton != 1){
		return false;
	}

	// create socket
	pimpl->dstSocket = socket(AF_INET, SOCK_STREAM, 0);

	// connect
	if (connect(pimpl->dstSocket, (struct sockaddr *) &dstAddr, sizeof(dstAddr))){
		return false;
	}

	// for select function
	FD_ZERO(&pimpl->fd_base);
	FD_SET(pimpl->dstSocket, &pimpl->fd_base);

	return true;
}


void CTcpClient::Close(){
	closesocket(pimpl->dstSocket);
}


int CTcpClient::Send(const char *buf, size_t size){
	int numsend = send(pimpl->dstSocket, buf, size, 0);
	return numsend;
}

int CTcpClient::Recv(char *buf, size_t size){
	int numrcv = recv(pimpl->dstSocket, buf, size, 0);
	return numrcv;
}

bool CTcpClient::Select(){
	//copy fdset<--fd_base
	memcpy(&pimpl->fdset, &pimpl->fd_base, sizeof(fd_set));

	// time out is 0
	struct timeval timeout;
	timeout.tv_sec = 0;
	timeout.tv_usec = 0;

	// select
	int ret = select(pimpl->dstSocket + 1, &pimpl->fdset, NULL, NULL, &timeout);

	return (ret == 1);
}
