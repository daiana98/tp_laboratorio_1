/*
 ============================================================================
 Name        : TP_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn_lib.h"

int main(void) {
	setbuf(stdout,NULL);

	int kmts;
	int opcion;
	float precioXLatam;
	float precioXAero;
	int flagKm = -1;
	int flagPrecio = -1;
	int flagCalculado = -1;
	float preciosLatam[5];
	float preciosAerolinea[5];

	do {//\n\t\t- Precio vuelo Aerolineas: (%f)\n\t\t- Precio vuelo Latam: (%f)
		menuOpciones(&opcion, kmts, flagKm, precioXLatam, precioXAero, flagPrecio);

		/*printf("\nMenú de Opciones: \n\t1. Ingresar Kilómetros: ( km=x)\n\t2. Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z)\n\t3. Calcular todos los costos:\n\t4. Informar Resultados\n\t5. Carga Forzada\n\t6. Salir");
		printf("\nSeleccione una opcion\n");
		scanf("%d", &opcion);*/

		switch (opcion) {
			case 1:
				printf("Por favor ingrese los kilometros");
				ingresarKmValido(&kmts);
				flagKm = 1;
				break;
			case 2:
				printf("Precio vuelo Aerolíneas:");
				ingresarPrecioValido(&precioXAero);
				printf("Precio vuelo Latam:");
				ingresarPrecioValido(&precioXLatam);
				flagPrecio = 1;
				break;
			case 3:
				if(validarIngresoDeDatos(flagKm, flagPrecio) == 1)
				{
					calcularCostos(kmts, precioXAero, precioXLatam, preciosLatam, preciosAerolinea);
					flagCalculado = 1;
				}else
				{
					printf("\nPor favor ingrese los datos");
				}
				break;
			case 4:
				if(flagCalculado == 1)
				{
					informarResultados(preciosLatam, preciosAerolinea);
				}else
				{
					printf("\nPor favor calcule los costos");
				}
				break;
			case 5:
				cargaForzada(&kmts, &precioXAero, &precioXLatam, preciosLatam, preciosAerolinea);
				flagKm = 1;
				flagPrecio = 1;
				flagCalculado = 1;
				break;
			case 6:
				printf("Hasta luego....");
				break;
			default:
				printf("Por favor ingrese una opcion valida");
				break;
		}

	} while (opcion != 6);

	return EXIT_SUCCESS;
}
