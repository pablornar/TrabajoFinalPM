// Bibliotecas
#include "sapi.h"        // <= Biblioteca sAPI
#include "inicio.h"
#include "lecturaADC.h"

void lecturaADC() {
	if (tarea == 1) {

		if (bantrigger == 0) {
			muestra16[0] = adcRead(CH1);
			for (i = 1; i < 256; i++) {
				if ((i > 0) && (bantrigger == 0)) {
					muestra16[i] = adcRead(CH1);
					if (((muestra16[i] < 540) && (muestra16[i] > 482))
							&& (muestra16[i] > muestra16[i - 1])) {
						bantrigger = 1;
						muestra16[0] = muestra16[i];
						i = 255;
					}
				}
			}
			i = 1;
		}
		//bantrigger=1;
		if (bantrigger == 1) {
			/* Leo la Entrada Analogica AI0 - ADC0 CH1 */
			muestra16[i] = adcRead(CH1);
			i = i + 1;
			if (i == 256) {
				i = 0;
				bantrigger = 0;
				tarea = 2;
			}
		}
	}
}
