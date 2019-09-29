/*
archivo<Vector.cpp>
Autores<
-RICHARD VARGAS VADO 402380714
-LEONARDO BALDARES GOMEZ 304950273
-CRISTOPHER ARCE DIAZ 702680366
>
Descripcion<vector estatico de 3 posiciones para la divicion de los numeros>
*/
#include "Vector.h"


//constructor 
Vector::Vector() {
	cant = 0;
	for (int i = 0; i < SIZE; i++) {
		vect[i] = -1;
	}
}

//destructor
Vector::~Vector() {	}

//agrega un valor dentro del vector
void Vector::Insertar(int numero) {
	vect[cant++] = numero;
}

//retorna el valor de la posicion del vector que se le pasa por parametro
int Vector::GetNumero(int i) {
	return vect[i];
}

//se le pone un valor a una posicion del vector que se le pase por parametro
void Vector::SetNumero(int pos, int val){
	vect[pos] = val;
}

//imprime los valores del vector
string Vector::ImprimirNumero() {
	stringstream s;
	for (int i = cant-1; i >= 0; i--) {
		s << AgregarCeros(to_string(vect[i]));
	}
	return s.str();
}

//retorna a cantidad de elementos que hay dentro del vector
int Vector::GetCantidad(){
	return cant;
}

// sobrecarga del operador << de salida
ostream & operator<<(ostream & salida,  Vector &d){
	salida << d.ImprimirNumero();
	return salida;
}

//completa con ceros en la izquierda el vector
string Vector::AgregarCeros(string n){
	if (n.length() < 9) {
		for (int i = 0; i < n.length() - 9; i++) {
				n = "0" + n;
		}
	}
	return n;
}