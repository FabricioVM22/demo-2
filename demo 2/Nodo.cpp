#include "Nodo.h"
Nodo::Nodo(){
	ptr = NULL;
	sig = NULL;
}
Nodo::Nodo(Persona *per, Nodo* s){
	ptr=per;
	sig=s;
}
Nodo::~Nodo(){
	delete ptr;
}
Persona* Nodo::getPersona(){
	return ptr;
}
Nodo* Nodo::getSiguiente(){
	return sig;
}
void Nodo::setPersona(Persona *can){
	ptr = can;
}
void Nodo::setSiguiente(Nodo* s){
	sig=s;
}
		
