#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define min 1
#define max 9

typedef struct
{
	char b[3][3];

} matrix;

matrix b = {'1', '2', '3',
			'4', '5', '6',
			'7', '8', '9'};

void print(void);
int check(void);
int assign(int num, int p);
char itoc(int num);
int random_num(void);
char win(void);
int computer(int st, matrix b);

int main(void)
{
	int num = 5;
	int p = (random_num() % 2) + 1;
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
			try:
				while (1)
				{
					printf("type which court you want : ");
					if (scanf("%d", &num) == 1 && num < 10 && num > 0)
					{
						break;
					}

					while (getchar() != '\n')
						;

					printf("INVALID INPUT!\n");
				}

			if (assign(num, 1))
			{
				printf("INVALID INPUT!\n");
				goto try;
			}
			p++;
		}
		else
		{
			while (assign(computer(st, b), 0))
				;

			p++;
			st = 1;
		}
	}
}

void print(void)
{
	printf("\ncomputer : (O) player : (X)\n");
	printf(" %c | %c | %c\n", b.b[0][0], b.b[0][1], b.b[0][2]);
	printf("---|---|---\n");
	printf(" %c | %c | %c\n", b.b[1][0], b.b[1][1], b.b[1][2]);
	printf("---|---|---\n");
	printf(" %c | %c | %c\n", b.b[2][0], b.b[2][1], b.b[2][2]);
}

int assign(int num, int p)
{
	if (p == 1)
	{
		for (int r = 0; r < 3; r++)
		{
			for (int c = 0; c < 3; c++)
			{
				if (itoc(num) == b.b[r][c])
				{
					b.b[r][c] = 'X';
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
				if (itoc(num) == b.b[r][c])
				{
					b.b[r][c] = 'O';
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
			if (b.b[r][c] != 'X' && b.b[r][c] != 'O')
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


// random number generator
int random()
{
	static unsigned long long int n = 0;
	srand(time(NULL) * n * getpid());
	n++;
	return (rand() % max) + min;
}

char win(void)
{
	// check rows
	for (int i = 0; i < 3; i++)
	{
		if (b.b[i][0] == b.b[i][1] && b.b[i][0] == b.b[i][2])
		{
			return b.b[i][0];
		}
	}
	// check columns
	for (int i = 0; i < 3; i++)
	{
		if (b.b[0][i] == b.b[1][i] && b.b[0][i] == b.b[2][i])
		{
			return b.b[0][i];
		}
	}
	// check diagonals
	if (b.b[0][0] == b.b[1][1] && b.b[0][0] == b.b[2][2])
	{
		return b.b[0][0];
	}

	if (b.b[0][2] == b.b[1][1] && b.b[0][2] == b.b[2][0])
	{
		return b.b[0][2];
	}

	return 'T';
}

int computer(int st, matrix b)
{
	if (st == 0)
	{
		if (b.b[2][0] == '7')
		{
			return 7;
		}
		else
		{
			return 9;
		}
	}
	else
	{

		// for colum
		if (b.b[0][0] == '1' && b.b[1][0] != '4' && b.b[2][0] != '7')
		{
			return 1;
		}
		else if (b.b[0][0] != '1' && b.b[1][0] == '4' && b.b[2][0] != '7')
		{
			return 4;
		}
		else if (b.b[0][0] != '1' && b.b[1][0] != '4' && b.b[2][0] == '7')
		{
			return 7;
		}
		else if (b.b[0][1] == '2' && b.b[1][1] != '5' && b.b[2][1] != '8')
		{
			return 2;
		}
		else if (b.b[0][1] != '2' && b.b[1][1] == '5' && b.b[2][1] != '8')
		{
			return 5;
		}
		else if (b.b[0][1] != '2' && b.b[1][1] != '5' && b.b[2][1] == '8')
		{
			return 8;
		}
		else if (b.b[0][2] == '3' && b.b[1][2] != '6' && b.b[2][2] != '9')
		{
			return 3;
		}
		else if (b.b[0][2] != '3' && b.b[1][2] == '6' && b.b[2][2] != '9')
		{
			return 6;
		}
		else if (b.b[0][2] != '3' && b.b[1][2] != '6' && b.b[2][2] == '9')
		{
			return 9;
		}
		// for diagonal
		else if (b.b[0][0] == '1' && b.b[1][1] != '5' && b.b[2][2] != '9')
		{
			return 1;
		}
		else if (b.b[0][0] != '1' && b.b[1][1] == '5' && b.b[2][2] != '9')
		{
			return 5;
		}
		else if (b.b[0][0] != '1' && b.b[1][1] != '5' && b.b[2][2] == '9')
		{
			return 9;
		}
		else if (b.b[0][2] == '3' && b.b[1][1] != '5' && b.b[2][0] != '7')
		{
			return 3;
		}
		else if (b.b[0][2] != '3' && b.b[1][1] == '5' && b.b[2][0] != '7')
		{
			return 5;
		}
		else if (b.b[0][2] != '3' && b.b[1][1] != '5' && b.b[2][0] == '7')
		{
			return 7;
		}
		// for row
		else if (b.b[0][0] == '1' && b.b[0][1] != '2' && b.b[0][2] != '3')
		{
			return 1;
		}
		else if (b.b[0][0] != '1' && b.b[0][1] == '2' && b.b[0][2] != '3')
		{
			return 2;
		}
		else if (b.b[0][0] != '1' && b.b[0][1] != '2' && b.b[0][2] == '3')
		{
			return 3;
		}
		else if (b.b[1][0] == '4' && b.b[1][1] != '5' && b.b[1][2] != '6')
		{
			return 4;
		}
		else if (b.b[1][0] != '4' && b.b[1][1] == '5' && b.b[1][2] != '6')
		{
			return 5;
		}
		else if (b.b[1][0] != '4' && b.b[1][1] != '5' && b.b[1][2] == '6')
		{
			return 6;
		}
		else if (b.b[2][0] == '7' && b.b[2][1] != '8' && b.b[2][2] != '9')
		{
			return 7;
		}
		else if (b.b[2][0] != '7' && b.b[2][1] == '8' && b.b[2][2] != '9')
		{
			return 8;
		}
		else if (b.b[2][0] != '7' && b.b[2][1] != '8' && b.b[2][2] == '9')
		{
			return 9;
		}
		else
		{
			return random_num();
		}
	}
}