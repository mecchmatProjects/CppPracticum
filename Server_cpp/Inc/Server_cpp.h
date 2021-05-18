#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>
#include <pthread.h>
#include <fcntl.h>
#include <vector>
#include <map>
#include <mutex>

#include "ErrWrap_cpp.h"

#define IP "127.0.0.1"
#define BUF_SIZE 1024
#define PORT 12321
/* Number of sockets that can be connected at one time */
#define MAX_SOCKET_NUM 3
/* Connections Table */
std::map<int, int> m_aConnections;

class CServer
{
private:
    /* Server File descriptor */
    int m_iServerFd;
    
    /* Mutex for defencing Connections table */
    pthread_mutex_t m_ConnectionsTableMutex;
    /* Number of connected clients < MAX_SOCKET_NUM */
    int m_iClientsNum;
    /* Array of threads */
    std::vector<pthread_t*> m_aServerRoutines;
    /* Socket data types */
    struct sockaddr_in m_siServerAddr;
    socklen_t m_slSocketSize;


    
public:
    
    /** Constructor
     * 
     * Set ups client prefernces before creating socket and connecting 
     * to the server
     * 
     */ 
    CServer();
    CServer(int iPortNew);

    ~CServer();

    /** Setters and getters are the atomic parts of code, so 
     * that is not neccessary to cover them with tests
     */
    /* Setters */
    void SetServerFd(int iFdNew);
    void SetClientsNum(int iNumNew);
    void SetSocketAddr( short SinFamilyNew, 
                        unsigned short SinPortNew, 
                        struct in_addr SinZeroNew );

    void SetSocketSize(socklen_t slSizeNew);

    /* Getters */
    int GetServerFd() const;
    int GetBufSize() const;
    int GetClientsNum() const;
    struct sockaddr_in GetServerAddr() const;
    struct sockaddr* GetServerPtrAddr() const; 
    socklen_t GetSocketSize() const;
    int GetHighestSocket() const;

    /* Server functionalities */
    /**
     * Initialization function, that creates a socket for server,
     * Bind network setting to it
     * and begin listening (creating queue of socket for accept())
     */
    void ServerInit();

    /**
     * Handles connection requests on the server
     * 
     * If Client connects succesfully, the function creates a new thread for 
     * servicing this Client and push pthread_t variable to the Vector of active pthreads
     * 
     * @return: -1 if accept() - failed,
     *           0 if connection succeed 
     */
    int HandleNewConnection();

    /** 
     * Function that serves each client in specific thread
     * 
     * Function authorized client and then handles messages from client
     * (Thread function)
     */
    void* ServerThreadWorkCycle(void *iNewSocket);

    /** Sending data in standart format (ASCII, ANSI or Utf-8)
     * 
     * Client sends Message data in specific order in which 
     * server and other clients can read it
     * 
     * Send:
     *  Sender ID;
     *  Addressee ID;
     *  Send WCHAR flag that helps other nodes understand how it should be received; (not fully implemented)
     *  Send Data (char *)
     */
    void SendString(int iDestFd, int iSrcID, int iDestID, const char* c_strMessage);

    /** Sending data in UNICODE format
     * 
     * Client sends Message data in specific order in which 
     * server and other clients can read it
     * 
     * Send:
     *  Sender ID;
     *  Addressee ID;
     *  Send WCHAR flag that helps other nodes understand how it should be received; (not fully implemented)
     *  Send Data (wchar_t *)
     */
    void SendWString(int iDestFd, int iSrcID, int iDestID, const wchar_t* wc_strMessage);

    /** 
     * Helper static representation of th thread function
     * 
     * It used for parsing ServerThreadWorkCycle function to the
     * pthread_create
     */
    static void* ServerThreadWorkCycle_PassHelper(void *context)
    {
        return ((CServer*)context)->ServerThreadWorkCycle(context);
    }
};

#endif