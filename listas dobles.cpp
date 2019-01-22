#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

struct Nodo{
	Nodo *ant;
	int elemento;
	Nodo *sig;
};

void InsertarFrente (Nodo **, Nodo **, Nodo **, int);
void InsertarFinal (Nodo **, Nodo **, Nodo **, int);
void Mostrar (Nodo **);
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
	int menu_1;
	int menu_2;
	
	do{
		system("cls");
		cout << "1.-Insertar" << endl;
		cout << "2.-Mostrar" << endl;
		cout << "3.-SALIR" << endl;
		cout << "Ingrese opcion: ";
		cin >> menu_1;
		switch (menu_1){
			case 1:
				do{
					system("cls");
					cout << "1.-Insertar al frente" << endl;
					cout << "2.-Insertar al ultimo" << endl;
					cout << "Ingrese opcion: ";
					cin >> menu_2;
				}while((menu_2 != 1) && (menu_2 != 2) );
				switch (menu_2){
					case 1:	
						system("cls");
						cout << "Ingrese numero: ";
						cin >> valor;
						int opcion_1;
						cout << "1.-Mover pvte al inicio" << endl;
						cout << "2.-Mover pvte al final" << endl;
						cout << "3.-Retroceder pvte" << endl;
						cout << "Ingrese opcion: ";
						cin >> opcion_1;
						switch (opcion_1){
							case 1:
								IrInicio (&cab, &pvte);
								break;
							case 2:
								IrFinal (&ult, &pvte);
								break;
							case 3:
								Retroceder (&pvte);
								break;
						}
						InsertarFrente (&cab, &ult, &pvte, valor);
						break;
					case 2: 
						system("cls");
						cout << "Ingrese numero: ";
						cin >> valor;
						int opcion_2;
						cout << "1.-Mover pvte al inicio" << endl;
						cout << "2.-Mover pvte al final" << endl;
						cout << "3.-Avanzar pvte" << endl;
						cout << "Ingrese opcion: ";
						cin >> opcion_2;
						switch (opcion_2){
							case 1:
								IrInicio (&cab, &pvte);
								break;
							case 2:
								IrFinal (&ult, &pvte);
								break;
							case 3:
								Avanzar (&pvte);
								break;
						}
						InsertarFinal (&cab, &ult, &pvte, valor);
						break;
				}		
				break;
			case 2:
				system("cls");
				cout << "LOS ELEMENTOS INGRESADOS SON" << endl;
				Mostrar (&cab);
				break;
		}
		system("pause");
	}while(menu_1 != 3);
	return 0;
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
			cout << "Valor insertado correctamente" << endl;
		}
	}
}

void InsertarFinal (Nodo **cab, Nodo **ult, Nodo **pvte, int valor){
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
			aux -> sig = p;
			cout << "Valor insertado correctamente" << endl;
		}
	}
}

void Mostrar(Nodo **cab){
	if (EsVacia(cab))
		cout << LISTA_VACIA << endl;
	else {
		Nodo *aux = *cab;
		while (aux != NULL){
			cout << "Elemento: " << aux -> elemento << endl;
			aux = aux -> sig;
		}
		cout << "TODOS LOS ELEMENTOS MOSTRADOS" << endl;
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
	else
		*pvte = *cab;
}

void IrFinal (Nodo **ult, Nodo **pvte){
	if(EsVacia(ult))
		cout << LISTA_VACIA << endl;
	else
		*pvte = *ult;
}

void Avanzar (Nodo **pvte){
	if(EsVacia(pvte))
		cout << LISTA_VACIA << endl;
	else{
		Nodo *aux = *pvte;
		if(aux -> sig == NULL)
			cout << "No se puede avanzar" << endl;
		else 
			*pvte = aux -> sig;
	}
}

void Retroceder (Nodo **pvte){
	if(EsVacia(pvte))
		cout << LISTA_VACIA << endl;
	else{
		Nodo *aux = *pvte;
		if(aux -> ant == NULL)
			cout << "No se puede retroceder" << endl;
		else 
			*pvte = aux -> ant;
	}
}
