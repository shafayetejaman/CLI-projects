#include "Map2.h"
#include <fstream>
#include <ctime>
#include <random>
#include <unistd.h>
#include <time.h>
#include <sstream>
#include <unistd.h>

const int MAX = 30; // maximum length of the password
const int MIN = 20; // minimum length of the password

// generating more precise random number between MAX and MIN
int random(int min, int max)
{
    static unsigned long long n = 1;
    srand(time(nullptr) * n * getpid());
    n++;
    int val = (rand() % (max - min + 1)) + min;

    return val;
}
int random()
{
    static unsigned long long n = 1;
    srand(time(nullptr) * n * getpid());
    n++;
    return rand();
}
// generating random password
string generate_pass(int min = MIN, int max = MAX)
{
    int len = random(min, max);
    // all the possible characters for inserting in the password
    string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=";
    string password;

    for (auto i = 0; i < len; i++)
    {
        int randIndex = random() % characters.size();
        password += characters[randIndex];
    }
    return password;
}
// string to map converter
string map_to_string(Map<string, string> &data)
{
    string output;
    if (!data.empty())
    {
        auto node = data.next();

        while (node)
        {
            output += node->key + " " + node->val + " ";
            node = data.next();
        }
    }
    if (!output.empty())
        output.pop_back();

    return output;
}
// string to map converter
Map<string, string> string_to_map(const string &data)
{
    Map<string, string> output;
    stringstream ss(data);
    string s;
    while (ss >> s)
    {
        string pass;
        ss >> pass;

        output[s] = pass;
    }
    return output;
}
class PassWord
{
private:
    string loginPass;         // password for login to the software
    Map<string, string> data; // data structure for saving the passwords
    const string encryptKey = "$#&#$";

    // encrypting all the data of the map
    string encrypt(const string &data)
    {
        string output;
        bool insert = false;
        for (auto i = 0; i < data.size(); i++)
        {
            if (insert)
            {
                string s = generate_pass(2, 9);
                output += data[i] + to_string(s.size()) + encryptKey + s;
            }
            else
            {
                output += data[i];
            }
            insert = my_random() % 2;
        }
        return output;
    }
    // decrypting all the data from the file
    string decrypt(const string &data)
    {
        string output = data;
        for (auto i = 0; i < output.size() - encryptKey.size(); i++)
        {
            if (output.substr(i + 1, encryptKey.size()) == encryptKey)
            {
                int num = output[i] - '0';
                output.erase(i, num + encryptKey.size() + 1);
            }
        }
        return output;
    }
    // input the data to a txt file for long term storage
    void file_output()
    {
        if (this->data.empty())
            return;

        string s = this->encrypt(map_to_string(this->data));
        ofstream file("saved_password.txt");
        file << s;
        file.close();
    }
    // extracting the data from the file
    void file_input()
    {
        string s;
        ifstream file("saved_password.txt");

        if (file.is_open() && file.peek() == ifstream::traits_type::eof())
        {
            file.close();
            return;
        }
        while (!file.eof())
        {
            string line;
            getline(file, line);
            s += line;
        }
        string newData = this->decrypt(s);
        this->data = string_to_map(newData);

        file.close();
    }
    // checking for valid login password
    string login(const string &data)
    {
        string s;
        ifstream fileIn("login.txt");

        string line;
        getline(fileIn, line);
        s += line;

        if (!s.empty())
        {
            return decrypt(s); // returning the saved password
        }
        fileIn.close();
        ofstream fileOut("login.txt");

        s = this->encrypt(data);
        fileOut << s; // saving the new password to the file

        fileOut.close();
        return data;
    }

public:
    PassWord(const string &loginPass)
    {
        this->loginPass = login(loginPass);
        if (this->loginPass == loginPass)
        {
            cout << "Successfully longed in!" << endl;
        }
        else
        {
            cout << "INVALID PASSWORD!\nexiting!" << endl;
            exit(-2);
        }
        this->file_input();
    }
    ~PassWord()
    {
        this->file_output();
        this->data.clear();
        cout << "Exiting!" << endl;
    }
    // inserting the password to the hash map
    void insert(const string &key, const string &pass)
    {
        if (!data.find(key))
        {
            data[key] = pass;
        }
        else // asking to overwrite the password
        {
            cout << "The Password already exits!" << endl
                 << "Do you want to overwrite the password?(y,n) : ";
            string choice;
            while (true)
            {
                getline(cin, choice);
                if (choice.size() == 1 && (tolower(choice[0]) == 'y' || tolower(choice[0]) == 'n'))
                {
                    break;
                }
                cout << "Invalid Input!" << endl;
                cin.clear();
                cout << "Type Again : ";
            }
            if (tolower(choice[0]) == 'y')
            {
                data[key] = pass; // overwriting the password
            }
        }
    }

    // deleting the saved password
    bool erase(const string &key)
    {
        return this->data.erase(key);
    }
    // printing the saved password
    void print()
    {
        if (!data.empty())
        {
            auto node = data.next();
            while (node)
            {
                cout << node->key << " : " << node->val << endl;
                node = data.next();
            }
        }
        else
        {
            cout << "No password has been saved!" << endl;
        }
    }
    // if the key exits
    bool find(const string &key)
    {
        if (data.find(key))
        {
            return true;
        }
        return false;
    }
    // view the saved password
    string get(const string &key)
    {
       return this->data[key];
    }
  

};