/*
 * author: Walter 1930006025
 * Class Exercise
 * write my own strcmp and strlen
 */

#include <stdio.h>

int my_strlen(const char *);
int my_strcmp(const char *, const char *);
void show_cmp(const char *, const char *);

int main() {
	char str_1[] = "hhhhhhhhhhhhhhhhhhh";
	char str_2[] = "hhhhhhhhhhhhhhhhhhh";
	char str_3[] = "ooooooooooooooooooo";
	char str_4[] = "asdfasdfasfasfd";

	show_cmp(str_1, str_2);
	show_cmp(str_1, str_3);
	show_cmp(str_1, str_4);
	show_cmp(str_4, str_1);

	return 0;
}


void show_cmp(const char *s1, const char *s2) {
	printf("%s compare with %s, result: %s\n",
			s1, s2, my_strcmp(s1, s2) ? "True" : "False");
}
int my_strlen(const char *str) {
	int len = 0;
	for (; str[len]; len++) {}
	return len;
}

int my_strcmp(const char *dest, const char *src) {
	int len_src = my_strlen(src);
	int len_dest = my_strlen(dest);
	if (!(len_src == len_dest)) {
		return 0;
	}

	for (int i; i<len_dest; i++) {
		if (!(src[i] == dest[i])) {
			return 0;
		}
	}
	return 1;
}

