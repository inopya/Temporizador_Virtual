/*
 * Version 1.0
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
    Temporizador_inopya(void); 
	
	void begin(uint32_t tiempo_accion);	

    bool estado(void);
    
	void stop(void);

  /*  ------ private ------  */              
  private:
    bool _FLAG_activo = false;
    uint32_t _start_time;
    uint32_t _last_uptate;
    uint32_t _actual_time;
    uint32_t _end_time;
    bool _FLAG_overflow = false;	//control para temporizadores proximos al desbordamiento de millis()
    					//y que podrian causar errores (usa _last_uptate)
    
    void _start(uint32_t _tiempo_tarea);  
};


#endif 

