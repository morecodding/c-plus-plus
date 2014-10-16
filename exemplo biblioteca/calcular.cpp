#include "calcular.h"

Calcular::Calcular(){

}

Calcular::~Calcular(){

}


void Calcular::somar(int a, int b){
	cout << "soma: " << a + b << endl;
}

void Calcular::subtrair(int a, int b){
	cout << "subtracao: " << a - b << endl;
}

void Calcular::fazTudo(int a, int b){
	somar(a, b);
	subtrair(a, b);
}
