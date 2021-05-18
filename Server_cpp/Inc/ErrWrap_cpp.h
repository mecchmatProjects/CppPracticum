#ifndef ERR_WRAP_H
#define ERR_WRAP_H

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

/**
 *  
 *  This helper file contains wrappers for
 * handling and asserting socket manipultion sysyem calls 
 * ------------------------------------------------------
 */


/** 
 * 
 * Creates socket and returns it`s file descriptor
 * 
 */
int Socket(int domain, int type, int protocol);

/**
 * 
 * Converts Ip address from text to binary form
 * 
 */
void Inet_pton(int af, const char *src, void *dst);


/**
 * 
 * Bind (Attach) socket addr to socket 
 * 
 */
void Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);

/** 
 * 
 * Listen for connections on socket
 * 
 */
void Listen(int sockfd, int backlog);

/**
 * 
 * Accept a conection on socket
 * 
 */
int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);

/**
 * 
 * Connects to socket
 * 
 */
void Connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);

#endif
