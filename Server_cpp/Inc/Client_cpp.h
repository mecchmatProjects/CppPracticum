#ifndef CLIENT_H
#define CLIENT_H

/** Client.h 
 * Header file for client source code
 * 
 * Describes Client class and its functionalities
 * 
 * Client - application that gives an opportunity for user to 
 * communicate with other clients using centrilized communication with server
 */

#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <wchar.h>
#include "ErrWrap_cpp.h"

#define IP "127.0.0.1"
#define BUF_SIZE 1024
#define PORT 12321

class CClient
{
private:
    /* ID of the client */
    int m_iID;
    /* Client Socket file descriptor */
    int m_iClientFd;
    
    /* Struct that contains server socket connection info */
    struct sockaddr_in m_siServerAddr;
    socklen_t m_slSocketSize;
    
public:
    
    /** Constructors
     * 
     * Set ups client prefernces before creating socket and connecting 
     * to the server
     * 
     */ 
    CClient();
    CClient(int iIDNew);
    CClient(int iIDNew, int iPortNew);

    ~CClient();

    /** Setters and getters are the atomic parts of code, so 
     * that is not neccessary to cover them with tests
     */
    /* Setters */
    void SetID(int iIDNew);
    void SetClientFd(int iFdNew);

    void SetSocketAddr( short SinFamilyNew, 
                        unsigned short SinPortNew, 
                        struct in_addr SinAddrNew );

    void SetSocketSize(socklen_t slSizeNew);

    /* Getters */
    int GetID() const;
    int GetClientFd() const;
    struct sockaddr_in GetServerAddr() const;
    struct sockaddr* GetServerPtrAddr() const; 
    socklen_t GetSocketSize() const;

    /* Client functionalities: */
    /** Client initializator
     * 
     * Function create client socket and connect it ti the server via
     * connect() syscall
     * 
     * In case of successful connection it start authorization:
     *      -Server response Connected
     *      -Client send it`s ID to the Server
     *      -Server receive Client`s ID and push it to the Connections Table
     * 
     */
    void ConnectionInit();

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
    void SendString(int DestID, const char* c_strMessage);

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
    void SendWString(int DestID, const wchar_t* wc_strMessage);

    /** Reeceives forwarded message from server and shows it 
     * 
     */
    void RecvMessage();

    /** Client endless loop 
     * 
     * Loop of client that asks user for choosing reaceive or sender mode and
     * then accepting data from the user and parse it to the sending functions
     */
    void ClientCycle();
};

#endif