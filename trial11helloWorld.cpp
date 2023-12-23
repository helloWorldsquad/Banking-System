#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;
class Bank
{
private:
    int acc;
    char name[50];
    int deposit;
    char type;

public:
    void create_account();
    void show_account() const;
    void modify();
    void dep(int);
    void drw(int);
    void report() const;
    int retacno() const;
    int retdepo() const;
    char retype() const;
};
void Bank::create_account()
{
    cout << "Enter the Account number : ";
    cin >> acc;
    cout << "\n\nEnter account holder name : ";
    cin.ignore();
    cin.getline(name, 50);
    cout << "\n Enter your account type(Saving-S/Current-C) : ";
    cin >> type;
    type = toupper(type);
    cout << "\n Enter the Initial Amount : ";
    cin >> deposit;
    cout << "Account is Successfully Registered : ";
}
void Bank::show_account() const
{
    cout << "\nAccont number  : " << acc;
    cout << "\nAccont Holder name  : " << name;
    cout << "\nAccont Type  : " << type;
    cout << "\nAccont BAlance  : " << deposit;
}
void Bank::modify()
{
    cout << "\nAccont number  : " << acc;
    cout << "\nModify Accont Holder Name : ";
    cin.ignore();
    cin.getline(name, 50);
    cout << "\nModify Accont Typer  : ";
    cin >> type;
    type = toupper(type);
    cout << "\nModify  Accont Money  : ";
    cin >> deposit;
}
void Bank::dep(int x)
{
    deposit += x;
}
void Bank::drw(int x)
{
    deposit -= x;
}
void Bank::report() const
{
    cout << "||"<<setw(15) << left << acc << setw(30) <<left<< name << setw(15) <<left << type << setw(15) <<left<< deposit<< "||" << endl;
    cout<<"||---------------------------------------------------------------------------||\n";
}
int Bank::retacno() const
{
    return acc;
}
int Bank::retdepo() const
{
    return deposit;
}
char Bank::retype() const
{
    return type;
}
void write_account();
void display_sp(int);
void modify_account(int);
void delete_account(int);
void display_all();
void deposit_withdraw(int, int);
void intro();
int main()
{
    char ch;
    int num;
    intro();
    do
    {
        
        cout << "-----------------------------------------" << endl;
        cout << "||\t\t"<< setw(23) << left <<"MAIN MENU"<<"||"<<endl;
        cout << "||-------------------------------------||" << endl;
        cout << "||\t" << setw(31) << left << "1. NEW ACCOUNT :"<<"||"<< endl;
        cout << "||\t" << setw(31) << left <<"2. DEPPOSITE AMOUNT :"<<"||"<< endl;
        cout << "||\t" << setw(31) << left <<"3. WITHDRAW AMOUNT :"<<"||"<< endl;
        cout << "||\t" << setw(31) << left <<"4. BALANCE INQUIRY :"<<"||"<< endl;
        cout << "||\t" << setw(31) << left <<"5. ALL ACCOUNT HOLDER LIST :"<<"||"<< endl;
        cout << "||\t" << setw(31) << left <<"6. CLOSE AN ACCOUNT :"<<"||"<< endl;
        cout << "||\t" << setw(31) << left <<"7. MODIFY ACCOUNT :"<<"||"<< endl;
        cout << "||\t" << setw(31) << left <<"8. EXIT :"<<"||"<< endl;
        cout << "||-------------------------------------||" << endl;
        cout <<"\t" << setw(31) << left <<"Select Your option (1-8)...: ";
        cin >> ch;
        system("cls");
        switch (ch)
        {
        case '1':
            write_account();
            break;
        case '2':
            cout << "\n\n\tEnter the account No. :";
            cin >> num;
            deposit_withdraw(num, 1);
            break;
        case '3':
            cout << "\n\n\tEnter the account No. :";
            cin >> num;
            deposit_withdraw(num, 2);
            break;
        case '4':
            cout << "\n\n\tEnter the account No. :";
            cin >> num;
            display_sp(num);
            break;
        case '5':
            display_all();
            break;
        case '6':
            cout << "\n\n\tEnter the account No. :";
            cin >> num;
            delete_account(num);
            break;
        case '7':
            cout << "\n\n\tEnter the account No. :";
            cin >> num;
            modify_account(num);
            break;
        case '8':
            cout << "\n\n\tThank for Using Our Bank System  : ";
            break;
        default:
            cout << "\a";
        }
        cin.ignore();
        cin.get();

    } while (ch != '8');
    return 0;
}
void write_account()
{
    Bank ac;
    ofstream outfile;
    outfile.open("Account2.dat", ios::binary | ios::app);
    ac.create_account();
    outfile.write(reinterpret_cast<char *>(&ac), sizeof(Bank));
    outfile.close();
}
void display_sp(int n)
{
    Bank ac;
    bool flag = false;
    ifstream infile;
    infile.open("Account2.dat", ios::binary);
    if (!infile)
    {
        cout << "File could not be open !! Press any key...";
        return;
    }
    cout << "\n BALANCE DETAILS : \n";
    while (infile.read(reinterpret_cast<char *>(&ac), sizeof(Bank)))
    {
        if (ac.retacno() == n)
        {
            ac.show_account();
            flag = true;
        }
    }
    infile.close();
    if (flag == false)
    {
        cout << "\n\nAccount number does not exist ..";
    }
}
void modify_account(int n)
{
    bool found = false;
    Bank ac;
    fstream file;
    file.open("Account2.dat", ios::binary | ios::in | ios::out);
    if (!file)
    {
        cout << "File could not be open !! Press any key...";
        return;
    }
    while (!file.eof() && found == false)
    {
        file.read(reinterpret_cast<char *>(&ac), sizeof(Bank));
        if (ac.retacno() == n)
        {
            ac.show_account();
            cout << "\n\n Enter the New details of Acount   ";
            ac.modify();
            int pos = (-1) * static_cast<int>(sizeof(Bank));
            file.seekp(pos, ios::cur);
            file.write(reinterpret_cast<char *>(&ac), sizeof(Bank));
            cout << "\n\n\t Record update...";

            found = true;
        }
    }
    file.close();
    if (found == false)
    {
        cout << "\n\n Record not Found :";
    }
}
void delete_account(int n)
{
    Bank ac;
    ifstream infile;
    ofstream outfile;
    infile.open("Account2.dat", ios::binary);
    if (!infile)
    {
        cout << "File can't be open";
        return;
    }
    outfile.open("Temp2.dat", ios::binary);
    infile.seekg(0, ios::beg);
    while (infile.read(reinterpret_cast<char *>(&ac), sizeof(Bank)))
    {
        if (ac.retacno() != n)
        {
            outfile.write(reinterpret_cast<char *>(&ac), sizeof(Bank));
        }
    }
    infile.close();
    outfile.close();
    remove("Account2.dat");
    rename("Temp2.dat", "Account2.dat");
    cout << "\n\n\t Record Deleted";
}
void display_all()
{
    Bank ac;
    ifstream infile;
    infile.open("Account2.dat", ios::binary);
    if (!infile)
    {
        cout << "File con't be open";
        return;
    }
    cout << "\n\n\t\t\t  Account Holder list \n\n";
    cout << "===============================================================================\n";
    cout << "||"<<setw(15) << left << "A/c no."<< setw(30) << left <<"Name"<<setw(15) << left <<"Type"<<setw(15) << left << "Balnce"<< "||"<<"\n";
    cout << "||===========================================================================||\n";
    while (infile.read(reinterpret_cast<char *>(&ac), sizeof(Bank)))
    {
        ac.report();
    }
    infile.close();
}
void deposit_withdraw(int n, int option)
{
    int amt;
    bool found = false;
    Bank ac;
    fstream file;
    file.open("Account2.dat", ios::binary | ios::in | ios::out);
    if (!file)
    {
        cout << "File could not be open !! Press any key...";
        return;
    }
    while (!file.eof() && found == false)
    {
        file.read(reinterpret_cast<char *>(&ac), sizeof(Bank));
        if (ac.retacno() == n)
        {
            ac.show_account();
            if (option == 1)
            {
                cout << "\n\n To Deposite Amount ";
                cout << "\n\n Enter the amount : ";
                cin >> amt;
                ac.dep(amt);
            }
            if (option == 2)
            {
                cout << "\n\nTo withdraw Amount ";
                cout << "\n\nEnter The Amount : ";
                cin >> amt;
                int bal = ac.retdepo() - amt;
                if (bal < 500 && ac.retype() == 'S' || bal < 1000 && ac.retype() == 'C')
                {
                    cout << "Insufficient Balance ";
                }
                else
                    ac.drw(amt);
            }
            int pos = (-1) * static_cast<int>(sizeof(Bank));
            file.seekp(pos, ios::cur);
            file.write(reinterpret_cast<char *>(&ac), sizeof(Bank));
            cout << "\n\n\t Record update...";
            found = true;
        }
    }
    file.close();
    if (found == false)
    {
        cout << "\n\n Record Not found ";
    }
}
void intro()
{
    cout << "\n\n\t BANK";
    cout << "\n\n\t MANAGEMENT";
    cout << "\n\n\t SYSTEM";
    cout << "\n\n\n|| MADE BY HelloWorld Team ||";
    cout << "\n\n Team Members: Vishwasjeet, Sunil, Vivek, Ram Vinay\n";
    
}