#ifndef SOCKET_H
#define SOCKET_H
class Socket {
private:
    int sock = 0;
public:
    Socket(const char *,int);
    ~Socket();
};
#endif