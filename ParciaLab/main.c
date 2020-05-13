#include <stdio.h>
#include <stdlib.h>
#include <string.h>;
#include "LibreriaParcialLab.h"


int main()
{
 char seguir = 's';
 char confirmacion;
 char opcion;
 int flag = 0;

 car listaAutos[TAM];


    while(seguir == 's' )
        {
            printf(" 0.Alta Auto\n 1.Modificar Auto\n 2.Baja Auto\n 3.Listar Autos\n 3.Listar Marcas\n 5.Listar colores\n 6.Listar Servicio\n 7.Alta trabajo\n 8.Listar Trabajo\n 9.Salir\n\n");
            printf("Seleccione una opcion: \n");
            scanf("%c", &opcion);

            while(opcion < 48 || opcion > 57)
            {
                system("cls");
                printf("Opcion invalida \n\n");
                printf(" 0.Alta Auto\n 1.Modificar Auto\n 2.Baja Auto\n 3.Listar Autos\n 3.Listar Marcas\n 5.Listar colores\n 6.Listar Servicio\n 7.Alta trabajo\n 8.Listar Trabajo\n 9.Salir\n\n");
                printf("Seleccione una opcion valida: \n");
                scanf("%c", &opcion);

            }

            switch(opcion)
            {
                case '0':
                    {
                        system("cls");

                        int idAuto;
                        char patente[10];
                        int idMarca;
                        int idColor;
                        int modelo;
                        int respuestaAlta;


                            printf("*******Alta Auto*******\n\n");

                            printf("Ingrse el id de la Marca del auto: ");
                            scanf("%d", &idMarca);
                            system("cls");

                            printf("Ingrse el id del color: ");
                            scanf("%d", &idColor);
                            system("cls");

                            printf("Ingrese el id: ");
                            scanf("%d", &idAuto);
                            system("cls");

                            printf("Ingrese la patente: ");
                            fflush(stdin);
                            gets(patente);
                            system("cls");

                            printf("Ingrese el modelo (anio): ");
                            scanf("%d", &modelo);
                            system("cls");

                            initAutos(listaAutos, TAM);

                            respuestaAlta = addAuto(listaAutos, TAM, idAuto, patente, idMarca, idColor ,modelo);

                            while(respuestaAlta == 0)
                            {
                                printf("No es posible registrar el auto, intente otra vez\n\n");
                            }

                            printf("El auto se ha registrado correctamente\n\n");


                        }

                    break;

                case '1':
                    system("cls");

                    printf("*******Modificar Auto*******\n\n");

                    int idModificar;
                    char menuModificar;
                    char patenteModificar[10];
                    int idmarcaModificar;
                    int idcolorModificar;
                    int modeloModificar;
                    int rtaModificar;


                    printf("Ingrese el Id del auto que desea modificar: \n\n");
                    scanf("%d", &idModificar);
                    system("cls");

                    rtaModificar = findCardById(listaAutos, TAM, idModificar);

                    if(rtaModificar == -1)
                    {
                        printf("No se encontro el auto\n\n");
                    }
                    else
                    {
                        printf("Se enconto el auto\n\n");
                        printf(" A.patente\n B. Id de la marca\n C. Id del color\n D. Modelo\n\n");
                        printf("Ingrese la opcion que desea modificar: ");
                        fflush(stdin);
                        scanf("%c", &menuModificar);

                        while(menuModificar != 'a' && menuModificar != 'A' && menuModificar != 'b' && menuModificar != 'B' && menuModificar != 'c' && menuModificar != 'C' && menuModificar != 'd' && menuModificar != 'D')
                        {
                            system("cls");
                            printf(" A.patente\n B.Id de la marca\n C.Id del color\n D.Modelo\n\n");
                            printf("Ingrese una opcion valida: ");
                            fflush(stdin);
                            scanf("%c", &menuModificar);
                        }

                        switch(menuModificar)
                        {
                            case 'a':
                            case 'A':
                                system("cls");
                                printf("Reingrese la patente: ");
                                fflush(stdin);
                                gets(patenteModificar);
                                strcpy(listaAutos[rtaModificar].patente, patenteModificar);
                                system("cls");
                                printf("La patente fue modificado\n\n");
                                break;

                            case 'b':
                            case 'B':
                                system("cls");
                                printf("Reingrese el id de la marca: ");
                                scanf("%d", &idmarcaModificar);
                                listaAutos[rtaModificar].idMarca = idmarcaModificar;
                                system("cls");
                                printf("El id de la marca fue modificado\n\n");
                                break;

                            case 'c':
                            case 'C':
                                system("cls");
                                printf("Reingrese el id del color: ");
                                scanf("%d", &idcolorModificar);
                                listaAutos[rtaModificar].idColor = idcolorModificar;
                                system("cls");
                                printf("El id del color fue modificado\n\n");
                                break;

                            case 'd':
                            case 'D':
                                system("cls");
                                printf("Reingrese el modelo: ");
                                scanf("%d", &modeloModificar);
                                listaAutos[rtaModificar].modelo = modeloModificar;
                                system("cls");
                                printf("El sector fue modificado\n\n");
                                break;
                        }
                    }
                    break;

                case '2':
                    system("cls");
                    printf("*******Baja Auto*******\n\n");
                    int idBaja;
                    int rtaBaja;

                    printf("Ingrese el Id del auto que desea dar de baja: \n\n");
                    scanf("%d", &idBaja);

                    rtaBaja = removeCar( listaAutos, TAM, idBaja);

                    if(rtaBaja==0)
                    {
                        system("cls");
                        printf("Id erroneo\n\n");
                    }
                    else
                    {
                        system("cls");
                        printf("Se ha removido el auto con exito\n\n");
                    }

                    break;

                case '3':
                    printf("*******Lista de autos*******\n\n");

                    int flagMostrar = 0;
                    int indiceMarca;
                    int indiceColor;

                    printf("Marca     Color       Patente       Modelo       ID\n\n\n");

                    for(int i=0; i<TAM; i++)
                    {
                        if(listaAutos[i].isEmpty == 0)
                        {
                            indiceMarca = bucarMarca(listaAutos[i].idMarca, TAM, listaMarca);
                            indiceColor = buscarColor(listaAutos[i].idColor, TAM, listaColor);

                            printf("%s       %s       %s        %d           %d\n\n", listaMarca[indiceMarca].marca, listaColor[indiceColor].color, listaAutos[i].patente, listaAutos[i].modelo, listaAutos[i].id);
                            flagMostrar = 1;
                        }

                    }
                    if(flagMostrar == 0)
                    {
                        system("cls");
                        printf("No hay autos registrados\n\n");
                    }
                    break;

                case '4':
                    printf("*******Lista de marcas*******\n\n");

                     printf("Marca         ID\n\n\n");

                    for(int x=0; x<TAM; x++)
                    {
                        {
                            printf("%s          %d           %d\n\n", listaMarca[x].marca, listaMarca[x].id);
                        }

                    }
                    break;

                    case '5':
                    printf("*******Lista de colores*******\n\n");

                     printf("Color         ID\n\n\n");

                    for(int y=0; y<TAM; y++)
                    {
                        {
                            printf("%s          %d           %d\n\n", listaColor[y].color, listaColor[y].id);
                        }

                    }
                    break;

                    case '6':
                    printf("*******Lista de servicios*******\n\n");

                     printf("Servicio        Precio         ID\n\n\n");

                    for(int z=0; z<TAM; z++)
                    {
                        {
                            printf("%s          %d           %d\n\n", listaServicio[z].descripcionServicio, listaServicio[z].precio, listaServicio[z].id);
                        }

                    }
                    break;

                    case '7':

                        system("cls");

                            printf("*******Alta Trabajo*******\n\n");

                            printf("No llegue a realizar este punto\n\n");

                    break;

                    case '8':

                        system("cls");

                            printf("*******Listar Trabajos*******\n\n");

                            printf("No llegue a realizar este punto\n\n");

                    break;

                case '9':
                    system("cls");
                    printf("Confirme con 's' si siquiere salir del pograma:\n ");
                    fflush(stdin);
                    scanf("%c", &confirmacion);
                    if (confirmacion == 's')
                    {
                        system("cls");
                        printf("\n******Fin del programa********\n\n");
                        flag = 1;
                        break;

                    }
            }
            if(flag == 0)
            {
                printf("Para continuar ingrese 's': ");
                fflush(stdin);
                scanf("%c", &seguir);
                system("cls");
            }
            else
            {
                seguir = 'f';
            }
     }
 return 0;

}

int initAutos(car* list, int len)
{
    for(int i=0; i<len; i++)
    {
        list[i].isEmpty = 1;
    }

    return 0;
}
int addAuto(car* list, int len, int id, char patente[], int Marca, int Color ,int modelo)
{
    int indice;

    indice = buscarVacio(list, len);
     int flagAlta = 0;

    if(indice == -1)
    {
        flagAlta = 0;
        return flagAlta;
    }
    else
    {
        list[indice].id = id;
        strcpy(list[indice].patente, patente);
        list[indice].idMarca = Marca;
        list[indice].idColor = Color;
        list[indice].modelo = modelo;
        list[indice].isEmpty = 0;

        flagAlta = 1;
        return  flagAlta;
    }
}

int buscarVacio(car* list, int len)
{
    int indice = -1;

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty == 1)
        {
            indice = i;
            return i;
            break;
        }
    }

    return indice;
}
int findCardById(car* list, int len, int id)
{
    int indice = -1;

    for(int i=0; i<len; i++)
    {
        if(list[i].id == id && list[i].isEmpty == 0)
        {
            indice = i;
            return indice;
            break;
        }
    }
    return indice;
}
int removeCar(car* list, int len, int id)
{
    int flagBaja = 0;
    int flagID = 0;

    for( int i=0; i<len; i++)
    {
        if(list[i].id == id && list[i].isEmpty == 0)
        {
            list[i].isEmpty = 1;
            flagBaja = 1;
        }
    }
    if(flagBaja==0)
    {
        flagID = 0;
        return flagID;
    }
    else
    {
        flagID = 1;
        return flagID;
    }
}

int bucarMarca(int idMarca, int tam, marca* lista)
{
    int indice = -1;

    for(int i=0; i<tam; i++)
    {
        if(lista[i].id == idMarca)
        {
            indice = i;
            return indice;
            break;
        }
    }
    return indice;
}
int buscarColor(int idColor, int tam, color* lista)
{
    int indice = -1;

    for(int i=0; i<tam; i++)
    {
        if(lista[i].id == idColor)
        {
            indice = i;
            return indice;
            break;
        }
    }
    return indice;
}
