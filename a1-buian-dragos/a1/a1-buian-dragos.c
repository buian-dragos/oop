//5

#include  <stdio.h>


void primeDecomposition(int n, int exponents[]) {
	//modifies the array "exponents" such that it has on the even positions the prime factor 
	//and on the odd postitions the exponent of that prime factor

	int d=2,k=0;
	exponents[0] = 0;
	exponents[1] = 0;
	while (n > 1) {
		if (n % d == 0) {
			n /= d;
			exponents[k]=d;
			exponents[k + 1]++;
		}
		else
		{
			d++;
			if (exponents[k] != 0) {
				k += 2;
				exponents[k] = 0;
				exponents[k + 1] = 0;
			}
		}
	}
	exponents[k + 2] = -1;
}

void printExponentOfP(int p, int exponents[]) {	//a
	//prints the exponent of p in the decomposition of n
	int i = 0;
	while (exponents[i] != -1) {
		if (exponents[i] == p) {
			printf("The exponent of %d is %d\n\n", p, exponents[i + 1]);
			return;
		}
		i += 2;
	}
	printf("%d is not a prime factor in the decomposition.\n\n", p);
}

void copyExponets(int exp1[], int exp2[]) {
	//copies the exponents from exp2 to exp1
	int i = 0;
	while (exp2[i] != -1) {
		exp1[i] = exp2[i];
		exp1[i + 1] = exp2[i + 1];

		i += 2;
	}
	exp1[i] = -1;
}

int compareExponents(int exp1[], int exp2[]) {
	//checks if the array of 2 consecutive numbers have common exponents
	int i = 0,j;
	while (exp1[i] != -1) {
		j = 0;
		while (exp2[j] != -1) {
			if (exp1[i] == exp2[j])
				return 0;
			j += 2;
		}
		i += 2;
	}
	return 1;
}

void findLongestSequence(int vec[],int length) {
	//finds and prints the longest sequence with the given property
	int exp1[100],exp2[100];
	int startMax = 0, endMax = 0,start = 0,end;

	primeDecomposition(vec[0], exp2);

	for (int i = 1; i < length; i++) {
		end = i;

		copyExponets(exp1, exp2);
		primeDecomposition(vec[i], exp2);

		if ((!compareExponents(exp1, exp2)) || i == length - 1) {
			if (end - start > endMax - startMax) {
				endMax = end;
				startMax = start;
			}
			start = i;
		}
	}

	printf("\nThe longest sequence is: ");
	for (int i = startMax; i < endMax; i++) {
		printf("%d ", vec[i]);
	}
	printf("\n\n");
}

int readArray(int vec[]) {
	//reads and array from the keyboard and returns it's length
	int length;
	printf("\nEnter length of vector: ");
	scanf_s("%d", &length);
	printf("\nEnter the elements of the vector: ");
	for (int i = 0; i < length; i++) {
		scanf_s("%d", &vec[i]);
	}
	vec[length] = 1;
	length++;
	return length;
}

void menu() {
	//prints a menu - exits with input 0

	int p, n, i = 0;
	int exponents[100];

	int vec[100], length = 0;

	int choice;
	while (1)
	{
		printf("1.The exponent of a prime number\n");
		printf("2.The longest subsequence\n");
		printf("3.Read array\n");
		printf("0.Exit\n>");
		scanf_s("%d", &choice);

		if (choice == 1)
		{
			printf("Enter n: ");
			scanf_s("%d", &n);
			printf("\nEnter p: ");
			scanf_s("%d", &p);

			primeDecomposition(n, exponents);

			printExponentOfP(p, exponents);
		}
		else if (choice == 2)
		{
			if (length == 0)
				printf("Please read the vector first!");
			else
				findLongestSequence(vec, length);
		}
		else if (choice == 3) 
		{
			length = readArray(vec);
		}
	
		else
		{
			break;
		}
	}

}

int main()
{
	menu();
	//Example	  
	  //4 7 3 32		len = 10
	//2 4 7 3 32 12 44 3 11 22
		  //6 11 2 3 5	len = 8
	//4 2 3 6 11 2 3 5
		  //6 7 13 11	len = 7
	//4 5 3 6 7 13 11

	return 0;
}