#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <algorithm>

#define ROW 9
#define COL 9

using namespace std;

#define matrix vector<vector<int>>

matrix board(ROW, vector<int>(COL, 0));

bool set_board(int i, int j);
bool check(const matrix &b, int r, int c, int val);
void print_board(const matrix &b);
matrix get_board();
bool is_duplicate(const matrix &b);

int main(void)
{

    int n = 0;
    cout << "type the board to solve : \n";
    board = get_board();

    print_board(board);
    if (!is_duplicate(board) || !set_board(0, 0))
    {
        cout << "INVALID BOARD!\n";
        exit(-1);
    }

    print_board(board);

    return 0;
}

// setting the board using recursion and backtracing
bool set_board(int i, int j)
{
    if (i == ROW)
    {
        return true; // Reached the end of the board
    }
    if (j == COL)
    {
        return set_board(i + 1, 0); // Move to the next row
    }

    if (board[i][j] == 0)
    {
        for (int k = 1; k <= 9; k++)
        {
            if (check(board, i, j, k))
            {
                board[i][j] = k; // Try placing number k at position (i, j)
                if (set_board(i, j + 1))
                {
                    return true; // Move to the next column
                }

                board[i][j] = 0; // backtrack and try the next number
            }
        }
    }
    else
    {
        return set_board(i, j + 1); // move to the next column
    }

    return false;
}

// printing the board
void print_board(const matrix &b)
{
    cout << endl;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// checking the board for existing elements
bool check(const matrix &b, int r, int c, int val)
{
    // for columns
    for (int i = 0; i < ROW; i++)
    {
        if (b[r][i] == val)
            return false;
    }
    // for rows
    for (int i = 0; i < ROW; i++)
    {
        if (b[i][c] == val)
            return false;
    }

    // for sub grid
    int sub_row = r - (r % int(sqrt(b.size())));
    int sub_col = c - (c % int(sqrt(b[0].size())));

    for (int i = sub_row; i < sub_row + 3; i++)
    {
        for (int j = sub_col; j < sub_col + 3; j++)
        {
            if (b[i][j] == val)
                return false;
        }
    }
    return true;
}

// getting input from the user
matrix get_board()
{
    matrix temp(ROW, vector<int>(COL));
    string input;
    int count_row = 0;

    for (auto i = 0; count_row < ROW; i++)
    {
        string s;
        getline(cin, s);
        // checking if it a valid row
        for (const auto &i : s)
        {
            if (isdigit(i))
            {
                input.append(s);
                count_row++;
                break;
            }
        }
    }
    int x = 0;
    int y = 0;

    // setting the board
    for (const auto &i : input)
    {
        if (y == temp.size())
        {
            x++;
            y = 0;
        }
        if (isdigit(i))
        {
            temp[x][y] = i - '0';
            y++;
        }
        else if (i == '.')
        {
            temp[x][y] = 0;
            y++;
        }
    }

    return temp;
}

// validating the input
bool is_duplicate(const matrix &b)
{

    int r = b.size();
    int c = b[0].size();
    bool hash_row[9][9] = {false};
    bool hash_col[9][9] = {false};
    vector<vector<vector<int>>> sub(3, vector<vector<int>>(3));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (b[i][j] == 0)
            {
                continue;
            }
            int in = b[i][j] - 1;
            int sub_row = i / 3;
            int sub_col = j / 3;

            if (!sub[sub_row][sub_col].empty())
            {
                int tar = b[i][j];
                if (find(sub[sub_row][sub_col].begin(), sub[sub_row][sub_col].end(), tar) != sub[sub_row][sub_col].end())
                {
                    return false; // Found a duplicate number in the same sub-grid
                }

            }
            if (hash_col[j][in] || hash_row[i][in])
            {
                return false; // Found a duplicate number in the same row or column
            }
            else
            {
                sub[sub_row][sub_col].push_back(b[i][j]);
                hash_col[j][in] = true;
                hash_row[i][in] = true;
            }
        }
    }
    return true; // No duplicates found
}
