#include <stdio.h>
#include <math.h>

typedef struct Point Point;
typedef struct Line Line;
typedef struct Triangle Triangle;

double len_of_tow_points(const Point *p1, const Point *p2);
double len_of_line(const Line *line);
double len_of_triangle(const Triangle *Triangle);

typedef struct Point {
	double x;
	double y;
} Point;

typedef struct Line {
	Point p1;
	Point p2;
} Line;

typedef struct Triangle {
	Point p1;
	Point p2;
	Point p3;
} Triangle;

int main() {
	Point point = {4.0, 11.0};
	Line line = {
		{2.0, 7.0},
		{10.0, 9.0},
	};
	Triangle triangle = {
		{6.0, 5.0},
		{2.0, 0.0},
		{8.0, 3.0},
	};
	printf("length of line is %f\n",
			len_of_line(&line));
	printf("length of triangle is %f\n",
			len_of_triangle(&triangle));
	return 0;
}

double len_of_tow_points(const Point *p1, const Point *p2) {
	return sqrt(
			pow(p1->x - p2->x, 2.0)
			+
			pow(p1->y - p2->y, 2.0)
		   );
}

double len_of_line(const Line *line) {
	return len_of_tow_points(&line->p1, &line->p2);
}

double len_of_triangle(const Triangle *triangle) {
	return len_of_tow_points(&triangle->p1, &triangle->p2)
		+
		len_of_tow_points(&triangle->p1, &triangle->p3)
		+
		len_of_tow_points(&triangle->p2, &triangle->p3);
}
