#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <random>
#include <climits>
#include <limits>

#define MIN 1
#define MAX 9

using namespace std;

#define matrix vector<vector<char>>

matrix board = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}};

void print();
bool check(const matrix &b);
int assign(matrix &board, int num, int p);
char win(const matrix &b);
int wining_chance(matrix &temp);
int computer(matrix &b, int st);
int random_number();

int main()
{
    int num = 5;
    int p = random() % 2;
    int st = 0;

    while (true)
    {
        // checking for the result of the game
        char w = win(board);
        if (check(board) == 0 || w == 'O' || w == 'X')
        {
            if (w == 'X')
            {
                print();
                cout << "You won the game!" << endl;
            }
            else if (w == 'O')
            {
                print();
                cout << "Computer won the game!" << endl;
            }
            else
            {
                print();
                cout << "It is a tie!" << endl;
            }
            return 0;
        }

        print();
        if (p % 2 == 0)
        {
            bool try_again = true;
            while (try_again)
            {
                // getting input from the user
                while (true)
                {
                    cout << "Type the court you want: ";
                    if (cin >> num && num < 10 && num > 0)
                    {
                        break;
                    }
                    // flashing the input buffer
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    cout << "INVALID INPUT!" << endl;
                }

                if (assign(board, num, 1))
                {
                    cout << "INVALID INPUT!" << endl;
                }
                else
                {
                    try_again = false;
                }
            }
            p++;
        }
        else
        {
            while (assign(board, computer(board, st), 0))
                ;

            p++;
            st = 1;
        }
    }
}
// Function to print the Tic-Tac-Toe board
void print()
{
    cout << "\nComputer: (O) Player: (X)\n";
    for (int i = 0; i < 3; i++)
    {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << endl;
        if (i != 2)
            cout << "---|---|---" << endl;
    }
}
// checking for if there is a spot available on the board
int assign(matrix &b, int num, int p)
{
    if (p == 1)
    {
        for (int r = 0; r < 3; r++)
        {
            for (int c = 0; c < 3; c++)
            {
                if (num + '0' == b[r][c])
                {
                    b[r][c] = 'X';
                    return 0;
                }
            }
        }
        return 1;
    }
    else
    {
        for (int r = 0; r < 3; r++)
        {
            for (int c = 0; c < 3; c++)
            {
                if (num + '0' == b[r][c])
                {
                    b[r][c] = 'O';
                    return 0;
                }
            }
        }
        return 1;
    }
}

// Function to check if there is a spot available on the board
bool check(const matrix &b)
{
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            if (b[r][c] != 'X' && b[r][c] != 'O')
            {
                return true;
            }
        }
    }
    return false;
}
// Function to check if someone has won or if it's a draw
char win(const matrix &b)
{
    // check rows
    for (int i = 0; i < 3; i++)
    {
        if (b[i][0] == b[i][1] && b[i][0] == b[i][2])
        {
            return b[i][0];
        }
    }
    // check columns
    for (int i = 0; i < 3; i++)
    {
        if (b[0][i] == b[1][i] && b[0][i] == b[2][i])
        {
            return b[0][i];
        }
    }
    // check diagonals
    if (b[0][0] == b[1][1] && b[0][0] == b[2][2])
    {
        return b[0][0];
    }

    if (b[0][2] == b[1][1] && b[0][2] == b[2][0])
    {
        return b[0][2];
    }
    return 'T';
}
// Function to make the computer's move
int computer(matrix &b, int st)
{
    if (st == 0)
    {
        if (b[2][0] == '7')
        {
            return 7;
        }
        else
        {
            return 9;
        }
    }

    matrix temp = board;
    return wining_chance(temp);
}
// random number generator
int random_number()
{
    static unsigned long long n = 1;
    srand(time(nullptr) * n * getpid());
    n++;
    int val = (rand() % (MAX - MIN+1)) + MIN;

    return val;
}

// Function to determine the winning chance using backtracking
int wining_chance(matrix &temp)
{
    int count = 0;
    // for wining chance
    for (auto i = 0; i < 3; i++)
    {
        for (auto j = 0; j < 3; j++)
        {
            count++;
            if (temp[i][j] != 'X' && temp[i][j] != 'O')
            {
                temp[i][j] = 'O';
                if (win(temp) != 'T')
                {
                    return count;
                }
                else
                {
                    temp[i][j] = count + '0';
                }
            }
        }
    }
    count = 0;
    // for preventing the wining of the user
    for (auto i = 0; i < 3; i++)
    {
        for (auto j = 0; j < 3; j++)
        {
            count++;
            if (temp[i][j] != 'X' && temp[i][j] != 'O')
            {
                temp[i][j] = 'X';
                if (win(temp) != 'T')
                {
                    return count;
                }
                else
                {
                    temp[i][j] = count + '0';
                }
            }
        }
    }
    return random_number(); // if no winner is possible
}
