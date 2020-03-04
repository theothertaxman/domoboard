// Do not remove the include below
#include "P4_DomoBoard.h"


//The setup function is called once at startup of the sketch
void setup()
{
	//config_practica3_apt_1();
	config_practica4_apt_2();
	//config_practica3_apt_3();

	Serial.begin(19200);

	Serial.println("Test DomoBoard LIB");

	Serial.flush();
// Add your initialization code here
}

// The loop function is called in an endless loop
void loop()
{
	domoboard.leerAllSensor();

	if(Serial.available() >= 2){

		if (Serial.read() == '#') // Start of new control message
		{
			char command = Serial.read(); // Commands
			switch(command){
			case '1':
				config_practica4_apt_1_Pulsador();
				Serial.println("Modo de control: Pulsador");
				break;
			case '2':
				config_practica4_apt_1_Interruptor();
				Serial.println("Modo de control: Interruptor");
				break;
			case '3':
				config_practica4_apt_2();
				Serial.println("Modo de control: Conmutador");
				break;
			case '4':
				cambiarEstado(&domoboard.RELE_1);
				break;
			case '5':
				cambiarEstado(&domoboard.RELE_2);
				break;
			}
		}
	}
}
