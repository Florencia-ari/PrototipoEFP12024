#include "Pelicula.h"
#include <fstream>
#include <iostream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

//#include "Bitacora.h"

using namespace std;

void PeliculaCRUD::CrudPelicula() {
int choice;
//implementacion de variables para la bitacora
string codigoPrograma="1001";
//Bitacora Auditoria;
string user="Florencia";

    do {
	//limpiar pantalla
	system("cls");
	cout << "\t\t\tMaria FLorencia Ariaga Chiroy-9959-23-6741" << endl;
	//menu de opciones
	cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\t|          Pelicula                         |"<<endl;
	cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingresar Pelicula"<<endl;
	cout<<"\t\t\t 2. Modificar Pelicula"<<endl;
	cout<<"\t\t\t 3. Borrar Pelicula"<<endl;
	cout<<"\t\t\t 4. Desplegar Pelicula"<<endl;
	cout<<"\t\t\t 5. Regresar Menu Anterior"<<endl;
    cout<<"\t\t\t --------------------------------------------"<<endl;
	cout<<"\t\t\t |   Opcion a escoger:[1|2|3|4|5|]           |"<<endl;
	cout<<"\t\t\t --------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
	case 1:
        Ingresar();
        //Se ejecuta la accion y se registra en la bitacora
//        Auditoria.ingresoBitacora(user,codigoPrograma,"CJU"); //CCU = Create Pelicula
         system("pause");
		break;
    case 2:
        Modificar();
         //Se ejecuta la accion y se registra en la bitacora
//        Auditoria.ingresoBitacora(user,codigoPrograma,"UJU"); //UCU = Update Pelicula
         system("pause");
		break;
    case 3:
        Borrar();
        //Se ejecuta la accion y se registra en la bitacora
//        Auditoria.ingresoBitacora(user,codigoPrograma,"DJU"); //DCU = Delete Pelicula
         system("pause");
		break;
    case 4:
        Desplegar();
        //Se ejecuta la accion y se registra en la bitacora
//        Auditoria.ingresoBitacora(user,codigoPrograma,"RJU"); //RCU = Read Pelicula
        system("pause");
		break;
    case 5:
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
		cin.get();
	}
    }while(choice!= 5);
}


//Funcion que nos permite ingresar nuevos datos

void PeliculaCRUD::Ingresar() {

   system("cls");
    cout<<"\n------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\n-------------------------------------------------Agregar Pelicula--------------------------------------------"<<endl;
    Pelicula Pelicula;

        //se ingresa los datos y se guardan en variables

    cout << "Ingrese codigo de Pelicula: ";
    cin >> Pelicula.codigo;
    cin.ignore();

    cout << "Ingrese nombre de Pelicula: ";
    cin.getline(Pelicula.nombre, 50);

    cout << "Ingrese  Genero de Pelicula: ";
    cin.getline(Pelicula.Genero, 50);

    cout <<"Ingrese  Precio de Pelicula: ";
    cin.getline (Pelicula.Precio,50);
	//Se crea el objeto archivo para abrir el archivo en binario
	//si el archivo no esta existe, se crea uno nuevo


    ofstream archivo("Pelicula.DAT", ios::binary | ios::app);
    archivo.write(reinterpret_cast<const char*>(&Pelicula), sizeof(Pelicula));
    archivo.close();

    cout << "Pelicula agregada exitosamente!" << endl;
}
//Funcion que nos permite modificar registros

void PeliculaCRUD::Modificar() {
    int codigo;
    //ingresar el codigo del dato a modificar
    cout << "Ingrese el codigo de Pelicula a modificar: ";
    cin >> codigo;
//abrir el archivo en modo lectura y escribir en binario

    fstream archivo("Pelicula.DAT", ios::binary | ios::in | ios::out);
    //verificar si el archivo se pudo abrir correctamente
    if (!archivo) {
        cout << "No hay Pelicula registrados." << endl;
        return;
    }

    Pelicula Pelicula;
    //variable booleana que se usara para indicar si se encontro el codigo que se ingreso
    bool encontrada = false;
    //lee de forma repetida cada registro del archivo hasta que no haya mas registros
    while (archivo.read(reinterpret_cast<char*>(&Pelicula), sizeof(Pelicula))) {
        //compara el codigo del archivo con el ingresado para determinar si se ha encontrado o no
        if (Pelicula.codigo == codigo) {
            cout << "Ingrese nombre de Pelicula: ";
            cin.ignore();
            cin.getline(Pelicula.nombre, 50);

            cout << "Ingrese Genero de Pelicula: ";
            cin.getline(Pelicula.Genero, 50);

            cout <<"Ingrese Precio de Pelicula";
            cin.getline(Pelicula.Precio, 50);

            archivo.seekp(-static_cast<int>(sizeof(Pelicula)), ios::cur);
            //modifica el archivo, sobreescribiendo el registro original
            archivo.write(reinterpret_cast<const char*>(&Pelicula), sizeof(Pelicula));
			//establece como verdadera la variable, para indicar que se ha encontrado la jornada que se desea modificar
            encontrada = true;
            break;
        }
    }
//se cierra el archivo
    archivo.close();

    if (!encontrada) {
        cout << "No se encontro Pelicula con el codigo ingresado." << endl;
    } else {
        cout << "Pelicula modificada exitosamente!" << endl;
    }

}
//funcion para borrar los resgistros
void PeliculaCRUD::Borrar() {
    int codigo;
    //se ingresa el codigo del registro a eliminar
    cout << "Ingrese el codigo de  Pelicula a eliminar: ";
    cin >> codigo;
    //abre el archivo en modo de lectura binario y lee los datos del archivo

    ifstream archivo("Pelicula.DAT", ios::binary);
    //verifica si el archivo se pudo abrir correctamente
    if (!archivo) {
        cout << "No hay Pelicula registrada." << endl;

    }
//abre un nuevo archivo temporal en modo de escritura binaria
//el archivo temporal se utilizara para escribir los datos del archivo original exepto los que se desea eliminar
    ofstream archivoTmp("Peliculass_tmp.DAT", ios::binary);
    Pelicula Pelicula;
    bool eliminada = false;
    while (archivo.read(reinterpret_cast<char*>(&Pelicula), sizeof(Pelicula))) {
        if (Pelicula.codigo != codigo) {
            archivoTmp.write(reinterpret_cast<const char*>(&Pelicula), sizeof(Pelicula));
        } else {
            eliminada = true;
        }
    }

    archivo.close();
    archivoTmp.close();
//elimina el archivo original y renombra el archivo temporal
//esto reemplaza el archivo origial con el archivo nuevo que no contiene el registro eliminado
    remove("Pelicula.DAT");
    rename("Peliculass_tmp.DAT", "Pelicula.DAT");

    if (eliminada) {
        cout << "Pelicula eliminado exitosamente!" << endl;

    } else {
        cout << "No se encontró  Pelicula con el codigo ingresado." << endl;
    }

}
//Funcion para desplegar todos los registros

void PeliculaCRUD::Desplegar() {
    system("cls");
 system("cls");
 cout << "\t\t\tMaria FLorencia Ariaga Chiroy-9959-23-6741" << endl<< endl;
    cout<<"------------------------ASIGNACION DE Pelicula---------------------"<<endl;
    cout<<" Codigo      Nombre del Pelicula        Genero         Precio "<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;

   //abre el archivo en modo lectura binaria y lee los datos del archivo
    ifstream archivo("Pelicula.DAT", ios::binary);
    if (!archivo) {
        cout << "No hay Peliculaes registradas." << endl;
        return;
    }

    Pelicula Pelicula;
    //lee de forma repetida cada registro del archivo hasta que no haya mas registros
    while (archivo.read(reinterpret_cast<char*>(&Pelicula), sizeof(Pelicula))) {
		//Imprime los registros leidos del archivo

		cout << setw(5)<< Pelicula.codigo;
        cout << setw(20)<< Pelicula.nombre;
        cout  << setw(20)<< Pelicula.Genero ;
        cout << setw(16)<< Pelicula.Precio ;
        cout<<" "<<endl;
            }

    archivo.close();

    cout << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();
}
