#pragma once
#include <iostream>
#include <sstream>
#include"Persona.h"
using namespace std;
class Nodo {
	Persona* ptr;
	Nodo* sig;
public:
	Nodo();
	Nodo(Persona*, Nodo*);
	~Nodo();
	void setPersona(Persona*);
	void setSiguiente(Nodo*);
	Persona* getPersona();
	Nodo* getSiguiente();
};