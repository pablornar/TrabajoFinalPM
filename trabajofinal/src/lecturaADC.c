// Bibliotecas
#include "sapi.h"        // <= Biblioteca sAPI
#include "inicio.h"
#include "lecturaADC.h"



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
