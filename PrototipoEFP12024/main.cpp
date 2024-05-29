//Maria Florencia Ariaga Chiroy 9959-23-6741
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "Login.h"
#include "Pelicula.h"
#include "Bitacora.h"

using namespace std;

void menuGeneral();
void catalogos();
void reportes();
void procesos();
void ayuda();
void seguridad();
string codigoPrograma="1000";
Bitacora Auditoria;
string user, contrasena;

int main()
{
        // Llamamos al objeto e ingresamos los parametros
    Login ingreso(user, contrasena);

    // Creamos un bool que verifique y despliegue el metodo VerificarUsuario
    bool UsuarioCorrecto = ingreso.VerificarUsuario();

    // Luego de ingresar con usuario y contraseña se nos despliega otro menu
    if (UsuarioCorrecto)
    {
        menuGeneral();
    }

    return 0;
}

void menuGeneral()
{
    int choice;


    do
    {
        system("cls");
		cout << "\t\t\tMaria FLorencia Ariaga Chiroy-9959-23-6741" << endl;
        cout << "\t\t\t+------------------------------+" << endl;
        cout << "\t\t\t|          BIENBENIDO          |" << endl;
        cout << "\t\t\t+------------------------------+" << endl;
        cout << "\t\t\t| 1. Catalogos                 |" << endl;
        cout << "\t\t\t| 2. Informes                  |" << endl;
        cout << "\t\t\t| 3. Seguridad                 |" << endl;
        cout << "\t\t\t| 4. Salir del Sistema         |" << endl;
        cout << "\t\t\t+------------------------------+" << endl;
        cout << "\t\t\t|Opcion a escoger:[1/2/3/4]    |" << endl;
        cout << "\t\t\t+------------------------------+" << endl;
        cout << "\t\t\tIngresa tu Opcion: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            catalogos();
            break;
        case 2:
        	{
        	PeliculaCRUD a;
			a.imprimir();
        	 Auditoria.ingresoBitacora(user,"1006","IPE");
        	         system("pause");
        	         }
            break;
        case 3:
        	{
             Bitacora Auditoria;
			Auditoria.visualizarBitacora();
			}
            break;
        case 4:
                    Auditoria.ingresoBitacora(user,codigoPrograma,"LGO"); //llamada para registrar la bitacora de seguridad
            exit(0);
        default:
            cout << "\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
            cin.ignore();
            cin.get();
        }
    } while (choice != 4);
}

void catalogos()
{
    int choice;

    do
    {
        system("cls");
        cout << "\t\t\t+-------------------------------------------+" << endl;
        cout << "\t\t\t|                 CATALOGOS                 |" << endl;
        cout << "\t\t\t+-------------------------------------------+" << endl;
		cout << "\t\t\t|1. Peliculas                               |" << endl;
        cout << "\t\t\t|2. Regresar al menu anterior               |" << endl;
        cout << "\t\t\t+-------------------------------------------+" << endl;
        cout << "\t\t\t| Opcion a escoger:[1/2]                    |" << endl;
        cout << "\t\t\t+-------------------------------------------+" << endl;
        cout << "\t\t\tIngresa tu Opcion: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
        	PeliculaCRUD Pelicula;
            Pelicula.CrudPelicula();

        }
            break;

             case 2:
        {

        }
            break;

        default:
            cout << "\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
            cin.ignore();
            cin.get();
        }
    } while (choice != 2);
}
