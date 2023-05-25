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


  • ico (introducir concierto):
    o Solicitar el código del concierto y los datos del evento y crear un nuevo concierto en la colección de conciertos.
    o si es posible introducir los datos del concierto, se mostrará en pantalla “INSERCION REALIZADA: ”; si el concierto ya existe se actualizarán los datos de ese evento y se mostrará “ACTUALIZACION REALIZADA: ”; si no es posible introducir o actualizar los datos del concierto, se mostrará “INSERCION DESCARTADA”
  • mco (mostrar un concierto):
oSolicitar el código del concierto y mostrar su contenido completo
oSe mostrará el código del concierto y toda la información del evento tal como se indica en los apartados
anteriores
2•
•
•
•
bco (borrar concierto):
oPedir el código del concierto y eliminarlo
oSi en la “venta de tickets” se encuentra un concierto con el código dado, se mostrará por pantalla
“CONCIERTO BORRADO:”, seguida de la clave utilizada, seguida de un salto de línea. Si no se
encuentra un concierto con el código dado, se mostrará “BORRADO DESCARTADO: ”, seguido del
código utilizado para la instrucción.
lco (listas todos los conciertos):
oMostrará un listado completo de todos los conciertos
oSe mostrará en pantalla la cadena devuelta por la operación listar descrita en la especificación del TAD
conciertos
icli (inscribir cliente):
oPedir el nombre y titulación del estudiante
oSi es posible añadir el estudiante en el proceso de venta, se mostrará en pantalla “cliente INSCRITO”
mcli (mostar cliente):
o
•
Mostrará un listado con todos los datos del estudiante y sus tickets adquiridos.
com (comprar ticket):
oMostrar listado de todos los conciertos, solicitar al cliente un código de concierto y actualizar los datos
del cliente y del proceso de venta
oSe mostrará: “TICKET COMPRADO OK”
oSi no es posible que el cliente actual compre un ticket debido a que y no hay clientes inscritos, se mostrará,
“NO HAY CLIENTES”; si no hay conciertos se mostrará, “NO HAY CONCIERTOS”; si el código del
concierto no existe, se mostrará “EL CODIGO NO PERTENECE A NINGUN CONCIERTO”.

 
