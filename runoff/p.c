#include <stdio.h>

char convarter(int x)

int main(void)
{
	int count = 0, i = 0, num, k = 0;
	char c[10];
	scanf("%i", &num);
	if (num == 0)
	{
		printf("%d\n", num);
	}
	else
	{
		while (num > 0)
		{
			k = num % 10;
			num /= 10;
       		c[i] = convarter(k);
			i++;
			count++;
			if (count == 3 && num > 0)
			{
				c[i] =',';
				i++;
				count = 0;
			}
		}
		for (int j = i - 1; j >= 0; j--)
		{
			printf("%c", c[j]);
		}
		printf("\n");
	}
	return 0;
}

char convarter(int x)
{
	if (x == 0)
	{
		return '0';
	}
	else if (x == 1)
	{
		return '1';
	}
	else if (x == 2)
	{
		return '2';
	}
	else if (x == 3)
	{
		return '3';
	}
	else if (x == 4)
	{
		return '4';
	}
	else if (x == 5)
	{
		return '5';
	}
	else if (x == 6)
	{
		return '6';
	}
	else if (x == 7)
	{
		return '7';
	}
	else if (x == 8)
	{
		return '8';
	}
	else
	{
		return '9';
	}
}