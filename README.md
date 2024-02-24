# 4-Contenedoras

## Vector y unordered_map

**Objetivo**
* Practicar la adición, eliminación, consulta y modificación de elementos usando la clase contenedora `vector`, `iteradores` y `unordered_map`. 
* Usar algoritmos propios de los contenedores para insertar, eliminar y encontrar elementos.

**REGLA**: La clase Main será el único lugar donde se puede tener interacción con el usuario, es decir que no se debe tener entrada ni salida de datos por consola en ninguna otra clase en su programa.

### PARTE 1: MODIFICACIÓN (Principalmente): 
* Tanto en Refugio.cpp como en Perro.cpp encontrará uso de entradas y salidas de datos por consola, realice el refactor (modificación de código) para que la entrada y salida de datos por consola sólo se realice en el método main().
* Agregue el método en la clase Refugio para agregar un perro nuevo tanto en un vector como en un mapa no ordenado (Para el caso del mapa no ordenado la llave será el id del Perro y el valor un apuntador a la clase Perro.). Observe y analice la diferencia entre ambas implementaciones. y en comentarios, exprese los resultados de su observación.
* Agrege una funcion en el main que pida los datos básicos del perro y llame al método que creó en el punto anterior de la clase Refugio para agregar el nuevo perro en el mapa no ordenado y en el vector.
* Agrege un método en la clase Refugio para mostrar los Perros que están disponibles. A manera de ejercicio use este método (o bien construya 2 métodos) para mostrar tanto los perros que estan en el Vector como los que están en el mapa. Cada colección requiere su propio ciclo. 
* Modifique el código para que el ID del Perro sea un contador que se asigna automáticamente. Tenga en cuenta que no es necesario modificarlo cuando se eliminan perros.
* Agrege un método en la clase Refugio que retorne True si dado un ID de Perro que se recibe por parámetro el perro se encuentra en el Vector y False en caso contrario.
* Agrege un método en la clase Refugio que permita mostrar todos los Perros en el Vector que tengan una edad que se encuentre en un rango recibido por parámetro. Por Ejemplo, perros cuya edad esté entre 3 y 6 años.
* Agrege un método en la clase Refugio para eliminar un Perro (darlo en adopción) del vector y del mapa (dado el Id). Note cómo es mucho más sencillo identificar si un elemento se encuentra o no en una colección cuando se usan mapas.
* Agregue las opciones del menu en el main para probar todas las funcionalidades.

### PARTE 2: CREACIÓN (Principalmente): 
* El sistema deberá transformarse para soportar los siguientes cambios:
  + Ahora el sistema deberá interactuar con propietarios: El refugio tendra el registro de todos los propietarios.
  + Un propietario puede tener hasta 2 perros por adopción.
  + Debe existir el método adoptar (que recibe el ID del Perro y el ID del propietario) y consiste en borrar al perro del vector y del mapa del refugio pero adicionarlo a los perros a cargo del propietario.
  + Cuando un perro a cargo del propietario fallezca deberá borrarse de los perros a cargo del propietario.
  + Construya el método dondeEstaElPerro() que recibe el ID del perro e identifica si el perro se encuentra en el refugio o en caso de estar adoptado indica el ID y nombre del propietario.

### PARTE 3: CONCEPTOS Y DISEÑO:
* Para esta parte cree un Directorio nuevo en su proyecto (llamado Doc) y adicione el texto en archivos .md y las imágenes en PDF o JPG para dar respuesta a lo que en esta PARTE 3 se solicita.
* En la Parte 2 de la tarea fue necesario construir clases, crear relaciones y usar contenedores, en ese orden de ideas usted debe:
  + Indicar si utilizó relaciones de asociación o agregación y justificar su análisis.
  + indicar el o los contenedores nuevos que utilizó, justifique porqué uso estos y no otros.
  + Elabore el Diagrama UML de todo su programa, donde se note claramente, las clases, atributos, métodos y relaciones construidas.


## Fuentes de consulta
* Sobre STL  y contenedores [https://dev.to/pratikparvati/c-stl-containers-choose-your-containers-wisely-4lc4]
* Iteradores:   https://www.geeksforgeeks.org/introduction-iterators-c/
* Algoritmos por contenedor
    * Deque: https://www.geeksforgeeks.org/deque-cpp-stl/?ref=lbp
    * https://www.javatpoint.com/cpp-vector
    * https://www.javatpoint.com/post/cpp-list
    * https://www.javatpoint.com/cpp-set
    * Map: https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/?ref=leftbar-rightbar
    * Unordered map: https://www.geeksforgeeks.org/unordered_map-in-cpp-stl/