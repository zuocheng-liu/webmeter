#include <iostream>
#include "Socket.h"
#include "SocketException.h"
using namespace std;
extern "C" {
#include <sys/types.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
}

Socket::Socket(const char * host,int port) {
    unsigned long inaddr;
    struct sockaddr_in ad;
    struct hostent *hp;

    memset(&ad, 0, sizeof(ad));
    ad.sin_family = AF_INET;

    inaddr = inet_addr(host);
    if (inaddr != INADDR_NONE)
        memcpy(&ad.sin_addr, &inaddr, sizeof(inaddr));
    else
    {
        hp = gethostbyname(host);
        if (hp == NULL)
            return -1;
        memcpy(&ad.sin_addr, hp->h_addr, hp->h_length);
    }
    ad.sin_port = htons(clientPort);

    this->sock = socket(AF_INET, SOCK_STREAM, 0);
    if (this->sock < 0) {
        throw SocketException();
    }
    if (connect(this->sock, (struct sockaddr *)&ad, sizeof(ad)) < 0) {
        throw SocketException();
    }
}