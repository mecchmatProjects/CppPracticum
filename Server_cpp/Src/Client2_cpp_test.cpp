#include "../Inc/Client_cpp.h"

/** Client2_test.cpp 
 * Test scenarios for second client in dialog
 * 
 * Describes automatic and common scenarios in main()
 */

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

#define TEST_NO 2
#define ID 2

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
//Short dialog scenario
void TestScenario_1()
{
    CClient my_client(ID);
    my_client.ConnectionInit();
    my_client.RecvMessage();
    my_client.SendString(1, "Hello1");
}
//Long dialog scenario
void TestScenario_2()
{
    CClient my_client(ID);
    my_client.ConnectionInit();
    my_client.RecvMessage();
    my_client.SendString(1, "Hello1");
    my_client.RecvMessage();
    my_client.SendString(1, "Fine!");
    my_client.RecvMessage();
    my_client.SendString(1, "Bye1");
}

int main()
{
    switch(TEST_NO)
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