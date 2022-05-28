#include "Persona.h"

Persona::Persona(string nom, string ape, string cor)
{
	nombre = nom;
	apellido = ape;
	correo = cor;
}

Persona::~Persona()
{
}

string Persona::getNom()
{
	return nombre;
}

string Persona::getAp()
{
	return apellido;
}

string Persona::getCor()
{
	return correo;
}

string Persona::getNombreCompleto()
{
	stringstream s;
	s << nombre << " " << apellido;
	return s.str();
}

void Persona::setNom(string nom)
{
	nombre = nom;
}

void Persona::setAp(string ap)
{
	apellido = ap;
}

void Persona::setCorr(string corr)
{
	correo = corr;
}

string Persona::toString()
{
	stringstream s;
	s << "Name: " << nombre << endl;
	s << "Lastname: " << apellido << endl;
	s << "Email: " << correo << endl;
	return s.str();
}


