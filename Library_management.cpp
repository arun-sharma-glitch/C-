#include <iostream>
#include <fstream>
#include <iomanip>  // For setw()
using namespace std;

class temp {
    string id, name, author, search;
    int price, qty;
    fstream file, tempFile;

public:
    void show_All();
    void Add_books();
    void Extract();
} obj;

int main() {
    char choice;

    while (true) {
        cout << "--------------------------" << endl;
        cout << "    1. Show all books " << endl;
        cout << "    2. Add books " << endl;
        cout << "    3. Extract book " << endl;
        cout << "    4. Take exit " << endl;
        cout << "--------------------------";

        cout << endl << "Enter your choice : ";
        cin >> choice;

        switch (choice) {
        case '1':
            cin.ignore();
            obj.show_All();
            break;
        case '2':
            cin.ignore();
            obj.Add_books();
            break;
        case '3':
            cin.ignore();
            obj.Extract();
            break;
        case '4':
            exit(0);
        default:
            cout << "Invalid input!" << endl;
        }
    }
    return 0;
}

void temp::Add_books() {
    cout << "Enter book Id : ";
    getline(cin, id);
    cout << "Enter book Name : ";
    getline(cin, name);
    cout << "Enter Author's Name : ";
    getline(cin, author);
    cout << "Enter Quantity : ";
    cin >> qty;

    file.open("library.txt", ios::out | ios::app);
    file << id << "*" << name << "*" << author << "*" << qty << endl;
    file.close();
}

void temp::show_All() {
    file.open("library.txt", ios::in);

    // Set table headers with setw for consistent width
    cout << setw(10) << left << "BOOK ID" 
         << setw(25) << left << "BOOK NAME" 
         << setw(25) << left << "AUTHOR NAME" 
         << setw(10) << left << "QUANTITY" << endl;
    cout << string(70, '-') << endl; // Draw a separator line

    // Read and display data
    while (getline(file, id, '*')) {
        getline(file, name, '*');
        getline(file, author, '*');
        file >> qty;
        file.ignore(); // ignore the newline after qty

        cout << setw(10) << left << id
             << setw(25) << left << name
             << setw(25) << left << author
             << setw(10) << left << qty << endl;
    }

    file.close();
}

void temp::Extract() {
    bool found = false;
    cout << "Enter the Book ID to extract: ";
    getline(cin, search);

    file.open("library.txt", ios::in);
    tempFile.open("temp.txt", ios::out);

    while (getline(file, id, '*')) {
        getline(file, name, '*');
        getline(file, author, '*');
        file >> qty;
        file.ignore(); // ignore the newline after qty

        if (id == search) {
            found = true;
            cout << "\nBook found!" << endl;
            cout << "Book ID: " << id << "\nBook Name: " << name << "\nAuthor: " << author << "\nQuantity: " << qty << endl;

            if (qty > 0) {
                qty--; // reduce quantity by 1
                cout << "One copy of the book has been extracted. New Quantity: " << qty << endl;
            } else {
                cout << "This book is out of stock!" << endl;
            }
        }

        tempFile << id << "*" << name << "*" << author << "*" << qty << endl;
    }

    if (!found) {
        cout << "Book not found!" << endl;
    }

    file.close();
    tempFile.close();

    // Remove the old file and rename the temp file
    remove("library.txt");
    rename("temp.txt", "library.txt");
}
