#include <iostream>
#include <fstream>
#include <iomanip>
#include"Lista.h"
using namespace std;


Lista* empleados = new Lista();
Nodo* p = new Nodo();		//auxiliar node to add to the list


int main()
{

	//archivos
	string Fpersonas = "Fpersonas.txt";

	ifstream fpersonas;
	fpersonas.open(Fpersonas);
		while (!fpersonas.eof())
		{
			string name;
			fpersonas >> name;

			string Lname;
			fpersonas >> Lname;

			string mail;
			fpersonas >> mail;

			Persona* e = new Persona(name, Lname, mail);
			Nodo* p = new Nodo(e, NULL);
			empleados->addInicio(p);
		}
		fpersonas.close();

	//
	bool end = false;
	
	while (!end)
	{
		cout << "-----------------------WELCOME-----------------------" << endl << endl;


		cout << "1)	add employee" << endl;
		cout << "2)	edit employee" << endl;
		cout << "3)	remove employee" << endl;
		cout << "4)	save files" << endl;

		int option;
		cin >> option;
		switch (option)
		{
		case 1: {
			system("cls");
			cout << "-------------------ADD EMPLOYEE-------------------" << endl << endl << endl;
			cout << "Name: " << endl;
			string name;
			cin >> name;

			cout << "Lastname: " << endl;
			string lastname;
			cin >> lastname;

			cout << "Email: " << endl;
			string email;
			cin >> email;

			Persona* e = new Persona(name, lastname, email);
			Nodo* p = new Nodo(e,NULL);
			empleados->addInicio(p);

			cout<<endl<<endl << "Employee added succesfully" << endl;
			system("pause");
			system("cls");
		}
			break;
		case 2: {
			system("cls");
			cout << "-------------------EDIT EMPLOYEE-------------------" << endl << endl << endl;
			cout << "Select an emplyee: "<<endl;
			cout<<empleados->toString()<<endl;

			int select;
			cin >> select;
			cout << endl;
			while (select<0 || select>empleados->cuentaNodos())
			{

				cout << endl << "Select an emplyee: "<<endl;
				empleados->toString();
				cin >> select;
				cout << endl;
			}

			cout << "This is the employe infomration:" << endl;
			cout << empleados->getNodo(select)->getPersona()->toString() << endl;
			system("pause");

			system("cls");
			cout << "-------------------EDIT EMPLOYEE-------------------" << endl << endl << endl;
			cout << "please add the new information" << endl << endl;

			cout << "Name: " << endl;
			string name;
			cin >> name;

			cout << "Lastname: " << endl;
			string lastname;
			cin >> lastname;

			cout << "Email: "<<endl;
			string email;
			cin >> email;

			empleados->getNodo(select)->getPersona()->setNom(name);
			empleados->getNodo(select)->getPersona()->setAp(lastname);
			empleados->getNodo(select)->getPersona()->setCorr(email);


			cout << "Employee edited succesfully" << endl;
			system("pause");
			system("cls");
		}
			break;
		case 3: {
			system("cls");
			cout << "-------------------REMOVE EMPLOYEE-------------------" << endl << endl << endl;
			cout << "Select an emplyee: " << endl;
			cout << empleados->toString() << endl;

			int select;
			cin >> select;
			cout << endl;
			while (select<0 || select>empleados->cuentaNodos())
			{

				cout << endl << "Select an emplyee: " << endl;
				empleados->toString();
				cin >> select;
				cout << endl;
			}
			if (empleados->cuentaNodos() == 1) {
				empleados->Borrar();
			}
			else {
				empleados->Eliminar(select);
			}

			cout << "Employee removed succesfully" << endl;
			system("pause");
			system("cls");
		}
			break;
		case 4:
		{
			ofstream fpersonas;
			fpersonas.open(Fpersonas);
			if (fpersonas.fail()) {
				cout << "error trying to open the file." << endl;
			}
			else {
				fpersonas << empleados->toString2();
				cout << "Employes saved" << endl;
			}
			fpersonas.close();


		}

			break;
		default:
			cout << "try with another option, that wasn´t in the table" << endl<<endl;
			system("pause");
			system("cls");
			break;
		}
	}

}

