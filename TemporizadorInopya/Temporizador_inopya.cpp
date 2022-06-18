/*
 * Version 1.1 (optimizado el uso de RAM)
 * Temporizador basado en millis()
 */

#include "Temporizador_inopya.h"


Temporizador_inopya::Temporizador_inopya( void )
{	
  _FLAG_activo = false;
}  


void Temporizador_inopya::begin( uint32_t tiempo_accion )  //tiempo recibido en millis
{ 
  if(tiempo_accion==0){ return; }
  
  if(_FLAG_activo == false){
	_start_time = millis();
	_valor_temporizador = tiempo_accion - 1;
	_FLAG_activo = true; 
  }
}


void Temporizador_inopya::stop( void )
{
  _FLAG_activo = false;	
}


bool Temporizador_inopya::estado( void )
{
  if (_FLAG_activo == true){	
	if( millis() -_start_time > _valor_temporizador){ _FLAG_activo = false; }
  }
  return _FLAG_activo;
}
