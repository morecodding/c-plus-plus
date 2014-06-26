/*
 *  DOJO C++ - Online
 * 
 *  Uma iniciativa da +codding
 *  Site: morecodding.azurewebsites.net
 *
 *
 *  File: agenda.cpp
 *  Created on: 26/06/2014
 *  Authors: Igor Costa, Johnathan Fercher, Lucas Marques, Paulo Leite
 */


///////////////////////////////////
//// Definição do Problema
///////////////////////////////////


/*
     Criar utilizando C++ e o paradigma de orientação a objetos:
     1 - Agenda Telefonica:
     [Básico]
     a - Criar a Classe e afins, numero maximo de 5 contatos e salvo em memoria
     b - Implementar Adicionar Contatos
     c - Implementar Listar Contatos
     d - Implementar Buscar Contatos por Numero
     e - Implementar Editar Contatos por Numero
     f - Implementar Excluir Contatos por Numero

     [Intermediário]
     g - Otimizar Código

*/

#include "iostream"
#include "cstdlib"

using namespace std;

struct Contato{
    int numero;
    string nome;
};

class Agenda{
private:
    Contato contatos[5];
    int top;
    int indice;

public:
    Agenda(){
        //contador de contatos.
        top = 0;
    }

	// adiciona um contato
    void adicionarContatos(Contato contato){
        contatos[top] = contato;
        top++;
    }

	// mostra todos os contatos
    void mostrarContatos(){
        for(int i=0; i < top; i++){
            cout<<"\nNome >> "<<contatos[i].nome<< "\nNumero >> "<<contatos[i].numero<<endl;
        }
    }

	// mostra um unico contato
    void mostrarContatos(Contato contato){
        cout<<"\nNome >> "<< contato.nome<< "\nNumero >> "<<contato.numero <<endl;
    }


    //d - Implementar Buscar Contatos por Numero
    Contato buscar(int num){
        Contato c;
        for(int i = 0; i < top; i++){
            if(contatos[i].numero == num){
                c =  contatos[i];
                indice = i;
                return c;
            }
        }
        return c;
    }

    // e - Implementar editar contatos por numero
    void editarContato(int numero){
		buscar(numero);
		cout << "Insira um nome: ";
		cin >> contatos[indice].nome;
		cout << "Insira um numero: ";
		cin >> contatos[indice].numero;
    }

    // f - Implementar excluir contatos por numero
    void excluirContato(int numero){
      for(int i = 0; i < top; i++){
		  if(numero == contatos[i].numero){
		      for(int j = i; j <= (top-1) ; j++){
		          contatos[j] = contatos[j+1];
		      }
		  }
	  }
      top--;
    }
};



int main(){
    Agenda a;
    Contato c, c1, c2, c3;
    int n;

    c.numero = 1;
    c.nome = "John";

    c1.numero = 2;
    c1.nome = "Hebert";

    c2.numero = 3;
    c2.nome = "Igor";

    c3.numero = 4;
    c3.nome = "Lucas";

    //adiciona um contato
    a.adicionarContatos(c);
    a.adicionarContatos(c1);
    a.adicionarContatos(c2);
    a.adicionarContatos(c3);

	// mostra os contatos
    a.mostrarContatos();

	// edita os contatos
    a.editarContato(4);

	// mostra um unico contato
    a.mostrarContatos(1);
}
