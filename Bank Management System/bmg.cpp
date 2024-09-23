#include <iostream>
#include <fstream>
#include <limits.h>
#include <limits>

using namespace std;

string load(ifstream &file);
long long int input(int min, long long int max);
int find_no(string s, long long int n);
long long int max_no(string s);
double erase_s(string &s, int index, int line, int mode);
void change_m(string filename, int mode);

// class for storing data of account
class Account
{
public:
    string name;
    int id;
    string email;
    long long int number;

    Account(string name, int id, string email, string filename) : name{name}, id{id}, email{email}
    {
        number = max_no(filename) + 1;
        balance = 0;
    }

    void deposit(int amount)
    {
        balance += amount;
    }

    void withdraw(int amount)
    {
        balance -= amount;
    }

    void print()
    {
        cout << "No : " << number << endl
             << "Name : " << name << endl
             << "ID : " << id << endl
             << "Email : " << email << endl
             << "Balance : " << balance << endl;
    }

    string info()
    {
        string bal = to_string(balance);
        for (auto i = 0; i < 4; i++)
            bal.pop_back();

        string s = "No : " + to_string(number) + "\n" + "Name : " + name + "\n" + "ID : " + to_string(id) + "\n" + "Email : " + email + "\n" + "Balance : " + bal + "\n";
        return s;
    }

private:
    double balance;
};

int main(void)
{

    // getting file name
    string filename = "bank_account.txt"; // The name of the file to store account information
    // while (true)
    // {
    //     cout << "Enter the file name : ";
    //     cin >> filename;
    //     if (filename.compare("bank_account.txt") == 0)
    //         break;

    //     cout << filename << " Not Found" << endl;
    //     cin.clear();
    //     cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // }

    while (true)
    {
        int n = -1;
        cout << "\n0) Exit" << endl
             << "1) View all accounts" << endl
             << "2) Add a new account" << endl
             << "3) Delete an account" << endl
             << "4) withdrawal from an account" << endl
             << "5) Deposit to an account\n" << endl
             << "Type your choses : ";

        n = input(0, 5);
        // printing all account
        if (n == 1)
        {
            ifstream file1(filename);

            string s = load(file1);
            cout << endl
                 << s;

            file1.close();
        }
        // adding new account
        else if (n == 2)
        {
            string name;
            long long int id;
            string email;

            cout << "Name : ";
            cin >> name;
            cout << "Id : ";
            id = input(0, LLONG_MAX);
            cout << "Email : ";
            cin >> email;

            ofstream file2(filename, ofstream::app);
            Account account(name, id, email, filename);

            file2 << endl
                  << account.info();

            file2.close();
        }
        // delete account
        else if (n == 3)
        {
            long long int n;
            cout << "Give the account number to delete : ";
            n = input(1, LLONG_MAX);

            // input from file to s
            ifstream file1(filename);
            string s = load(file1);

            // checking if the account is present
            int index = find_no(s, n);
            if (index != -1)
            {
                // erasing the account
                erase_s(s, index, 5,3);

                // overwriting the file with new content
                ofstream file3(filename);
                file3 << s;
                file3.close();
            }
            else
            {
                cout << "Not Found!" << endl;
            }
        }
        // withdrawal account
        else if (n == 4)
        {
            change_m(filename, 4);
        }
        // deposit account
        else if (n == 5)
        {
            change_m(filename, 5);
        }
        else
            break;
    }
    return 0;
}

// finding number
int find_no(string s, long long int n)
{
    string n_s = "No : " + to_string(n);
    int index = 0;

    while (index < s.size())
    {
        auto sc = s.find(n_s, index);
        if (sc != string::npos && s[sc + n_s.size()] == '\n')
            return sc;
        else
            index += 20;
    }
    return -1;
}

// loading file to string
string load(ifstream &file)
{
    string s;
    while (!file.eof())
    {
        string line;
        getline(file, line);
        s += line + "\n";
    }
    s.pop_back();
    return s;
}

// input validation
long long int input(int min, long long int max)
{
    string n;

    while (true)
    {
        cin >> n;

        for (int i = 0; isdigit(n[i]); i++)
        {
            if (i == n.size() - 1)
            {
                long long int num = stoll(n);
                if (num >= min && num <= max)
                    return num;
            }
        }

        cout << "Invalid Input!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Type Again : ";
    }
}

// find the maximum number
long long int max_no(string s)
{
    ifstream f(s);
    int index = 0;
    string file = load(f);
    long long int max = 0;

    while (index < file.size())
    {
        auto i = file.find("No : ", index);

        if (i != string::npos)
        {
            string s;
            for (int j = i + 5; isdigit(file[j]); j++)
                s += file[j];

            max = std::max(max, stoll(s));
        }
        else
            break;

        index += 20;
    }
    f.close();
    return max;
}

// erasing the balance
double erase_s(string &s, int index, int line, int mode)
{
    int count = 0;
    int count_n = 0;
    for (int i = index + 10; count_n != line; i++)
    {
        if (s[i] == '\n')
            count_n++;

        count++;
    }
    count--;
    string amount = s.substr(index + 10, count);
    s.erase(index, count + 10);
    if (mode == 3)
        return 0;
    return stod(amount);
}

void change_m(string filename, int mode)
{
    long long int n;
    // deposit
    if (mode == 5)
    {
        cout << "Give the account number to deposit from : ";
    }
    // withdrawal
    else
    {
        cout << "Give the account number to withdrawal from : ";
    }
    n = input(1, LLONG_MAX);
    string amount = "Balance : ";

    ifstream file1(filename);
    string s = load(file1);

    int index = find_no(s, n);
    int index2 = s.find("Balance : ", index);

    if (index != -1)
    {
        double balance = erase_s(s, index2, 1,5);
        double w_balance;
        cout << "Amount : ";
        cin >> w_balance;
        // deposit
        if (mode == 5)
        {
            amount += to_string(balance + w_balance);
        }
        // withdrawal
        else
        {
            if (w_balance > balance)
            {
                cout << "Insufficient balance!" << endl;
                return;
            }
            amount += to_string(balance - w_balance);
        }

        for (auto i = 0; i < 4; i++)
            amount.pop_back();
        s.insert(index2, amount);
        // overwriting the file with new content
        ofstream file3(filename);
        file3 << s;
        file3.close();
        file1.close();
    }
    else
    {
        cout << "Not found!" << endl;
    }
}