// Bibliotecas
#include "sapi.h"        // <= Biblioteca sAPI
#include "inicio.h"
#include "enviodatos.h"

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
