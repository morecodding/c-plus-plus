#include <stdio.h>


/**
	Exemplo de ponteiro para função
*/


int somar(int x, int y){
	return x + y;
}

void print(int x, int y){
	printf("\n%d - %d\n\n", x, y);
}

int main(int a, char **b){
	int (*k)(int, int) = somar;
	printf("\n%d\n" ,k(2, 2)); 

	void (*as)(int, int) =  print;
	as(2, 2);
	return 0;
}
