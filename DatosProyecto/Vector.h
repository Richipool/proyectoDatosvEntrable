#ifndef VECTOR
#define VECTOR
#define SIZE 3

#include <iostream>
#include <sstream>

using std::ostream;
using std::string;
using std::stringstream;
using std::to_string;

class Vector {
private:
	int cant;
	int vect[SIZE];

public:
	Vector();
	~Vector();
	void Insertar(int numero);
	int GetNumero(int i);
	void SetNumero(int pos, int val);
	string toString();
	int GetCantidad();
	string AgregarCeros(string n);
};
ostream& operator << (ostream&, Vector&);

#endif // !VECTOR