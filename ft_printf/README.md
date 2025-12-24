*Este proyecto ha sido creado como parte del currículo de 42 por ncaravac.*

# ft_printf

## Descripción
Este proyecto consiste en implementar una función propia `ft_printf`, que replica el comportamiento de la función estándar `printf` de C para un conjunto específico de conversiones.

Las conversiones soportadas son:

- `%c` → carácter
- `%s` → string
- `%p` → puntero
- `%d` / `%i` → entero con signo
- `%u` → entero sin signo
- `%x` / `%X` → hexadecimal en minúsculas / mayúsculas
- `%%` → símbolo `%`

El objetivo principal del proyecto es practicar el uso de funciones variádicas (`stdarg.h`), el formateo de salida y la creación de una librería estática en C.

---

## Instrucciones

### Compilación
Para compilar la librería, ejecuta el siguiente comando en la raíz del proyecto:

```bash
make
```

Comandos disponibles en el Makefile
```
1. make → compila la librería libftprintf.a
```
```
2. make clean → elimina los archivos objeto .o
```
```
3. make fclean → elimina los archivos .o y la librería .a
```
```
4. make re → recompila todo (equivale a make fclean + make)
```

### Antes del uso

Antes de compilar, la librería se encuentra en la carpeta `./includes`, es importante que en tu archivo `main.c` uses la dirección correcta:

### Ejemplo de uso
```
#include "./includes/ft_printf.h"

int main(void)
{
    ft_printf("Hola %s, el número es %d y en hex es %x\n", "mundo", 42, 42);
    return 0;
}
```
### Uso

Para usar la librería en un archivo `main.c`, compila de la siguiente manera:
```
gcc main.c libftprintf.a -o example
```



## Elección del algoritmo y estructura de datos

### Algoritmo

El algoritmo utilizado en `ft_printf` se basa en un recorrido secuencial del string de formato, carácter por carácter.  
Mientras se recorre la cadena:

1. Si el carácter actual **no es `%`**, se imprime directamente.
2. Si se detecta un `%`, se analiza el carácter siguiente para identificar el tipo de conversión.
3. Dependiendo de la conversión encontrada (`%c`, `%s`, `%d`, etc.), se llama a una función específica encargada de imprimir ese tipo de dato.
4. Cada función devuelve el número de caracteres impresos, que se acumula para devolver el valor final de `ft_printf`, replicando el comportamiento de `printf`.

---

### Estructura de datos

No se utilizan estructuras de datos complejas en este proyecto, ya que no son necesarias para cumplir los requisitos funcionales de `printf`.  
Las herramientas principales utilizadas son:

- **Argumentos variádicos** (`va_list`, `va_start`, `va_arg`, `va_end`) para acceder a un número variable de argumentos.
- **Variables locales** para el control del índice y el conteo de caracteres impresos.
- **Funciones auxiliares** especializadas para cada tipo de conversión, lo que mejora la legibilidad y modularidad del código.

Esta elección evita el uso innecesario de memoria dinámica y mantiene el código sencillo, eficiente y fácil de mantener.

### Justificacion

Se optó por este diseño porque:
- Replica de forma fiel el comportamiento de `printf`.
- Es fácil de depurar y extender.
- Favorece la claridad del código frente a soluciones más complejas.

El uso de funciones separadas por tipo de conversión permite un código modular y organizado, facilitando futuras ampliaciones o correcciones.

---

## Recursos
1. Stackoverflow
2. Documentación de C
3. Inteligencia Artifical
<br> Manejo de errores, sugerencias de optimización y mejora de legibilidad del código.
