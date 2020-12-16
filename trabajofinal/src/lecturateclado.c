// Bibliotecas
#include "sapi.h"        // <= Biblioteca sAPI
#include "inicio.h"
#include "lecturateclado.h"
/* Inicializacion de variables locales*/




void lecturateclado() {
	if (tarea == 0) {
		if ((!gpioRead(TEC2)) == 1) {
			tempo = 1;
			mili = mili + 1;
			if (mili > 20) {
				mili = 20;
			}
		} else if ((!gpioRead(TEC3)) == 1) {
			tempo = 1;
			mili = mili - 1;
			if (mili < 2) {
				mili = 1;
			}
		}

		if (uartReadByte(UART_USB, &receivedByte)) {
			switch (receivedByte) {
			case 'a':
				tempo = 1;
				mili = mili + 1;
				if (mili > 20) {
					mili = 20;
				}
				break;
			case 'b':
				tempo = 1;
				mili = mili - 1;
				if (mili < 2) {
					mili = 1;
				}
				break;
			}
		}

		tarea = 1;
	}
}
