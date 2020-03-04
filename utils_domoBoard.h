/*
 * utils_domoBoard.h
 *
 *  Created on: 10/03/2015
 *      Author: jctejero
 */

#ifndef UTILS_DOMOBOARD_H_
#define UTILS_DOMOBOARD_H_

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/
#include	"Arduino.h"
#include	"domoBoard.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#define 	ON   				HIGH
#define     OFF					LOW

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
void Interruptor(tsSensor *Sensor);
void Actuador_Interruptor(tsSensor *Sensor);
void Pulsado_Soltado(tsSensor *Sensor);
void Actuador_Pulsado_Soltado(tsSensor *Sensor);
void conmutador(tsSensor *Sensor);
void Actuador_conmutador(tsSensor *Sensor);
void cambiarEstado(Actuador *actuador);


#endif /* UTILS_DOMOBOARD_H_ */
