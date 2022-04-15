/*
 * utn_lib.c
 *
 *  Created on: 14 abr. 2022
 *      Author: quisp
 */
#include "utn_lib.h"
#define BITCOIN 4606954.55

float calcularPorcentaje(float precio, int porc);
void precioTarjetaDebito(float precioXAero, float precioXLatam, float* preciosLatam, float* preciosAerolinea);
void precioTarjetaCredito(float precioXAero, float precioXLatam, float* preciosLatam, float* preciosAerolinea);
void precioBitcoin(float precioXAero, float precioXLatam, float* preciosLatam, float* preciosAerolinea);
void precioUnitario(int kmts, float precioXAero, float precioXLatam, float* preciosLatam, float* preciosAerolinea);
void diferenciaPrecios(float precioXAero, float precioXLatam, float* preciosLatam, float* preciosAerolinea);

void menuOpciones(int* opcion, int kmts, int flagKm, float precioXLatam, float precioXAero, int flagPrecio)
{
	printf("\nMenú de Opciones: ");
	if(flagKm == -1)
	{
		printf("\n1. Ingresar Kilómetros: ( km=x)");
	}else{
		printf("\n1. Ingresar Kilómetros: ( km=%d)", kmts);
	}
	if(flagPrecio == -1)
	{
		printf("\n2. Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z)");
	}else{
		printf("\n2. Ingresar Precio de Vuelos: (Aerolíneas=$%.2f, Latam=$%.2f)", precioXAero, precioXLatam);
	}
	printf("\n3. Calcular todos los costos:\n\ta) Tarjeta de débito (descuento 10%%)\n\tb) Tarjeta de crédito (interés 25%%)\n\tc) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)\n\td) Mostrar precio por km (precio unitario)\n\te) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)");
	printf("\n4. Informar Resultados\n5. Carga Forzada\n6. Salir");
	printf("\nSeleccione una opcion\n");
	scanf("%d", opcion);
}

void ingresarKmValido(int* pKm)
{
	scanf("%d",pKm);
	while(*pKm <= 0)
	{
		printf("Por favor ingrese un valor positivo");
		scanf("%d", pKm);
	}

}

void ingresarPrecioValido(float* pPrecio)
{
	scanf("%f",pPrecio);
	while(*pPrecio <= 0)
	{
		printf("Por favor ingrese un valor positivo");
		scanf("%f", pPrecio);
	}

}

int validarIngresoDeDatos(int flagKm,int flagPrecio)
{
	int estado = -1;
	if(flagKm == 1 && flagPrecio == 1)
	{
		estado=1;
	}
	return estado;
}

void calcularCostos(int kmts, float precioXAero, float precioXLatam, float* preciosLatam, float* preciosAerolinea)
{
	precioTarjetaDebito(precioXAero, precioXLatam, preciosLatam, preciosAerolinea);
	precioTarjetaCredito(precioXAero, precioXLatam, preciosLatam, preciosAerolinea);
	precioBitcoin(precioXAero, precioXLatam, preciosLatam, preciosAerolinea);
	precioUnitario(kmts, precioXAero, precioXLatam, preciosLatam, preciosAerolinea);
	diferenciaPrecios(precioXAero, precioXLatam, preciosLatam, preciosAerolinea);
}

float calcularPorcentaje(float precio, int porc)
{
	float resultado;
	resultado =  (porc * precio) / 100 ;
	return resultado;
}

void precioTarjetaDebito(float precioXAero, float precioXLatam, float* preciosLatam, float* preciosAerolinea)
{
	float descuento;

	descuento = calcularPorcentaje(precioXLatam, 10);
	preciosLatam[0] = precioXLatam - descuento;

	descuento = calcularPorcentaje(precioXAero, 10);
	preciosAerolinea[0] = precioXAero - descuento;

}

void precioTarjetaCredito(float precioXAero, float precioXLatam, float* preciosLatam, float* preciosAerolinea)
{
	float interes;

	interes = calcularPorcentaje(precioXLatam, 25);
	preciosLatam[1] = precioXLatam + interes;

	interes = calcularPorcentaje(precioXAero, 25);
	preciosAerolinea[1] = precioXAero + interes;
}

void precioBitcoin(float precioXAero, float precioXLatam, float* preciosLatam, float* preciosAerolinea)
{
	float precBitcoin;

	precBitcoin = precioXLatam/BITCOIN;
	preciosLatam[2] = precBitcoin;

	precBitcoin = precioXAero/BITCOIN;
	preciosAerolinea[2] = precBitcoin;
}

void precioUnitario(int kmts, float precioXAero, float precioXLatam, float* preciosLatam, float* preciosAerolinea)
{
	float precioUnit;

	precioUnit = precioXLatam/kmts;
	preciosLatam[3] = precioUnit;

	precioUnit = precioXAero/kmts;
	preciosAerolinea[3] = precioUnit;
}

void diferenciaPrecios(float precioXAero, float precioXLatam, float* preciosLatam, float* preciosAerolinea)
{
	float difPrecio;

	difPrecio = precioXAero - precioXLatam;
	if(difPrecio < 0)
	{
		difPrecio = difPrecio * (-1);
	}
	preciosLatam[4] = difPrecio;
	preciosAerolinea[4] = difPrecio;
}

void informarResultados(float* preciosLatam, float* preciosAerolinea)
{
	printf("\nLatam:\na) Precio con tarjeta de debito: $%.2f\nb) Precio con tarjeta de credito: $%.2f\nc) Precio pagando con bitcoin: %.2fBTC\nd) Precio unitario: $%.2f ", preciosLatam[0], preciosLatam[1], preciosLatam[2], preciosLatam[3]);
	printf("\nAerolineas:\na) Precio con tarjeta de debito: $%.2f\nb) Precio con tarjeta de credito: $%.2f\nc) Precio pagando con bitcoin: %.2fBTC\nd) Precio unitario: $%.2f ", preciosAerolinea[0], preciosAerolinea[1], preciosAerolinea[2], preciosAerolinea[3]);
	printf("\nLa diferencia de precio es $%.2f\n", preciosLatam[4]);

}

void cargaForzada(int* kmts, float* precioXAero, float* precioXLatam, float* preciosLatam, float* preciosAerolinea)
{
	*kmts = 7090;
	*precioXAero = 162965;
	*precioXLatam = 159339;
	calcularCostos(*kmts, *precioXAero, *precioXLatam, preciosLatam, preciosAerolinea);
	printf("\nKMs Ingresados: %d km\n", *kmts);
	printf("\nPrecio Aerolineas: $%.2f\n", *precioXAero);
	printf("a) Precio con tarjeta de debito: $%.2f\nb) Precio con tarjeta de credito: $%.2f\nc) Precio pagando con bitcoin: %.2fBTC\nd) Precio unitario: $%.2f \n", preciosAerolinea[0], preciosAerolinea[1], preciosAerolinea[2], preciosAerolinea[3]);

	printf("\nPrecio Latam: $%.2f\n", *precioXLatam);
	printf("a) Precio con tarjeta de debito: $%.2f\nb) Precio con tarjeta de credito: $%.2f\nc) Precio pagando con bitcoin: %.2fBTC\nd) Precio unitario: $%.2f \n", preciosLatam[0], preciosLatam[1], preciosLatam[2], preciosLatam[3]);
	printf("\nLa diferencia de precio es $%.2f\n", preciosLatam[4]);
}
