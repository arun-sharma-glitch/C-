#include <iostream>
#include <conio.h>
#include<string.h>
using namespace std;

int main()
{
    int spos, lpos, month, b = 1;
    char m[15];
    cout << "Enter month : ";
    cin >> month;

    switch (month)
    {
    case 1:
        spos = 2;
        lpos = 31;
        strcpy(m, "January");
        break;
    case 2:
        spos = 5;
        lpos = 29;
        strcpy(m, "Fbruary");
        break;
    case 3:
        spos = 6;
        lpos = 31;
        strcpy(m, "March");
        break;
    case 4:
        spos = 2;
        lpos = 30;
        strcpy(m, "April");
        break;
    case 5:
        spos = 4;
        lpos = 31;
        strcpy(m, "May");
        break;
    case 6:
        spos = 7;
        lpos = 31;
        strcpy(m, "June");
        break;
    case 7:
        spos = 2;
        lpos = 31;
        strcpy(m, "July");
        break;
    case 8:
        spos = 5;
        lpos = 31;
        strcpy(m, "August");
        break;
    case 9:
        spos = 1;
        lpos = 30;
        strcpy(m, "September");
        break;
    case 10:
        spos = 3;
        lpos = 31;
        strcpy(m, "October");
        break;
    case 11:
        spos = 6;
        lpos = 30;
        strcpy(m, "November");
        break;
    case 12:
        spos = 1;
        lpos = 31;
        strcpy(m, "December");
        break;

    default:
    cout<<"invalid input!";
        break;
    }

    cout << "\n\n\t\t"<<m<<"  " << month << " - 2024" << endl;
    cout << "\nSat\tSun\tMon\tTue\tWed\tThu\tFri" << endl
         << endl;

    

    for (int i = 1; i <= spos; i++)
    {
        cout << "\t";
        b++;
    }

    for (int i = 1; i <= lpos; i++)
    {

        if (b == 8)
        {
            cout << endl;
            b = 1;
        }
        cout << i << "\t";

        b++;
    }

    getch();
    return 0;
}