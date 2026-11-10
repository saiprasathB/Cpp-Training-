#include <iostream>
#include <string>
using namespace std;

class Transaction
{
public:
    string type;
    float amount;
};

class Account
{
private:
    int accNo;
    string name;
    float balance;
    Transaction history[100];
    int count;

public:
    Account()
    {
        count = 0;
        balance = 0;
        accNo = 0;
    }

    void createAccountWithNumber(int num)
    {
        accNo = num;

        cout << "Enter Name: ";
        cin >> ws;
        getline(cin, name);

        cout << "Enter Initial Balance: ";
        cin >> balance;

        if(balance < 0)
            balance = 0;

        cout << "Account Created Successfully!\n";
    }

    int getAccNo()
    {
        return accNo;
    }

    int getHistoryCount()
    {
        return count;
    }

    void deposit(float amount)
    {
        if(amount <= 0)
        {
            cout << "Invalid Amount!\n";
            return;
        }

        balance += amount;

        history[count].type = "Deposit";
        history[count].amount = amount;
        count++;

        cout << "Amount Deposited Successfully!\n";
    }

    void withdraw(float amount)
    {
        if(amount <= 0)
            cout << "Invalid Amount!\n";
        else if(amount > balance)
            cout << "Insufficient Balance!\n";
        else
        {
            balance -= amount;

            history[count].type = "Withdrawal";
            history[count].amount = amount;
            count++;

            cout << "Withdrawal Successful!\n";
        }
    }

    void transfer(float amount, Account &receiver)
    {
        if(amount <= 0)
            cout << "Invalid Amount!\n";
        else if(amount > balance)
            cout << "Insufficient Balance!\n";
        else
        {
            balance -= amount;
            receiver.balance += amount;

            history[count].type = "Transfer Sent";
            history[count].amount = amount;
            count++;

            receiver.history[receiver.count].type = "Transfer Received";
            receiver.history[receiver.count].amount = amount;
            receiver.count++;

            cout << "Transfer Successful!\n";
        }
    }

    void balanceEnquiry()
    {
        cout << "Available Balance: " << balance << endl;
    }

    void display()
    {
        cout << "\nAccount Number: " << accNo;
        cout << "\nName: " << name;
        cout << "\nBalance: " << balance << endl;
    }

    void transactionHistory()
    {
        cout << "\nTransaction History:\n";

        if(count == 0)
            cout << "No Transactions Found!\n";

        for(int i = 0; i < count; i++)
        {
            cout << history[i].type << " : "
                 << history[i].amount << endl;
        }
    }
};

class Bank
{
private:
    Account accounts[100];
    int n;

    int search(int num)
    {
        for(int i = 0; i < n; i++)
        {
            if(accounts[i].getAccNo() == num)
                return i;
        }
        return -1;
    }

public:
    Bank()
    {
        n = 0;
    }

    void create()
    {
        if(n == 100)
        {
            cout << "Account Limit Reached!\n";
            return;
        }

        int num;

        cout << "Enter Account Number: ";
        cin >> num;

        if(search(num) != -1)
        {
            cout << "Account Already Exists!\n";
            return;
        }

        accounts[n].createAccountWithNumber(num);
        n++;
    }

    void depositMoney()
    {
        int num;
        float amount;

        cout << "Enter Account Number: ";
        cin >> num;

        int i = search(num);

        if(i == -1)
        {
            cout << "Account Not Found!\n";
            return;
        }

        cout << "Enter Amount: ";
        cin >> amount;

        if(amount <= 0 || accounts[i].getHistoryCount() >= 100)
        {
            cout << "Invalid Amount or History Full!\n";
            return;
        }

        accounts[i].deposit(amount);
    }

    void withdrawMoney()
    {
        int num;
        float amount;

        cout << "Enter Account Number: ";
        cin >> num;

        int i = search(num);

        if(i == -1)
        {
            cout << "Account Not Found!\n";
            return;
        }

        cout << "Enter Amount: ";
        cin >> amount;

        if(accounts[i].getHistoryCount() >= 100)
        {
            cout << "Transaction History Full!\n";
            return;
        }

        accounts[i].withdraw(amount);
    }

    void checkBalance()
    {
        int num;

        cout << "Enter Account Number: ";
        cin >> num;

        int i = search(num);

        if(i == -1)
            cout << "Account Not Found!\n";
        else
            accounts[i].balanceEnquiry();
    }

    void transferMoney()
    {
        int from, to;
        float amount;

        cout << "Enter Sender Account Number: ";
        cin >> from;

        cout << "Enter Receiver Account Number: ";
        cin >> to;

        int i = search(from);
        int j = search(to);

        if(i == -1 || j == -1 || i == j)
        {
            cout << "Invalid Account Details!\n";
            return;
        }

        cout << "Enter Amount: ";
        cin >> amount;

        if(accounts[i].getHistoryCount() >= 100 ||
           accounts[j].getHistoryCount() >= 100)
        {
            cout << "Transaction History Full!\n";
            return;
        }

        accounts[i].transfer(amount, accounts[j]);
    }

    void showDetails()
    {
        int num;

        cout << "Enter Account Number: ";
        cin >> num;

        int i = search(num);

        if(i == -1)
            cout << "Account Not Found!\n";
        else
            accounts[i].display();
    }

    void showHistory()
    {
        int num;

        cout << "Enter Account Number: ";
        cin >> num;

        int i = search(num);

        if(i == -1)
            cout << "Account Not Found!\n";
        else
            accounts[i].transactionHistory();
    }

    void menu()
    {
        int choice;

        do
        {
            cout << "\n===== BANKING SYSTEM =====\n";
            cout << "1. Create Account\n";
            cout << "2. Deposit\n";
            cout << "3. Withdraw\n";
            cout << "4. Balance Enquiry\n";
            cout << "5. Fund Transfer\n";
            cout << "6. Transaction History\n";
            cout << "7. Display Account Details\n";
            cout << "8. Exit\n";

            cout << "Enter Choice: ";
            cin >> choice;

            switch(choice)
            {
                case 1: create(); break;
                case 2: depositMoney(); break;
                case 3: withdrawMoney(); break;
                case 4: checkBalance(); break;
                case 5: transferMoney(); break;
                case 6: showHistory(); break;
                case 7: showDetails(); break;
                case 8: cout << "Thank You!\n"; break;
                default: cout << "Invalid Choice!\n";
            }

        } while(choice != 8);
    }
};

int main()
{
    Bank b;
    b.menu();

    return 0;
}
