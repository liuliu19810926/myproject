/*
 ============================================================================
 Name        : main.c
 Author      : liu
 Version     :
 Copyright   : Your copyright notice
 Description : C test code, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define get2DArray(array, row, column) ((column)[(row)[(array)]])

void getBinaryString(int dec, int num_bits, char *str);
void printSectionSeparator(int n);

int main(void) {

	// Example of how to access array
	int num[3][2]={
						{3,6},
						{9,12},
						{15,18}
		};
	printSectionSeparator(20);
	printf("This example shows how to access arrays:\n");
	printf("array=\n|%d,\t%d|\n|%d, \t%d|\n|%d, \t%d|\r\n",
			num[0][0], num[0][1],
			num[1][0], num[1][1],
			num[2][0], num[2][1]);

	printf("(a) Get the 1st element of the 1st row\n");
	printf("num=0x%x\n", (int)num);					// Address of the 1st row
	printf("*num=0x%x\n", (int)(*num));				// After dereference, we get the 1st row which is another array - a pointer points to the array
	printf("*num + 0=0x%x\n", (int)(*num + 0));		// Address of the 1st element of the 1st row
	printf("*(*num + 0)=%d\r\n", *(*num + 0));		// After dereference, we get the value of the 1st element of the 1st row

	printf("(b) Get the 2nd element of the 3rd row\n");
	printf("(num + 2)=0x%x\n", (int)(num + 2));				// Address of the 3rd row
	printf("*(num + 2)=0x%x\n", (int)*(num + 2));			// After dereference, we get the 3rd row which is another array - a pointer points to the array
	printf("*(num + 2) + 1=%x\n", (int)(*(num + 2) + 1));	// Address of the 2nd element of the 3rd row
	printf("*(*(num + 2) + 1)=%d\r\n", *(*(num + 2) + 1));	// After dereference, we get the value of the 2nd element of the 3rd row

	printf("(c) Get the 2nd element of the 2nd row\n");
	printf("1[num]=0x%x\n", (int)(1[num]));			// 2nd row which is an array - a pointer points to the array
	printf("1[num] + 1=0x%x\n", (int)(1[num] + 1));	// Address of the 2nd element of the 2nd row
	printf("*(1[num] + 1)=%d\n", *(1[num] + 1));	// Value of the 2nd element of the 2nd row
	printf("1[1[num]]=%d\n", (1[1[num]]));			// Value of the 2nd element of the 2nd row
	printf("1[num][1]=%d\r\n", (1[num][1]));		// Value of the 2nd element of the 2nd row

	printf("(d) Use hash define \"get2DArray\" to get the element from a 2D array:\n");
	int row, column;
	row = 1;
	column = 0;
	printf("row=%d, column=%d element is %d\r\n", (row + 1), (column + 1), get2DArray(num, row, column));

	// Show the size of the "char, ""short", "int", and "long"
	printSectionSeparator(20);
	char charVariable = 1;
	short int shortVariable = 1;
	int intVariable = 1;
	long int longVariable = 1;
	printf("This example shows the size of \"char\", \"short\", \"int\", and \"long\" variables:\n");
	printf("(1) \"char\" variable on this platform consists of %d byte\n", sizeof(charVariable));
	printf("\"unsigned char\": min=%d, max=%d\n", 0, UCHAR_MAX);
	printf("\"signed char\": min=%d, max=%d\r\n", SCHAR_MIN, SCHAR_MAX);

	printf("(2) \"short\" variable on this platform consists of %d bytes\n", sizeof(shortVariable));
	printf("\"unsigned short int\": min=%d, max=%d\n", 0, USHRT_MAX);
	printf("\"signed short int\": min=%d, max=%d\r\n", SHRT_MIN, SHRT_MAX);

	printf("(3) \"int\" variable on this platform consists of %d bytes\n", sizeof(intVariable));
	printf("\"unsigned int\": min=%u, max=%u\n", 0, UINT_MAX);
	printf("\"signed int\": min=%d, max=%d\r\n", INT_MIN, INT_MAX);

	printf("(4) \"long\" variable on this platform consists of %d bytes\n", sizeof(longVariable));
	printf("\"unsigned long int\": min=%lu, max=%lu\n", (unsigned long)0, (unsigned long)ULONG_MAX);
	printf("\"signed long int\": min=%ld, max=%ld\r\n", (signed long)LONG_MIN, (signed long)LONG_MAX);


	// Demo precedence of post-increment
	printSectionSeparator(20);
	int array[] = {3, 5};
	int *p;
	int j;
	printf("This is a demo precedence of post-increment:\n");
	printf("array=|%d, %d|\n", array[0], array[1]);
	printf("\"array\" is at address %#x\n", (unsigned int)array);

	p = array;
	printf("The result of \"p = array\" is p = %#x\n", (unsigned int)p);
	j = *p++;
	printf("The result of \"j = *p++;\" is j = %d, p = %#x, array=|%d, %d|\n", j, (unsigned int)p, array[0], array[1]);

	p = array;
	printf("The result of \"p = array\" is p = %#x\n", (unsigned int)p);
	j = *(p++);
	printf("The result of \"j = *(p++);\" is j = %d, p = %#x, array=|%d, %d|\n", j, (unsigned int)p, array[0], array[1]);

	j = --*p;
	printf("The result of \"j = --*p;\" is j = %d, p = %#x, array=|%d, %d|\n", j, (unsigned int)p, array[0], array[1]);
	j = --*p++;
	printf("The result of \"j = --*p++;\" is j = %d, p = %#x, array=|%d, %d|\r\n", j, (unsigned int)p, array[0], array[1]);

	// Example of a+++b
	printSectionSeparator(20);
	int a, b, c;
	printf("This example shows the result of \"a+++b\":\n");
	a = 1;
	b = 1;
	printf("a = %d, b = %d\n", a, b);
	c = a+++b;
	printf("The result of \"c = a+++b\" is a = %d, b = %d, c = %d\n", a, b, c);
	a = 1;
	b = 1;
	c = (a++) + b;
	printf("The result of \"c = (a++) + b\" is a = %d, b = %d, c = %d\n", a, b, c);
	printf("So, \"c = a+++b\" is eqaul to \"c = (a++) + b\"\r\n");

	// Verify 4-bit adder
	printSectionSeparator(20);
	printf("Verify 4-bit adder:\n");
	int x, y, result, count;
	char *xbin, *ybin, *rbin;
	count = 0;
	xbin = (char *)calloc(4, sizeof(char));
	ybin = (char *)calloc(4, sizeof(char));
	rbin = (char *)calloc(5, sizeof(char));
	for(x = 0; x < 2; x++)
	{
		getBinaryString(x, 4, xbin);
		for(y = 0; y < 2; y++)
		{
			result = x + y;
			getBinaryString(y, 4, ybin);
			getBinaryString(result, 5, rbin);
			printf("<combination %d> x=%d(b%s), y=%d(b%s), x+y=%d(b%s)\n", (++count), x, xbin, y, ybin, result, rbin);
		}
	}
	free((void *)xbin);
	free((void *)ybin);
	free((void *)rbin);
	printf("\n");

	printSectionSeparator(20);
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}

// This function gets the the binary string
// <NOTE>:
// (1) This function gets the binary string.
//
// (2) dec - decimal number.
//	   num_bits - number of bits in the binary format.
//	   str - binary string.
void getBinaryString(int dec, int num_bits, char *str)
{
	int mask;
	int i;

	mask = 1 << (num_bits - 1);						// Get binary mask (starts from the highest bit)
	for(i = num_bits; i > 0; i--, (mask >>= 1))		// Loop through each bit
	{
		*(str++) = (dec & mask ? '1' : '0');		// Check bit
	}
	*str = '\0';
}

// This function prints section separator
void printSectionSeparator(int n)
{
	int i;
	for(i = 0; i < n; n--)
		printf("=");
	printf("\r\n");
}
