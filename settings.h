#include<iostream>
#include<windows.h>
#include <cstdlib>  

using namespace std;

#ifndef settings_h
#define settings_h

struct settings
{

    float delay = (10);
    int keyToStart = VK_F6, keyToStop = VK_F7;               
    bool keyForClick = 0;     //0 = left mouse button         1 = right mouse button;
    void changesettings()
    {
        while(true)
        {
            cout << "Choose:\n" 
            << "1) Change clicks per second. (CURRENT: " << 1000/delay << ")\n" 
            << "2) Change button to click. (CURRENT :" << (keyForClick? "RMB" : "LBM") << ")\n"
            << "3) Close settings\n"
            << "4) Exit the program";
        
            int option = _getch(); 
            switch (option)
            {
                case 49:
                    changeDelay();
                    break;
                case 50:
                    keyForClick = !keyForClick;             //49 = 1     50 = 2 .........
                    break;            
                case 51:
                    system("cls");
                    return;
                case 52: 
                    exit(0);
                default:
                    cout << "Invalid option.\n";
            }
            system("Cls");
        }
    }
    
    void changeDelay()
    {
        cout << "Enter clicks per second rate (CURRENT: " << 1000/delay << "): ";
        delay = _getch();
        cout << "delay";
        delay = 1000/delay;
    } 

};

#endif