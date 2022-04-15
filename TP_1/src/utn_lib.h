/*
 * utn_lib.h
 *
 *  Created on: 14 abr. 2022
 *      Author: quisp
 */

#ifndef UTN_LIB_H_
#define UTN_LIB_H_

#include <stdio.h>
#include <stdlib.h>

/*
 *\brief valida si se ingreso kmts validos
 *\param pKm (el puntero donde voy a guardar el valor ingresado)
 *\return no retorna nada es una funcion void
 * */
void ingresarKmValido(int* pKm);
/*
 *\brief valida si se ingreso un precio valido
 *\param pPrecio (el puntero donde voy a guardar el valor ingresado)
 *\return no retorna nada es una funcion void
 * */
void ingresarPrecioValido(float* pPrecio);
/*
 *\brief valida si se ingresaron los datos
 *\param flagKm (es el estado del km si se ingreso o no el mismo)
 *\param flagPrecio (es el estado del precio si se ingreso o no el mismo)
 *\return devuelve 1 si se ingresaron los 2 datos y devuelve -1 caso contrario
 * */
int validarIngresoDeDatos(int flagKm,int flagPrecio);
/*
 *\brief Calcula los costos
 *\param kmts (valor del km ingresado)
 *\param precioXAero (valor del precio Aerolinea ingresado)
 *\param precioXLatam (valor del precio Latam ingresado)
 *\param preciosLatam (puntero del vector donde se guardaran los resultados de las operaciones de Latam)
 *\param preciosAerolinea (puntero del vector donde se guardaran los resultados de las operaciones de Aerolineas)
 *\return no retorna nada es una funcion void
 * */
void calcularCostos(int kmts, float precioXAero, float precioXLatam, float* preciosLatam, float* preciosAerolinea);
/*
 *\brief informa los resultados de los calculos realizados
 *\param preciosLatam (puntero del vector donde se encuentran los resultados de las operaciones de Latam)
 *\param preciosAerolinea (puntero del vector donde se encuentran los resultados de las operaciones de Aerolineas)
 *\return no retorna nada es una funcion void
 * */
void informarResultados(float* preciosLatam, float* preciosAerolinea);
/*
 *\brief realiza la carga forzada de datos, calcula y informa los resultados
 *\param kmts (punteros donde se guardara el km ingresado por carga forzada)
 *\param precioXAero (punteros donde se guardara el precio Aerolinea ingresado por carga forzada)
 *\param precioXLatam (punteros donde se guardara el precio Latam ingresado por carga forzada)
 *\param preciosLatam (puntero del vector donde se guardaran los resultados de las operaciones de Latam)
 *\param preciosAerolinea (puntero del vector donde se guardaran los resultados de las operaciones de Aerolineas)
 *\return no retorna nada es una funcion void
 * */
void cargaForzada(int* kmts, float* precioXAero, float* precioXLatam, float* preciosLatam, float* preciosAerolinea);
/*
 *\brief muestra el menu de opciones y almacena la opcion seleccionada por el usuario
 *\param opcion (puntero donde guardo la opcion seleccionada del usuario)
 *\param kmts (valor del km ingresado)
 *\param flagKm (es el estado del km si se ingreso o no el mismo)
 *\param precioXLatam (valor del precio Latam ingresado)
 *\param precioXAero (valor del precio Aerolineas ingresado)
 *\param flagPrecio (es el estado de los precios si se ingresaron o no)
 *\return no retorna nada es una funcion void
 * */
void menuOpciones(int* opcion, int kmts, int flagKm, float precioXLatam, float precioXAero, int flagPrecio);
#endif /* UTN_LIB_H_ */
