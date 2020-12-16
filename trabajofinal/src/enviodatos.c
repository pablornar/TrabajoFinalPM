// Bibliotecas
#include "sapi.h"        // <= Biblioteca sAPI
#include "inicio.h"
#include "enviodatos.h"

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

void enviodatos() {
	/* Buffer */
	    static char uartBuff[10];
	if (tarea == 3) {
		/* Conversión de muestra entera a ascii con base decimal */
		itoa(muestra16[i], uartBuff, 10); /* 10 significa decimal */
		/* Enviar muestra y Enter */
		uartWriteString(UART_USB, uartBuff);
		uartWriteByte(UART_232, datos8[i]);
		//uartWriteString(UART_USB, uartBuff);
		//uartWriteString( UART_USB, muestra );
		//uartWriteString(UART_232, "\r\n");
		uartWriteString(UART_USB, "\r\n");
		i = i + 1;
		if (i == 256) {
			i = 0;
			tarea = 0;
			//uartWriteString(UART_USB, "clear");
			//uartWriteString(UART_USB, "\r\n");
		}
	}
}
