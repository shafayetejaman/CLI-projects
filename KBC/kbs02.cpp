#include <bits/stdc++.h>

using namespace std;

#define Q_C 10
#define QUESTION 0
#define OPTION 1
#define ANSWER 2
#define ANS_C 9

int main(void)
{
    vector<string> question[] = {
        {{"What is the full form of CPU?\n"},
         {"A : Central Processing Unit\nB : Central Processing System\nC : Central Processor System\nD : Central Processor Unit\n"},
         {"Answer = A : Central Processing Unit\n"}},

        {{"Who is known as the father of computer science?\n"},
         {"A : Charles Babbage\nB : Alan Turing\nC : Ada Lovelace\nD : John Von Neumann\n"},
         {"Answer = B : Alan Turing\n"}},

        {{"What is the name of the first electronic computer?\n"},
         {"A : UNIVAC\nB : ENIAC\nC : EDSAC\nD : Babbage Analytical Engine\n"},
         {"Answer = B : ENIAC\n"}},

        {{"Who developed the programming language C++?\n"},
         {"A : James Gosling\nB : Guido van Rossum\nC : Bjarne Stroustrup\nD : Rasmus Lerdorf\n"},
         {"Answer = C : Bjarne Stroustrup\n"}},

        {{"In which year was the first computer virus discovered?\n"},
         {"A : 1983\nB : 1986\nC : 1989\nD : 1992\n"},
         {"Answer = B : 1986\n"}},

        {{"What is the most widely used operating system in the world?\n"},
         {"A : Microsoft Windows\nB : macOS\nC : Linux\nD : UNIX\n"},
         {"Answer = A : Microsoft Windows\n"}},

        {{"What is the term used for the collection of instructions used to control the behavior of a computer?\n"},
         {"A : Operating System\nB : Computer Program\nC : Software\nD : Application\n"},
         {"Answer = B : Computer Program or Software\n"}},

        {{"Which company developed the mobile operating system Android?\n"},
         {"A : Microsoft\nB : Apple\nC : Google\nD : Amazon\n"},
         {"Answer = C : Google\n"}},

        {{"What is the name of the world's first website?\n"},
         {"A : google.com\nB : yahoo.com\nC : info.cern.ch\nD : bing.com\n"},
         {"Answer = C : info.cern.ch\n"}},

        {{"Which company developed the popular video game \"Super Mario Bros.\"?\n"},
         {"A : Sony\nB : Nintendo\nC : Microsoft\nD : Apple\n"},
         {"Answer = B : Nintendo\n"}}};

    int score = 0;

    for (int i = 0; i < Q_C; i++)
    {
        cout << question[i][QUESTION] << endl;
        cout << question[i][OPTION] << endl;

        string answer;
        cout << "Type your answer : ";
        cin >> answer;
        if (question[i][ANSWER][ANS_C] == toupper(answer[0]))
            score++;
        else
        {
            cout << "Wrong answer!" << endl;
            cout << question[i][ANSWER] << endl;
            break;
        }
        cout << question[i][ANSWER] << endl;
        cin.clear();
    }

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

    return 0;
}