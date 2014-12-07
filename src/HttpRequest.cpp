#include "HttpRequest.h"
#include "HttpException.h"
#include <cstring>
extern "C" {

}
char * HttpRequest::build() {
    bzero(this->message);
    bzero(this->host);

    /*
     * GET / HTTP/1.1
     */
    strcpy(this->message,Http::METHOD_LABELS[this->method]);
    strcat(this->message," ");
    strcat(this->message,this->uri);
    strcat(this->message," ");
    strcat(this->message,Http::HTTP_VERSION_LABELS[this->httpVersion]);
    strcat(this->message,"\r\n");
    /*
     * User Agent: ******
     */
    strcat(this->message,"User-Agent: ");
    strcat(this->message,this->userAgent);
    strcat(this->message,"\r\n");
    /*
     * Host: www.zuocheng.net
     */
    strcat(this->message,"Host: ");
    strcat(this->message,this->host);
    strcat(this->message,"\r\n");

    /*
     * Pragma: no-cache\r\n
     */
    if (this->pragmaCache) {
        strcat(this->message,"Pragma: no-cache\r\n");
    }
    /*
     * Connection: close
     */
    if (this->httpVersion == Http::HTTP_VERSION_1_1) {
        strcat(this->message,"Connection: close\r\n");
    }
    /*
     * add empty line at end
     */
    if(this->httpVersion == Http::HTTP_VERSION_1_1 || this->httpVersion == Http::HTTP_VERSION_1_0) {
        strcat(this->message,"\r\n");
    }
}
void HttpRequest::setUrl(char *url) {
    if (NULL == strstr(url,"://")) {
        throw HttpException("is not a valid URL");
    }
    if (strlen(url) > HttpRequest::URL_LENGTH) {
        throw HttpException("URL is too long");
    }
    strcpy(this->url,url);
}
