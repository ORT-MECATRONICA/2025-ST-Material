unsigned long TiempoUltimoCambio = 0; ///debe ser unsigened long ya que millis es de ese tipo.
					      ///y en el caso de que llegue al fin de los valores retorna en 0
const long Intervalo = 1000; /// intervalo en milisegundos

//// esta parte del codigo va dentro del loop donde se quiera usar el delay sin bloqueo
/// si se quiere tener varios retardos se puede adicionar un TiempoUltimoCambio2 y la variable ///tiempoahora se puede usar la misma.Osea no llamar dos veces a millis que consume recursos. 


void setup() {
 Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:

unsigned long TiempoAhora = millis();

	if (TiempoAhora - TiempoUltimoCambio >= Intervalo) ///delay sin bloqueo 
	{
	TiempoUltimoCambio = TiempoAhora;/// importante actualizar el tiempo
		///ingresar aca la funcion o proceso que se debe ejecutar cada dicho intervalo
    Serial.println("HOLA..");    //// ejemplo imprime un hola cada cierto internavalo
    ////
	}


}



