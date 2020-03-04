/*
 * domoBoard.cpp
 *
 *  Created on: 09/03/2015
 *      Author: jctejero
 */

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/
#include "domoBoard.h"

// Constructors ////////////////////////////////////////////////////////////////

DomoBoard::DomoBoard()
{
	//Definimos pin's DomoBoard.
	pinMode(BUTTON_1, INPUT);
	pinMode(BUTTON_2, INPUT);
	pinMode(RELAY_1, OUTPUT);
	pinMode(RELAY_2, OUTPUT);
	pinMode(ENTRADA_OPTOCOPLADA, INPUT);      	//Pin Entrada Optocoplada

	BOTON1.sSensor.pin 			= BUTTON_1;
	BOTON1.sSensor.valor 		= HIGH;
	BOTON1.sSensor.Activo 		= true;
	BOTON1.sSensor.numSensorAct = 0;
	BOTON1.sSensor.eSensor  	= S_DIGITAL;
	BOTON1.sSensor.name			= "BOTÓN 1";
	BOTON1.sSensor.valor_Df 	= HIGH;


	BOTON2.sSensor.pin 			= BUTTON_2;
	BOTON2.sSensor.valor 		= HIGH;
	BOTON2.sSensor.Activo 		= true;
	BOTON2.sSensor.numSensorAct = 0;
	BOTON2.sSensor.eSensor  	= S_DIGITAL;
	BOTON2.sSensor.name			= "BOTÓN 2";
	BOTON2.sSensor.valor_Df 	= HIGH;

	BTN_OPT.sSensor.pin 		= ENTRADA_OPTOCOPLADA;
	BTN_OPT.sSensor.valor 		= LOW;
	BTN_OPT.sSensor.Activo 		= true;
	BTN_OPT.sSensor.eSensor 	= S_DIGITAL;
	BTN_OPT.sSensor.name		= "Pulsador Optocoplado";
	BTN_OPT.sSensor.valor_Df	= LOW;

	RELE_1.pin					= RELAY_1;
	RELE_1.Activo				= true;
	RELE_1.valorDF 				= LOW;
	RELE_1.name					= "RELE 1";

	RELE_2.pin					= RELAY_2;
	RELE_2.Activo				= true;
	RELE_2.valorDF 				= LOW;
	RELE_2.name					= "RELE 2";


}

void DomoBoard::leerAllSensor(void){
	leerSensor(&BOTON1);
	leerSensor(&BOTON2);
	leerSensor(&BTN_OPT);
}


void  DomoBoard::leerSensor(ptsSensor *Sensor){
	int valor = 0;

	if(Sensor->sSensor.Activo){
		switch (Sensor->sSensor.eSensor)
		{
		case S_DIGITAL:
			valor = digitalRead(Sensor->sSensor.pin);
			break;

		case S_ANALOGICO:
			valor = analogRead(Sensor->sSensor.pin);
			break;
		}

		if(Sensor->sSensor.valor != valor)
		{
			Sensor->sSensor.valor = valor;

			//Si hay un cambio en el estado del sensor llamamos a la aplicación asociada
			if(Sensor->SensorApp != NULL)
				Sensor->SensorApp(&(Sensor->sSensor));
		}
	}
}

void DomoBoard::actuar(Actuador *act, int nuevoEstado){
	if((nuevoEstado==1)||(nuevoEstado==0)){
		act->valor = nuevoEstado;
	}else{
		act->valor = act->valorDF;
	}
		if(act->Activo){

		digitalWrite(act->pin,act->valor);
		}

}


void DomoBoard::writeAllactuador(void){

	actuar(&RELE_1,-1);
	actuar(&RELE_2,-1);

}

void DomoBoard::sensorActuador(tsSensor *Sensor, int estado){
	for(int i = 0; i<=Sensor->numSensorAct; i++){
		actuar(Sensor->actuadores[i],estado);
	}
}

void DomoBoard::relacionar(tsSensor sensor, Actuador actuador){
	Actuador* act = &actuador;

	sensor.actuadores[sensor.numSensorAct] = act;
	sensor.numSensorAct++;
}

DomoBoard domoboard;

