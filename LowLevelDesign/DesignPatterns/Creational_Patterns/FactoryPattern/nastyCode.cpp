#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Button
{
protected:
    string operating_system;

public:
    virtual void render() = 0;
    virtual void onClick() = 0;
};

class RoundedButton : public Button
{
private:
    int radius = 30;
    void (*on_click_func)(string);

public:
    RoundedButton(int radius, void (*on_click_ptr)(string), string operating_system)
    {
        this->operating_system = operating_system;
        this->radius = radius;
        this->on_click_func = on_click_ptr;
    }
    void render()
    {
        cout << "rendered Rounded Button with radius : " << radius << '\n';
    }
    void onClick()
    {
        on_click_func("Rounded Button");
    }
};

class RectangleButton : public Button
{
private:
    int width = 50, height = 50;
    void (*on_click_func)(string);

public:
    RectangleButton(int height, int width, void (*on_click_ptr)(string), string operating_system)
    {
        this->operating_system = operating_system;
        this->width = width;
        this->height = height;
        this->on_click_func = on_click_ptr;
    }
    void render()
    {
        cout << "rendered rectangle Button with dimensions : " << width << "x" << height << "\n";
    }
    void onClick()
    {
        on_click_func("Rectangle Button");
    }
};

class ToggleButton : public Button
{

private:
    int width = 50, height = 50;
    int curr_val = 1;
    string *toggle_values;
    void (*on_click_func)(string);

public:
    ToggleButton(int height, int width, string *toggle_values, void (*on_click_ptr)(string), string operating_system)
    {
        this->operating_system = operating_system;
        this->width = width;
        this->height = height;
        this->toggle_values = toggle_values;
        this->on_click_func = on_click_ptr;
    }
    void render()
    {
        cout << "rendered rectangle Button with dimensions : " << width << "x" << height << "\n";
        cout << "with toggle values : " << toggle_values[0] << "/" << toggle_values[1] << "\n";
        cout << "initial value : " << toggle_values[curr_val] << "\n";
    }
    void onClick()
    {
        curr_val = !curr_val;
        string notification = "Toggle button => toggled from " + toggle_values[!curr_val] + " to " + toggle_values[curr_val];
        on_click_func(notification);
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

void clickHandler(string btn_type)
{
    cout << "clicked on" << btn_type << "\n";
}

int main()
{
    UserInterface *mainUserInterface = new UserInterface(500, 500);
    string *toggle_values = new string[2];
    toggle_values[0] = "off";
    toggle_values[1] = "on";

    string os;
    cout << "Enter the operating system : ";
    cin >> os;

    // we have 2 button types 1.rectangle_button, 2.round_button
    Button *rnd_button = new RoundedButton(60, clickHandler, os);
    Button *rect_button = new RectangleButton(75, 75, clickHandler, os);
    Button *tog_button = new ToggleButton(65, 65, toggle_values, clickHandler, os);

    mainUserInterface->addButton(rnd_button);
    mainUserInterface->addButton(rect_button);
    mainUserInterface->addButton(tog_button);
    mainUserInterface->renderElements();
    mainUserInterface->testClicks();
    mainUserInterface->testClicks();
    mainUserInterface->testClicks();
    return 0;
}