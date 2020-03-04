/*
 * domoBoard.h
 *
 *  Created on: 09/03/2015
 *      Author: jctejero
 */

#ifndef DOMOBOARD_H_
#define DOMOBOARD_H_

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/
#include	"Arduino.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#define 	BUTTON_1   				3   	   	// Pulsador 1
#define 	BUTTON_2   				4        	// Pulsador 2
#define		RELAY_1					8			// Rele 1
#define		RELAY_2					11			// Rele 2
#define 	ENTRADA_OPTOCOPLADA    	13 	    	// Entrada Optocoplada
#define		NUMACTUADORES			8			// Numero de Actuadores

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

typedef enum
{
	S_DIGITAL,
	S_ANALOGICO
}teSensor;

typedef struct
{
	byte		pin;			//Pin asignado al actuador
	int			valor;			//Estado actual del actuador (ON/OFF)
	int	    	valorDF;		//Valor por defecto del componente
	bool		Activo;			//Activar/Desactivar Actuador
	String		name;			//Nombre del actuador
}Actuador;


typedef struct
{
	byte		pin;			//Pin asignado al sensor
	int	    	valor;			//Valor leido
	int			valor_Df;		//Valor Sensor por defecto
	bool		Activo;			//Activar/Desactivas sensor
	teSensor	eSensor;		//Tipos de sensor ANALÓGICO/DIGITAL
	int			Aux;			//Variables para ser usadas en la gestión del sensor
	int			numSensorAct;	//Numero de actuadores relacionados con el sensor (Numero de elementos en el array)
	Actuador	*actuadores[NUMACTUADORES];
	String		name;
}tsSensor;

typedef void (*TNotifySensorEvent)(tsSensor *);

typedef struct
{
	tsSensor			sSensor;
	TNotifySensorEvent	SensorApp;	//Evento para aplicación asociada
}ptsSensor;


/****************************************************************************/
/***        Exported Class                                                ***/
/****************************************************************************/
class DomoBoard
{
private:


public:

	DomoBoard(); 						//Constructor

	ptsSensor		BOTON1;
	ptsSensor		BOTON2;
	ptsSensor 		BTN_OPT;
	Actuador		RELE_1,RELE_2;


	void 	leerAllSensor(void);
	void 	leerSensor(ptsSensor *Sensor);
	void 	actuar(Actuador *act, int nuevoEstado);
	void 	writeAllactuador(void);
	void	sensorActuador(tsSensor *Sensor, int estado);
	void	relacionar(tsSensor sensor, Actuador actuador);
};

extern DomoBoard domoboard;


#endif /* DOMOBOARD_H_ */
