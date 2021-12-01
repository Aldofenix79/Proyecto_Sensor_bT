# Proyecto_Sensor_bT
Proyecto de sensor de temperatura monitoreado por bluetooth para la materia de embebidos.

El proyecto consiste en crear un sensor de temperatura monitoreado por bluetooth, con la intención de que pueda observarse el comportamiento del sensor en cualquier dispositivo móvil con la funcionalidad bluetooth, esto para facilitar el constante monitoreo en tiempo real, el cual puede ser utilizado en la industria o en el ámbito particular.
Este proyecto tiene la finalidad de avisar al usuario los cambios de temperatura y emitir una alerta, dependiendo a lo que se ajuste a sus necesidades.

CONEXION

![image](https://user-images.githubusercontent.com/91091105/143726325-030ba88c-680b-477c-b4c0-6010a1a57d31.png)

VIDEO DEL FUNCIONAMIENTO

https://drive.google.com/file/d/13n1JOV5dfPIQOg4DDto9mTSqRqZZX_2C/view?usp=sharing

LINKS DE REFERENCIA

COMUNICACION BLUETOOTH: https://www.youtube.com/watch?v=nwuxZL9ktRk

APP PARA LA TERMINAL BLUETOOTH: https://play.google.com/store/apps/details?id=ptah.apps.bluetoothterminal

IMPLEMENTACION DEL BUZZER: https://www.youtube.com/watch?v=fy23D10oUXQ

LIBRERIA PARA EL SENSOR (DHT11): https://www.arduino.cc/reference/en/libraries/dht-sensor-library/


# PROYECTO SENSOR BT V2

para la version 2 del proyecto, implemente la funcion de que el usuario pueda modificar los valores de temperatura y humedad maxima que el mismo desee, modificandolos desde su dispostivo movil.

la implementacion consiste en que la comunicacion serial(el monitor serialBT) lea puros enteros y no String, reservando el valor 1 y 0 para activar y desactivar la alarma respectivamente

![image](https://user-images.githubusercontent.com/91091105/144162606-c6c75123-267c-40a7-9c63-9aefb32a8386.png)

![image](https://user-images.githubusercontent.com/91091105/144163160-cdac3131-5c68-402d-a14d-5254e0e65e49.png)

CAPTURAS DE PANTALLA DE INTERACCCION

EMPEZANDO LA CONEXION:

![image](https://user-images.githubusercontent.com/91091105/144164802-f1fafe79-e8ea-47a5-97de-ee49d7b0a0ba.png)

ESTABLECIENDO 70 COMO VALOR MAXIMO DE HUMEDAD Y TEMPERATURA

![image](https://user-images.githubusercontent.com/91091105/144164887-53688712-5540-4190-8cce-1b60df1ddcde.png)

ESTABLECIENDO 35 COMO VALOR MAXIMO

![image](https://user-images.githubusercontent.com/91091105/144164916-306f1238-ea4f-4110-a852-a280e739f84a.png)









