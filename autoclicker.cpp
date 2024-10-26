#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>  
#include "settings.h"

using namespace std;

void startautoclicker(settings autoclickerSettings) 
{
    LARGE_INTEGER frequency, start, end;
    QueryPerformanceFrequency(&frequency);        //delay configuration          

    while (true)
    {
        QueryPerformanceCounter(&start); //delay start

        POINT position;
        GetCursorPos(&position);        //get current cursor coordinates (x, y)
    
        mouse_event( (autoclickerSettings.keyForClick? MOUSEEVENTF_RIGHTDOWN: MOUSEEVENTF_LEFTDOWN) , position.x, position.y, 0, 0);           
        mouse_event( (autoclickerSettings.keyForClick? MOUSEEVENTF_RIGHTUP: MOUSEEVENTF_LEFTUP) , position.x, position.y, 0, 0);            //click simulation  

        if (GetAsyncKeyState(VK_F7) & 0x8000)       //F7 to stop
        {
            return;
        }

        do {
            QueryPerformanceCounter(&end);  //record current delay time                                                          
        } while ((end.QuadPart - start.QuadPart) * 1000.0 / frequency.QuadPart < autoclickerSettings.delay);    //perform until the delay is less than autoclickerSettings.delay
    }
}


int main() {  

    settings autoclickerSettings;

    while (true)
    {    
        cout << "Press F6 to start the autoclicker.\n" 
        << "Press F7 to stop the autoclicker.\n" 
        << "Press F8 to change settings.\n";

    while (true) 
    {
        if (GetAsyncKeyState(VK_F6) & 0x8000)           // F6 to start 
        {
            cout << "Autoclicker is running\n";               
            startautoclicker(autoclickerSettings);
            system("cls");
            cout << "Autoclicker is stopped\n\n"; 
            break;;
        }
        if (GetAsyncKeyState(VK_F8) & 0x8000)           // F8 to show and change the settings 
        {
            autoclickerSettings.changesettings(); 
            break;
        }
    }
    }
    return 0;
}
