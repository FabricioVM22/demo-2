#pragma once
#include <iostream>
#include <sstream>
#include "Nodo.h"
using namespace std;
class Lista {
	Nodo* raiz;
public:
	Lista() { raiz = NULL; };
	bool vacia();
	int cuentaNodos();
	string toString();
	void addInicio(Nodo*);
	void addFinal(Nodo*);
	void addPosicion(Nodo*, int);
	Nodo* getNodo(int);
	int iLookingForName(string);
	void Borrar();
	void Eliminar(int);

	string toString2();
};