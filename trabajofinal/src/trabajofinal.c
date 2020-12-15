/*============================================================================
 * Autor: Narvaez Pablo
 * Licencia:
 * Fecha:07/12/2020
 *===========================================================================*/

// Inlcusiones
#include "sapi.h"        // <= Biblioteca sAPI
#include "inicio.h"
#include "trabajofinal.h"         // <= Su propia cabecera

/* Variable para almacenar los leds */
const gpioMap_t secuencia[] = { LEDB, LED1, LED2, LED3 };


// FUNCION PRINCIPAL, PUNTO DE ENTRADA AL PROGRAMA LUEGO DE ENCENDIDO O RESET.
int main(void)
{
   /* ------------- INICIALIZACIONES ------------- */
   /* Inicializar la placa */
   boardConfig();

   /* Inicializar UART_USB a 115200 baudios */
   uartConfig(UART_USB, 230400);
   uartConfig(UART_232, 230400);
   /* Inicializar AnalogIO */
   adcConfig(ADC_ENABLE); /* ADC */

   /* Variable de Retardo no bloqueante */
   delay_t delay;
   delay_t tarea;

   /* Inicializar Retardo no bloqueante con tiempo en milisegundos
    (500ms = 0,5s) */
   delayConfig(&delay, 100);

   /*Inicializacion de variables  */
   tempo=0;
   bancont=0;
   i = 0;
   bandenviar = 0;

   /* ------------- REPETIR POR SIEMPRE ------------- */
	while (1) {
		lecturateclado();
		/* delayRead retorna TRUE cuando se cumple el tiempo de retardo */
		if (delayRead(&delay)) {
			if (tempo == 1) {
				delayConfig(&delay, 1);
			} else if (tempo == 2) {
				delayConfig(&delay, 2);
			}
			lecturaADC();
		}
		enviodatos();
	}
   return 0;
}
