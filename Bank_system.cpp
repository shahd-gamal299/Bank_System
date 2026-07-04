#include <iostream>
#include <string>
using namespace std;
class Account
{
public:
    int accountNumber;
    string name;
    double balance;
};
int main()
{
    Account accounts[10];
    int count = 0;
    int choice;
    while(true)
    {
        cout << "\n===== Bank System =====\n";
        cout << "1. Create Account\n";
        cout << "2. View Accounts\n";
        cout << "3. Deposit\n";
        cout << "4. Withdraw\n";
        cout << "5. Search Account\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        if(choice == 1)
        {
            cout << "Enter Account Number: ";
            cin >> accounts[count].accountNumber;
            bool exists = false;
            for(int i=0; i<count; i++)
            {
                if(accounts[i].accountNumber ==
                   accounts[count].accountNumber)
                {
                    exists = true;
                }
            }

            if(exists)
            {
                cout << "Account Number already exists\n";
            }
            else
            {
                cin.ignore();
                cout << "Enter Name: ";
                getline(cin, accounts[count].name);
                cout << "Enter Balance: ";
                cin >> accounts[count].balance;
                count++;
                cout << "Account Created Successfully\n";
            }
        }

        else if(choice == 2)
        {
            for(int i=0; i<count; i++)
            {
                cout << "\nAccount Number: "
                     << accounts[i].accountNumber;

                cout << "\nName: "
                     << accounts[i].name;

                cout << "\nBalance: "
                     << accounts[i].balance << endl;
            }
        }
        else if(choice == 3)
        {
            int accNum;
            double amount;
            cout << "Enter Account Number: ";
            cin >> accNum;
            cout << "Enter Amount: ";
            cin >> amount;
            bool found=false;
            for(int i=0; i<count; i++)
            {
                if(accounts[i].accountNumber==accNum)
                {
                    accounts[i].balance += amount;
                    cout<<"Deposit Successful\n";
                    cout<<"New Balance: "
                        <<accounts[i].balance<<endl;
                    found=true;
                }
            }
            if(!found)
            {
                cout<<"Account not found\n";
            }
        }

        else if(choice == 4)
        {
            int accNum;
            double amount;
            cout<<"Enter Account Number: ";
            cin>>accNum;
            cout<<"Enter Amount: ";
            cin>>amount;
            bool found=false;
            for(int i=0;i<count;i++)
            {
                if(accounts[i].accountNumber==accNum)
                {
                    found=true;
                    if(amount<=accounts[i].balance)
                    {
                        accounts[i].balance-=amount;
                        cout<<"Withdraw Successful\n";
                        cout<<"New Balance: "
                            <<accounts[i].balance<<endl;
                    }
                    else
                    {
                        cout<<"Insufficient Balance\n";
                    }
                }
            }
            if(!found)
            {
                cout<<"Account not found\n";
            }
        }

        // Search Account
        else if(choice==5)
        {
            int accNum;
            bool found=false;
            cout<<"Enter Account Number: ";
            cin>>accNum;
            for(int i=0;i<count;i++)
            {
                if(accounts[i].accountNumber==accNum)
                {
                    cout<<"\nAccount Number: "
                        <<accounts[i].accountNumber;

                    cout<<"\nName: "
                        <<accounts[i].name;

                    cout<<"\nBalance: "
                        <<accounts[i].balance<<endl;

                    found=true;
                }
            }

            if(!found)
            {
                cout<<"Account not found\n";
            }
        }
        else if(choice==6)
        {
            cout<<"Goodbye!\n";
            break;
        }
        else
        {
            cout<<"Invalid Choice\n";
        }
    }
    return 0;
}
