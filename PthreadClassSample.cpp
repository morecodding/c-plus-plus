/**
*   Create by Lucas Marques
*   Brief: Usando pthread com metodos em classes com C++
*   ~  para compilar use: g++ PthreadClassSample.cpp -o PthreadClassSample -w -lpthread
*/

#include <iostream>
#include <pthread.h>

using namespace std;

class PthreadClassSample
{
public:
	PthreadClassSample(){}
	~PthreadClassSample(){}

	void *printar(void){
		cout << "estou printando \n" << endl;
	}

	static void *printar_thread(void *arg){
		return ((PthreadClassSample *)arg)->printar();
	}
};

main(){
	PthreadClassSample c;

	pthread_t t1;
	int ct1;

	ct1= pthread_create(&t1, NULL, &PthreadClassSample::printar_thread, &c);

	pthread_join(t1, NULL);
}
