/*
 * Version 1.1 (optimizado el uso de RAM)
 * Temporizador basado en millis()
 */
 
#ifndef Temporizador_inopya_h
#define Temporizador_inopya_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class Temporizador_inopya
{
  /*  ------ public ------  */    
  public:
    Temporizador_inopya( void ); 
	
	void begin( uint32_t );	

    bool estado( void );
    
	void stop( void );

  /*  ------ private ------  */              
  private:
    bool _FLAG_activo = false;
	uint32_t _start_time;
    uint32_t _valor_temporizador;

    
};


#endif 

