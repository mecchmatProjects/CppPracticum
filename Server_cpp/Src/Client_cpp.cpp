#include "../Inc/Client_cpp.h"

/** Client.cpp 
 * Source code of clients app
 * 
 * Describes Client class and its functionalities
 * 
 * Client - application that gives an opportunity for user to 
 * communicate with other clients using centrilized communication with server
 */

/* Taking streams for more comfortable usage */
using std::cout;
using std::endl;
using std::cin;
using std::cerr;

/**
 * Definition of constructors 
 */
CClient::CClient()
{
    m_iID = 1;
    const char *iIP = IP;
    m_siServerAddr.sin_family = AF_INET;
    m_siServerAddr.sin_port = htons(PORT);
    Inet_pton(AF_INET, iIP, &m_siServerAddr.sin_addr);
    m_slSocketSize = sizeof(m_siServerAddr);
    cout << "Client setuped" << endl;
}

CClient::CClient(int iIDNew)
{
    m_iID = iIDNew;
    const char *iIP = IP;
    m_siServerAddr.sin_family = AF_INET;
    m_siServerAddr.sin_port = htons(PORT);
    Inet_pton(AF_INET, iIP, &m_siServerAddr.sin_addr);
    m_slSocketSize = sizeof(m_siServerAddr);
    cout << "Client setuped" << endl;
}

CClient::CClient(int iIDNew, int iPortNew)
{
    m_iID = iIDNew;
    const char *iIP = IP;
    m_siServerAddr.sin_family = AF_INET;
    m_siServerAddr.sin_port = htons(iPortNew);
    Inet_pton(AF_INET, iIP, &m_siServerAddr.sin_addr);
    m_slSocketSize = sizeof(m_siServerAddr);
    cout << "Client setuped" << endl;
}

/** Destructor 
 * Closing socket(That case apeared if Client cycle`s breaked)
 */
CClient::~CClient()
{
    cout << "Client #" << m_iID << "shuts downs!" << endl;
    close(m_iClientFd);
}
/* Definitions of Setters */
void CClient::SetID(int iIDNew)
{
    m_iID = iIDNew;
}

void CClient::SetClientFd(int iFdNew)
{
    m_iClientFd = iFdNew;
}

void CClient::SetSocketAddr( short SinFamilyNew, 
                    unsigned short SinPortNew, 
                    struct in_addr SinAddrNew )
{
    m_siServerAddr.sin_addr = SinAddrNew;
    m_siServerAddr.sin_family = SinFamilyNew;
    m_siServerAddr.sin_port = SinPortNew;
}

void CClient::SetSocketSize(socklen_t slSizeNew)
{
    m_slSocketSize = slSizeNew;
}

/* Definition of getters */
int CClient::GetID() const
{
    return m_iID;
}
int CClient::GetClientFd() const
{
    return m_iClientFd;
}

struct sockaddr_in CClient::GetServerAddr() const 
{
    return m_siServerAddr;
}

struct sockaddr* CClient::GetServerPtrAddr() const
{
    return (struct sockaddr*)&m_siServerAddr;
}

socklen_t CClient::GetSocketSize() const
{
    return m_slSocketSize;
}

void CClient::ConnectionInit()
{
    /* Creating socket */
    m_iClientFd = Socket(AF_INET, SOCK_STREAM, 0);
        
    /* Connect current socket to the server */
    Connect(m_iClientFd, GetServerPtrAddr(), m_slSocketSize);
    char *m_c_strBuffer = new char[BUF_SIZE];
    cout << recv(m_iClientFd, m_c_strBuffer, BUF_SIZE, 0) << endl; 
    /* Authorization initiated if server response with (Connected) */
    cout << "Connection confirmed and Server responses: " << m_c_strBuffer << endl;
    if(strcmp("Connected", m_c_strBuffer) == 0)
    {
        /* Authorization */
        /* Sending to the server ID of current client */
        cout << send(m_iClientFd, &m_iID, sizeof(int), 0) << endl;
    }
}

void CClient::ClientCycle()
{
    while(1)
    {
        /* Asking user to choose mode */
        cout << "Sending or Receiving..." << endl;
        cout << "S/R: ";
        char chIsSend;
        cin >> chIsSend;
        cout << endl;
        if(chIsSend == 'S' || chIsSend == 's')
        {
            /* Asking user to chose message format */
            int DestID;
            char chIsWCHAR;
            cout << "Set Destination Client ID" << endl;
            cin >> DestID;
            cout << "Do you want to send common string" << endl;
            cout << "Y/N (Yes/Np): ";
            cin >> chIsWCHAR;
            cout << endl;
            if(chIsWCHAR == 'Y' || chIsWCHAR == 'y')
            {
                /* Initiate sending message */
                char cstrMsg[BUF_SIZE];
                cout << "Set message text: ";
                cin >> (char*)cstrMsg;
                cout << endl;
                SendString(DestID, cstrMsg);
            }
            else if(chIsWCHAR == 'N' || chIsWCHAR == 'n')
            {
                /* Initiate sending wchar message */
                const wchar_t* wstrMsg;
                std::wstring wstrConv;
                cout << "Set message text: ";
                std::wcin >> wstrConv;
                cout << endl;
                wstrMsg = wcsdup(wstrConv.c_str());
                SendWString(DestID, wstrMsg);
            }
            else
            {
                cerr << "Wrong option" << endl;
            }
        }
        else if(chIsSend == 'R' || chIsSend == 'r')
        {
            /* In case of receiving mode */
            /* Reading message from server and show it */
            RecvMessage();
        }
        else
        {
            cerr << "Wrong option" << endl;
        }
    }
}

void CClient::SendString(int DestID, const char* c_strMessage)
{
    /* Send Source ID */
    cout << "Sending..." << endl;
    cout << send(m_iClientFd, &m_iID, sizeof(int), 0) << endl;
    /* Send Destination */
    cout << send(m_iClientFd, &DestID, sizeof(int), 0) << endl;
    /* Specify WCHAR or CHAR message */
    bool IsWchar = false;
    cout << send(m_iClientFd, &IsWchar, sizeof(bool), 0) << endl;
    /* Send Data */
    cout << send(m_iClientFd, c_strMessage, BUF_SIZE, 0) << endl;
}

void CClient::SendWString(int DestID, const wchar_t* wc_strMessage)
{
    /* Send Source ID */
    cout << "Sending..." << endl;
    cout << send(m_iClientFd, &m_iID, sizeof(int), 0) << endl;
    /* Send Destination */
    cout << send(m_iClientFd, &DestID, sizeof(int), 0) << endl;
    /* Specify WCHAR or CHAR message */
    bool IsWchar = true;
    cout << send(m_iClientFd, &IsWchar, sizeof(bool), 0) << endl;
    /* Send Data */
    cout << send(m_iClientFd, wc_strMessage, BUF_SIZE, 0) << endl;
}

void CClient::RecvMessage()
{
    int iSrcID;
    int iDestID;
    bool bISWchar;
    char c_strBuffer[BUF_SIZE];
    wchar_t wc_strBuffer[BUF_SIZE]; 
    /* Receiving data */
    /* Recv. Source ID */
    cout << recv(m_iClientFd, &iSrcID, sizeof(int), 0) << endl;
    /* Recv. Destination ID */
    cout << recv(m_iClientFd, &iDestID, sizeof(int), 0) << endl;
    /* Recv. WCHAR flag */
    cout << recv(m_iClientFd, &bISWchar, sizeof(bool), 0) << endl;
    /* Recveive and show text */
    if(bISWchar)
    {
        cout << recv(m_iClientFd, &wc_strBuffer, BUF_SIZE, 0) << endl;
        std::wcout << L"#ID" << iSrcID << L" says: " << wc_strBuffer << endl;
    }
    else
    {
        cout << recv(m_iClientFd, &c_strBuffer, BUF_SIZE, 0) << endl;
        std::cout << "#ID" << iSrcID << " says: " << c_strBuffer << endl;
    }
    
}
