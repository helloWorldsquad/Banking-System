#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
class Bank
{
    string bank_name = "India Bank Limited";
    string bank_IFSC = "IBL005710";
    string bank_address = "Board Office, MP Nagar, Bhopal-462011";

public:
    void welcomeMessage();
    string getbname();
    string getaddress();
    string getIFSc();
};
void Bank::welcomeMessage()
{

    cout << "\nWelcome to " << bank_name << endl;
    cout << "Address: " << bank_address << endl;
    cout << "IFSC:" << bank_IFSC << endl;
    cout << "\nHello Sir/Madam... \n\n Please select the option from the following menu to proceed: " << endl;
}
string Bank::getaddress()
{
    return bank_address;
}
string Bank::getbname()
{
    return bank_name;
}
string Bank::getIFSc()
{
    return bank_IFSC;
}
class NewUser : public Bank
{
private:
    string cname;
    string cage;
    string cmob;
    string cdob;
    string cpinCode = "";
    string caddress;
    string cID;
    static string accNum;
    string userId;
  int loginPassword;
    string transactionPIN;
    string acc;

public:
    void getPersonalDetails();
    string getcname();
    void modifycname(string);
    string getcage();
    void modifycage(string);
    string getcDob();
    void modifycDob(string);
    string getcpincode();
    void modifycpinCode(string);
    string getcmob();
    void modifycmob(string);
    string getcaddress();
    void modifycaddress(string);
    string getUserId();
    int getloginPassword();
    string putdata();
    void createTransactionPin();
    string getTransactionPin();
    string getacc();
    void generateAccountNum(const string &dob, const string &mobile, const string &age, const string &pinCode);
    void getLogindetail();

private:
    static string getDobPart(const string &cdob)
    {
        string dobPart;

        for (char ch : cdob)
        {
            if (ch != '-' && ch != '/')
            {
                dobPart += ch;
            }
            dobPart = dobPart.substr(0, 4);
        }
        return dobPart;
    }
    static string getMobilePart(const string &cmob)
    {
        string mobilePart = cmob.substr(10 - 3);
        return mobilePart;
    }
    static string getAgePart(const string &cage)
    {
        string agePart = cage.substr(cage.length() - 2);
        return agePart;
    }
    static string getPinCodePart(const string &cpinCode)
    {
        string pinCodePart = cpinCode.substr(cpinCode.length() - 3);
        return pinCodePart;
    }
};
void NewUser::getLogindetail()
{
    cout << "Enter Your User Name: \n";
    cin >> userId;
    cout << "Enter Your Login Password: \n";
    cin >> loginPassword;
}
void NewUser::createTransactionPin()
{
    cout << "Create Your 6-digit Transaction PIN: \n";
    cin >> transactionPIN;
}

string NewUser::putdata()
{
    cout << cname << "\n Age : " << cage << "\n Your Mobile number : " << cmob;
}
string NewUser::getcage()
{
    return cage;
}
string NewUser::getcDob()
{
    return cdob;
}
string NewUser::getcmob()
{
    return cmob;
}
string NewUser::getcname()
{
    return cname;
}
string NewUser::getcpincode()
{
    return cpinCode;
}
string NewUser::getcaddress()
{
    return caddress;
}
string NewUser::getUserId()
{
    return userId;
}
int NewUser::getloginPassword()
{
    return loginPassword;
}
string NewUser::getTransactionPin()
{
    return transactionPIN;
}
string NewUser::getacc()
{
    return acc;
}
void NewUser::modifycname(string cname2)
{
    cname = cname2;
}
void NewUser::modifycage(string cage2)
{
    cage = cage2;
}
void NewUser::modifycDob(string cDob2)
{
    cdob = cDob2;
}
void NewUser::modifycmob(string cmob2)
{
    cmob = cmob2;
}
void NewUser::modifycpinCode(string cpinCode2)
{
    cpinCode = cpinCode2;
}
void NewUser::modifycaddress(string caddress2)
{
    caddress = caddress2;
}

void NewUser ::getPersonalDetails()
{

    cout << "\nYour good name: ";
    cin.ignore();
    getline(cin, cname);
    cout << "Enter your age: ";
    cin >> cage;
    cout << "Your date of birth in the formate DD-MM-YYYY: ";
    cin >> cdob;
    cout << "Enter your 10 digit mobile number: ";
    cin >> cmob;
    cout << "Enter your Address : ";
    cin.ignore();
    getline(cin, caddress);
    cout << "Enter your 6 digit PIN code(Postal): ";
    cin >> cpinCode;
    cout << "------------------------------" << endl;
    cout << "Your account is successfully created please create your user id and login password to complete the account generation process" << endl;
    generateAccountNum(cage, cdob, cmob, cpinCode);
    getLogindetail();
    cout << "Thank you for regestering, here is your regestered details: " << endl;
    cout << "Name: " << cname << endl;
    cout << "Age: " << cage << endl;
    cout << "Date of Birth: " << cdob << endl;
    cout << "Mobile No.: " << cmob << endl;
    cout << "PIN Code: " << cpinCode << endl;
    cout << "Your Account Number is: " << acc << endl;
    cout << "Create a transaction PIN for transactions" << endl;
    createTransactionPin();
    cout << "Deposit a minimum amount of Rs 1000 at the cash counter to initiate the transactions in your account\n Press Enter to continue: ";
    return;
}
void NewUser::generateAccountNum(const string &dob, const string &mobile, const string &age, const string &pinCode)
{
    string accNum = "57";
    accNum += getDobPart(dob);
    accNum += getMobilePart(mobile);
    accNum += getAgePart(age);
    accNum += getPinCodePart(pinCode);
    acc = accNum;
}
class ExistingUser : public Bank
{
    string regdUserName;
    string regdPswd;

public:
    void getRegdAccDetails();
    string getRegdUserName();
    string getRegdPswd();
};
void ExistingUser ::getRegdAccDetails()
{
    cout << "Enter your UserName : ";
    cin >> regdUserName;
    cin.ignore();
    cout << "Enter your Login Passsword : ";
    cin >> regdPswd;
    cin.ignore();
}
string ExistingUser::getRegdUserName()
{
    return regdUserName;
}
string ExistingUser::getRegdPswd()
{
    return regdPswd;
}
class Employe : public NewUser, public ExistingUser
{
private:
    string AllempId[4] = {"vishwas7782", "sunil9131", "vivek8871", "vinay7903"};
    string AllempPswd[4] = {"843125", "465687", "464693", "843333"};
    string empId;
    string empPswd;

public:
    bool validId = false;
    bool validPswd = false;
    void getEmpDetail();
    void EmpCheck();
    void modifyname();
    void modifyage();
    void modifyDob();
    void modifymob();
    void modifypinCode();
    void modifyaddress();
    void modifyAccountMenu();
};

void Employe::getEmpDetail()
{
    cout << "Enter Your Employe ID :\n";
    cin >> empId;
    cin.ignore();
    cout << "Enter Your Login Password :\n";

    cin >> empPswd;
    cin.ignore();
}
void Employe::EmpCheck()
{

    do
    {

        cout << "Enter Your Employee ID:\n";
        cin >> empId;
        cin.ignore();
        for (int i = 0; i < 4; i++)
        {
            if (empId == AllempId[i])
            {
                validId = true;
                cout << "Enter Your Login Password:\n";
                cin >> empPswd;
                cin.ignore();

                if (empPswd == AllempPswd[i])
                {
                    validPswd = true;
                    cout << "Login Successful!\n";
                }
                else
                {
                    cout << "Incorrect Password!\n";
                    break;
                }
            }
        }

        if (!validId)
        {
            cout << "Invalid Employee ID!\n";
        }
    } while (!validId || !validPswd);
}
void Employe::modifyname()
{
    string namecheck;
    string cname2;
    do
    {

        cout << "Enter the old name to verify: ";
        cin.ignore();
        getline(cin, namecheck);
        if (getcname() == namecheck)
        {
            cout << "Enter Modified Name: ";
            cin >> cname2;
            modifycname(cname2);
            break;
        }
        else
        {
            cout << "Customer name not found, please try again with correct detail\n";
        }
    } while (namecheck != getcname());
}
void Employe::modifyage()
{
    string agecheck;
    string cage2;
    do
    {

        cout << "Enter the old age to verify: ";
        cin.ignore();
        getline(cin, agecheck);
        if (getcage() == agecheck)
        {
            cout << "Enter Modified Age: ";
            cin >> cage2;
            modifycage(cage2);
            break;
        }
        else
        {
            cout << "Wrong age entered, please try again with correct detail\n";
        }
    } while (agecheck != getcage());
}

void Employe::modifyDob()
{
    string dobcheck;
    string cDob2;
    do
    {

        cout << "Enter the old Dob to verify: ";
        cin.ignore();
        getline(cin, dobcheck);
        if (getcDob() == dobcheck)
        {
            cout << "Enter Modified Dob: ";
            cin >> cDob2;
            modifycDob(cDob2);
            break;
        }
        else
        {
            cout << "Wrong Dob entered, please try again with correct detail\n";
        }
    } while (dobcheck != getcDob());
}
void Employe::modifymob()
{
    string mobcheck;
    string cmob2;
    do
    {

        cout << "Enter the old mobile number to verify: ";
        cin.ignore();
        getline(cin, mobcheck);
        if (getcmob() == mobcheck)
        {
            cout << "Enter Modified Mobile no: ";
            cin >> cmob2;
            modifycmob(cmob2);
            break;
        }
        else
        {
            cout << "Wrong mobile no entered, please try again with correct detail\n";
        }
    } while (mobcheck != getcmob());
}
void Employe::modifypinCode()
{
    string pinCodecheck;
    string cpinCode2;
    do
    {

        cout << "Enter the old PIN Code to verify: ";
        cin.ignore();
        getline(cin, pinCodecheck);
        if (getcpincode() == pinCodecheck)
        {
            cout << "Enter Modified Pin Code: ";
            cin >> cpinCode2;
            modifycpinCode(cpinCode2);
            break;
        }
        else
        {
            cout << "Wrong Pin Code entered, please try again with correct detail\n";
        }
    } while (pinCodecheck != getcpincode());
}
void Employe::modifyaddress()
{
    string addresscheck;
    string caddress2;
    do
    {

        cout << "Enter the old address to verify: ";
        cin.ignore();
        getline(cin, addresscheck);
        if (getcaddress() == addresscheck)
        {
            cout << "Enter Modified Address: ";
            cin >> caddress2;
            modifycaddress(caddress2);
            break;
        }
        else
        {
            cout << "Wrong address entered, please try again with correct detail\n";
        }
    } while (addresscheck != getcaddress());
}
void Employe::modifyAccountMenu()
{
    char ch2;
    do
    {
        // system("cls");
        cout << "-----------------------------------------" << endl;
        cout << "||\t\t" << setw(15) << left << "Modify Account MENU"
             << "||" << endl;
        cout << "||-------------------------------------||" << endl;
        cout << "||\t" << setw(31) << left << "1. Modify Name :"
             << "||" << endl;
        cout << "||\t" << setw(31) << left << "2. Modify Age :"
             << "||" << endl;
        cout << "||\t" << setw(31) << left << "3. Modify DOB :"
             << "||" << endl;
        cout << "||\t" << setw(31) << left << "4. Modify Mob No. :"
             << "||" << endl;
        cout << "||\t" << setw(31) << left << "5. Modify Pin Code :"
             << "||" << endl;
        cout << "||\t" << setw(31) << left << "6. Modify Address :"
             << "||" << endl;
        cout << "||\t" << setw(31) << left << "7. EXIT :"
             << "||" << endl;
        cout << "||-------------------------------------||" << endl;
        cout << "\t" << setw(31) << left << "Select option from the given menu ...: ";
        cin >> ch2;
        // system("cls");
        switch (ch2)
        {
        case '1':
            modifyname();
            break;
        case '2':
            modifyage();
            break;
        case '3':
            modifyDob();
            break;
        case '4':
            modifymob();
            break;
        case '5':
            modifypinCode();
            break;
        case '6':
            modifyaddress();
            break;
        case '7':
            cout << "Press enter to go back";
            break;
        default:
            cout << "\a Wrong Choice...Try Again...\n";
            break;
        }
        cin.ignore();
        cin.get();

    } while (ch2 != '7');
}

class Authentication : public Employe
{
private:
    string check_usrname;
    string regdPINCheck;
   int check_loginPass;
    // int transferAccountCheck[20];

public:
    void getAuthenticationDetails();
    // void getTransferAccDetails();
    void doAuthentication();
    void getPINAuthenticationDetails();
    void doPINAuthentication();
    string num;
    bool logincheck = false;
    bool PINcheck = false;

    // void write_account()
    // {
    //     ofstream outfile;
    //     outfile.open("Account3.dat", ios::binary | ios::app);
    //     outfile.write(reinterpret_cast<char *>(&ac), sizeof(Bank));
    //     outfile.close();

    //     std::ofstream outFile("function_data.dat", std::ios::binary); // Open file in binary mode
    //     if (outFile.is_open())
    //     {
    //         outFile.write(data.c_str(), data.size()); // Writing data to the file in binary mode
    //         outFile.close();                          // Closing the file
    //         std::cout << "Data written to .dat file successfully." << std::endl;
    //     }
    //     else
    //     {
    //         std::cout << "Unable to open .dat file." << std::endl;
    //     }
    // }
};

void Authentication::getAuthenticationDetails()
{

    cout << "Welcome Back...\n Login to proceede : " << endl;
    cout << "Enter your Username : ";
    cin >> check_usrname;
    cin.ignore();
    cout << "Enter your Login Password : ";
    cin >> check_loginPass;
    cin.ignore();
}
void Authentication::doAuthentication()
{ // getRegdUserName()=check_usrname;
  // getRegdPswd()=check_loginPass;

    do
    {
        getAuthenticationDetails();
        if (getUserId() == check_usrname && getloginPassword() == check_loginPass)
        {
            logincheck = true;
            cout << "Log in successfull " << endl;
            cout << "Your can access all Bank Services :  " << endl;
            // bankingMenu();
        }
        else
        {

            cout << "Sorry.... Bad credentials, please try again..." << endl;
        }
    } while (!logincheck);
}
void Authentication::getPINAuthenticationDetails()
{
    cout << "Enter your Transaction PIN to procede:";

    cin >> regdPINCheck;
    cin.ignore();
}
void Authentication::doPINAuthentication()
{

    do
    {
        getPINAuthenticationDetails();
        if (getTransactionPin() == regdPINCheck)
        {
            PINcheck = true;
            cout << "Verification Successfull successfull " << endl;
            cout << "Your can procede with your transacction:  " << endl;
            // bankingMenu();
        }
        else
        {

            cout << "Sorry.... Bad credentials, please try again..." << endl;
        }
    } while (!PINcheck);
}
static int transactionCount = 0;
class Transactions : public Authentication
{
private:
    float bal = 1000;

    // float amount, calCharge;
public:
    // int choice;
    string pass = getRegdPswd();

    void cashdeposit(int amt);
    void cashwithdraw(int amt);
    int calcharge(int amt);
    void CheckBalance();
    void trans(int amt);
    void trans(int amt, int charge);
    void showUserData();
    float getbal();
    void showAllUserData();
};
void Transactions::showUserData()
{
    cout << "Name: " << getcname() << endl;
    cout << "Age: " << getcage() << endl;
    cout << "Date of Birth: " << getcDob() << endl;
    cout << "Mobile No.: " << getcmob() << endl;
    cout << "PIN Code: " << getcpincode() << endl;
    cout << "Your Account Number is: " << getacc() << endl;
}
void Transactions ::cashdeposit(int amt)
{
    cout << "Enter Amount to Deposit: ";
    cin >> amt;
    bal += amt;
    cout << "Amount Deposited succesfully." << endl;
    cout << "New Balance : " << bal << endl;
}
void Transactions ::cashwithdraw(int amt)
{
    cout << "Enter Amount to Withdraw: ";
    cin >> amt;
    if (bal > amt && (bal - amt) >= 1000)
    {
        bal -= amt;
        cout << "Amount Withdrawl succesfully." << endl;
        cout << "New Balance : " << bal << endl;
    }
    else
    {
        cout << "Insufficient Balance" << endl;
    }
}
int Transactions::calcharge(int amt)
{

    if (amt <= 10000)
    {
        return 5;
    }
    else if (amt > 10000 && amt <= 100000)
    {
        return 10;
    }
    else if (amt > 100000 && amt <= 200000)
    {
        return 15;
    }
    else
    {
        return 25;
    }
}
void Transactions ::CheckBalance()
{
    cout << "Your Account Balance : " << bal << endl;
}
void Transactions ::trans(int amt)
{
    cout << "Enter Transfer amount: ";
    cin >> amt;
    if (bal > amt && (bal - amt) >= 1000)
    {
        bal -= amt;
        cout << "Balance after transaction : " << bal << endl;
    }
    else
    {
        cout << "Insufficient Balance, minimum balance of 1000 sould be maintained" << endl;
    }
}
void Transactions ::trans(int amt, int charge)
{
    cout << "Additional Charges apply" << endl;
    cout << "Enter transaction amount: ";
    cin >> amt;
    if (bal > amt && (bal - amt - charge) >= 1000)
    {
        bal = bal - amt - charge;
        cout << "Your transaction charge : " << charge << endl;
        cout << "Balance after transaction : " << bal << endl;
    }
    else
    {
        cout << "Insufficient Balance, minimum balance of 1000 sould be maintained" << endl;
    }
}
float Transactions::getbal()
{
    return bal;
}
void Transactions::showAllUserData()
{
    cout << "\tUser\t" << setw(30) << left << "Name" << setw(15) << "A/c No" << setw(15) << "A/c Type" << setw(15) << "Balance" << endl;
    cout << "-------------------------------------------------------------------------------------------------" << endl;
    cout << "|\t"
         << "1"
         << "\t" << setw(30) << left << getcname() << setw(15) << getacc() << setw(15) << getUserId() << setw(15) << getbal() << "\t|" << endl;
    cout << "-------------------------------------------------------------------------------------------------" << endl;
}

class BankDatabase : public Transactions
{
public:
    void BankMenu();
    void empMenu();
    void mainMenu();
}stud1;
void BankDatabase::BankMenu()
{
    char c;
    double amt, charge = calcharge(amt);
    do
    {
        cout << "------------------------------\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Transfer to same Bank\n";
        cout << "5. Transfer to other Bank\n";
        cout << "6. Show Your Acc Details \n";
        cout << "7. Exit\n";
        cout << "------------------------------\n";
        cout << "Enter your choice: ";
        cin >> c;
        cout << "------------------------------\n";

    if(c=='1')
       
         {   doPINAuthentication();
            if (PINcheck)
            
                CheckBalance();
                transactionCount;
                PINcheck = false;
            
            break;}
        else if(c=='2'){
            doPINAuthentication();
            if (PINcheck)
            {
                cashdeposit(amt);
                transactionCount;
                PINcheck = false;
            }
            break;
        }
        else if(c=='3'){
            doPINAuthentication();
            if (PINcheck)
            {
                cashwithdraw(amt);
                transactionCount;
                PINcheck = false;
            }
            break;
        }
        else if(c== '4'){
            doPINAuthentication();
            if (PINcheck)
            {
                trans(amt);
                transactionCount;
                PINcheck = false;
            }
            break;
        }
        else if(c=='5'){
            doPINAuthentication();
            if (PINcheck)
            {
                trans(amt, charge);
                transactionCount;
                PINcheck = false;
            }
            break;
        }
       else if(c== '6'){
            doPINAuthentication();
            if (PINcheck)
            {
                showUserData();
                PINcheck = false;
            }
            break;
       }
        else if(c== '7')
            break;
        
        
        
    } while (c != 7);
}

void BankDatabase::empMenu()
{
    char ch1;
    do
    {
        // system("cls");
        cout << "-----------------------------------------" << endl;
        cout << "||\t\t" << setw(23) << left << "Employe MENU"
             << "||" << endl;
        cout << "||-------------------------------------||" << endl;
        cout << "||\t" << setw(31) << left << "1. Modify Account :"
             << "||" << endl;
        cout << "||\t" << setw(31) << left << "2. Show Total Balance of Bank:"
             << "||" << endl;
        cout << "||\t" << setw(31) << left << "3. Show All Accounts :"
             << "||" << endl;
        cout << "||\t" << setw(31) << left << "4. EXIT :"
             << "||" << endl;
        cout << "||-------------------------------------||" << endl;
        cout << "\t" << setw(31) << left << "Select option from the given menu ...: ";
        cin >> ch1;
        // system("cls");
        switch (ch1)
        {
        case '1':
            modifyAccountMenu();
            break;
        case '2':
            cout << "Under Maintenance...Sorry..." << endl;
            break;
        case '3':
            showAllUserData();
            cout << "\nUnder Maintenance...Sorry..." << endl;
            break;
        case '4':
            mainMenu();
            break;
        default:
            cout << "\a Wrong Choice...Try Again...\n";
            break;
        }
        cin.ignore();
        cin.get();

    } while (ch1 != '4');
}
void BankDatabase::mainMenu()
{
    char ch;
    do
    {
        // system("cls");
        cout << "-----------------------------------------" << endl;
        cout << "||\t\t" << setw(23) << left << "MAIN MENU"
             << "||" << endl;
        cout << "||-------------------------------------||" << endl;
        cout << "||\t" << setw(31) << left << "1. NEW USER :"
             << "||" << endl;
        cout << "||\t" << setw(31) << left << "2. EXISTING USER :"
             << "||" << endl;
        cout << "||\t" << setw(31) << left << "3. EMPLOYE :"
             << "||" << endl;
        cout << "||\t" << setw(31) << left << "4. EXIT :"
             << "||" << endl;
        cout << "||-------------------------------------||" << endl;
        cout << "\t" << setw(31) << left << "Select User Type from the given menu ...: ";
        cin >> ch;
        // system("cls");
        switch (ch)
        {
        case '1':
            getPersonalDetails();
            break;
        case '2':
            doAuthentication();
            if (logincheck)
            {
                BankMenu();
            }
            break;
        case '3':
            EmpCheck();
            if (validId && validPswd)
            {
                empMenu();
            }
            break;
        case '4':
            cout << "\n\n\tThankyou for Visiting India Bank Limited\nClosing System...";
            exit(0);
            break;

        default:
            cout << "\a Wrong Choice...Try Again...\nPress Enter to ";
        }
        cin.ignore();
        cin.get();

    } while (ch != '4');
}
void intro();
void introto();

int main()
{  int Loginpin;
    char found='f';
    char cr;
    intro();
    do{
         cout << "||-------------------------------------||" << endl;
        cout << "||\t" << setw(31) << left << "1. NEW USER :"
             << "||" << endl;
        cout << "||\t" << setw(31) << left << "2. EXISTING USER :"
             << "||" << endl;
              cout << "||\t" << setw(31) << left << "3. EMPLOYE :"
             << "||" << endl;
             cout << "||\t" << setw(31) << left << "4. EXIT : "
             << "||" << endl;
        cout << "||-------------------------------------||" << endl;
        cout << "\t" << setw(31) << left << "Select option from the given menu ...: ";
        cin >> cr;
    system("cls");
    switch(cr){
        
        case '1':{
             ofstream fout("Acc1234.dat",ios::out|ios::app);
   
        stud1.getPersonalDetails();
        fout.write((char*)&stud1,sizeof(stud1));
      break;
    fout.close();
        }
        case '2':{
            ifstream fin("Acc1234.dat",ios::in|ios::app);
    cout<<"Enter the login Password : " ;
    cin>>Loginpin;
    while(!fin.eof()){
fin.read((char *)&stud1,sizeof(stud1));
if(stud1.getloginPassword() ==Loginpin){
    stud1.BankMenu();
    found='n';
    break;

    } 

}
if(found=='f'){
    cout<<"Sorry Invalid  Password... \n Please try Again... "<<endl;

        
    }
    fin.close();
    break;
    }
     case '3':
           stud1.EmpCheck();
          
            
                stud1.empMenu();
            
case '4':
            break;
    }
   
    }while(cr!='4');
 introto();
return 0;
}
void intro(){
 stud1.ExistingUser::welcomeMessage();
}
void introto(){
    cout<<"THANK YOU FOR USING OUR BANKING SERVICES !..........\n.....VISIT AGAIN.....!!!!!!!  ";
}
