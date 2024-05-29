#ifndef PELICULA_H
#define PELICULA_H
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

using namespace std;

struct Pelicula{
    int codigo;
    char nombre[50];
    char Genero[50];
    char Precio[50];

};
class PeliculaCRUD {
public:
    void Ingresar();
    void Modificar();
    void Borrar();
    void Desplegar();
    void CrudPelicula();

};
#endif // PELICULA_H
