#ifndef INTEGER
#define INTEGER

#include <string>
#include<iostream>
#include "Vector.h"
#include "Lista_Doble.h"

#define ZERO 0
#define UNO 1

using std::string;
using std::cout;
using std::to_string;

class Integer {
private:
	ListaDobleEnlazada<Vector>* lista;//va a ser mi numero enooorme
	bool variable_negativa;
public:
	Integer();//sin parametros
	Integer(string);
	Integer(Integer&);//constructor copia
	Integer& operator = (Integer& int2);//sobrecarga del operador de asignacion
	~Integer();
	/*ayudas*/
	char PasarIntChar(int n);//este lo ocupa
	int PasarCharInt(char n);//este lo ocupa
	void Parse(string);//pasa de string a Integer

	/*operaciones*/
	//Multiplicacion

	Integer& Multiplicacion(Integer*);//este lo ocupa
	//division

	Integer& Dividir(Integer& divisor);
	//suma

	Integer& operator +(Integer&);//suma
	Integer& SumarPorNodos(Integer*);
	int SumarVectorSiSePasa(Vector*, int, Integer&);
	int SumaVectores(Vector*, Vector*, Integer&, int);
	//Resta

	Integer& Resta(Integer& num2);

	/*operadores*/
	Integer& operator -(Integer&);//Resta
	Integer& operator *(Integer&);//multiplica
	Integer& operator /(Integer&);//division
	void operator +=(Integer&);//incremento
	void operator -=(Integer&);//decremento
	void operator *=(Integer&);//Multiplicacion propia
	void operator /=(Integer&);//division propia
	bool operator ==(Integer&);//comparacion
	bool operator !=(Integer&);//distinto
	bool operator <(Integer&);//menor
	bool operator <=(Integer&);//menor igual
	bool operator >(Integer&);//mayor
	bool operator >=(Integer&);//mayor igual

	/*metodos de comparaciones*/
	bool ComparaPorNodos(Integer*); //Recorre la lista
	bool ComparaPorVectores(Vector* v1, Vector* v2); //Recorre el vector
	bool NodoMenor(Integer*);
	bool VectorMenor(Vector*, Vector*);

	/*sets/gets*/
	bool GetNegativa();
	void SetNegativa(bool variable_negativa);
	ListaDobleEnlazada<Vector>* getList();

	/*metodos para agregar numero al integer*/
	void Agregar(string num);
	void AgregarResultado(string num);

	/*meodos para ImprimeNumero */
	string ImprimeNumero();
	void QuitaCerosExtra(string &n);

	

	//Integer& factorialCola(Integer& uno, Integer &dos);
	//el verdadero
	Integer& Factorial(Integer&);
	
	//siempre positivos
	Integer& Fibonacci(Integer&);

	Integer& Combinatoria(Integer& uno, Integer& dos);
	bool Menor(Integer& num);
};




#endif // !INTEGER

