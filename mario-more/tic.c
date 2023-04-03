
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char b[3][3] = {'1', '2', '3',
		 	    '4', '5', '6',
		 	    '7', '8', '9'};


void print(void);
int check(void);
int assign(int num, int p);
char itoc(int num);
int random_num(void);
char win(void);

int main(void)
{
	int num = 5;
	int p = random_num() % 3;
	int st = 0;

	while (1)
	{
		char w = win();
		if (check() == 0 || w == 'O' || w == 'X')
		{
			if (w == 'X')
			{
				print();
				printf("You won the game!\n");
			}
			else if (w == 'O')
			{
				print();
				printf("Computer won the game!\n");
			}
			else
			{
				print();
				printf("It is a tie!\n");
			}
			return 0;
		}

		print();
		if (p % 2 == 0)
		{
			do
			{
				printf("type witch court you want : ");
				if (scanf("%d", &num) != 1)
        		{
        	   		printf("INVALID INPUT!\n");
        	    	return 1;
        		}
			}
			while (num > 9 || num < 1);
			assign(num, 1);
			p++;
		}
		else
		{
			if (st == 0)
			{
				if (num != 7)
				{
					num = 7;
					assign(num, 0);
				}
				else
				{
					num = 9;
					assign(num, 0);
				}
			}
			else
			{
				num = random_num();
				while (assign(num, 0) == 1)
				{
					num = random_num();
				}
			}
			p++;
			st = 1;
		}

	}
}

void print(void)
{
	printf("\ncomputer : (O) player : (X)\n");
	printf(" %c | %c | %c\n", b[0][0], b[0][1], b[0][2]);
	printf("---|---|---\n");
	printf(" %c | %c | %c\n", b[1][0], b[1][1], b[1][2]);
	printf("---|---|---\n");
	printf(" %c | %c | %c\n", b[2][0], b[2][1], b[2][2]);
}

int assign(int num, int p)
{
	if (p == 1)
	{
		for (int r = 0; r < 3; r++)
		{
			for (int c = 0; c < 3; c++)
			{
				if (itoc(num) == b[r][c])
				{
					b[r][c] = 'X';
					return 0;
				}
			}
		}
		printf("INVALID INPUT!\n");
		return 1;
	}
	else
	{
		for (int r = 0; r < 3; r++)
		{
			for (int c = 0; c < 3; c++)
			{
				if (itoc(num) == b[r][c])
				{
					b[r][c] = 'O';
					return 0;
				}
			}
		}
		return 1;
	}
}

int check(void)
{
	int t = 0;
	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			if (b[r][c] != 'X' && b[r][c] != 'O')
			{
				t = 1;
				return t;
			}
		}
	}
	return t;
}

char itoc(int num)
{
	return num + 48;
}

// random number generator between 0 to 2
int random_num(void)
{
    srand(time(NULL));
    return (rand() % 9) + 1;
}

char win(void)
{
	//check rows
    for (int i = 0; i < 3; i++)
    {
        if (b[i][0] == b[i][1] && b[i][0] == b[i][2])
        {
        	return b[i][0];
        }
    }
   //check columns
    for (int i = 0; i < 3; i++)
    {
      	if (b[0][i] == b[1][i] && b[0][i] == b[2][i])
      	{
        	return b[0][i];
      	}
    }
    //check diagonals
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
