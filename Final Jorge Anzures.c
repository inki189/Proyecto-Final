#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
/**Estructura Agenda que contiene los datos
Y el apuntador siguiente que es el nodo al
siguiente nodo de la lista
*/
typedef struct Agenda{
	char Nombre[30];
	char Telefono[12];
	char Correo[20];
	struct Agenda *siguiente;
} Agenda;

struct Agenda *Cabeza,*enlace;
/**Funcion para el despliegue del menu
@param vacio, pues no recibe nada
@author Jorge Anzures
*/
char mostrarMenu() {
	/**Secuencia de impresiones que le dan forma 
	a la salida para que el menu este organizado*/
	printf("\nMenú:\n");
	printf("1.-Crear elemento\n");
	printf("2.-Eliminar elemento\n");
	printf("3.-Mostrar Lista\n");
	printf("4.-Consultar elemento\n");
	printf("5.-Cambiar elemento\n");
	printf("6.-Salir \n");
	printf("Escoge una opción: ");
}

/**funcion para elementos nuevos al final de la lista
@param vacio,pues no recibe nada
@author Jorge Anzures*/
void anadir() {
	/** Se crea un elemento nuevo y se reserva la memoria*/
	struct Agenda *nuevo;
	nuevo = (struct Agenda *) malloc (sizeof(struct Agenda));
	/**Se valida que haya espacio disponible*/
	if (nuevo==NULL) printf( "No hay memoria disponible!\n");
	/**Se imprime un mini-menu y se capturan y almacenan los datos a la variable nuevo*/
	printf("\nNuevo elemento:\n");
	printf("Nombre: "); fflush(stdout);
	scanf("%s",&nuevo->Nombre);
	printf("Teléfono: "); fflush(stdout);
	scanf("%s",&nuevo->Telefono);
	printf("Correo: ");fflush(stdout);
	scanf("%s",&nuevo->Correo);
	
	/**el campo siguiente va a ser NULL por ser el último elemento
	de la lista */
	nuevo->siguiente = NULL;	
	/**
	Hacemos la comprobacion para saber si es el primer elemento e imprimimos una leyenda si lo es
	Asignamos que este elemento es la cabeza de la lista y que el anterior(enlace) es igual al primero
	*/
	if (Cabeza==NULL) {
		printf("Primer elemento\n");
		Cabeza = nuevo;
		enlace = nuevo;
	}
	/**En caso de ser falso, el enlace del anterior apunta al nuevo elemento
	El enlace se convierte en el nuevo*/
	else {
		enlace->siguiente = nuevo;
		enlace = nuevo;
	}
}

/**
Funcion para imprimir la lista con un auxiliar
@param Vacio, pues no recibe nada
@author Jorge Anzures
*/
void Imprimir_Lista() {
	/** 
	Declaramos el auxiliar y un contador inicializado en 0
	Hacemos que el auxiliar sea el primer elemento
	Imprimimos una leyenda
	*/
	struct Agenda *Aux; 
	int i=0;
	Aux=Cabeza;
	printf("\nMostrando la lista completa:\n");
	/**
	Recorremos la lista mientras que el auxiliar sea diferente a NULL
	imprimimos los valores encontrados
	Incrementamos el contador
	Auxiliar toma el valor del siguiente nodo
	*/
	while (Aux!=NULL) {
		printf( "Nombre: %s, Telefono: %s , Correo: %s\n",Aux->Nombre,Aux->Telefono,Aux->Correo);
		i++;
		Aux=Aux->siguiente;
	}
	/**Si la lista esta vacia se imprime una leyenda*/
	if (i==0) printf( "\nLa lista aun no contiene elementos\n" );
}
/**
@note Funcion para eliminar un nodo de la lista con ayuda de un auxiliar, recorriendo el vector y eliminando el ultimo valor en este
en caso de ser el ultimo,se cambia el apuntador de este y posteriormente se libera la memoria utilizada por este
@param vacios, pues no recibe nada
@author Jorge Anzures
@warning En caso de eliminarse la cabeza, marcara error pues no esta implementado el proceso para esto
*/
void eliminar(){
	/*
	Se declara un vector para guardar el nombre
	se imprime una leyenda 
	se escanea el nombre del nodo para borrar
	*/
	char nombre[20];
	printf("\nIntroduzca el nombre del nodo a Borrar: ");
	scanf("%s",&nombre);
	struct Agenda *auxiliar;
	/*
	Usado para recorrer la lista
	Se recorre el arreglo hasta encontrar lo que se busca y en caso de no encontrarse se se termina
	Se recorren los valores de los nodos siguientes y se elimina el ultimo
	en caso de ser el ultimo elemento, se cambia el apuntador del anterior a este a NULL y se libera la memoria
	*/
	int i=0;
	auxiliar = Cabeza;
	enlace=NULL;
	while (auxiliar!=NULL){
		if(strcmp(nombre,auxiliar->Nombre)==0){
			if(auxiliar->siguiente!=NULL){
			while(auxiliar->siguiente!=NULL){
			strcpy(auxiliar->Nombre,auxiliar->siguiente->Nombre);
			strcpy(auxiliar->Telefono,auxiliar->siguiente->Telefono);
			strcpy(auxiliar->Correo,auxiliar->siguiente->Correo);
			enlace=auxiliar;
			auxiliar=auxiliar->siguiente;
			i++;
			}
			break;
			}else{
			if(auxiliar->siguiente==NULL){
				auxiliar->siguiente=enlace->siguiente;
				auxiliar->siguiente=NULL;
				i++;
			}
			}
			break;
		}
		enlace=auxiliar;
		auxiliar=auxiliar->siguiente;
	}
	if(i==0) printf("No se encontro el elemento\n");
	enlace->siguiente=NULL;
	free(auxiliar);
}
/**
@note Funcion para cambiar un elemento utilizando una bandera para recorrer la lista y si es encontrado
cambiando todos sus parametros, si no se encuentra se imprime otra leyenda
@param No recibe al ser vacio
@author Jorge Anzures
*/
void cambiar(){
	//Se declara la variable para guardar el nombre y se almacena el nombre en ella
	char nombre[20];
	printf("\nIntroduzca el nombre del nodo a cambiar: ");
	scanf("%s",&nombre);
	struct Agenda *auxiliar;//usado para recorrer la lista
	int i=0;
	auxiliar = Cabeza;
	while (auxiliar!=NULL){
		//si se encuentra, se imprime el elemento
		if(strcmp(nombre,auxiliar->Nombre)==0){
			printf("Se encontro el elemento a cambiar");
			printf("\nNuevo elemento:\n");
			printf("Nombre: "); fflush(stdout);
			scanf("%s",&auxiliar->Nombre);
			printf("Teléfono: "); fflush(stdout);
			scanf("%s",&auxiliar->Telefono);
			printf("Correo: ");fflush(stdout);
			scanf("%s",&auxiliar->Correo);
			i++;
		}
		auxiliar = auxiliar->siguiente;
	}
	if(i==0) printf("No se encontro el elemento");
}
void consultar(){
	char nombre[20];
	printf("\nIntroduzca el nombre del nodo a consultar: ");
	scanf("%s",&nombre);
	struct Agenda *auxiliar;//usado para recorrer la lista
	int i=0;
	auxiliar = Cabeza;
	while (auxiliar!=NULL){
		//si se encuentra, se imprime el elemento
		if(strcmp(nombre,auxiliar->Nombre)==0){
			printf("Nombre: %s Telefono: %s Correo: %s\n",auxiliar->Nombre,auxiliar->Telefono,auxiliar->Correo);
			i++;
		}
		auxiliar = auxiliar->siguiente;
	}
	if(i==0) printf("Nos se encontro el elemento\n");
}
/**
@note Funcion para un switch del menu principal,dependiendo de la opcion llama a la funcion asociada a esta
	@param Ninguno, pues es un metodo vacio y no regresa ningun valor
	@author Jorge Anzures
*/
int menu(){
	char opcion;
	do {
		mostrarMenu();
		opcion = getch();
		switch ( opcion ) {
		case '1':
			anadir();
			break;
		case '2':
			eliminar();
			break;
		case '3':
			Imprimir_Lista();
			break;
		case '4':
			consultar();
			break;
		case '5':
			cambiar();
			break;
		case '6':
			exit(0);
			break;
		default:
			printf( "Opción no válida\n" );			
			break;
		}
		system("pause");
		system("cls");	
	} while (opcion!=6);
	
}
int main(int argc, char *argv[]) {
	Cabeza = (struct Agenda*) NULL;
	enlace=(struct Agenda *)NULL;
menu(); 	
	return 0;
}

