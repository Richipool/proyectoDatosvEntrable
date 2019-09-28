#ifndef LISTA_SIMPLE_H
#define LISTA_SIMPLE_H

#include <iostream>
#include <sstream>

using std::stringstream;
using std::string;

template <class T>
struct NodoDoble {
	T* objeto;
	NodoDoble<T>* anterior;
	NodoDoble<T>* siguiente;
};

template <class T>
class ListaDobleEnlazada {
private:
	NodoDoble<T>* inicio;
	NodoDoble<T>* final;
	int tam;
public:
	ListaDobleEnlazada();
	virtual ~ListaDobleEnlazada();
	virtual bool Agregar(T*);
	virtual bool Vacia();
	virtual string Mostrar();
	virtual string MostrarListaInvertida();
	virtual int GetTam();
	virtual NodoDoble<T>* GetInicio();
	virtual NodoDoble<T>* GetFinal();
};

//retorna el final de la lista
template <class T>
NodoDoble<T>* ListaDobleEnlazada<T>::GetFinal() {
	return final;
}

//retorna el inicio de la lista 
template <class T>
NodoDoble<T>* ListaDobleEnlazada<T>::GetInicio() {
	return inicio;
}

//retorna el tamano de la lista
template <class T>
int ListaDobleEnlazada<T>::GetTam() {
	return tam;
}

//constructor default de la lista
template <class T>
ListaDobleEnlazada<T>::ListaDobleEnlazada() {
	inicio = NULL;
	tam = 0;
}

//destructor de la lista
template <class T>
ListaDobleEnlazada<T>::~ListaDobleEnlazada() {
	NodoDoble<T>* tmp;
	while (inicio != NULL) {
		tmp = inicio;
		inicio = inicio->siguiente;
		delete tmp;
	}
	tam = 0;
}

//Agrega un elemento a la lista
template <class T>
bool ListaDobleEnlazada<T>::Agregar(T* item) {
	NodoDoble<T>* actual;
	try {
		actual = new NodoDoble<T>;
	}
	catch (std::bad_alloc exception) {
		return false;
	}

	actual->objeto = item;
	actual->siguiente = NULL;
	actual->anterior = NULL;

	if (inicio == NULL) {
		this->inicio = actual;
		this->final = actual;
		++tam;
		return true;
	}
	else {
		NodoDoble<T>* tmp = inicio;
		while (tmp->siguiente != NULL)
			tmp = tmp->siguiente;
		tmp->siguiente = actual;
		final = actual;
		actual->anterior = tmp;
		++tam;
		return true;
	}
}

//retorna true si la lista esta vacia
template <class T>
bool ListaDobleEnlazada<T>::Vacia() {
	return (!inicio);
}

//Imprime la lista normal de inicio a fin
template <class T>
string ListaDobleEnlazada<T>::Mostrar() {
	stringstream aux;
	if (!inicio)
		aux << "Lista Vacia \n\n";
	else {
		aux << "Elementos de la lista\n";
		NodoDoble<T>* tmp = inicio;
		while (tmp) {
			aux << *(tmp->objeto);
			tmp = tmp->siguiente;
		}
		aux << "\n Tamano de la Lista:" << tam;
	}
	return aux.str();
}

//imprime la lista del final hasta el inicio
template <class T>
string ListaDobleEnlazada<T>::MostrarListaInvertida() {
	stringstream aux;
	if (!inicio)
		aux << "\n Lista Vacia ...\n";
	else {
		NodoDoble<T>* tmp = final;
		while (tmp != NULL) {
			aux << *(tmp->objeto);
			tmp = tmp->anterior;
		}
	}
	return aux.str();
}

#endif // !LISTA_SIMPLE_H
