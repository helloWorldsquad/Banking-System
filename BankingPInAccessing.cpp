#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;
class Bank{
    private:
    int acc,pin;
    char name[50],user[20];
    int deposit;
   char type;
    public:
    void create_account();
    void show_account()const;
    void modify();
    void dep(int);
    void drw(int);
    void report()const;
    int retpin()const;
    int retdepo()const;
    char retype()const;
    
};
class Account:public Bank{

}
void Bank::create_account(){
    cout<<"Enter the Account number : ";
    cin>>acc;
    cout<<"\n\nEnter the Account holdr name : ";
    cin.ignore();
    cin.getline(name,50);
    cout<<"\n Enter your Account Type  S/C : ";
    cin>>type;
    type=toupper(type);
    cout<<"\n Enter the Initial Amount : ";
    cin>>deposit;
    cout<<"Enter your transcation pin : ";
    cin>>pin;
    // cout<<"Enter your UserName : ";
    // cin.ignore();
    // cin.getline(user,20);
    cout<<"Account is Successfully Created : ";
    
}
void Bank::show_account()const{
    cout<<"\nAccont number  : "<<acc;
    cout<<"\nAccont Holder name  : "<<name;
    cout<<"\nAccont Type  : "<<type;
    cout<<"\nAccont BAlance  : "<<deposit;
    

}
void Bank::modify(){
    cout<<"\nAccount number  : "<<acc;
    cout<<"\nModify Account Holder Name : ";
    cin.ignore();
    cin.getline(name,50);
    cout<<"\nModify Account Type S/C  : ";
    cin>>type;
    type=toupper(type);
    cout<<"\nModify  Account Money  : ";
    cin>>deposit;
   
}
void Bank::dep(int x){
    deposit+=x;

}
void Bank::drw(int x){
    deposit-=x;

}
void Bank::report()const{
    cout<<acc<<setw(10)<<""<<name<<setw(10)<<""<<type<<setw(10)<<deposit<<endl;
}
int Bank::retpin()const{
    return pin;
}
int Bank::retdepo()const{
    return deposit;
}
char Bank::retype()const{
    return type;
}

void write_account();
void display_sp(int);
void modify_account(int);
void delete_account(int);
void display_all();
void deposit_withdraw(int,int);
void intro();
int main(){
    char ch;
   int num;
    intro();
    do{
        system("cls");
          cout<<"\n\n\tMAIN MENU :" ;
           cout<<"\n\n\t01 NEW ACCOUNT :" ;
            cout<<"\n\n\t02 DEPPOSITE AMOUNT :" ;
             cout<<"\n\n\t03 WITHDRAW AMOUNT :" ;
              cout<<"\n\n\t04 BALANCE INQUIRY :" ;
               cout<<"\n\n\t05 ALL ACCOUNT HOLDER LIST :" ;
                cout<<"\n\n\t06 CLOSE AN ACCOUNT :" ;
                 cout<<"\n\n\t07 MODIFY ACCOUNT :" ;
                  cout<<"\n\n\t08 EXIT :" ;
                   cout<<"\n\n\tSelect Your option (1-8)...: " ;
                   cin>>ch;
      system("cls");
      switch(ch){
        case '1':
        write_account();
        break;
        case '2':
         cout<<"\n\n\tEnter the PIN No. :" ;
         cin>>num;
         deposit_withdraw(num,1);break;
      case '3':
       cout<<"\n\n\tEnter the PIN No. :" ;
         cin>>num;
         deposit_withdraw(num,2);
         break;
    case '4':
     cout<<"\n\n\tEnter the PIN No. :" ;
         cin>>num;
         display_sp(num);
         break;
         case '5':
         display_all();
         break;
         case '6':
          cout<<"\n\n\tEnter the PIN No. :" ;
         cin>>num;
         delete_account(num);
         break;
         case '7':
          cout<<"\n\n\tEnter the PIN No. :" ;
         cin>>num;
         modify_account(num);
         break;
         case '8':
          cout<<"\n\n\tThank for Using Our Bank System  : " ;
          break;
          default: cout<<"\a";
         
      }
      cin.ignore();
      cin.get();             

    }while(ch!='8');
    return 0;
}
void write_account(){
    Bank ac;
    ofstream outfile;
    outfile.open("Account.dat",ios::binary|ios::app);
    ac.create_account();
    outfile.write(reinterpret_cast<char *>(&ac),sizeof(Bank));
    outfile.close();
}
void display_sp(int n){
    Bank ac;
    bool flag=false;
    ifstream infile;
    infile.open("Account.dat",ios::binary);
    if(!infile){
        cout<<"File could not be open !! Press any key...";
        return;
    }
    cout<<"\n BALANCE DETAILS : \n";
    while(infile.read(reinterpret_cast<char *>(&ac),sizeof(Bank))){
        if(ac.retpin()==n){
            ac.show_account();
            flag=true;
        }
    }
    infile.close();
    if(flag==false){
        cout<<"\n\nAccount number does not exist ..";
    }
}
    void modify_account(int n){
        bool found=false;
        Bank ac;
        fstream file;
        file.open("Account.dat",ios::binary|ios::in|ios::out);
        if(!file){
             cout<<"File could not be open !! Press any key...";
        return;
        }
        while(!file.eof()&& found==false){
            file.read(reinterpret_cast<char *>(&ac),sizeof(Bank));
        if(ac.retpin()==n){
            ac.show_account();
            cout<<"\n\n Enter the New details of Acount   ";
            ac.modify();
            int pos =(-1)*static_cast<int>(sizeof(Bank));
            file.seekp(pos,ios::cur);
            file.write(reinterpret_cast<char *>(&ac),sizeof(Bank));
            cout<<"\n\n\t Record update...";

            found=true;
        }
        }
        file.close();
        if(found==false){
            cout<<"\n\n Record not Found :";
        }
    }
    void delete_account(int n){
        Bank ac;
        ifstream infile;
        ofstream outfile;
        infile.open("Account.dat",ios::binary);
        if(!infile){
            cout<<"File con't be open";
            return;

        }
        outfile.open("Temp.dat",ios::binary);
        infile.seekg(0,ios::beg);
        while(infile.read(reinterpret_cast<char *>(&ac),sizeof(Bank))){
            if(ac.retpin()!=n){
                outfile.write(reinterpret_cast<char *>(&ac),sizeof(Bank));
            }
        }
        infile.close();
        outfile.close();
        remove("Account.dat");
        rename("Temp.dat","Account.dat");
        cout<<"\n\n\t Record Deleted";
            }
    void display_all(){
        Bank ac;
        ifstream infile;
        infile.open("Account.dat",ios::binary);
         if(!infile){
            cout<<"File con't be open";
            return;

        }
        cout<<"\n\n\t\tAccount Holder list \n\n ";
        cout<<"=====================================================\n";
        cout<<"A/c no.     Name      Type  Balnce \n";
        cout<<"=====================================================\n";
        while(infile.read(reinterpret_cast<char *>(&ac),sizeof(Bank))){
            ac.report();
        }
        infile.close();
    }
    void deposit_withdraw(int n, int option){
        int amt;
        bool found=false;
        Bank ac;
        fstream  file;
        file.open("Account.dat",ios::binary|ios::in|ios::out);
        if(!file){
             cout<<"File could not be open !! Press any key...";
        return;
        }
        while(!file.eof()&& found==false){
            file.read(reinterpret_cast<char *>(&ac),sizeof(Bank));
        if(ac.retpin()==n){
            ac.show_account();
            if(option==1){
                cout<<"\n\n To Deposite Amount ";
                cout<<"\n\n Enter the amount : ";
                cin>>amt;
                ac.dep(amt);
            }
            if(option==2){
                cout<<"\n\nTo withdraw Amount ";
                cout<<"\n\nEnter The Amount : ";
                cin>>amt;
             int bal=ac.retdepo()-amt;
             if(bal<500&&ac.retype()=='S'||bal<1000&&ac.retype()=='C'){
                cout<<"Insufficient Balance ";

             }
             else 
             ac.drw(amt);
            }
             int pos =(-1)*static_cast<int>(sizeof(Bank));
            file.seekp(pos,ios::cur);
            file.write(reinterpret_cast<char *>(&ac),sizeof(Bank));
            cout<<"\n\n\t Record update...";
            found=true;
            }
        }
        file.close();
        if(found==false){
            cout<<"\n\n Record Not found ";
        }
    }
void intro(){
    cout<<"\n\n\t BANK";
     cout<<"\n\n\t MANAGEMENT";
      cout<<"\n\n\t SYSTEM";
       cout<<"\n\n\n MADE BY SUNIL ";
        cout<<"\n\n COLLEGE...: JNCT\n";
}