/*
 * Author: Walter
 * Student ID: 1930006025
 * Q1_fixErrors.cpp
 */

/* ignore scanf() unsafe warrning in Visual Studio */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int i = 0;
	char ch;
	scanf("%c", &ch);
	printf("%d is the ASCII code of '%c'\n", ch, ch);
	printf("the value of i is %d\n", i);
	i = ch;
	printf("the value of i is %d\n", i);
	return 0;
}

/*
 * Errors:
 * 1. program did not include stdio.h then use scanf() and printf()
 * 2. function main do not specify a return value
 * 3. passed the value of ch to scanf, but it should be an address
 * 4. last printf statement did not have a comma at the end
 *
 * Warning:
 * 1. unused variable 'j'
 * 2. unused variable 'f'
 * 3. 'i' may be used uninitialized in printf()
 * 4. main function do not have a return statement
 * 5. (Only in Visual Studio) "scanf" function may be unsafe.
 *    Actually, scanf("%c", &ch); only read one char, so it will NOT overflow.
 *    This warrning can be ignore.
 */
