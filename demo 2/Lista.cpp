#include "Lista.h"
#include <sstream>
#include <cstring>

bool Lista::vacia(){
	if(raiz != NULL)
		return false;
	else
		return true;
}

int Lista::cuentaNodos(){
	int i=0;
	Nodo* temp = raiz;
	while (temp != NULL) {
		i=i+1;
		temp = temp->getSiguiente();
	}
	return i;
}

void Lista::addInicio(Nodo* p){
	Nodo *temp = p;
	if(vacia()){
		raiz = temp;
	}
	else{
		temp->setSiguiente(raiz);
		raiz = temp;
	}
}
void Lista::addFinal(Nodo* p){
	Nodo *temp = p;
	if(vacia()){
		raiz = temp;
	}
	else{
		Nodo *auxi;
		auxi = raiz;
		while(auxi->getSiguiente() != NULL){
			auxi = auxi->getSiguiente();
		}
		auxi=temp;
	}
}


void Lista::addPosicion(Nodo *p, int pos){
	Nodo *temp = p;
	Nodo *auxi1, *auxi2=NULL;
	if(vacia()){
		raiz = temp;
	}
	else{
		if(pos == 1)
			addInicio(temp);
		if(pos == (cuentaNodos()+1))
			addFinal(temp);
		if(pos > 1 && (pos < (cuentaNodos()+1))){
			
			auxi1 = raiz;
			for(int i=1; i<pos; i++)
			{
				auxi2 = auxi1;
				auxi1 = auxi1->getSiguiente();
			}
			auxi2->setSiguiente(temp);
			temp->setSiguiente(auxi1);
		}
		if(pos < 1 || pos > (cuentaNodos()+1))
		{
			return;
		}
		   
		
	}
}

Nodo* Lista::getNodo(int pos)
{
	Nodo* auxi;
	auxi = raiz;
	if(pos > 0 && pos <= cuentaNodos())
		for(int i=1; i<pos; i++)
			auxi = auxi->getSiguiente();
		return auxi;
	
	
}

int Lista::iLookingForName(string wanted)
{
	int encontrado = 1;
	Nodo *auxi;
	auxi=raiz;
	while(auxi != NULL)
	{
		if(auxi->getPersona()->getNom() == wanted)
			return encontrado;
		encontrado++;
		auxi = auxi->getSiguiente();
	}
	return -1;
}

void Lista::Borrar()
{
	Nodo *auxi;
	while(raiz != NULL)
	{
		auxi = raiz;
		raiz = raiz->getSiguiente(),
		delete(auxi);
	}
}

void Lista::Eliminar(int pos)
{
	Nodo *auxi1, *auxi2=NULL;
	auxi1=raiz;
	for(int i=0; i<=pos; i++)
	{
		auxi2=auxi1;
		auxi1=auxi1->getSiguiente();
	}
	auxi2->setSiguiente(auxi1->getSiguiente());
	delete(auxi1);
}
string Lista::toString2()
{
	stringstream s;
	Nodo* auxi;
	auxi = raiz;
	while (auxi != NULL)
	{
		s << auxi->getPersona()->getNom() << endl;
		s << auxi->getPersona()->getAp() << endl;
		s << auxi->getPersona()->getCor() << endl;
		auxi = auxi->getSiguiente();
	}
	return s.str();
}
string Lista::toString()
{
	stringstream s;
	Nodo *auxi;
	auxi = raiz;
	int contador = 0;
	if(auxi == NULL)
		s << "theres no employes added now " << endl;
	while(auxi != NULL)
	{
		s << contador<<") "<<endl;
		s << auxi->getPersona()->toString()<<endl;
		auxi = auxi->getSiguiente();
		contador++;
	}

	return s.str();
}
