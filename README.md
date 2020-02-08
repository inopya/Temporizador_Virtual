# Temporizadores virtuales basados en la funcion Arduino millis()
  
  ### **Temporizadores versatiles y relativamente precisos basados en millis().**

  
    Para crear un temporizador: --> Temporizador_inopya nombreTemporizador;
    Los temporizadores virtuales disponen de tres metodos: begin(), stop() y estado()
      
		Una vez definido un temporizador se usa de la siguiente forma:
	  
		*nombreTemporizador.begin(tiempoEnMilisegundos) --> carga tiempo en el temporizador y lo inicia.
	  
		Si un temporizador esta en marcha no se puede sobreescribir su valor.
		Debe ser parado previamente o esperar a que acabe apra poder cargarle n nuevo valor.
		* nombreTemporizador.stop() --> detiene el temporizador, pasando su estado a ser 'false'.
	  
		* nombreTemporizador.estado() --> retorna un valor booleano: 
			true = temporizador aun activo; 
			false = temporizador terminado
