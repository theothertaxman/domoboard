/*
 * config_practicas.cpp
 *
 *  Created on: 10/03/2015
 *      Author: jctejero
 */

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/
#include	"config_practicas.h"

/****************************************************************************/
/***                 Functions                                            ***/
/****************************************************************************/
void config_practica3_apt_1(void){
	domoboard.BOTON1.SensorApp = Pulsado_Soltado;

	domoboard.BOTON2.SensorApp = Pulsado_Soltado;

	domoboard.BTN_OPT.SensorApp = Pulsado_Soltado;
}

void config_practica3_apt_2(void){
	domoboard.BOTON1.SensorApp = Interruptor;
	domoboard.BOTON1.sSensor.Aux = OFF;

	domoboard.BOTON2.SensorApp = Interruptor;
	domoboard.BOTON2.sSensor.Aux = OFF;

	domoboard.BTN_OPT.SensorApp = Interruptor;
	domoboard.BTN_OPT.sSensor.Aux = OFF;
}

void config_practica3_apt_3(void){
	domoboard.BOTON1.SensorApp = conmutador;

	domoboard.BOTON2.SensorApp = conmutador;

	domoboard.BTN_OPT.SensorApp = conmutador;
}

void config_practica4_apt_1_Pulsador(void){
	domoboard.BOTON1.SensorApp = Actuador_Pulsado_Soltado;
	domoboard.relacionar(domoboard.BOTON1.sSensor,domoboard.RELE_1);
	domoboard.BOTON2.SensorApp = Actuador_Pulsado_Soltado;
	domoboard.relacionar(domoboard.BOTON2.sSensor,domoboard.RELE_2);

	domoboard.writeAllactuador();
}
void config_practica4_apt_1_Interruptor(void){
	domoboard.BOTON1.SensorApp = Actuador_Interruptor;
	domoboard.relacionar(domoboard.BOTON1.sSensor,domoboard.RELE_1);

	domoboard.BOTON2.SensorApp = Actuador_Interruptor;
	domoboard.relacionar(domoboard.BOTON2.sSensor,domoboard.RELE_2);

	domoboard.writeAllactuador();
}
void config_practica4_apt_2(void){
	domoboard.BOTON1.SensorApp = Actuador_conmutador;
	domoboard.relacionar(domoboard.BOTON1.sSensor,domoboard.RELE_1);
	domoboard.relacionar(domoboard.BOTON1.sSensor,domoboard.RELE_2);

	domoboard.BOTON2.SensorApp = Actuador_conmutador;
	domoboard.relacionar(domoboard.BOTON2.sSensor,domoboard.RELE_1);
	domoboard.relacionar(domoboard.BOTON2.sSensor,domoboard.RELE_2);

	domoboard.writeAllactuador();
}
