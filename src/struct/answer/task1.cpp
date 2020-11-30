/*****
Author:Nina
Date: 2020/04/27
Description:
Declare structures Point, Line and Triangle (refer to the lecture)
and define the point, line and triangle in the following picture.
Calculate the length of the line and the circumference of the
triangle

• Use sqrt() function to calculate square root 
• #include <math.h> should be added at the beginning of the program)
• The coordinates of points should be declared as float or double type.

************/

#include<stdio.h>
#include<math.h>// don't forget to add math.h
struct Point {  // The stucture is to store the coordinates of points
	double x, y; // x is the x-axis value, y is the y-axis value
};//Please always define the structure outside the main function, so that each sub function can use it.

struct Line{// the stucture is to store the point belong to the line
	Point p1, p2;
};

struct Triangle{// the stucture is to store the point belong to the triangle
	Point p1, p2, p3;
};


double lengthOfLine(Point, Point);// the subfunction is to compute the length of each line, notice the input type is Point

int main() {

	Line line = {(2,7),(10,9)};//Declare a line, and initialize it
	Triangle tri = {(6,5),(2,0),(8,3)};//Declare a line, and initialize it

	double lineLen = lengthOfLine(line.p1, line.p2);// call the subfunction, notice the input variables

	double triCir = lengthOfLine(tri.p1,tri.p2) + lengthOfLine(tri.p1,tri.p3) + lengthOfLine(tri.p2,tri.p3);// sum up all the line's length

	printf("i = %.2f\n", lineLen);//output the line length
	printf("j = %.2f\n", triCir);//output the triangle circumference
	return 0;
}

double lengthOfLine(Point a, Point b) {

	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.x - b.y));// compute the length, notice that the input of sqrt function must be double or float
}
