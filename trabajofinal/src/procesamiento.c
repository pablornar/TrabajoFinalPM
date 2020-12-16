// Bibliotecas
#include "sapi.h"        // <= Biblioteca sAPI
#include "inicio.h"
#include "procesamiento.h"

void procesamiento() {
	if (tarea == 2) {
		for (i = 0; i < 256; i++) {
			datos8[i] = (muestra16[i] * 256) / 1024;
		}
		i = 0;
		tarea = 3;
	}
}
