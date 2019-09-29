#include <iostream>
#include <sstream>
#include "Integer.h"
#include "Lista_Doble.h"
#include "Vector.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
	cout << "Proyecto Numeros Integer.\n";
	cout << "Estudiantes:\n RICHARD VARGAS VADO 402380714\n LEONARDO BALDARES GOMEZ 304950273\n CRISTOPHER ARCE DIAZ 702680366\n";
	cout << "Descripcion:\n";
	cout << "Este proyecto permite realizar operaciones con numero enormes incluso mas grandes que las soportadas por \nel long long int de c++\n"
		<< "Las operaciones permitidas son la suma, Resta, multiplicacion, divicion, comparaciones, asignaciones, factorial,\nfibonacci, combinatoria\n";
	system("pause");
	system("cls");
	// Constructores:

	int salir;
	do {
		cout << "Menu de operaciones.\n";
		cout << "1- suma.\n2- resta.\n3- multiplicacion.\n4- Division.\n";
		cout << "5- Comparar ==.\n6- Comparar !=.\n7- Comparar <=.\n8- Comparar >=.\n9- Comparar <.\n10- Comparar >.\n";
		cout << "11- Factorial.\n12- Fibonacci.\n13- Combinatoria.\n";
		cout << "Digite 0 para salir\n";
		cout << "Digite el numero de la operacion que desea realizar: ";
		cin >> salir;
		system("pause");
		system("cls");
		switch (salir)
		{
		case 1: {
			cout << "Suma de Integers uwu\n";
			string numero1;
			string numero2;
			Integer* integer1;
			Integer* integer2;
			cout << "Digite numero 1 ";
			cin >> numero1;
			cout << "Digite numero 2 ";
			cin >> numero2;
			integer1 = new Integer(numero1);
			integer2 = new Integer(numero2);
			cout << numero1 << " + " << numero2 << endl;
			cout << (*integer1 + *integer2).ImprimeNumero() << endl;
			system("pause");
			system("cls");
			delete integer1;
			delete integer2;
			break;
		}
		case 2: {
			cout << "Restar Integer uwu\n";
			string numero1;
			string numero2;
			Integer* integer1;
			Integer* integer2;
			cout << "Digite numero 1 ";
			cin >> numero1;
			cout << "Digite numero 2 ";
			cin >> numero2;
			integer1 = new Integer(numero1);
			integer2 = new Integer(numero2);
			cout << numero1 << " - " << numero2 << endl;
			cout << (*integer1 - *integer2).ImprimeNumero() << endl;
			system("pause");
			system("cls");
			delete integer1;
			delete integer2;
			break;
		}
		case 3: {
			cout << "Multiplicar Integer uwu\n";
			string numero1;
			string numero2;
			Integer* integer1;
			Integer* integer2;
			cout << "Digite numero 1 ";
			cin >> numero1;
			cout << "Digite numero 2 ";
			cin >> numero2;
			integer1 = new Integer(numero1);
			integer2 = new Integer(numero2);
			cout << numero1 << " * " << numero2 << endl;
			cout << (*integer1 * *integer2).ImprimeNumero() << endl;
			system("pause");
			system("cls");
			delete integer1;
			delete integer2;
			break;
		}
		case 4: {
			cout << "Dividir Integer uwu\n";
			string numero1;
			string numero2;
			Integer* integer1;
			Integer* integer2;
			cout << "Digite numero 1 ";
			cin >> numero1;
			cout << "Digite numero 2 ";
			cin >> numero2;
			integer1 = new Integer(numero1);
			integer2 = new Integer(numero2);
			cout << numero1 << " / " << numero2 << endl;
			cout << (*integer1 / *integer2).ImprimeNumero() << endl;
			system("pause");
			system("cls");
			delete integer1;
			delete integer2;
			break;
		}
		case 5: {
			cout << "Comparar == Integer uwu\n";
			string numero1;
			string numero2;
			Integer* integer1;
			Integer* integer2;
			cout << "Digite numero 1 ";
			cin >> numero1;
			cout << "Digite numero 2 ";
			cin >> numero2;
			integer1 = new Integer(numero1);
			integer2 = new Integer(numero2);
			cout << numero1 << " == " << numero2 << endl;
			if ((*integer1 == *integer2)) {
				cout << "Son iguales\n";
			}
			else {
				cout << "No son iguales\n";
			}
			system("pause");
			system("cls");
			delete integer1;
			delete integer2;
			break;
		}
		case 6: {
			cout << "Comparar != Integer uwu\n";
			string numero1;
			string numero2;
			Integer* integer1;
			Integer* integer2;
			cout << "Digite numero 1 ";
			cin >> numero1;
			cout << "Digite numero 2 ";
			cin >> numero2;
			integer1 = new Integer(numero1);
			integer2 = new Integer(numero2);
			cout << numero1 << " != " << numero2 << endl;
			if ((*integer1 != *integer2)) {
				cout << "Son distintos\n";
			}
			else {
				cout << "No son distintos\n";
			}
			system("pause");
			system("cls");
			delete integer1;
			delete integer2;
			break;
		}
		case 7: {
			cout << "Comparar <= Integer uwu\n";
			string numero1;
			string numero2;
			Integer* integer1;
			Integer* integer2;
			cout << "Digite numero 1 ";
			cin >> numero1;
			cout << "Digite numero 2 ";
			cin >> numero2;
			integer1 = new Integer(numero1);
			integer2 = new Integer(numero2);
			cout << numero1 << " <= " << numero2 << endl;
			if ((*integer1 <= *integer2)) {
				cout << "El numero 1 es menor o igual al otro numero 2\n";
			}
			else {
				cout << "El numero 2 es menor\n";
			}
			system("pause");
			system("cls");
			delete integer1;
			delete integer2;
			break;
		}
		case 8: {
			cout << "Comparar >= Integer uwu\n";
			string numero1;
			string numero2;
			Integer* integer1;
			Integer* integer2;
			cout << "Digite numero 1 ";
			cin >> numero1;
			cout << "Digite numero 2 ";
			cin >> numero2;
			integer1 = new Integer(numero1);
			integer2 = new Integer(numero2);
			cout << numero1 << " >= " << numero2 << endl;
			if ((*integer1 >= *integer2)) {
				cout << "El numero 1 es mayor o igual al otro numero 2\n";
			}
			else {
				cout << "El numero 2 es mayor\n";
			}
			system("pause");
			system("cls");
			delete integer1;
			delete integer2;
			break;
		}
		case 9: {
			cout << "Comparar < Integer uwu\n";
			string numero1;
			string numero2;
			Integer* integer1;
			Integer* integer2;
			cout << "Digite numero 1 ";
			cin >> numero1;
			cout << "Digite numero 2 ";
			cin >> numero2;
			integer1 = new Integer(numero1);
			integer2 = new Integer(numero2);
			cout << numero1 << " < " << numero2 << endl;
			if ((*integer1 < *integer2)) {
				cout << "El numero 1 es menor\n";
			}
			else {
				cout << "El numero 2 es menor o igual al otro numero 1\n";
			}
			system("pause");
			system("cls");
			delete integer1;
			delete integer2;
			break;
		}
		case 10:{
			cout << "Comparar > Integer uwu\n";
			string numero1;
			string numero2;
			Integer* integer1;
			Integer* integer2;
			cout << "Digite numero 1 ";
			cin >> numero1;
			cout << "Digite numero 2 ";
			cin >> numero2;
			integer1 = new Integer(numero1);
			integer2 = new Integer(numero2);
			cout << numero1 << " > " << numero2 << endl;
			if ((*integer1 > *integer2)) {
				cout << "El numero 1 es mayor\n";
			}
			else {
				cout << "El numero 2 es mayor o igual al otro numero 1\n";
			}
			system("pause");
			system("cls");
			delete integer1;
			delete integer2;
			break; 
		}
		case 11: {
			cout << "Factorial Integers uwu\n";
			string numero1;
			string numero2;
			Integer* integer1;
			cout << "Digite:\n";
			cout << "!"; cin >> numero1; cout << endl;
			cout << "Resultado: \n";
			integer1 = new Integer(numero1);
			cout << (integer1->Factorial(*integer1)).ImprimeNumero() << endl;
			system("pause");
			system("cls");
			delete integer1;
			break;
		}
		case 12: {
			cout << "Fibonacci Integers uwu\n";
			string numero1;
			string numero2;
			Integer* integer1;
			cout << "Digite:\n";
			cout << "Fibonacci de: "; cin >> numero1; cout << endl;
			cout << "Resultado: \n";
			integer1 = new Integer(numero1);
			cout<<(integer1->Fibonacci(*integer1)).ImprimeNumero()<<endl;
			system("pause");
			system("cls");
			delete integer1;
			break;
		}
		case 13: {
			cout << "Combinatoria Integers uwu\n";
			string numero1;
			string numero2;
			Integer* integer1;
			Integer* integer2;
			cout << "Digite numero 1 ";
			cin >> numero1;
			cout << "Digite numero 2 ";
			cin >> numero2;
			cout << "C" << numero1 << ","<<numero2 << endl;
			cout << "Resultado: \n";
			integer1 = new Integer(numero1);
			integer2 = new Integer(numero2);
			cout << (integer1->Combinatoria(*integer1, *integer2)).ImprimeNumero() << endl;
			system("pause");
			system("cls");
			delete integer1;
			delete integer2;
			break;
		}
		case 0: {
			cout << "Gracias por Usar el programa UwU\n";
			break;
		}
		default:
			cout << "Opcion invalida intentelo de nuevo >:3";
			system("pause");
			system("cls");
			break;
		}
	} while (salir != 0);
	cout << endl << endl << endl;
	cin.get();
}
