#include <stdio.h>

float get_highest(float a[], int n);

int main() {
	float value[4] = {2.5, 1, 1.2, 5.2};
	float highest = get_highest(value, 4);
	printf("highest number is %.1f\n", highest);
	return 0;
}

float get_highest(float a[], int n) {
	float highest = a[0];
	for (int i=0; i<n; i++) {
		if (highest < a[i]) {
			highest = a[i];
		}
	}
	return highest;
}
	
