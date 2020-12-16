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
uint8_t tempo;
uint8_t bancont;
uint16_t muestra16[300];
uint8_t datos8[300];
uint16_t i;
uint8_t tarea;
uint8_t mili;
uint8_t bantrigger;

/*==================[declaraciones de funciones externas]====================*/

extern void lecturateclado(void);
extern void lecturaADC(void);
extern void enviodatos(void);
extern void procesamiento(void);

/*==================[end of file]============================================*/
#endif
