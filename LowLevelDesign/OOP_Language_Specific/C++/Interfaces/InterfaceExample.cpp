#include <iostream>
#include "ServiceFactory.h"
#include "UserServices.h"
#include "Types.h"
#include "GlobalState.h"
using namespace std;

int main()
{
    ServiceFactory *customSerrviceFactory = new ServiceFactory();
    // Input Types (keyboard and file)
    InputServiceType inputType = IST_Keyboard;
    OutputServiceType outputType = OST_Monitor;
    // dependency injection into the user class
    User *user = new User(inputType, outputType, customSerrviceFactory);

    user->read();
    user->write();
    return 0;
}
