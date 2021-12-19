#include <conio.h>
#include <stdio.h>

int Gcd(int x, int y)
{
	if (x % y == 0)
		return y;

	else
		return Gcd(y, x % y);
}

int main()
{
	printf("GCD[9, 19]: %d", Gcd(9, 19));

	getch();
	return 0;
}
