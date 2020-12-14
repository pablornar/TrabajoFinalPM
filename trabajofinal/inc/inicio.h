/*============================================================================
 * Licencia:
 * Autor:
 * Fecha:
 *===========================================================================*/

#ifndef _INICIO_H_
#define _INICIO_H_

/*==================[inclusiones]============================================*/



/*==================[macros]=================================================*/

/*==================[tipos de datos declarados por el usuario]===============*/

/*==================[declaraciones de datos externos]========================*/
uint8_t band1;
uint8_t band4;
uint8_t ret;
uint8_t valor1;
uint8_t valor4;
uint8_t tempo;
uint8_t bancont;
uint16_t muestra;
uint8_t muestra8[300];
uint16_t i;
uint8_t bandenviar;

/*==================[declaraciones de funciones externas]====================*/

extern void lecturateclado(void);
extern void lecturaADC(void);
extern void enviodatos(void);

/*==================[end of file]============================================*/
#endif
