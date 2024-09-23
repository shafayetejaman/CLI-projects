// main file 
#include "password.h"

// input validation
int input(int min, int max)
{
    string s;

    while (true)
    {
        cin.clear();
        getline(cin, s); // getting the input
        bool flag = true;
        int num = stoi(s);

        for (int i = 0; i < s.size(); i++)
        {
            if (!isdigit(s[i]))
                flag = false;
        }
        if (!(num >= min && num <= max))
            flag = false;

        if (flag)
            return num;

        cout << "Invalid Input(" << min << "-" << max << ")!\n"
            << "Type Again : ";
    }
}
// input of password or key
string input()
{
    string s;

    while (true)
    {
        cin.clear();
        getline(cin, s); // getting the input
        bool flag = true;
        if (s[0] == '0' && s.size() == 1)
        {
            return generate_pass();
        }

        if (!(s.size() >= 5 && s.size() <= 20))
            flag = false;

        for (int i = 0; i < s.size(); i++)
        {
            if (!isalpha(s[i]) && !isdigit(s[i]))
                flag = false;
        }

        if (flag)
            return s;

        cout << "Invalid Input(5-20)!\n"
            << "Type Again : ";
    }
}

int main()
{
    cout << "\nType the password to login to the Password Manager.\n-> ";

    PassWord passWord(input()); // getting the login password

    while (true)
    {
        cout << endl;
        cout << "(1) Exit.\n(2) save a password.\n(3) Delete a password.\n(4) View a password\n(5) View all saved password\nType your choice : ";

        int num = input(1, 5);
        // exiting
        if (num == 1)
        {
            break;
        }
        // saving a new password
        else if (num == 2)
        {
            cout << "type the name of the key : ";
            string key = input();
            cout << "type the name of the password(0 for suggestion) : ";
            string val = input();

            passWord.insert(key, val);
            cout << "The saved password = " << key << " : " << passWord.get(key) << endl;
        }
        // deleting a saved password
        else if (num == 3)
        {
            cout << "type the name of the key : ";
            string key = input();

            if (!passWord.erase(key))
            {
                cout << "The password was not found!" << endl;
            }
            else
            {
                cout << "The password was successfully deleted!" << endl;
            }
        }
        // viewing a saved password
        else if (num == 4)
        {
            cout << "type the name of the key : ";
            string key = input();

            if (passWord.find(key))
            {
                cout << key << " : " << passWord.get(key) << endl;
            }
            else
            {
                cout << "No such key found in the memory!\n";
            }
        }
        // viewing all the saved password 
        else if (num == 5)
        {
            passWord.print();
        }
        cout << endl;
    }

    return 0;
}