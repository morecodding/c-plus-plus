#include <iostream>
#include <vector>
using namespace std;

class S{
public:
	int a;
	S(){
		a = 10;
	}
};


void asf(vector<S>& a){
	for(int i = 0; i < 3; i++)
		cout << a[i].a << endl;
}

void asdf(vector<S>& aas){
	asf(aas);
}

int main(int a, char** b){
	vector<S> s;
	for( int i =0; i < 3; i++){
		S as;
		s.push_back(as);
	}
	asdf(s);
	return 0;
}
