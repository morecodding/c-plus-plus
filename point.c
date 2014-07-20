/*
  Create by Lucas Marques
  Resume: Starting a Oriented Objects Programming with C language 
  
  Brief of this file: Creating a sample struct with function and constructor
*/


#include <stdio.h>

typedef int (*Soma)(struct Point*);

typedef struct Point
{
	int X;
	int Y;

	Soma soma;

} Point;


Point* Point_new(int x, int y){
	Point* point = malloc(sizeof(Point));
	point->X = x;
	point->Y = y;
	return point;
}

int somar(Point *thisPoint){
	return (thisPoint->X + thisPoint->Y);
}

int main(int argc, char const *argv[])
{
	Point* p = Point_new(10, 10);
	p->soma = somar;
	printf("Resultado soma: %d\n", p->soma(p));
	return 0;
}
