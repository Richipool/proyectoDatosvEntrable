#include <iostream>
#include <sstream>
#include "Integer.h"
#include "Lista_Doble.h"
#include "Vector.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
	Integer* prueba =  new Integer("78");
	Integer* prueba2 = new Integer("54");

	/*Integer* aux = new Integer(prueba->fibonacci(*prueba2));
	cout << aux->toString()<<endl;*/
	//Integer nuevo = (*prueba)-(*prueba2);
	//Integer nuevo = (*prueba)/(*prueba2);
	//cout << nuevo.toString()<<endl;
	//nuevo += *prueba;

	//(*prueba2) *= (*prueba);
	//cout << prueba2->toString();
	if (*prueba < *prueba2) {
		cout << "good";
	}
	else
		cout << "Fx1000";




	delete prueba;
	delete prueba2;
	cout << endl << endl << endl;
	cin.get();
}
