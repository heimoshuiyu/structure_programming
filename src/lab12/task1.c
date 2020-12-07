/*
 * Programmer: Walter
 * Student ID: 1930006025
 * Date: 2020.12.7
 * Task no: Week_11_Task_1
 * Requirements:
 * Modify the following program so that
 * values of a and b can be exchanged.
 */

#include <stdio.h>
void exchange(int *x, int *y);
int main() {
  int a = 10, b = 20;
  printf("before exchange: a = %d, b = %d\n", a, b);
  exchange(&a, &b);
  printf("after exchange: a = %d, b = %d\n", a, b);
  return 0;
}
void exchange(int *x, int *y) {
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}
