#ifndef INTEGER
#define INTEGER
#define CERO 0
#define UNO 1
#include <string>

#include "Vector.h"
#include "Lista_Doble.h"

using std::string;
using std::cout;
using std::to_string;
using std::reverse;


class Integer {
private:
	ListaDobleEnlazada<Vector>* lista;
	bool varible_negativo;
public:
	Integer();
	Integer(string);
	Integer(Integer&);
	Integer& operator = (Integer& int2);
	~Integer();
	char PasarIntChar(int n);
	int PasarCharInt(char n);
	Integer& MultiplicacionInteger(Integer*);

	bool GetVaribleNegativa();
	void SetNegativo(bool negative);
	ListaDobleEnlazada<Vector>* GetLista();
	void AgregarNormal(string num);
	void AgregarNumeroCorrecto(string num);

	Integer& operator +(Integer&);
	Integer& SumarNodos(Integer*);
	int SumarVectores(Vector *,Vector*,Integer&, int);
	int SumarVectoresSiSePasa(Vector*, int, Integer&);
	Integer& operator -(Integer&);
	 
	Integer& operator *(Integer&);
	Integer& operator /(Integer&);

	


	void operator +=(Integer&);
	void operator -=(Integer&);
	void operator *=(Integer&);
	void operator /=(Integer&);


	bool operator ==(Integer&) ;
	bool CompararNodosLista(Integer*); 
	bool CompararVectoresPorNodo(Vector* v1, Vector* v2);

	bool operator !=(Integer&);
	bool operator <(Integer&);
	bool CompararMenoresNodosLista(Integer*);
	bool CompararMenorVectoresPorNodoLista(Vector*, Vector*);
	bool operator <=(Integer&);
	bool operator >(Integer&);
	bool operator >=(Integer&);

	void Parse(string);

	string ImprimirNumero();
	void EliminarCeros(string &n);

	Integer& DividirNumero(Integer& divisor);

	Integer& resta(Integer& num2);
	
	Integer& factorial(Integer&);
	
	Integer& fibonacci(Integer&);

	Integer& Combinatoria(Integer& uno, Integer& dos);

};

#endif // !INTEGER

