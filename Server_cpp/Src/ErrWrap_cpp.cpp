#include "../Inc/ErrWrap_cpp.h"

using std::cout;
using std::cerr;
using std::endl;

int Socket(int domain, int type, int protocol)
{
    int res = socket(domain, type, protocol);
    if(res == -1)
    {
        cerr << "Socket creation error" << endl;
        exit(EXIT_FAILURE);
    }
    cout << "Socket created successfuly" << endl;
    return res;
}

void Inet_pton(int af, const char *src, void *dst)
{
    int res = inet_pton( af, src, dst);

    if(res == 0)
    {
        cerr << "Invalid address" << endl;
        exit(EXIT_FAILURE);
    }
    else if(res == -1)
    {
        cerr << "Convertation error" << endl;
        exit(EXIT_FAILURE);
    }
}

void Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
    int res = bind(sockfd, addr, addrlen);
    if(res == -1)
    {
        cerr << "Binding error" << endl;
        exit(EXIT_FAILURE);
    }
    cout << "Binding completed" << endl;
}

void Listen(int sockfd, int backlog)
{
    cout << "Listening..." << endl;
    int res = listen(sockfd, backlog);
    if(res == -1)
    {
        cerr << "Listening failure" << endl;
        exit(EXIT_FAILURE);
    }
}

int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
{
    int res = accept(sockfd, addr, addrlen);
    if ( res == -1 )
    {
        cerr << "Accept failure" << endl;
        exit(EXIT_FAILURE);
    }
    cout << "Socket is uccessfuly accpeted" << endl;
    return res;
}

void Connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
    int res = connect(sockfd, addr, addrlen);
    if(res == -1)
    {
        cerr << "Connection problem" << endl;
        exit(EXIT_FAILURE);
    }
    cout << "Connection established" << endl;
}