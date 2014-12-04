class Http {
public:
    const static char METHOD_GET = 0;
    const static char METHOD_HEAD = 1;
    const static char METHOD_OPTIONS = 2;
    const static char METHOD_TRACE = 3;
    const static char METHOD_LABELS[4][8]= {"GET","OPTIONS","HEAD","TRACE"};
    const static unsigned int MAX_REQUEST_LENGTH = 2048;
    //const static
    char version[3];
    Http();


private:
    unsigned short method;
    char request[MAX_REQUEST_LENGTH];
};