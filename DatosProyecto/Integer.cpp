#include "Integer.h"

Integer::Integer() {//mientras tanto
	this->lista = new ListaDobleEnlazada<Vector>();
	variable_negativa = false;
}

Integer::Integer(string valor) {
	this->lista = new ListaDobleEnlazada<Vector>();
	variable_negativa = false;
	Parse(valor);
}

Integer::Integer(Integer& obj) {//constructor de copia, copio de uno lleno a uno vacio
	this->variable_negativa = obj.variable_negativa;
	this->lista = new ListaDobleEnlazada<Vector>();
	//NodoDoble<Vector> *aux = lista->GetInicio();
	NodoDoble<Vector>* aux2 = obj.lista->GetInicio();

	while (aux2 != NULL) {//ir recorriendo la segunda lista
		Vector* tmp = new Vector();//por cada nodo se hace un vector
		//tmp->setVect(aux2->objeto);
		for (int i = 0; i < aux2->objeto->GetCantidad(); i++) {//se llena hasta la cantidad de cada vector
			tmp->Insertar(aux2->objeto->GetNumero(i));
		}
		lista->Agregar(tmp);
		tmp = NULL;
		aux2 = aux2->siguiente;
	}//fin del while
}//fin del constructor copia

Integer& Integer::operator=(Integer& obj) {
	if (lista != NULL) {//si mi lista esta llena, eliminela
		delete lista;
	}
	this->lista = new ListaDobleEnlazada<Vector>();
	//NodoDoble<Vector> *aux = lista->GetInicio();
	NodoDoble<Vector>* aux2 = obj.lista->GetInicio();

	while (aux2 != NULL) {//ir recorriendo la segunda lista
		Vector* tmp = new Vector();//por cada nodo se hace un vector
		//tmp->setVect(aux2->objeto);
		for (int i = 0; i < aux2->objeto->GetCantidad(); i++) {//se llena hasta la cantidad de cada vector
			tmp->Insertar(aux2->objeto->GetNumero(i));
		}
		lista->Agregar(tmp);
		tmp = NULL;
		aux2 = aux2->siguiente;
	}//fin del while
	return *this;
}


Integer::~Integer() {
	delete lista;
}

char Integer::PasarIntChar(int n){
	stringstream a;
	char x;
	a << n;
	a >> x;
	return x;
}

int Integer::PasarCharInt(char n){
	stringstream a;
	int x;
	a << n;
	a >> x;
	return x;
}

Integer& Integer::Multiplicacion(Integer* nuemro2){
	string aux_numero1;
	string aux_numero2;
	Integer* nuevo = new Integer();
	int numero_aux1 = 0;
	int numero_aux2 = 0;

	aux_numero1 = this->ImprimeNumero();
	aux_numero2 = nuemro2->ImprimeNumero();
	string aux_resultado(aux_numero1.length() + aux_numero2.length(), 0);
	if (aux_numero1.length() == 0 || aux_numero2.length() == 0) {
		nuevo->Agregar("0");
		return *nuevo;
	}

	for (int i = aux_numero1.length() - 1; i >= 0; i--) { //recorre de derecha izquierda el vector 1 
		int carry = 0;
		int numero1 = aux_numero1[i] - '0';
		numero_aux2 = 0;
		for (int j = aux_numero2.length() - 1; j >= 0; j--) {
			int numero2 = aux_numero2[j] - '0';
			int suma = numero1 * numero2 + PasarCharInt(aux_resultado[numero_aux1 + numero_aux2]) + carry;
			carry = suma / 10;
			aux_resultado[numero_aux1 + numero_aux2] = PasarIntChar(suma % 10);
			numero_aux2++;
		}
		if (carry > 0) {
			aux_resultado[numero_aux1 + numero_aux2] += PasarIntChar(carry);
		}
		numero_aux1++;
	}
	int i = aux_resultado.size() - 1;
	while (i >= 0 && aux_resultado[i] == 0)
	{
		i--;
	}
	if (i == -1) {
		nuevo->Agregar("0");
		return *nuevo;
	}
	string s = "";
	while (i >= 0) {//para darle vuelta
		s += (aux_resultado[i--]);
	}
	nuevo->Agregar(s);
	return *nuevo;
}

bool Integer::GetNegativa() {
	return variable_negativa;
}

void Integer::SetNegativa(bool variable_negativa) {
	this->variable_negativa = variable_negativa;
}


ListaDobleEnlazada<Vector>* Integer::getList() {
	return lista;
}


void Integer::Agregar(string num) {
	string num_aux = num;
	if (num_aux[0] == '-') {
		num_aux.erase(0, 1);
		variable_negativa = true;
	}
	AgregarResultado(num_aux);
}
void Integer::AgregarResultado(string num) {
	string num_auxiliar;
	Vector* aux = NULL;
	for (int i = num.size(); i >= 0; i -= 9) {
		//el error radica en el caso de que sea un numero de 6 digitos ya que va a seguir iterando
		if (aux == NULL) {
			aux = new Vector(); //Cuando el auxiliar es nulo crea un nuevo vector
		}
		if (i < 9 && aux->GetCantidad() == 3) { //Por si lo que queda es menos de 6
			num_auxiliar = num.substr(0, i);
			//out << num_auxiliar << endl;
			aux->Insertar(stoi(num_auxiliar));
		}
		else if (i <= 9) {
			num_auxiliar = num.substr(0, i);
			//cout << num_auxiliar << endl;
			aux->Insertar(stoi(num_auxiliar));
			lista->Agregar(aux);
			return;
		}
		else { //sino pos no
			num_auxiliar = num.substr(i - 9, 9);
			//cout << num_auxiliar << endl;
			aux->Insertar(stoi(num_auxiliar));
		}
		if (i - 9 == 0) {
			lista->Agregar(aux);
			aux = NULL;
			return;
		}
		else if (aux->GetCantidad() == 3) { //cuando el vector se llena se borra ese y se a;ade a la lista
			lista->Agregar(aux);
			aux = NULL;
		}
	}
}

Integer& Integer::operator+(Integer& i1) {
	return SumarPorNodos(&i1);
}

Integer& Integer::SumarPorNodos(Integer* integer) {
	Integer* nuevo = new Integer();//el que se retorna al final y se va modificando
	int i = 0, carry = 0;
	Integer* aux1_i, * aux2_i;//auxiliares
	NodoDoble<Vector>* aux = this->lista->GetInicio();
	NodoDoble<Vector>* aux1 = integer->getList()->GetInicio();
	//Se recorrerá el integer que tenga mayor tamaño
	if (this->lista->GetTam() > integer->getList()->GetTam()) {
		//se posiciona en los primeros digitos, los "menores"
		aux = this->lista->GetInicio();
		aux1 = integer->getList()->GetInicio();
		//y acomoda los integers con el mayor arriba y el menor abajo
		aux1_i = this;
		aux2_i = integer;
	}
	else {//resulta que el de la izquierda es el menor y el de la derecha es mayor, recorrer el de la derecha
		aux = integer->getList()->GetInicio();
		aux1 = this->lista->GetInicio();
		//se acomoda igual, el mayor arriba y el menor abajo
		aux1_i = integer;
		aux2_i = this;
	}
	//empezar a recorrer con el noodo mayor
	while (aux != NULL) {//ir de nodo en nodo
		//el contador me dice cuando ya se terminó la lista menor para seguir trabajando con la grande
		if (i < aux2_i->getList()->GetTam()) {
			//el carry se va modificando tambien, le mando los 2 vectores, el nuevo integer y el mismo carry
			carry = SumaVectores(aux->objeto, aux1->objeto, *nuevo, carry);
			//cout << "\n\n\nCARRY: " << carry << "\n\n\n";//prueba
			aux1 = aux1->siguiente; //Para que no se pase de verga
		}
		else {//todavia quedan nodos con vectores arriba, sefuir trabajando con esos
			//solo le mando el ultimo carry, el vector mas grande, y el nuevo integer
			carry = SumarVectorSiSePasa(aux->objeto, carry, *nuevo);
		}
		aux = aux->siguiente;//cambia al sgt nodo
		i++;//incrementa el contador
	}
	if (carry != 0) {//ya al final de todo, y si todavia tiene carry, que lo agrege
		nuevo->Agregar(to_string(carry));
		carry = 0;
	}
	return *nuevo;
}

int Integer::SumaVectores(Vector* v1, Vector* v2, Integer& nuevo, int carry) {//trabajar sobre el mismo integer
	int aux1, aux2, carry1 = carry;//el carry va a ser el mismo que traia
	long long int num;//para ir almacenando el numero y luego separarlo
	Vector* v_aux1;
	string numero = "";
	//Funciona sin la parte comentada, suponiendo que siempre enre el vector mayor, el de arriba
	if (v1->GetCantidad() > v2->GetCantidad()) {
		aux1 = v1->GetCantidad();
		aux2 = v2->GetCantidad();
		v_aux1 = v1;//todo el vector de arriba
		//v_aux2 = v2;
	}
	else {
		aux1 = v2->GetCantidad();
		aux2 = v1->GetCantidad();
		v_aux1 = v2;
		//v_aux2 = v1;
	}
	for (int i = 0; i < aux1; i++) {//recorre el vector con mayor cantidad de numeros
		//siempre que no se acabe el vector de menor tamaño, suma ambos
		if (aux2 > i) {
			num = v1->GetNumero(i) + v2->GetNumero(i) + carry1;//suma ambas posiciones de los vectores
			carry1 = num / 1000000000;//saca el primer digito, el carry
			num = num % 1000000000;//saca los 9 digitos limite a almacenar 
			if (num == 0)
				numero = "000000000" + numero;
			else
			numero = to_string(num) + numero;//pasa el numero a string
		}
		else {//si ya se acabó el vector de abajo, sigo sumando si quedo carry y bajando numeros
			//v_aux1 signficia que es el que tiene mayor cantidad
			num = v_aux1->GetNumero(i) + carry1;
			carry1 = num / 1000000000;
			num = num % 1000000000;
			if (num == 0)
				numero = "000000000" + numero;
			else
				numero = to_string(num) + numero;//lo pasa a string
		}
	}
	//000000001 ----1
	//000000000 ----2
	//000000000 --- 3
	//000000000 + 000000000 + 000000001
	//carry lo pasa
	//001
	nuevo.Agregar(numero);//agrega los valores al nuevo integer
	return carry1; //retorna el carry para que lo reciba de nuevo en el proximo nodo
}

int Integer::SumarVectorSiSePasa(Vector* v, int carry, Integer& integer) {
	int carry1 = carry;
	long long int num;
	string numero = "";
	for (int i = 0; i < v->GetCantidad(); i++) {
		num = v->GetNumero(i) + carry1;
		carry1 = num / 1000000000;
		num = num % 1000000000;
		numero = to_string(num) + numero;
	}
	integer.Agregar(numero);
	return carry1;
}

Integer& Integer::operator-(Integer& integer) {
	return Resta(integer);
}

string Integer::ImprimeNumero() {
	string aux = lista->MostrarListaInvertida();
	if (lista->GetTam() == 1 && lista->GetInicio()->objeto->GetCantidad()==1 && lista->GetInicio()->objeto->GetNumero(0) == 0)
		aux = "0";
	else QuitaCerosExtra(aux);
	if (variable_negativa) {
		return "-" + aux;
	}
	else {
		return aux;
	}
}

void Integer::QuitaCerosExtra(string &n) {
	if (n[0] == '0') {
		while (n[0] == '0') {
			n.erase(0, 1);
		}
	}
}



Integer& Integer::Dividir(Integer& divisor) {
	Integer *aux1 = new Integer(this->ImprimeNumero());
	Integer aux(divisor.ImprimeNumero());
	Integer* contador = new Integer("0");
	Integer help;
	Integer uno("1");
	while (aux <= *aux1) {//mientras el divisor sea menor al numero
		help = (*aux1 - aux);
		string s = help.ImprimeNumero();
		*aux1 = *new Integer(s);
		*contador += uno;
	}
	delete aux1;
	return *contador;
}

Integer& Integer::Resta(Integer& num2){
	Integer* nuevo = new Integer();
	string str1;
	string str2;
	//Resta 
	if (*this == num2 && ((!this->GetNegativa() && !num2.GetNegativa())
		|| (this->GetNegativa() && num2.GetNegativa()))) {
		nuevo->Agregar("-1");
		return *nuevo;
	}
	if (this->variable_negativa && num2.variable_negativa || !this->variable_negativa && !num2.variable_negativa) {//si ambos son negativos
		if (*this < num2) {//si el de la izquierda es el menor, entonces por dentro, el izq es el mayor en los negativos
			str2 = this->ImprimeNumero();//el menor
			str1 = num2.ImprimeNumero();//el mayor
			if (str1[0] == '-') //quitarles los -
				str1.erase(0, 1);
			if (str2[0] == '-') //quitarles los -
				str2.erase(0, 1);//quitarle el negativo	
			//darles vuelta cuando son ambos negativos
			if (this->variable_negativa && num2.variable_negativa) {//si ambos son positivos, el resultado es negativo
				swap(str1, str2);
				nuevo->SetNegativa(true);
			}
			//swap(str1,str2);//por si son negativos, 
			if (!this->variable_negativa && !num2.variable_negativa) {//si ambos son positivos, el resultado es negativo
				//swap(str1, str2);
				nuevo->SetNegativa(true);
			}

		}
		else {//siempre el mayor queda arriba
			str1 = this->ImprimeNumero();
			str2 = num2.ImprimeNumero();
			if (str1[0] == '-') //quitarles los -
				str1.erase(0, 1);
			if (str2[0] == '-') //quitarles los -
				str2.erase(0, 1);//quitarle el negativo	
			if (this->variable_negativa && num2.variable_negativa) {//si ambos son positivos, el resultado es negativo
				swap(str1, str2);
				//nuevo->SetNegativa(true);
			}
		}
	}//si ambos son negativos o positivos

	//si son de signos diferentes, suma
	if (this->variable_negativa && !num2.variable_negativa || !this->variable_negativa && num2.variable_negativa) {//si ambos son negativos
		//la suma ya acomoda al mayot y al menor
		if (this->variable_negativa && !num2.variable_negativa) {//-&+ = resultado -
			nuevo->SetNegativa(true);
		}
		*nuevo = this->SumarPorNodos(&num2);
		return *nuevo;
	}

	// Take an empty string for storing result 
	string str = "";
	// Calculate length of both string 
	int n1 = str1.length(), n2 = str2.length();
	// Reverse both of string
	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());
	int carry = 0;
	// Run loop till small string length 
	// and subtract digit of str1 to str2 
	for (int i = 0; i < n2; i++){
		// Do school mathematics, compute difference of current digits 
		int sub = ((str1[i] - '0') - (str2[i] - '0') - carry);
		// If subtraction is less then zero 
		// we add then we add 10 into sub and 
		// take carry as 1 for calculating siguiente step 
		if (sub < 0){
			sub = sub + 10;
			carry = 1;
		}
		else
			carry = 0;
		str.push_back(sub + '0');
	}

	// subtract remaining digits of larger number 
	for (int i = n2; i < n1; i++)	{
		int sub = ((str1[i] - '0') - carry);

		// if the sub value is -ve, then make it positive 
		if (sub < 0)		{
			sub = sub + 10;
			carry = 1;
		}
		else
			carry = 0;
		str.push_back(sub + '0');
	}
	// reverse resultant string 
	reverse(str.begin(), str.end());
	nuevo->Agregar(str);
	return *nuevo;
}

Integer& Integer::Factorial(Integer& num) {
	Integer* nuevo = new Integer("1");//empieza con 1							  
	Integer i("1");
	Integer contador("1");
	while (i <= num) {
		(*nuevo) *= i;
		i += contador;
	}
	return *nuevo;
}
/*metodo de Fibonacci de manera ierativa, resulta que fue la manera mas rapida de encontrarlo*/
Integer& Integer::Fibonacci(Integer& num){
	Integer aux1("0");
	Integer aux2("1");
	Integer sig, primero("0"), segundo("1");
	for (aux1; aux1 < num; aux1+=aux2) {
		if (aux1 < aux2)// < 1
			sig = aux1;
		else {
			sig = primero + segundo;
			primero = segundo;
			segundo = sig;
		}
	}
	Integer* nuevo = new Integer(sig);
	return *nuevo;
}


Integer& Integer::Combinatoria(Integer& uno, Integer&dos) {
	Integer* nuevo = new Integer();
	Integer aux1(uno);
	Integer aux2(dos);
	*nuevo = (Factorial(aux1) / (Factorial(aux2) * Factorial(aux1-aux2)));
	return *nuevo;
}

bool Integer::Menor(Integer& num)
{
	int num1;
	int num2;
	string aux = num.ImprimeNumero();
	string aux2 = this->ImprimeNumero();
	if (aux.size() < aux2.size()) {
		return true;
	}
	else if (aux.size() > aux2.size()) {
		return false;
	}
	else {
		num1 = stoi(aux.substr(0, 8));
		num2 = stoi(aux2.substr(0, 8));
		if (num1 < num2) {
			return true;
		}
		else
		{
			bool bandera = false;
			for (int i = 8; i < aux.size(); i+=9) {
				num1 = stoi(aux.substr(i, 9));
				num2 = stoi(aux2.substr(i, 9));
				if (num1 < num2) {
					bandera = true;
				}
				else
					bandera = false;
			}
			return bandera;
		}
	}
}
 


bool Integer::operator==(Integer& i1) {
	return ComparaPorNodos(&i1);
}

//recorre los nodos para comparar sus vectores, si son == o !=
bool Integer::ComparaPorNodos(Integer* integer) {
	//si los tamaños son distintos, de una vez no son iguales
	if (this->lista->GetTam() != integer->getList()->GetTam()) {
		return false;
	}
	//ir comparando los vectores de cada nodo, desde los ultimos numeros de integer
	NodoDoble<Vector>* aux = this->lista->GetInicio();
	NodoDoble<Vector>* aux1 = integer->getList()->GetInicio();
	while (aux != NULL) {//ir de nodo en nodo
		//si los contenidos de los arreglos no son iguales
		if (!ComparaPorVectores(aux->objeto, aux1->objeto)) {
			return false;
		}
		//moverse a los siguientes nodos (27 digitos a la izquierda)
		aux = aux->siguiente;
		aux1 = aux1->siguiente;
	}
	return true;//al final de todo, son iguales 
}

bool Integer::ComparaPorVectores(Vector* v1, Vector* v2) {
	//si las cantidades son distintas, de una vez no son iguales (uno tiene mas o menor digitos que el otro)
	if (v1->GetCantidad() != v2->GetCantidad()) {
		return false;
	}
	//ir comparando los contenidos de los vectores
	for (int i = 0; i < v1->GetCantidad(); i++) {
		//apenas sean distintos, se sale
		if (v1->GetNumero(i) != v2->GetNumero(i)) {
			return false;
		}
	}
	return true;//al final de todo, si son iguales los vectores
}

//si no son iguales, son diferentes...
bool Integer::operator!=(Integer& i1) {
	return !ComparaPorNodos(&i1);
}

bool Integer::operator<(Integer& i1) {
	return !Menor(i1);
	//// si son iguales, entonces no son menores
	//if (ComparaPorNodos(&i1)) {
	//	return false;
	//}
	////compara a ver si son mayores o menores
	//else {
	//	return !NodoMenor(&i1);
	//}
}


//i1 < i2
bool Integer::NodoMenor(Integer* integer) {
	//Si los 2 son negativos 
	if (this->variable_negativa && integer->GetNegativa()) {
		if (this->lista->GetTam() > integer->getList()->GetTam()) {
			return false;
		}
		//si tiene menos nodos, es el menor
		else if (this->lista->GetTam() < integer->getList()->GetTam()) {
			return true;
		}
		//si son del mismo tamaño
		NodoDoble<Vector>* aux = this->lista->GetFinal();
		NodoDoble<Vector>* aux1 = integer->getList()->GetFinal();
		while (aux != NULL) {
			if (VectorMenor(aux->objeto, aux1->objeto)) { //esta negado ya que va a devolver false apenas haya un mayor
				return true;
			}
			aux = aux->anterior;
			aux1 = aux1->anterior;
		}
		return false;
	}

	//S EL IZQUIERDO EN NEGATIVO Y EL DERECHO POSITIVO
	if (this->variable_negativa && !integer->GetNegativa()) {
		return false;//aqui era true
	}
	//SI EL IZQUIERDO ES POSITIVO Y EL DERECHO NEGATIVO
	if (!this->variable_negativa && integer->GetNegativa()) {
		return true;//aqui era false
	}
	//Compara tam de la lista, si tiene mas nodos, entonces no es el menor
	if (this->lista->GetTam() > integer->getList()->GetTam()) {
		return true;//era false
	}
	//si tiene menos nodos, es el menor
	else if (this->lista->GetTam() < integer->getList()->GetTam()) {
		return false;//era true
	}
	//SI AMBOS SON POSITIVOS
	NodoDoble<Vector>* aux = this->lista->GetFinal();
	NodoDoble<Vector>* aux1 = integer->getList()->GetFinal();
	while (aux != NULL) {
		if (VectorMenor(aux->objeto, aux1->objeto)) { //esta negado ya que va a devolver false apenas haya un mayor
			return false;//esto es false
		}
		aux = aux->anterior;
		aux1 = aux1->anterior;
	}
	return true;//era true
}

//IR COMPARANDO VECTORES DE LOS NODOS
bool Integer::VectorMenor(Vector* v1, Vector* v2) {
	//si el de la izq tiene mas numeros que el de la derecha, ya no es el menor
	if (v1->GetCantidad() > v2->GetCantidad()) {
		return false;
	}
	//si le de la izq tiene menos numeros que el de la derecha, entonces si es el menor
	else if (v1->GetCantidad() < v2->GetCantidad()) {
		return true;
	}
	//ir comparando los numeros de los vectores, pero inverso, desde los primeros digitos del numero...del vector empieza desde atras
	for (int i = v1->GetCantidad() - 1; i >= 0; i--) {
		int num1 = v1->GetNumero(i);
		int num2 = v2->GetNumero(i);
		//si mi primer digito es mayor al primer digito del otro, ya no cumple que sea el menor
		if (v1->GetNumero(i) > v2->GetNumero(i)) {
			return false;
		}
		//si el primero digito de v1 es menor al primer digito de v2...entonces si es el menor
		if (v1->GetNumero(i) < v2->GetNumero(i)) {
			return true;
		}
	}//fin del for
	return false;
}


bool Integer::operator<=(Integer& i1) {
	if(ComparaPorNodos(&i1)) {
		return true;
	}
	//compara a ver si son mayores o menores
	else 
	return !NodoMenor(&i1);	
}

bool Integer::operator>(Integer& i) {
	return Menor(i);
	/*if (ComparaPorNodos(&i)) {
		return false;
	}
	else if (NodoMenor(&i)) {
		return true;
	}
	else return false;*/
}

bool Integer::operator>=(Integer& i1) {
	if (ComparaPorNodos(&i1)) {
		return true;
	}
	else if (NodoMenor(&i1)) {
		return true;
	}
	else return false;
}

void Integer::Parse(string s) {
	this->Agregar(s);
}

Integer& Integer::operator*(Integer& I2) {
	return Multiplicacion(&I2);
}

Integer& Integer::operator/(Integer& num){
	return Dividir(num);
}

void Integer::operator+=(Integer& integer) {//no recibe esto...es this
	*this = SumarPorNodos(&integer);
}

void Integer::operator-=(Integer& integer) {
	*this = Resta(integer);
}

void Integer::operator*=(Integer& integer){
	*this = Multiplicacion(&integer);
}

void Integer::operator/=(Integer& integer){
	*this = Dividir(integer);
}

