# Gestion-de-conciertos
Una implementación arborescente y en memoria dinámica en C++ el TAD genérico “Conciertos”, y utilizar dicha implementación para crear una aplicación de venta de tickets para conciertos a estudiantes de la Universidad de Zaragoza.

Tareas:

1. Desarrollar una implementación dinámica en C++ , utilizando un árbol binario de búsqueda (ABB), del TAD genérico para representar colecciones de elementos de la forma (clave,dato), con claves no repetidas, sin límite en el número total de elementos que pueda contener una colección a la cual llamaremos “Conciertos”.

2. El TAD “unizar” alberga una lista de tickets comprados donde se indique el código del concierto y el precio, pudiendo comprar hasta 40 tickets con un importe máximo de 300 euros.

3. La venta de tickets permitirá adquirir tickets para los eventos de Conciertos, concretando su tipo genérico clave (código concierto) con un tipo de números enteros y el tipo dato se particularizará en un tipo evento. El tipo evento deberá poder utilizarse para representar toda la información que corresponda a un concepto de evento musical que incluya: nombre, lugar, fecha, hora y precio del evento. El tipo evento se deberá implementar en un TAD Eventos, de acuerdo a las indicaciones dadas en la asignatura, y ser diseñado con las operaciones y propiedades que se consideren adecuadas. El TAD Eventos deberá contar con una operación que dado un código de evento devuelva una cadena que contenga la información del evento en el siguiente formato:

  - Concierto: “nombre del evento”
  - Lugar: “lugar del evento”
  - Fecha: “dia del evento”
  - Hora: “hora del evento”
  - Precio: “precio del evento”
  
4. Utilizar los TADs implementados en las tareas anteriores para implementar un programa de prueba que nos permita realizar una venta de tickets a un estudiante, de acuerdo a lo que se describe a continuación. El programa deberá ofrecer un menú de opciones donde existan las siguientes posibilidades:

  

  - introducir concierto
  - mostrar un concierto
  - borrar un concierto
  - listas todos los conciertos
  - Inscribir cliente
  - mostar cliente
  - comprar ticket
  

 
