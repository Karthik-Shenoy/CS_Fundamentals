#include "./SubscriberServices/EmailNotificationServices.h"
#include "./SubscriberServices/SMSNotificationService.h"
#include "./PublisherServices/AccountTransactionManager.h"
#include "./PublisherServices/DatabaseController.cpp"
#include "./PublisherServices/PublisherTypes.h"
using namespace std;


int main()
{
    cout << 11 << endl;
    DatabaseController* databaseController = DatabaseController::getInstance();
    AccountTransactionManager* accountTransactionManager = new AccountTransactionManager(databaseController);
    // Ending notification services
    SMSNotificationService* smsNotificationService = new SMSNotificationService();
    EmailNotificationService*  emailNotificationService= new EmailNotificationService();

    accountTransactionManager->subscribe(emailNotificationService, Event::EVENT_READ);

    accountTransactionManager->subscribe(smsNotificationService, Event::EVENT_WRITE);

    // 3 accounts ACN_1, ACN_2, ACN_3
    vector<string> accounts = {"ACN_1", "ACN_2", "ACN_3"};
    vector<thread> threads;


    for(int i = 0; i < 9;i++)
    {
        if(i%3 == 0)
        {
            thread writerThread(&AccountTransactionManager::withdraw_money, accountTransactionManager, accounts[i % 3], 1000);
            threads.push_back(move(writerThread));
        }
        else
        {
            thread readerThread(&AccountTransactionManager::get_account_balance, accountTransactionManager, accounts[i % 3]);
            threads.push_back(move(readerThread));
        }
    }

    for(auto &th:threads)
    {
        th.join();
    }

    return 0;
}