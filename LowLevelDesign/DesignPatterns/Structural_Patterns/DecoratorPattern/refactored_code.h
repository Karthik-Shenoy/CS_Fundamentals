#include <iostream>
using namespace std;

namespace refactored
{
    // 3 types of notification
    /*
        1. push notification
        2. email notification
        3. sms notification
    */
    class Notifier
    {
    public:
        virtual void sendNotification(string msg) = 0;
    };

    class BaseDecorator : public Notifier
    {
    protected:
        Notifier *m_wrappedObject;

    public:
        void sendNotification(string msg)
        {
            cout << "Initialized message : " << msg << "\n";
        }
    };

    class EmailDecorator : public BaseDecorator
    {
    public:
        EmailDecorator(Notifier *objectToWrap)
        {
            m_wrappedObject = objectToWrap;
        }
        void sendNotification(string msg)
        {
            m_wrappedObject->sendNotification(msg);
            cout << "Sending Email Notification...( " << msg << " )\n";
        }
    };

    class PushDecorator : public BaseDecorator
    {
    public:
        PushDecorator(Notifier *objectToWrap)
        {
            m_wrappedObject = objectToWrap;
        }
        void sendNotification(string msg)
        {
            m_wrappedObject->sendNotification(msg);
            cout << "Sending push Notification...( " << msg << " )\n";
        }
    };
    class SmsDecorator : public BaseDecorator
    {
    public:
        SmsDecorator(Notifier *objectToWrap)
        {
            m_wrappedObject = objectToWrap;
        }
        void sendNotification(string msg)
        {
            m_wrappedObject->sendNotification(msg);
            cout << "Sending SMS Notification...( " << msg << " )\n";
        }
    };
}
