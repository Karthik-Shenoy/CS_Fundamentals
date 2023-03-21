#include <iostream>
#include "nasty_code.h"
#include "refactored_code.h"
using namespace std;


void clickHandler(string btn_type)
{
    cout << "clicked on" << btn_type << "\n";
}

void nastyCodeImpl(){
    nasty :: UserInterface *mainUserInterface = new nasty :: UserInterface(500, 500);
    string *toggle_values = new string[2];
    toggle_values[0] = "off";
    toggle_values[1] = "on";

    string os;
    cout << "Enter the operating system : ";
    cin >> os;

    // 1.rectangle_button, 2.round_button, 3.toggle_button
    nasty :: Button *rnd_button;
    nasty :: Button *rect_button;
    nasty :: Button *tog_button;
    if(os == "windows"){     
        rnd_button = new nasty :: WindowsRoundedButton(60, clickHandler);
        rect_button = new nasty :: WindowsRectangleButton(75, 75, clickHandler);
        tog_button = new nasty :: WindowsToggleButton(65, 65, toggle_values, clickHandler);
    }
    else if(os == "linux"){
        rnd_button = new nasty :: LinuxRoundedButton(60, clickHandler);
        rect_button = new nasty :: LinuxRectangleButton(75, 75, clickHandler);
        tog_button = new nasty :: LinuxToggleButton(65, 65, toggle_values, clickHandler);
    }
    // whenever we add a new type, more cases must be handled here
    // propogation of changes

    mainUserInterface->addButton(rnd_button);
    mainUserInterface->addButton(rect_button);
    mainUserInterface->addButton(tog_button);
    mainUserInterface->renderElements();
    mainUserInterface->testClicks();
    mainUserInterface->testClicks();
    mainUserInterface->testClicks();
    
}

void refactoredCodeImpl(){
    refactored :: UserInterface *mainUserInterface = new refactored :: UserInterface(500, 500);
    string *toggle_values = new string[2];
    toggle_values[0] = "off";
    toggle_values[1] = "on";

    string os;
    cout << "Enter the operating system : ";
    cin >> os;

    // we have 3 button types 1.rectangle_button, 2.round_button, 3.toggle_button
    refactored :: ButtonFactory *btnFactory = new refactored :: ButtonFactory(os);
    refactored :: Button *rnd_button = btnFactory->createRoundedButton(60, clickHandler);
    refactored :: Button *rect_button = btnFactory->createRectangleButton(75, 75, clickHandler);
    refactored :: Button *tog_button = btnFactory->createToggleButton(65, 65, toggle_values, clickHandler);
    
    // whenever we add a new type the handling of cases will be done
    // by the object factory
    // No propogation of changes in this part of the code
    
    
    mainUserInterface->addButton(rnd_button);
    mainUserInterface->addButton(rect_button);
    mainUserInterface->addButton(tog_button);
    mainUserInterface->renderElements();
    mainUserInterface->testClicks();
    mainUserInterface->testClicks();
    mainUserInterface->testClicks();
}

int main()
{
    cout << "Nasty Code\n";
    nastyCodeImpl();
    cout << "\n\nrefactored code\n\n";
    refactoredCodeImpl();
    return 0;
}