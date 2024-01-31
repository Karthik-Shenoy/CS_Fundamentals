#include <iostream>
#include<vector>
#include "refactored_code.h"
using namespace std;

int main()
{
    refactored ::Notifier *notif = new refactored::BaseDecorator();
    cout << "Enter the type of notifications you want to include\n";
    cout << "1.push\n2.email\n3.sms\nx.any other value to skip notification type\n";
    vector<int> functionalities(4, 0);
    for (int i = 0; i < 3; i++)
    {
        int input;
        cin >> input;
        if (input >= 1 && input < 4)
            functionalities[input] = 1;
    }
    if (functionalities[1])
    {
        notif = new refactored::PushDecorator(notif);
    }
    if (functionalities[2])
    {
        notif = new refactored::EmailDecorator(notif);
    }
    if (functionalities[3])
    {
        notif = new refactored::SmsDecorator(notif);
    }
    cout << "Enter the notification : ";
    string msg;
    cin >> msg;
    notif->sendNotification(msg);
    return 0;
}
