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

//using namespace std;

class Integer {
private:
	ListaDobleEnlazada<Vector>* list;//va a ser mi numero enooorme
	bool negative;
public:
	Integer();//sin parametros
	Integer(string);
	Integer(Integer&);//constructor copia
	Integer& operator = (Integer& int2);//sobrecarga del operador de asignacion
	~Integer();
	/*ayudas*/
	char intTochar(int n);//este lo ocupa
	int charToint(char n);//este lo ocupa
	void parse(string);//pasa de string a Integer

	/*operaciones*/
	//multiplicacion

	Integer& multiplicacion(Integer*);//este lo ocupa
	//divicion

	Integer& dividir(Integer& divisor);
	//suma

	Integer& operator +(Integer&);//suma
	Integer& sumar_nodos(Integer*);
	int sumar_vector_extra(Vector*, int, Integer&);
	int sumar_vectores(Vector*, Vector*, Integer&, int);
	//resta

	Integer& resta(Integer& num2);

	/*operadores*/
	Integer& operator -(Integer&);//resta
	Integer& operator *(Integer&);//multiplica
	Integer& operator /(Integer&);//division
	void operator +=(Integer&);//incremento
	void operator -=(Integer&);//decremento
	void operator *=(Integer&);//multiplicacion propia
	void operator /=(Integer&);//division propia
	bool operator ==(Integer&);//comparacion
	bool operator !=(Integer&);//distinto
	bool operator <(Integer&);//menor
	bool operator <=(Integer&);//menor igual
	bool operator >(Integer&);//mayor
	bool operator >=(Integer&);//mayor igual

	/*metodos de comparaciones*/
	bool comparar_nodos(Integer*); //Recorre la lista
	bool comparar_vectores(Vector* v1, Vector* v2); //Recorre el vector
	bool comparar_nodos_menor(Integer*);
	bool comparar_vectores_menor(Vector*, Vector*);

	/*sets/gets*/
	bool getNegative();
	void setNegative(bool negative);
	ListaDobleEnlazada<Vector>* getList();

	/*metodos para agregar numero al integer*/
	void Agregar(string num);
	void AgregarVerdadero(string num);

	/*meodos para toString */
	string toString();
	void quitarCeros(string &n);

	

	//Integer& factorialCola(Integer& uno, Integer &dos);
	//el verdadero
	Integer& factorial(Integer&);
	
	//siempre positivos
	Integer& fibonacci(Integer&);

	Integer& Combinatoria(Integer& uno, Integer& dos);
	bool Menor(Integer& num);
};
//ostream& operator << (ostream&, Integer&);



#endif // !INTEGER

