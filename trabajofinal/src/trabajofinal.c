/*============================================================================
 * Autor: Narvaez Pablo
 * Licencia:
 * Fecha:07/12/2020
 *===========================================================================*/

// Inlcusiones
#include "trabajofinal.h"         // <= Su propia cabecera
#include "sapi.h"        // <= Biblioteca sAPI

/** FUNCION PARA CONVERTIR A ASCII CON BASE 10
 * C++ version 0.4 char* style "itoa":
 * Written by Lukás Chmela
 * Released under GPLv3.
 */
char* itoa(int value, char* result, int base) {
   // check that the base if valid
   if (base < 2 || base > 36) { *result = '\0'; return result; }

   char* ptr = result, *ptr1 = result, tmp_char;
   int tmp_value;

   do {
      tmp_value = value;
      value /= base;
      *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
   } while ( value );

   // Apply negative sign
   if (tmp_value < 0) *ptr++ = '-';
   *ptr-- = '\0';
   while(ptr1 < ptr) {
      tmp_char = *ptr;
      *ptr--= *ptr1;
      *ptr1++ = tmp_char;
   }
   return result;
}

/* Variables Globales*/
      uint8_t band1 = 1;
      uint8_t band4 = 0;
      uint8_t ret = 200;
      uint8_t valor1 = 0;
      uint8_t valor4 = 0;
      uint8_t tempo=0;
      uint8_t bancont=0;
      /* Variable para almacenar el valor leido del ADC CH1 */
      uint16_t muestra;
      uint8_t muestra8[300];
      uint16_t i=0;
      uint8_t bandenviar=0;
      const gpioMap_t secuencia[]={LEDB, LED1, LED2, LED3};

      /* Buffer */
      static char uartBuff[10];


//Prototipos de funciones-------------
void borrarleds(void);
void lecturateclado(void);
void lecturaADC(void);
void enviodatos(void);      
void onTimer(void *unused);


// FUNCION PRINCIPAL, PUNTO DE ENTRADA AL PROGRAMA LUEGO DE ENCENDIDO O RESET.
int main(void) {

	/* ------------- INICIALIZACIONES ------------- */
	/* Inicializar la placa */
	boardConfig();

	/*timer*/
	//gpioInit(LEDR, GPIO_OUTPUT);
	//tickInit(50);
	//tickCallbackSet(onTimer, 0);

	/* Inicializar UART_USB a 115200 baudios */
	uartConfig(UART_USB, 230400);
	uartConfig(UART_232, 230400);
	/* Inicializar AnalogIO */
	adcConfig(ADC_ENABLE); /* ADC */

	/* Variable de Retardo no bloqueante */
	delay_t delay;

	/* Inicializar Retardo no bloqueante con tiempo en milisegundos
	 (500ms = 0,5s) */
	delayConfig(&delay, 100);


	/* ------------- REPETIR POR SIEMPRE ------------- */
   while (1)
   {
      lecturateclado();
      /* delayRead retorna TRUE cuando se cumple el tiempo de retardo */
      if (delayRead(&delay)) {
         if (tempo == 1) {
            delayConfig(&delay, 0.1);
         } else if (tempo == 2) {
            delayConfig(&delay, 1);
         }
         lecturaADC();
      }
      if(bandenviar==1) {
            enviodatos();
         }
   }

	/* NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa no es llamado
	 por ningun S.O. */
	return 0;
}


//-----------------Funciones------------------------------
void onTimer(void *unused) {
	gpioToggle(LEDG);
}

void lecturaADC()
{
   if (bandenviar==0) {
      /* Leo la Entrada Analogica AI0 - ADC0 CH1 */
      muestra = adcRead(CH1);
      muestra8[i] = (muestra*256)/1024;
      i=i+1;
      if(i==256) {
         i=0;
         bandenviar=1;
      }
   }
}

void enviodatos()
{
   /* Conversión de muestra entera a ascii con base decimal */
   //itoa(muestra, uartBuff, 10); /* 10 significa decimal */
   /* Enviar muestra y Enter */
   //uartWriteString(UART_USB, muestra);
   uartWriteByte(UART_232, muestra8[i]);
   //uartWriteString(UART_USB, uartBuff);
   //uartWriteString( UART_USB, muestra );
   //uartWriteString(UART_232, "\r\n");
   //uartWriteString(UART_USB, "\r\n");
   i=i+1;
   if (i==256) {
      i=0;
      bandenviar=0;
   }
}

void borrarleds() {
	gpioWrite(LEDB, OFF);
	gpioWrite(LED3, OFF);
	gpioWrite(LED2, OFF);
	gpioWrite(LED1, OFF);
}

void lecturateclado() {
	valor1 = !gpioRead(TEC1);
	valor4 = !gpioRead(TEC4);

	if ((valor1 == 1) && (band1 == 0)) {
		band1 = 1;
		band4 = 0;
		borrarleds();
	} else if ((valor4 == 1) && (band4 == 0)) {
		band4 = 1;
		band1 = 0;
		borrarleds();
	} else if ((!gpioRead(TEC2)) == 1) {
		tempo = 1;
	} else if ((!gpioRead(TEC3)) == 1) {
		tempo = 2;
	}
}


