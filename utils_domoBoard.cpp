/*
 * utils_domoBoard.cpp
 *
 *  Created on: 10/03/2015
 *      Author: jctejero
 */

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/
#include "utils_domoBoard.h"
#include "HardwareSerial.h"

void Interruptor(tsSensor *Sensor)
{
	if(Sensor->valor_Df == Sensor->valor){
		Serial.print(Sensor->name);
		Serial.print(" : Interruptor --> ");
		if(Sensor->Aux == OFF){
			Sensor->Aux = ON;
			Serial.println("ON");
		}else{
			Sensor->Aux = OFF;
			Serial.println("OFF");
		}
	}
}

void Actuador_Interruptor(tsSensor *Sensor){
	if(Sensor->valor_Df == Sensor->valor){
		Serial.print(Sensor->name);
		Serial.print(" : Interruptor --> ");
		if(Sensor->Aux == OFF){
			Sensor->Aux = ON;
			Serial.println("ON");
			domoboard.sensorActuador(Sensor,ON);
		}else{
			Sensor->Aux = OFF;
			Serial.println("OFF");
			domoboard.sensorActuador(Sensor,OFF);
		}

	}

}
void Pulsado_Soltado(tsSensor *Sensor){
	Serial.print(Sensor->name);
	if(Sensor->Aux == Sensor->valor){
		Serial.println(" --> Soltado");
	}else{
		Serial.println(" --> Pulsado");
	}

}

void Actuador_Pulsado_Soltado(tsSensor *Sensor){
	Serial.print(Sensor->name);
	if(Sensor->Aux == Sensor->valor){
		Serial.println(" --> Soltado");
		domoboard.sensorActuador(Sensor,OFF);
	}else{
		Serial.println(" --> Pulsado");
		domoboard.sensorActuador(Sensor,ON);
	}

}


void conmutador(tsSensor *Sensor)
{
	static int valor = OFF;

	if(Sensor->valor_Df == Sensor->valor){
		Serial.print("Conmutador --> ");
		if(valor == OFF){
			valor = ON;
			Serial.println("ON");

		}else{
			valor = OFF;
			Serial.println("OFF");
		}
	}
}
void Actuador_conmutador(tsSensor *Sensor)
{
	static int valor = OFF;

	if(Sensor->valor_Df == Sensor->valor){
		Serial.print("Conmutador --> ");
		if(valor == OFF){
			valor = ON;
			Serial.println("ON");
			domoboard.sensorActuador(Sensor,ON);
		}else{
			valor = OFF;
			Serial.println("OFF");
			domoboard.sensorActuador(Sensor,OFF);
		}
	}

}

void cambiarEstado(Actuador *act){
	if(act->valor == OFF){
		Serial.println(act->name+": ON");
		domoboard.actuar(act,ON);
	}else{
		Serial.println(act->name+": OFF");
		domoboard.actuar(act,OFF);
	}
}




