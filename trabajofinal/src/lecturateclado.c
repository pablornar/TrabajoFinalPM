// Bibliotecas
#include "sapi.h"        // <= Biblioteca sAPI
#include "inicio.h"
#include "lecturateclado.h"
/* Inicializacion de variables locales*/




void lecturateclado() {
	band1 = 1;
	band4 = 0;
	valor1 = 0;
	valor4 = 0;
	if (tarea == 0) {
		valor1 = !gpioRead(TEC1);
		valor4 = !gpioRead(TEC4);
		if ((valor1 == 1) && (band1 == 0)) {
			band1 = 1;
			band4 = 0;
		} else if ((valor4 == 1) && (band4 == 0)) {
			band4 = 1;
			band1 = 0;
		} else if ((!gpioRead(TEC2)) == 1) {
			tempo = 1;
		} else if ((!gpioRead(TEC3)) == 1) {
			tempo = 2;
		}
		tarea = 1;
	}
	if (uartReadByte(UART_USB, &receivedByte)) {
			switch (receivedByte) {
			case 'a':
			tempo=1;
			break;
			case 'b':
			tempo=2;
			break;
			}
			tarea = 1;
		}
}
