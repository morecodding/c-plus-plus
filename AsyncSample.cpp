/**
*  Author: Lucas Marques
*  Date: 2014/08/01
*
*  Obs: Para compilar use: g++ AsyncSample.cpp -o AsyncSample -pthread -std=c++11
**/

#include <iostream>
#include <future>
#include <string>

using namespace std;

bool e_primo(int x){
	for (int i = 2; i < x; ++i)
		if(x%i==0)
			return false;
	return true;
}

main(){
	future<bool> ft = async(e_primo,3121112323);
	cout << "checking..." << endl;
	bool result = ft.get();
	if(result)
		cout << "e primo" << endl;
	else
		cout << "nao e primo" << endl;
}
