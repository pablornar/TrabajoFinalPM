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
   delay_t Tm;
   delay_t Ttarea;

   /* Inicializar Retardo no bloqueante con tiempo en milisegundos
    (500ms = 0,5s) */
   delayConfig(&Ttarea, 1);

   /*Inicializacion de variables  */
   tempo=0;
   bancont=0;
   i = 0;
   tarea=0;
   mili=5;
   bantrigger = 0;

   /* ------------- REPETIR POR SIEMPRE ------------- */
	while (1) {
		lecturateclado();
		/* delayRead retorna TRUE cuando se cumple el tiempo de retardo */
		if (delayRead(&Ttarea)) {
			if (tempo == 1) {
				delayConfig(&Ttarea, mili);
				tempo=0;
			}
			lecturaADC();
		}
		procesamiento();
		enviodatos();
	}
   return 0;
}
