#ifndef LIBRERIAPARCIALLAB_H_INCLUDED
#define LIBRERIAPARCIALLAB_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>;

#endif // LIBRERIAPARCIALLAB_H_INCLUDED

#define TAM 5
#define TAMservicio 4

 struct
{
    int dia;
    int mes;
    int anio;

}typedef fecha;

 struct
{
    char marca[20];
    int id;

}typedef marca;

struct
{
    char color[20];
    int id;

}typedef color;

struct
{
    int id;
    char patente[10];
    int idMarca;
    int idColor;
    int modelo;
    int isEmpty;

}typedef car;

struct
{
    int id;
    char descripcionServicio [25];
    float precio;

}typedef servicio;

struct
{
    int id;
    int patente;
    int idServicio;
    int fecha;
}trabajo;


  marca listaMarca[TAM] =
    {
        {"Renault", 1000},
        {"Fiat", 1001},
        {"Ford", 1002},
        {"Chevrolet", 1003},
        {"Peugeot", 1004}
    };

 color listaColor[TAM] =
    {
        {"Negro", 5000},
        {"Blanco", 5001},
        {"Gris", 5002},
        {"Rojo", 5003},
        {"Azul", 5004}
    };

servicio listaServicio[TAMservicio] =
    {
        {2000, "Lavado", 250.00},
        {2001, "Pulido", 300.00},
        {2002, "Encerado", 400.00},
        {2003, "Completo", 600.00}
    };

/** \brief Carga los datos de un auto.
 *
 * \param car* list puntero al array de autos
 * \param len cantidad de estructuras
 * \param id es el id ingresado
 * \param patente es la patente ingresda
 * \param marca es el id de la marca ingresada
 * \param color es el id del color ingresado
 * \param modelo es el modelo ingresado
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int addAuto(car* list, int len, int id, char patente[], int Marca, int Color ,int modelo);

/** \brief inicializa el campo isEmpty
 *
 * \param car* list puntero al array de autos
 * \param len cantidad de estructuras
 * \return Devuelve un cero o un uno
 */
int initAutos(car* list, int len);

/** \brief pregunta si el campo isEmpty esta vacio
 *
 * \param car* list puntero al array de autos
 * \param len cantidad de estructuras
 * \return Devuelve un cero o un uno
 */
int buscarVacio(car* list, int len);

/** \brief busca un auto por id
 *
 * \param car* list puntero al array de autos
 * \param len cantidad de estructuras
  * \param id ingresado
 * \return Devuelve un cero o un uno
 */
int findCardById(car* list, int len, int id);

/** \brief setea el campo isEmpty en 1
 *
 * \param car* list puntero al array de autos
 * \param len cantidad de estructuras
  * \param id ingresado
 * \return Devuelve un cero o un uno
 */
int removeCar(car* list, int len, int id);

/** \brief imprime los datos
 *
 * \param car* list puntero al array de autos
 * \param len cantidad de estructuras
  * \param marca* listM puntero al array de Marcas
 * \return Devuelve un cero o un uno
 */
int printAutos(car* list, int len, marca* listM);

/** \brief busca una marca por id
 *
 * \param idMArca es el id de la marca ingresada
 * \param tam cantidad de estructuras
* \param marca* lista puntero al array de marcas
 */
int bucarMarca(int idMarca, int tam, marca* lista);


/** \brief busca el color por id
 *
 * \param idColor es el id del color ingresado
 * \param tam cantidad de estructuras
  * \param color* lista puntero al array de colores
 */
int buscarColor(int idColor, int tam, color* lista);
