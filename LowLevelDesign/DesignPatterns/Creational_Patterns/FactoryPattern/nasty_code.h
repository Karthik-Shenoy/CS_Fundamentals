#include <iostream>
#include <bits/stdc++.h>
using namespace std;

namespace nasty
{
    class Button
    {
    public:
        virtual void render() = 0;
        virtual void onClick() = 0;
    };

    class WindowsRoundedButton : public Button
    {
    private:
        int m_radius = 30;
        void (*m_onClickFunc)(string);

    public:
        WindowsRoundedButton(int radius, void (*onClickPtr)(string))
        {
            this->m_radius = radius;
            this->m_onClickFunc = onClickPtr;
        }
        void render()
        {
            // make calls to the windows internal styletypes
            cout << "using windows styling\n";
            cout << "rendered Rounded Button with radius : " << m_radius << '\n';
        }
        void onClick()
        {
            m_onClickFunc("Rounded Button");
        }
    };

    class LinuxRoundedButton : public Button
    {
    private:
        int m_radius = 30;
        void (*m_onClickFunc)(string);

    public:
        LinuxRoundedButton(int radius, void (*onClickPtr)(string))
        {
            this->m_radius = radius;
            this->m_onClickFunc = onClickPtr;
        }
        void render()
        {
            // make calls to the linux internal styletypes
            cout << "using Linux styling\n";
            cout << "rendered Rounded Button with radius : " << m_radius << '\n';
        }
        void onClick()
        {
            m_onClickFunc("Rounded Button");
        }
    };

    class LinuxRectangleButton : public Button
    {
    private:
        int m_width = 50, m_height = 50;
        void (*m_onClickFunc)(string);

    public:
        LinuxRectangleButton(int height, int width, void (*onClickPtr)(string))
        {
            this->m_width = width;
            this->m_height = height;
            this->m_onClickFunc = onClickPtr;
        }
        void render()
        {
            // make calls to the linux internal styletypes
            cout << "using Linux styling\n";
            cout << "rendered rectangle Button with dimensions : " << m_width << "x" << m_height << "\n";
        }
        void onClick()
        {
            m_onClickFunc("Rectangle Button");
        }
    };

    class WindowsRectangleButton : public Button
    {
    private:
        int m_width = 50, m_height = 50;
        void (*m_onClickFunc)(string);

    public:
        WindowsRectangleButton(int height, int width, void (*onClickPtr)(string))
        {
            this->m_width = width;
            this->m_height = height;
            this->m_onClickFunc = onClickPtr;
        }
        void render()
        {
            // make calls to the windows internal styletypes
            cout << "using Windows styling\n";
            cout << "rendered rectangle Button with dimensions : " << m_width << "x" << m_height << "\n";
        }
        void onClick()
        {
            m_onClickFunc("Rectangle Button");
        }
    };

    class LinuxToggleButton : public Button
    {

    private:
        int m_width = 50, m_height = 50;
        int m_currToggleValue = 1;
        string *m_toggleValues;
        void (*m_onClickFunc)(string);

    public:
        LinuxToggleButton(int height, int width, string *toggle_values, void (*onClickPtr)(string))
        {
            this->m_width = width;
            this->m_height = height;
            this->m_toggleValues = toggle_values;
            this->m_onClickFunc = onClickPtr;
        }
        void render()
        {
            // make calls to the linux internal styletypes
            cout << "using Linux styling\n";
            cout << "rendered rectangle Button with dimensions : " << m_width << "x" << m_height << "\n";
            cout << "with toggle values : " << m_toggleValues[0] << "/" << m_toggleValues[1] << "\n";
            cout << "initial value : " << m_toggleValues[m_currToggleValue] << "\n";
        }
        void onClick()
        {
            m_currToggleValue = !m_currToggleValue;
            string notification = "Toggle button => toggled from " + m_toggleValues[m_currToggleValue] + " to " + m_toggleValues[m_currToggleValue];
            m_onClickFunc(notification);
        }
    };

    class WindowsToggleButton : public Button
    {

    private:
        int m_width = 50, m_height = 50;
        int m_currToggleValue = 1;
        string *m_toggleValues;
        void (*m_onClickFunc)(string);

    public:
        WindowsToggleButton(int height, int width, string *toggle_values, void (*onClickPtr)(string))
        {
            this->m_width = width;
            this->m_height = height;
            this->m_toggleValues = toggle_values;
            this->m_onClickFunc = onClickPtr;
        }
        void render()
        {
            // make calls to the windows internal styletypes
            cout << "using Windows styling\n";
            cout << "rendered rectangle Button with dimensions : " << m_width << "x" << m_height << "\n";
            cout << "with toggle values : " << m_toggleValues[0] << "/" << m_toggleValues[1] << "\n";
            cout << "initial value : " << m_toggleValues[m_currToggleValue] << "\n";
        }
        void onClick()
        {
            m_currToggleValue = !m_currToggleValue;
            string notification = "Toggle button => toggled from " + m_toggleValues[m_currToggleValue] + " to " + m_toggleValues[m_currToggleValue];
            m_onClickFunc(notification);
        }
    };

    class UserInterface
    {
    private:
        vector<Button *> button_list;

    public:
        UserInterface(int window_width, int window_height)
        {
            cout << "window created of height " << window_height << "px and width " << window_width << "px.\n";
        }
        void addButton(Button *new_button)
        {
            button_list.push_back(new_button);
        }
        void renderElements()
        {
            cout << "#########################\n";
            cout << "rendering ...\n";
            cout << "#########################\n";
            for (Button *button : button_list)
            {
                button->render();
            }
        }
        void testClicks()
        {
            cout << "#########################\n";
            cout << "testing clicks ...\n";
            cout << "#########################\n";
            for (Button *button : button_list)
            {
                button->onClick();
            }
        }
    };
} // namespace nasty
