#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class Persona {
private:
	string nombre;
	string apellido;
	string correo;

public:
	Persona(string,string,string);
	~Persona();

	string getNom();
	string getAp();
	string getCor();
	string getNombreCompleto();

	void setNom(string);
	void setAp(string);
	void setCorr(string);

	string toString();
	string toString2();
};