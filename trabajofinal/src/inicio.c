// Bibliotecas
#include "sapi.h"        // <= Biblioteca sAPI
#include "inicio.h"

void inicio() {
	/* Inicializar UART_USB a 115200 baudios */
	uartConfig(UART_USB, 230400);
	uartConfig(UART_232, 230400);
	/* Inicializar AnalogIO */
	adcConfig(ADC_ENABLE); /* ADC */

	/*Inicializacion de variables  */
	tempo = 0;
	bancont = 0;
	i = 0;
	tarea = 0;
	mili = 5;
	bantrigger = 0;
}
