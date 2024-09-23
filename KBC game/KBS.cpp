#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define QUESTION 0
#define OPTION 1
#define ANSWER 2

vector<string> get_question()
{
    string question, option = "", answer;
    cout << "question :\n";
    cin.ignore();
    getline(cin, question);
    int opt = 1;
    while (opt != 5)
    {
        cout << "option" << opt << ":\n";
        string s;
        getline(cin, s);
        option += (s + '\n');
        opt++;
    }
    cout << "answer :\n";
    getline(cin, answer);
    return {question, option, answer};
}

int main(void)
{
    // Predefined questions and answers
    vector<vector<string>> questions = {
        {"What is the full form of CPU?",
         "A : Central Processing Unit\nB : Central Processing System\nC : Central Processor System\nD : Central Processor Unit\n",
         "Answer = A : Central Processing Unit"},

        {"Who is known as the father of computer science?",
         "A : Charles Babbage\nB : Alan Turing\nC : Ada Lovelace\nD : John Von Neumann\n",
         "Answer = B : Alan Turing"},

        {"What is the name of the first electronic computer?",
         "A : UNIVAC\nB : ENIAC\nC : EDSAC\nD : Babbage Analytical Engine\n",
         "Answer = B : ENIAC"},

        {"Who developed the programming language C++?",
         "A : James Gosling\nB : Guido van Rossum\nC : Bjarne Stroustrup\nD : Rasmus Lerdorf\n",
         "Answer = C : Bjarne Stroustrup"},

        {"In which year was the first computer virus discovered?",
         "A : 1983\nB : 1986\nC : 1989\nD : 1992\n",
         "Answer = B : 1986"},

        {"What is the most widely used operating system in the world?",
         "A : Microsoft Windows\nB : macOS\nC : Linux\nD : UNIX\n",
         "Answer = A : Microsoft Windows"},

        {"What is the term used for the collection of instructions used to control the behavior of a computer?",
         "A : Operating System\nB : Computer Program\nC : Software\nD : Application\n",
         "Answer = B : Computer Program or Software"},

        {"Which company developed the mobile operating system Android?",
         "A : Microsoft\nB : Apple\nC : Google\nD : Amazon\n",
         "Answer = C : Google"},

        {"What is the name of the world's first website?",
         "A : google.com\nB : yahoo.com\nC : info.cern.ch\nD : bing.com\n",
         "Answer = C : info.cern.ch"},

        {"Which company developed the popular video game \"Super Mario Bros.\"?",
         "A : Sony\nB : Nintendo\nC : Microsoft\nD : Apple\n",
         "Answer = B : Nintendo"}};

    while (true)
    {
        int quarry;
        cout << "Enter:\n1 for adding questions\n2 for playing the game\n0 to quit\n$> ";
        cin >> quarry;
        if (quarry == 0)
        {
            break;
        }
        else if (quarry == 1)
        {
            // Adding a new question
            cout << "Example : ";
            cout << questions[0][QUESTION] << endl;
            cout << questions[0][OPTION] << endl;
            cout << questions[0][ANSWER] << endl;
            questions.push_back(get_question());
        }
        else
        {
            // Playing the game
            int score = 0;
            for (int i = 0; i < questions.size(); i++)
            {
                cout << questions[i][QUESTION] << endl;
                cout << questions[i][OPTION] << endl;

                string answer;
                cout << "Type your answer : ";
                cin >> answer;
                string a = "Answer = ";
                if (questions[i][ANSWER][a.size()] == toupper(answer[0]))
                    score++;
                else
                {
                    cout << "Wrong answer!" << endl;
                    cout << questions[i][ANSWER] << endl;
                    break;
                }
                cout << questions[i][ANSWER] << endl;

                cin.clear();
                cin.ignore();
            }
            // Calculating the score and money earned
            int money = 0;
            if (score <= 2 && score > 0)
                money = 1000;
            else if (score <= 5 && score > 2)
                money = 10000;
            else if (score <= 9 && score > 5)
                money = 100000;
            else if (score == 10)
                money = 1000000;

            cout << "You have earned " << money << '$' << endl;
        }
    }

    return 0;
}