/*============================================================================
 * Autor: Narvaez Pablo
 * Licencia:
 * Fecha:07/12/2020
 *===========================================================================*/

// Inlcusiones
#include "sapi.h"        // <= Biblioteca sAPI
#include "inicio.h"
#include "trabajofinal.h"         // <= Su propia cabecera


// FUNCION PRINCIPAL, PUNTO DE ENTRADA AL PROGRAMA LUEGO DE ENCENDIDO O RESET.
int main(void) {
	/* ------------- INICIALIZACIONES ------------- */
	boardConfig();	//inicializacion de placa
	inicio();		//inicializacion

	/* Variable de Retardo no bloqueante */
	delay_t Tm;
	delay_t Ttarea;

	/* Inicializar Retardo no bloqueante con tiempo en milisegundos
	 (500ms = 0,5s) */
	delayConfig(&Ttarea, 1);

	/* ------------- REPETIR POR SIEMPRE ------------- */
	while (1) {
		lecturateclado();
		if (delayRead(&Ttarea)) { /* delayRead retorna TRUE cuando se cumple el tiempo de retardo */
			if (tempo == 1) {
				delayConfig(&Ttarea, mili);
				tempo = 0;
			}
			lecturaADC();
		}
		procesamiento();
		enviodatos();
	}
	return 0;
}
