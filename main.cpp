#include<iostream>
#include<fstream>
#include<cstring>
#include<iomanip>
using namespace std;

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

class HOTEL {
private:
    int room_no;
    char name[30];
    char address[50];
    char phone[15];
    long days;
    long cost;
    char rtype[30];
    long pay;
    void breakfast(int);
    void lunch(int);
    void dinner(int);

public:
    void main_menu();
    void add();
    void display();
    void rooms();
    void edit();
    int check(int);
    void modify();
    void delete_rec();
    void restaurant();
    void modify_name(int);
    void modify_address(int);
    void modify_phone(int);
    void modify_days(int);
} h;

void HOTEL::main_menu() {
    int choice = 0;
    while (choice != 6) {
        system(CLEAR);
        cout << "\n\t\t\t\t *************";
        cout << "\n\t\t\t\t **THE HOTEL**";
        cout << "\n\t\t\t\t *************";
        cout << "\n\t\t\t\t * MAIN MENU *";
        cout << "\n\t\t\t\t *************";
        cout << "\n\n\t\t\t\t1. Book A Room";
        cout << "\n\t\t\t\t2. Customer Information";
        cout << "\n\t\t\t\t3. Rooms Allotted";
        cout << "\n\t\t\t\t4. Edit Customer Details";
        cout << "\n\t\t\t\t5. Order Food from Restaurant";
        cout << "\n\t\t\t\t6. Exit";
        cout << "\n\n\t\t\t\tEnter Your Choice: ";
        cin >> choice;
        switch (choice) {
            case 1: add(); break;
            case 2: display(); break;
            case 3: rooms(); break;
            case 4: edit(); break;
            case 5: restaurant(); break;
            case 6: return;
            default:
                cout << "\n\n\t\t\tWrong choice.";
                cout << "\n\t\t\tPress any key to continue.";
                cin.ignore();
                cin.get();
        }
    }
}

void HOTEL::add() {
    system(CLEAR);
    int r, flag;
    ofstream fout("Record.DAT", ios::app | ios::binary);
    cout << "\n\t\t\t +-----------------------+";
    cout << "\n\t\t\t | Rooms  |   Room Type  |";
    cout << "\n\t\t\t +-----------------------+";
    cout << "\n\t\t\t |   1-50 |    Deluxe    |";
    cout << "\n\t\t\t |  51-80 |   Executive  |";
    cout << "\n\t\t\t | 81-100 | Presidential |";
    cout << "\n\t\t\t +-----------------------+";
    cout << "\n\n ENTER CUSTOMER DETAILS";
    cout << "\n ----------------------";
    cout << "\n\n Room Number: ";
    cin >> r;
    flag = check(r);
    if (flag == 1)
        cout << "\n Sorry, Room is already booked.\n";
    else if (flag == 2)
        cout << "\n Sorry, Room does not exist.\n";
    else {
        room_no = r;
        cout << " Name: ";
        cin.ignore();
        cin.getline(name, 30);
        cout << " Address: ";
        cin.getline(address, 50);
        cout << " Phone Number: ";
        cin >> phone;
        cout << " Number of Days: ";
        cin >> days;

        if (room_no >= 1 && room_no <= 50) {
            strcpy(rtype, "Deluxe");
            cost = days * 10000;
        } else if (room_no >= 51 && room_no <= 80) {
            strcpy(rtype, "Executive");
            cost = days * 12500;
        } else if (room_no >= 81 && room_no <= 100) {
            strcpy(rtype, "Presidential");
            cost = days * 15000;
        }
        fout.write((char*)this, sizeof(HOTEL));
        cout << "\n Room has been booked.";
    }
    cout << "\n Press any key to continue.";
    cin.ignore();
    cin.get();
    fout.close();
}

void HOTEL::display() {
    system(CLEAR);
    ifstream fin("Record.DAT", ios::in | ios::binary);
    int r, flag = 0;
    cout << "\n Enter Room Number: ";
    cin >> r;
    while (fin.read((char*)this, sizeof(HOTEL))) {
        if (room_no == r) {
            system(CLEAR);
            cout << "\n Customer Details";
            cout << "\n ----------------";
            cout << "\n\n Room Number: " << room_no;
            cout << "\n Name: " << name;
            cout << "\n Address: " << address;
            cout << "\n Phone Number: " << phone;
            cout << "\n Staying for " << days << " days.";
            cout << "\n Room Type: " << rtype;
            cout << "\n Total cost of stay: " << cost;
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        cout << "\n Room is Vacant.";
    cout << "\n\n Press any key to continue.";
    cin.ignore();
    cin.get();
    fin.close();
}

void HOTEL::rooms() {
    system(CLEAR);
    ifstream fin("Record.DAT", ios::in | ios::binary);
    cout << "\n\t\t\t    LIST OF ROOMS ALLOTED";
    cout << "\n\t\t\t   -----------------------";
    cout << "\n\n +---------+------------------+-----------------+--------------+--------------+";
    cout << "\n | Room No.|    Guest Name    |      Address    |   Room Type  |  Contact No. |";
    cout << "\n +---------+------------------+-----------------+--------------+--------------+";
    while (fin.read((char*)this, sizeof(HOTEL))) {
        cout << "\n |" << setw(9) << room_no << " |";
        cout << setw(17) << name << " |";
        cout << setw(17) << address << " |";
        cout << setw(13) << rtype << " |";
        cout << setw(13) << phone << " |";
    }
    cout << "\n +---------+------------------+-----------------+--------------+--------------+";
    cout << "\n\n\n\t\t\tPress any key to continue.";
    cin.ignore();
    cin.get();
    fin.close();
}

int HOTEL::check(int r) {
    int flag = 0;
    ifstream fin("Record.DAT", ios::in | ios::binary);
    while (fin.read((char*)this, sizeof(HOTEL))) {
        if (room_no == r) {
            flag = 1;
            break;
        } else if (r > 100) {
            flag = 2;
            break;
        }
    }
    fin.close();
    return flag;
}

void HOTEL::edit() {
    system(CLEAR);
    int choice;
    cout << "\n EDIT MENU";
    cout << "\n ---------";
    cout << "\n\n 1. Modify Customer Information.";
    cout << "\n 2. Customer Check Out.";
    cout << "\n Enter your choice: ";
    cin >> choice;
    system(CLEAR);
    switch (choice) {
        case 1: modify(); break;
        case 2: delete_rec(); break;
        default: cout << "\n Wrong Choice."; break;
    }
    cout << "\n Press any key to continue.";
    cin.ignore();
    cin.get();
}

void HOTEL::restaurant() {
    system(CLEAR);
    int r, ch;
    cout << "\n RESTAURANT MENU:";
    cout << "\n --------------- ";
    cout << "\n\n 1. Order Breakfast\n 2. Order Lunch\n 3. Order Dinner";
    cout << "\n\n Enter your choice: ";
    cin >> ch;
    system(CLEAR);
    cout << " Enter Room Number: ";
    cin >> r;
    switch (ch) {
        case 1: breakfast(r); break;
        case 2: lunch(r); break;
        case 3: dinner(r); break;
        default: cout << "Invalid choice."; break;
    }
    cout << "\n\n Press any key to continue.";
    cin.ignore();
    cin.get();
}

void HOTEL::breakfast(int r) {
    int num, flag = 0;
    long pos;
    cout << " Enter number of people: ";
    cin >> num;
    fstream file("Record.DAT", ios::in | ios::out | ios::binary);
    while (!file.eof()) {
        pos = file.tellg();
        file.read((char*)this, sizeof(HOTEL));
        if (room_no == r) {
            pay = 500 * num;
            cost += pay;
            file.seekg(pos);
            file.write((char*)this, sizeof(HOTEL));
            cout << "\n Amount added to the bill: Rs. " << pay;
            flag = 1;
            break;
        }
    }
    if (!flag) cout << "\n Sorry, Room is vacant.";
    cin.ignore();
    cin.get();
    file.close();
}

void HOTEL::lunch(int r) {
    int num, flag = 0;
    long pos;
    cout << " Enter number of people: ";
    cin >> num;
    fstream file("Record.DAT", ios::in | ios::out | ios::binary);
    while (!file.eof()) {
        pos = file.tellg();
        file.read((char*)this, sizeof(HOTEL));
        if (room_no == r) {
            pay = 1000 * num;
            cost += pay;
            file.seekg(pos);
            file.write((char*)this, sizeof(HOTEL));
            cout << "\n Amount added to the bill: Rs. " << pay;
            flag = 1;
            break;
        }
    }
    if (!flag) cout << "\n Sorry, Room is vacant.";
    cin.ignore();
    cin.get();
    file.close();
}

void HOTEL::dinner(int r) {
    int num, flag = 0;
    long pos;
    cout << " Enter number of people: ";
    cin >> num;
    fstream file("Record.DAT", ios::in | ios::out | ios::binary);
    while (!file.eof()) {
        pos = file.tellg();
        file.read((char*)this, sizeof(HOTEL));
        if (room_no == r) {
            pay = 1200 * num;
            cost += pay;
            file.seekg(pos);
            file.write((char*)this, sizeof(HOTEL));
            cout << "\n Amount added to the bill: Rs. " << pay;
            flag = 1;
            break;
        }
    }
    if (!flag) cout << "\n Sorry, Room is vacant.";
    cin.ignore();
    cin.get();
    file.close();
}

void HOTEL::modify() {
    int ch, r;
    cout << "\n MODIFY MENU";
    cout << "\n -----------";
    cout << "\n\n 1. Modify Name";
    cout << "\n 2. Modify Address";
    cout << "\n 3. Modify Phone Number";
    cout << "\n 4. Modify Number of Days of Stay";
    cout << "\n Enter Your Choice: ";
    cin >> ch;
    cout << "\n Enter Room Number: ";
    cin >> r;
    switch (ch) {
        case 1: modify_name(r); break;
        case 2: modify_address(r); break;
        case 3: modify_phone(r); break;
        case 4: modify_days(r); break;
        default: cout << "\n Wrong Choice"; break;
    }
}

void HOTEL::modify_name(int r) {
    long pos;
    int flag = 0;
    fstream file("Record.DAT", ios::in | ios::out | ios::binary);
    while (!file.eof()) {
        pos = file.tellg();
        file.read((char*)this, sizeof(HOTEL));
        if (room_no == r) {
            cout << "\n Enter New Name: ";
            cin.ignore();
            cin.getline(name, 30);
            file.seekg(pos);
            file.write((char*)this, sizeof(HOTEL));
            cout << "\n Customer Name has been modified.";
            flag = 1;
            break;
        }
    }
    if (!flag) cout << "\n Sorry, Room is vacant.";
    cin.ignore();
    cin.get();
    file.close();
}

void HOTEL::modify_address(int r) {
    long pos;
    int flag = 0;
    fstream file("Record.DAT", ios::in | ios::out | ios::binary);
    while (!file.eof()) {
        pos = file.tellg();
        file.read((char*)this, sizeof(HOTEL));
        if (room_no == r) {
            cout << "\n Enter New Address: ";
            cin.ignore();
            cin.getline(address, 50);
            file.seekg(pos);
            file.write((char*)this, sizeof(HOTEL));
            cout << "\n Customer Address has been modified.";
            flag = 1;
            break;
        }
    }
    if (!flag) cout << "\n Sorry, Room is vacant.";
    cin.ignore();
    cin.get();
    file.close();
}

void HOTEL::modify_phone(int r) {
    long pos;
    int flag = 0;
    fstream file("Record.DAT", ios::in | ios::out | ios::binary);
    while (!file.eof()) {
        pos = file.tellg();
        file.read((char*)this, sizeof(HOTEL));
        if (room_no == r) {
            cout << "\n Enter New Phone Number: ";
            cin >> phone;
            file.seekg(pos);
            file.write((char*)this, sizeof(HOTEL));
            cout << "\n Customer Phone Number has been modified.";
            flag = 1;
            break;
        }
    }
    if (!flag) cout << "\n Sorry, Room is vacant.";
    cin.ignore();
    cin.get();
    file.close();
}

void HOTEL::modify_days(int r) {
    long pos;
    int flag = 0;
    fstream file("Record.DAT", ios::in | ios::out | ios::binary);
    while (!file.eof()) {
        pos = file.tellg();
        file.read((char*)this, sizeof(HOTEL));
        if (room_no == r) {
            cout << " Enter New Number of Days of Stay: ";
            cin >> days;
            if (room_no >= 1 && room_no <= 50)
                cost = days * 10000;
            else if (room_no >= 51 && room_no <= 80)
                cost = days * 12500;
            else if (room_no >= 81 && room_no <= 100)
                cost = days * 15000;
            file.seekg(pos);
            file.write((char*)this, sizeof(HOTEL));
            cout << "\n Customer information is modified.";
            flag = 1;
            break;
        }
    }
    if (!flag) cout << "\n Sorry, Room is vacant.";
    cin.ignore();
    cin.get();
    file.close();
}

void HOTEL::delete_rec() {
    int r, flag = 0;
    char ch;
    cout << "\n Enter Room Number: ";
    cin >> r;
    ifstream fin("Record.DAT", ios::in | ios::binary);
    ofstream fout("temp.DAT", ios::out | ios::binary);
    while (fin.read((char*)this, sizeof(HOTEL))) {
        if (room_no == r) {
            cout << "\n Name: " << name;
            cout << "\n Address: " << address;
            cout << "\n Phone Number: " << phone;
            cout << "\n Room Type: " << rtype;
            cout << "\n Your total bill is: Rs. " << cost;
            cout << "\n\n Do you want to check out this customer(y/n): ";
            cin >> ch;
            if (ch == 'n' || ch == 'N')
                fout.write((char*)this, sizeof(HOTEL));
            else
                cout << "\n Customer Checked Out.";
            flag = 1;
        } else {
            fout.write((char*)this, sizeof(HOTEL));
        }
    }
    fin.close();
    fout.close();
    if (!flag) cout << "\n Sorry, Room is vacant.";
    else {
        remove("Record.DAT");
        rename("temp.DAT", "Record.DAT");
    }
    cin.ignore();
    cin.get();
}

int main() {
    system(CLEAR);
    h.main_menu();
    return 0;
}
