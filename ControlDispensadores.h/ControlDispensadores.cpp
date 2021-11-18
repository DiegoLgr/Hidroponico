#include "ControlDispensadores.h"
#include "Dispensador.h"

ControlDispensadores::ControlDispensadores(Notificador notificador)
{
 Dispensador sal1 = Dispensador();
 Dispensador sal2 = Dispensador();
 Dispensador sal3 = Dispensador();
 Dispensador acido= Dispensador();
 Dispensador base = Dispensador();

 notif = notificador;
}

void ControlDispensadores::rellenar(String nombre)
{if (nombre.compare("sal1") != 0) 
  sal1.rellenar();
 if (nombre.compare("sal2") != 0) 
  sal2.rellenar();
 if (nombre.compare("sal3") != 0) 
  sal3.rellenar();
 if (nombre.compare("acido") != 0) 
  acido.rellenar();
 if (nombre.compare("base") != 0) 
  base.rellenar();
}

void ControlDispensadores::comprobarContenido(String nombre)
{ float contsal1 = sal1.mostrar_contenido();
  float contsal2 = sal2.mostrar_contenido();
  float contsal3 = sal3.mostrar_contenido();
  float contacido = acido.mostrar_contenido();
  float contbase = base.mostrar_contenido();

  if (contsal1 <= 10.0) 
   notif.avisoSal1();
  if (contsal2 <= 10.0) 
   notif.avisoSal2();
  if (contsal3 <= 10.0) 
   notif.avisoSal3();
  if (contacido <= 10.0) 
   notif.avisoAcido();
  if (contbase <= 10.0) 
   notif.avisoBase();
}

 void ControlDispensadores::dispensar_Sales(float cansal1, float cansal2, float cansal3, Solenoide solsal1, Solenoide solsal2, Solenoide solsal3)
 {sal1.dispensar(cansal1);
  sal2.dispensar(cansal2);
  sal3.dispensar(cansal3);
  solsal1.encender((int) (cansal1));
  solsal2.encender((int) (cansal2));
  solsal3.encender((int) (cansal3));
  
 }
    
 void ControlDispensadores::dispensar_Acido(float cantidad, Solenoide solacido)
 {acido.dispensar(cantidad);
  solacido.encender((int) (cantidad));
  
 }
    
 void ControlDispensadores::dispensar_Base(float cantidad, Solenoide solbase)
 {base.dispensar(cantidad);
  solbase.encender((int) (cantidad));
  
 }
