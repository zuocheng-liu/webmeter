#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H
#include "Http.h"
extern "C" {
};
class HttpRequest : public Http {
private:
    unsigned char method = Http::METHOD_GET;
    char message[HttpRequest::REQUEST_SIZE];
    char url[HttpRequest::REQUEST_SIZE];
    char host[HttpRequest::HOST_NAME_LENGTH];
    char uri[HttpRequest::URI_LENGTH] = "/";
    bool pragmaCache = false;
public:
    const static unsigned short REQUEST_SIZE = 2048;
    const static unsigned short HOST_NAME_LENGTH = 128;
    const static unsigned short URL_LENGTH = 1500;
    const static unsigned short URI_LENGTH = 1372;
    const static unsigned short MAX_REQUEST_LENGTH = 2048;

    char * build();
    void setUrl(char * url);
    char * getMessage();

};
#endif