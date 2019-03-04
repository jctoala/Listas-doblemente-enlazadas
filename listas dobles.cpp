#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

struct Nodo{
	Nodo *ant;
	int elemento;
	Nodo *sig;
};

void InsertarAnterior (Nodo **, Nodo **, Nodo **, int);
void InsertarFrente (Nodo **, Nodo **, Nodo **, int);
void MostrarAscendente (Nodo **);
void MostrarDescendente (Nodo **);
int EsVacia (Nodo **);
void IrInicio (Nodo **, Nodo **);
void IrFinal (Nodo **, Nodo **);
void Avanzar (Nodo **);
void Retroceder (Nodo **);

const string LISTA_VACIA = "Lista vacia...";

int main(){
	Nodo *cab = NULL;
	Nodo *ult = NULL;
	Nodo *pvte = NULL;
	int valor;
	int opc;
	
	do{
		system("cls");
		cout << "1.-Insertar como anterior" << endl;
		cout << "2.-Insertar al frente" << endl;
		cout << "3.-Mover pvte al inicio" << endl;
		cout << "4.-Mover pvte al final" << endl;
		cout << "5.-Retroceder pvte" << endl;
		cout << "6.-Avanzar pvte" << endl;
		cout << "7.-Mostrar ascendente" << endl;
		cout << "8.-Mostrar descendente" << endl;
		cout << "9.-SALIR" << endl;
		cout << "Ingrese opcion: ";
		cin >> opc;
		
		switch (opc){
			case 1:
				system("cls");
				cout << "Ingrese numero: ";
				cin >> valor;
				InsertarAnterior (&cab, &ult, &pvte, valor);
				break;
			case 2: 
				system("cls");
				cout << "Ingrese numero: ";
				cin >> valor;
				InsertarFrente (&cab, &ult, &pvte, valor);
				break;
			case 3:
				system("cls");
				IrInicio(&cab, &pvte);
				break;
			case 4:
				system("cls");
				IrFinal(&ult, &pvte);
				break;
			case 5:
				system("cls");
				Retroceder(&pvte);
				break;
			case 6:
				system("cls");
				Avanzar(&pvte);
				break;
			case 7:
				system("cls");
				MostrarAscendente(&ult);
				break;
			case 8:
				system("cls");
				MostrarDescendente(&cab);
				break;
		}
		system("pause");
	}while(opc != 9);
	
	return 0;
}

void InsertarAnterior (Nodo **cab, Nodo **ult, Nodo **pvte, int valor){
	Nodo *p;
	Nodo *aux = NULL;
	p = new Nodo ();
	p -> elemento = valor;
	if(EsVacia(cab)){
		p -> sig = NULL;
		p -> ant = NULL;
		*cab = *ult = *pvte = p;
		cout << "Valor insertado correctamente como primero" << endl;
	}
	else{
		if(*cab == *pvte){
			aux = *pvte;
			p -> sig = aux;
			p -> ant = NULL;
			aux -> ant = p;
			*cab = p;
			cout << "Valor insertado correctamente como primero" << endl;
		}
		else{
			aux = *pvte;
			p -> ant = aux -> ant;
			p -> sig = aux;
			aux -> ant = p;
			aux -> ant -> sig = p;
			cout << "Valor insertado correctamente" << endl;
		}
	}
}

void InsertarFrente (Nodo **cab, Nodo **ult, Nodo **pvte, int valor){
	Nodo *p;
	Nodo *aux = NULL;
	p = new Nodo ();
	p -> elemento = valor;
	if(EsVacia(cab)){
		p -> sig = NULL;
		p -> ant = NULL;
		*cab = *ult = *pvte = p;
		cout << "Valor insertado correctamente como primero" << endl;
	}
	else{
		if(*ult == *pvte){	
			aux = *pvte;
			p -> sig = NULL;
			p -> ant = aux;
			aux -> sig = p;
			*ult = p;
			cout << "Valor insertado correctamente como ultimo" << endl;
		}
		else{
			aux = *pvte;
			p -> sig = aux -> sig;
			p -> ant = aux;
			aux -> sig -> ant = p;
			aux -> sig = p;
			cout << "Valor insertado correctamente" << endl;
		}
	}
}

void MostrarAscendente(Nodo **ult){
	if (EsVacia(ult))
		cout << LISTA_VACIA << endl;
	else {
		Nodo *aux = *ult;
		while (aux != NULL){
			cout << "Elemento: " << aux -> elemento << endl;
			aux = aux -> ant;
		}
		cout << "TODOS LOS ELEMENTOS ALMACENADOS ASCENDENTEMENTE" << endl;
	}
}

void MostrarDescendente(Nodo **cab){
	if (EsVacia(cab))
		cout << LISTA_VACIA << endl;
	else {
		Nodo *aux = *cab;
		while (aux != NULL){
			cout << "Elemento: " << aux -> elemento << endl;
			aux = aux -> sig;
		}
		cout << "TODOS LOS ELEMENTOS ALMACENADOS DESCENDENTEMENTE" << endl;
	}
}
 
int EsVacia (Nodo **p){
	if(*p == NULL)
		return 1;
	else
		return 0;
}

void IrInicio (Nodo **cab, Nodo **pvte){
	if(EsVacia(cab))
		cout << LISTA_VACIA << endl;
	else{
		if(*cab == *pvte)
			cout << "Puntero pvte ya se encuentra al incio" << endl;
		else{
			*pvte = *cab;
			cout << "Puntero pvte movido al inicio de la lista" << endl;
		}
	}
}

void IrFinal (Nodo **ult, Nodo **pvte){
	if(EsVacia(ult))
		cout << LISTA_VACIA << endl;
	else{
		if(*ult == *pvte)
			cout << "Puntero pvte ya se encuentra al final" << endl;
		else{
			*pvte = *ult;
			cout << "Puntero pvte movido al final de la lista" << endl;
		}
	}
}

void Avanzar (Nodo **pvte){
	if(EsVacia(pvte))
		cout << LISTA_VACIA << endl;
	else{
		Nodo *aux = *pvte;
		if(aux -> sig == NULL)
			cout << "No se puede avanzar" << endl;
		else{
			*pvte = aux -> sig;
			cout << "pvte ha sido avanzado" << endl;
		}
	}
}

void Retroceder (Nodo **pvte){
	if(EsVacia(pvte))
		cout << LISTA_VACIA << endl;
	else{
		Nodo *aux = *pvte;
		if(aux -> ant == NULL)
			cout << "No se puede retroceder" << endl;
		else{ 
			*pvte = aux -> ant;
			cout << "pvte ha sido retrocedido" << endl;
		}
	}
}
