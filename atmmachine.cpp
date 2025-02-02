#include <iostream>
#include <vector>
using namespace std;

double checkbalance(double Balance[], int userIndex);
double withdraw(double Balance[], int userIndex);
double deposit(double Balance[], int userIndex);
void Receipt(string name, vector<string> transactions, double finalBalance);

int main()
{
    string Name[] = {"Nath Bunlong", "Lay Katsrieng", "Monika Ly", "Dout Sophanha"};
    int pw[] = {3123, 7035, 9086 , 9999};
    double Balance[] = {1000, 2500, 4000, 10000};
    int userIndex = -1;
    int totalSeconds = 2;
    vector<string> transactions; // Store transaction history

    string account;
    cout << "=============================================================" << endl;
    cout << "                  *** Welcome to BMK Bank ***                " << endl;
    cout << "=============================================================" << endl;
    cout << "Enter User Account: ";
    getline(cin, account);
    
    for(int i = 0; i < 4; i++)
    {
        if(Name[i] == account)
        {
            userIndex = i;
            break;
        }
    }
    
    if (userIndex == -1)
    {
        cout << "\n[Error] Account not found. Please try again." << endl;
        return 0;
    }
    
    int IPW; //input password
    int attempt = 0;
    const int MA = 3; // maximum attempts
    
    while (attempt < MA)
    {
        cout << "\nEnter Your Password: ";
        cin >> IPW;
        cout << "=============================================================" << endl;
        
        if (IPW == pw[userIndex])
        {
            cout << "\n[Success] Login successful. Welcome, " << Name[userIndex] << "!\n";
            break;
        }
        else
        {
            cout << "\n[Error] Incorrect password. Please try again." << endl;
            attempt++;
        }
        
        if (attempt == MA)
        {
            cout << "\n[Error] Too many incorrect attempts. Exiting Program." << endl;
            return 0;
        }
    }
    
    int n;
    do
    { 
        cout << "\n=============================================================" << endl;
        cout << "Please choose one of the options below:" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Deposit Money" << endl;
        cout << "4. Exit" << endl;
        cout << "Please enter your choice: ";
        cin >> n;
        cout << "=============================================================" << endl;

        switch(n)
        {
            case 1:
                checkbalance(Balance, userIndex);
                break;
            case 2:
            {
                double amount = withdraw(Balance, userIndex);
                transactions.push_back("Withdraw: $" + to_string(amount));
                break;
            }
            case 3:
            {
                double amount = deposit(Balance, userIndex);
                 transactions.push_back("Deposit: $" + to_string(amount));
                break;
            }
            case 4:
                Receipt(Name[userIndex], transactions, Balance[userIndex]);
                break;
            default: 
                cout << "\n=============================================================\n";
                cout << "                         Invalid option                      \n";
                cout << "=============================================================\n"; 
                break;
        }
    } while (n != 4);
    return 0;    
}

double checkbalance(double Balance[], int userIndex)
{
    cout << "\n[Info] Your current balance: $" << Balance[userIndex] << endl;
    return Balance[userIndex];
}


double withdraw(double Balance[], int userIndex)
{
    double WDM; // WDM = withdraw Money
    cout << "\nEnter the amount to withdraw: $";
    cin >> WDM;
    if(WDM <= Balance[userIndex] && WDM > 0)
    {
        Balance[userIndex] -= WDM;
        cout << "\n[Success] You have withdrawn: $" << WDM << endl;
        cout << "[Info] Remaining balance: $" << Balance[userIndex] << endl;
    }
    else 
    {
        cout << "\n[Error] Insufficient balance or invalid amount." << endl;
        WDM = 0;
    }
    return WDM;
}

double deposit(double Balance[], int userIndex)
{
    double DM; //DM = Deposit Money
    cout << "\nEnter the amount to deposit: $";
    cin >> DM;
    if(DM > 0)
    {
        Balance[userIndex] += DM;
        cout << "\n[Success] You have deposited: $" << DM << endl;
        cout << "[Info] Updated balance: $" << Balance[userIndex] << endl;
    }
    else 
    {
        cout << "\n[Error] Please enter a positive amount." << endl;
        DM = 0;
    }
    return DM;
}
void Receipt(string name, vector<string> transactions, double finalBalance) {
    cout << "\n=============================================================\n";
    cout << "\n                       Bank Transaction                      \n";
    cout << "\n=============================================================\n";
    cout << "Account Holder: " << name << endl;
    cout << "-------------------------------------------------------------\n";
    
    if (transactions.empty()) {
        cout << "No transaction was made.\n";
    } else {
        for (const string& t : transactions) {
            cout << t << endl;
        }
    }

    cout << "-------------------------------------------------------------\n";
    cout << "Final Balance: $" << finalBalance << endl;
    cout << "\n=============================================================\n";
    cout << "\n               Thank you for using BMK Bank!  \n";
    cout << "\n=============================================================\n";
}