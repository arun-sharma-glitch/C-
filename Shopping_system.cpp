#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

class temp
{
    fstream file, file1;
    int price, qty, buy_qty;
    long amount = 0;
    string id, buy_id, name;

public:
    void addProduct();
    void showProduct();
    void shoping();
} obj;

int main()
{
    char choice;
    cout << "-------------By Arum-------------" << endl;
    cout << "Press 1. to Shopping " << endl;
    cout << "Press 2. to Exit " << endl;
    cout << "---------------------------------" << endl;

    cout << "Enter here :: ";
    cin >> choice;

    switch (choice)
    {
    case 'A':
        char admin_choice;
        cout << "1. to see Product " << endl;
        cout << "2. to add a new Product " << endl;
        cout << "Enter :: ";
        cin >> admin_choice;

        switch (admin_choice)
        {
        case '1':
            obj.showProduct();
            break;

        case '2':
            obj.showProduct();
            obj.addProduct();
            break;

        default:
            cout << "Invalid Input!";
            break;
        }
        break;

    case '1':
        obj.showProduct();
        obj.shoping();
        break;
    case '2':
        exit(0);
        break;
    default:
        cout << "Invalid Input!" << endl;
    }

    return 0;
}

void temp ::addProduct()
{
    cout << "Enter Product id : ";
    cin >> id;
    cout << "Enter Product Name : ";
    cin >> name;
    cout << "Enter Product Price : ";
    cin >> price;
    cout << "Enter Quantity : ";
    cin >> qty;

    file.open("shop.txt", ios::out | ios::app);

    file << id << '\t' << name << '\t' << price << '\t' << qty << endl;
    file.close();
}

void temp::showProduct()
{
    cout << '\t' << "PRODUCT ID" << '\t' << "PRODUCT NAME" << '\t' << "PRODUCT PRICE" << '\t' << "PRODUCT QTY" << endl
         << endl;
    file.open("shop.txt", ios::in);
    file >> id >> name >> price >> qty;
    while (!file.eof())
    {
        cout << '\t' << setw(8) << id << '\t' << setw(10) << name << '\t' << setw(10) << price << '\t' << setw(10) << qty << endl;
        file >> id >> name >> price >> qty;
    }
    file.close();
}

void temp::shoping()
{
    cout << "Enter id which you want to buy : ";
    cin >> buy_id;
    cout << "Enter Quantity of Purchase : ";
    cin >> buy_qty;

    file.open("shop.txt", ios::in);
    file1.open("temp_file.txt", ios::out | ios::app);
    file >> id >> name >> price >> qty;

    char ans;

    while (!file.eof())
    {
        if (id == buy_id)
        {
            if (qty < buy_qty)
            {
                cout << endl
                     << "Not Available !" << endl;
                cout << endl
                     << endl
                     << "Do You want to continue Shopping (Y/N):: ";
                cin >> ans;
                if (ans == 'Y' || ans == 'y')
                    obj.shoping();
                else
                    cout << endl
                         << "Thank You for Visiting " << (char)(1);
                        
                return ;
            }
            qty -= buy_qty;

            amount += buy_qty * price;
            cout << endl
                 << endl
                 << "TOTAL BILL :: " << amount;
            cout << endl
                 << endl
                 << "Do You want to continue Shopping (Y/N):: ";
            cin >> ans;
            if (ans == 'Y' || ans == 'y')
                obj.shoping();
            else
                cout << endl
                     << "Thank You for Visiting " << (char)(1);
            file1 << id << '\t' << name << '\t' << price << '\t' << qty << endl;
        }
        else
        {
            file1 << id << '\t' << name << '\t' << price << '\t' << qty << endl;
        }

        file >> id >> name >> price >> qty;
    }
    file.close();
    file1.close();

    remove("shop.txt");
    rename("temp_file.txt", "shop.txt");
}