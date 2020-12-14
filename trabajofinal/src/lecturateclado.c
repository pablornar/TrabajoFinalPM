// Bibliotecas
#include "sapi.h"        // <= Biblioteca sAPI
#include "inicio.h"
#include "lecturateclado.h"

void lecturateclado()
{
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
}
