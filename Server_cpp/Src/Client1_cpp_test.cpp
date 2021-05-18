#include "../Inc/Client_cpp.h"

/** Client1_test.cpp 
 * Test scenarios for first client in dialog
 * 
 * Describes automatic and common scenarios in main()
 */

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

#define ID 1

void CommonScenario()
{
    /* Creating Client object */
    CClient my_client;
    /* Setting it`s ID (Must be unique) */
    cout << "Set ID: ";
    int Client_ID;
    cin >> Client_ID;
    cout << endl;
    my_client.SetID(Client_ID);
    /* Inits comunication */
    my_client.ConnectionInit();
    my_client.ClientCycle();
}

//Short dialog
void TestScenario_1()
{
    CClient my_client(1);
    my_client.ConnectionInit();
    my_client.SendString(2, "Hello2");
    my_client.RecvMessage();
}

//Long dialog
void TestScenario_2()
{
    CClient my_client(1);
    my_client.ConnectionInit();
    my_client.SendString(2, "Hello2");
    my_client.RecvMessage();
    my_client.SendString(2, "What`s_up");
    my_client.RecvMessage();
    my_client.SendString(2, "Bye2");
    my_client.RecvMessage();
}

int main(int argc, char **argv)
{
    int i = atoi(argv[1]);
    switch(i)
    {
        case 0:
            CommonScenario();
        break;
        case 1:
            TestScenario_1();
        break;
        case 2:
            TestScenario_2();
        break;
    }
    return 0;
}