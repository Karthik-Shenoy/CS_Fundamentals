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

class ButtonFactory
{
private:
    string operating_system;

public:
    ButtonFactory(string operating_system)
    {
        this->operating_system = operating_system;
    }
    Button *create_rounded_button(int radius, void (*clickHandler)(string))
    {
        return new RoundedButton(radius, clickHandler, operating_system);
    }
    Button *create_toggle_button(int w, int h, string *toggle_values, void (*clickHandler)(string))
    {
        return new ToggleButton(w, h, toggle_values, clickHandler, operating_system);
    }
    Button *create_rectangle_button(int w, int h, void (*clickHandler)(string))
    {
        return new RectangleButton(w, h, clickHandler, operating_system);
    }
};

void clickHandler(string btn_type)
{
    cout << "clicked on" << btn_type << "\n";
}

int main()
{
    UserInterface *mainUserInterface = new UserInterface(500, 500);
    // we have 2 button types 1.rectangle_button, 2.round_button
    string *toggle_values = new string[2];
    toggle_values[0] = "off";
    toggle_values[1] = "on";
    
    string os;
    cout << "Enter the operating system : ";
    cin >> os;

    ButtonFactory *button_factory = new ButtonFactory(os);

    Button *rnd_button = button_factory->create_rounded_button(60, clickHandler);
    Button *rect_button = button_factory->create_rectangle_button(75, 75, clickHandler);
    Button *tog_button = button_factory->create_toggle_button(35, 35, toggle_values, clickHandler);

    mainUserInterface->addButton(rnd_button);
    mainUserInterface->addButton(rect_button);
    mainUserInterface->addButton(tog_button);
    mainUserInterface->renderElements();

    mainUserInterface->testClicks();
    mainUserInterface->testClicks();
    mainUserInterface->testClicks();
    return 0;
}