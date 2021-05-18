#include "../Inc/Server_cpp.h"

using std::cout;
using std::endl;
using std::cerr;

/* Constructors */
CServer::CServer()
{
    m_siServerAddr.sin_family = AF_INET;
    m_siServerAddr.sin_port = htons(PORT);
    Inet_pton(AF_INET, IP, &m_siServerAddr.sin_addr);
    m_slSocketSize = sizeof(m_siServerAddr);
    pthread_mutex_init(&m_ConnectionsTableMutex, 0);
}

CServer::CServer(int iPortNew)
{
    m_siServerAddr.sin_family = AF_INET;
    m_siServerAddr.sin_port = htons(iPortNew);
    Inet_pton(AF_INET, IP, &m_siServerAddr.sin_addr);
    m_slSocketSize = sizeof(m_siServerAddr);
    pthread_mutex_init(&m_ConnectionsTableMutex, 0);
}

CServer::~CServer()
{

}

/* Definition of setters */
void CServer::SetServerFd(int iFdNew)
{
    m_iServerFd = iFdNew;
}

void CServer::SetClientsNum(int iNumNew)
{
    m_iClientsNum = iNumNew;
}

void CServer::SetSocketAddr( short SinFamilyNew,
                             unsigned short SinPortNew,
                             struct in_addr SinAddrNew)
{
    m_siServerAddr.sin_addr = SinAddrNew;
    m_siServerAddr.sin_family = SinFamilyNew;
    m_siServerAddr.sin_port = SinPortNew;
}

void CServer::SetSocketSize(socklen_t slSizeNew)
{
    m_slSocketSize = slSizeNew;
}

/* Definitions of getters */
int CServer::GetServerFd() const
{
    return m_iServerFd;
}

struct sockaddr_in CServer::GetServerAddr() const 
{
    return m_siServerAddr;
}

int CServer::GetClientsNum() const    
{
    return m_iClientsNum;
}

struct sockaddr* CServer::GetServerPtrAddr() const
{
    return (struct sockaddr*)&m_siServerAddr;
}

socklen_t CServer::GetSocketSize() const
{
    return m_slSocketSize;
}

void CServer::ServerInit()
{
    m_iServerFd = Socket(AF_INET, SOCK_STREAM, 0);
    int enable = 1;
    /**
     *  Setting attribute that allows recreating server socket without
     *  waiting timeout:
     */ 
    if (setsockopt(m_iServerFd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0)
        cerr << "setsockopt(SO_REUSEADDR) failed" << endl;
    
    /* Binding server addr to it`s socket */
    Bind(m_iServerFd, (struct sockaddr*)&m_siServerAddr, m_slSocketSize);
    /* Listening connection requests */
    Listen(m_iServerFd, MAX_SOCKET_NUM);
}

void CServer::SendString(int iDestFd, int iSrcID, int iDestID, const char* c_strMessage)
{
    cout << "Sending..." << endl;
    /* Send Source ID */
    cout << send(iDestFd, &iSrcID, sizeof(int), 0) << endl;
    /* Send Destination */
    cout << send(iDestFd, &iDestID, sizeof(int), 0) << endl;
    /* Specify WCHAR or CHAR message */
    bool IsWchar = false;
    cout << send(iDestFd, &IsWchar, sizeof(bool), 0) << endl;
    /* Send Data */
    cout << c_strMessage << endl;
    cout << send(iDestFd, c_strMessage, BUF_SIZE, 0) << endl;
}

void CServer::SendWString(int iDestFd, int iSrcID, int iDestID, const wchar_t* wc_strMessage)
{
    cout << "WSending..." << endl;
    /* Send Source ID */
    cout << send(iDestID, &iSrcID, sizeof(int), 0) << endl;
    /* Send Destination */
    cout << send(iDestID, &iDestID, sizeof(int), 0) << endl;
    /* Specify WCHAR or CHAR message */
    bool IsWchar = true;
    cout << send(iDestID, &IsWchar, sizeof(bool), 0) << endl;
    /* Send Data */
    std::wcout << wc_strMessage << endl;
    cout << send(iDestID, wc_strMessage, BUF_SIZE, 0) << endl;
}


int CServer::HandleNewConnection()
{
    /* Accepting socket from listenig queue */
    int iNewClientFd = accept(m_iServerFd, 0, 0);
    if(iNewClientFd < 0)
    {
        /* Go out, in case of no connection requests */
        return -1;
    }
    /* Creating thread */
    pthread_t *NewClientThread = new pthread_t;
    /* Prepare Connected socket Fd as an argument */
    int *ptrArgs = new int;
    *ptrArgs = iNewClientFd;
    /* Runing new thread for accepted client */
    pthread_create(NewClientThread, 0, &CServer::ServerThreadWorkCycle_PassHelper, (void*) ptrArgs);
    /* Adds new thread identifier to the vector that containes all routes */
    m_aServerRoutines.push_back(NewClientThread);
    return 0;
}

void* CServer::ServerThreadWorkCycle(void *iNewSocket)
{
    /* Client authorization */
    int iClientFd = *((int *) iNewSocket);
    cout << "Client auth" << endl;
    const char* c_strConfirm = "Connected";
    send(iClientFd, c_strConfirm, BUF_SIZE, 0);
    /* Critical section */
    pthread_mutex_lock(&m_ConnectionsTableMutex);
    int iClientID;
    
    cout << recv(iClientFd, &iClientID, sizeof(int), 0) << endl;
    cout << "Receiving ID:" << iClientID << endl;
    /* Register client in connections table */
    m_aConnections.insert(std::make_pair(iClientID, iClientFd));
    
    pthread_mutex_unlock(&m_ConnectionsTableMutex);
    cout << "Client #ID" << iClientID << " authorized" << endl;
    /* End of authorization */
    while(1)
    {
        /* Main client servicing cycle: */
        int iSrcID; 
        int iDestID;
        int iSourceID;
        bool bIsWchar;
        char c_strBuffer[BUF_SIZE];
        wchar_t wc_strBuffer[BUF_SIZE];
        
        cout << recv(iClientFd, &iSourceID, sizeof(int), 0) << endl;
        cout << recv(iClientFd, &iDestID, sizeof(int), 0) << endl;
        /* Receiving Is WCHAR flag */
        cout << recv(iClientFd, &bIsWchar, sizeof(bool), 0) << endl;
        int iDestinationFd = m_aConnections[iDestID];
        /* Receiving text and sending message */
        if(bIsWchar)
        {
            cout << recv(iClientFd, &wc_strBuffer, BUF_SIZE, 0) << endl;
            SendWString(iDestinationFd, iSourceID, iDestID, wc_strBuffer);
        }
        else
        {
            cout << recv(iClientFd, &c_strBuffer, BUF_SIZE, 0) << endl;
            SendString(iDestinationFd, iSourceID, iDestID, c_strBuffer);
        }
        cout << "Transfer message from #ID" << iSourceID << " to #ID"
            << iDestID << endl;
    }
}

int main()
{
    CServer my_server;
    my_server.ServerInit();
    /* Handling new connections cycle */
    while(1)
    {
        if(!my_server.HandleNewConnection())
        {
            cout << "New client connected!" << endl;
        }
    }
    
}