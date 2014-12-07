class Http {
private:
    unsigned char httpVersion = Http::HTTP_VERSION_1_1;
    char userAgent[USER_AGENT_LENGTH];
public:
    const static char METHOD_GET = 0;
    const static char METHOD_HEAD = 1;
    const static char METHOD_OPTIONS = 2;
    const static char METHOD_TRACE = 3;
    const static char METHOD_LABELS[4][8]= {"GET","OPTIONS","HEAD","TRACE"};

    const static char HTTP_VERSION_0_9 = 0;
    const static char HTTP_VERSION_1_0 = 1;
    const static char HTTP_VERSION_1_1 = 2;
    const static char HTTP_VERSION_LABELS[] = {"HTTP/0.9","HTTP/1.0","HTTP/1.1"};

    const static char USER_AGENT_LENGTH = 128;
};