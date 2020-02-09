/*
  #       _\|/_   A ver..., ¿que tenemos por aqui?
  #       (O-O)        
  # ---oOO-(_)-OOo---------------------------------
   
   
  ##########################################################
  # ****************************************************** #
  # *            DOMOTICA PARA AFICIONADOS               * #
  # *    Parpadeo de un led con tiempos asimetrisos      * #
  # *          Autor:  Eulogio López Cayuela             * #
  # *                                                    * #
  # *       Versión v1.0      Fecha: 07/03/2020          * #
  # ****************************************************** #
  ##########################################################
*/

#define __VERSION__ "Ejemplo parpadeo led con tiempos asimetricos\n"

/*
  
 ===== NOTAS DE LA VERSION =====
 

  1.- Control de parpadeo de un led con tiempos de encendido y apagado asimetricos   


*/ 



/*mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
//        IMPORTACION DE LIBRERIAS 
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm*/
#include <Temporizador_inopya.h>


/*mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
//        SECCION DE DECLARACION DE CONSTANTES  Y  VARIABLES GLOBALES
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm*/

//------------------------------------------------------
// Definiciones para pines y variables
//------------------------------------------------------

#define LED_ONBOARD                     13

#define DURACION_CICLO_PARPADEO           2000  // milisegundos
#define TIEMPO_LED_ON                      500  // milisegundos 



//------------------------------------------------------------------------
// Creacion de objetos del tipo Temporizador_inopya, 
// uno para cada una de las tareas
//------------------------------------------------------------------------

/* 
 * Los temporizadores virtuales disponen de dos metodos: begin() y estado()
 * 
 *  nombreTemporizador.begin(tiempoEnMilisegundos) --> carga tiempo en el temporizador y lo inicia.
 *  nombreTemporizador.estado() --> retorna un valor booleano: 
 *                                                              true = temporizador aun activo; 
 *                                                              false = temporizador terminado
 */
 
Temporizador_inopya duracionCicloParpadeo;    // controla el tiempo que dura un ciclo completo de parpadeo
Temporizador_inopya tiempoLEDon;              // Controla el tiempo que el led dbe permanecer encendido


//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm 
//***************************************************************************************************
//         FUNCION DE CONFIGURACION
//***************************************************************************************************
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm 

void setup() 
{
  pinMode(LED_ONBOARD, OUTPUT);
}



//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm 
//***************************************************************************************************
//  BUCLE PRINCIPAL DEL PROGRAMA   (SISTEMA VEGETATIVO)
//***************************************************************************************************
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm 


void loop() 
{  

  /* Mantener un parpadeo del led onboard con tiempos asimetris de encendido y apagado */
  
  if(duracionCicloParpadeo.estado()==false){
    duracionCicloParpadeo.begin(DURACION_CICLO_PARPADEO);       // tiempo apagado + t. encendido
    tiempoLEDon.begin(TIEMPO_LED_ON);                           // tiempo encendido
  }
  
  digitalWrite(LED_ONBOARD, tiempoLEDon.estado());
}





//*******************************************************
//                    FIN DE PROGRAMA
//*******************************************************
