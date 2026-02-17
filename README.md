# ft_printf

Una reimplementación de la función `printf` de la biblioteca estándar de C, desarrollada como parte del currículum de 42.

## 📋 Descripción

`ft_printf` es una función personalizada que replica el comportamiento de la función `printf` estándar de C. Este proyecto forma parte de los ejercicios fundamentales de 42 School y tiene como objetivo comprender en profundidad el funcionamiento de las funciones variádicas, el formateo de cadenas y la gestión de diferentes tipos de datos en C.

La implementación maneja múltiples especificadores de conversión y devuelve el número total de caracteres impresos, tal como lo hace la función original `printf`.

## ✨ Características

### Conversiones Soportadas

La función `ft_printf` soporta los siguientes especificadores de formato:

| Especificador | Descripción | Tipo |
|---------------|-------------|------|
| `%c` | Imprime un carácter individual | `char` |
| `%s` | Imprime una cadena de caracteres | `char *` |
| `%p` | Imprime un puntero en formato hexadecimal | `void *` |
| `%d` | Imprime un número decimal (base 10) | `int` |
| `%i` | Imprime un entero en base 10 | `int` |
| `%u` | Imprime un número decimal sin signo | `unsigned int` |
| `%x` | Imprime un número hexadecimal en minúsculas | `unsigned int` |
| `%X` | Imprime un número hexadecimal en mayúsculas | `unsigned int` |
| `%%` | Imprime el símbolo de porcentaje | N/A |

### Funcionalidades Especiales

- **Gestión de valores NULL**: Imprime `(null)` para cadenas NULL y `(nil)` para punteros NULL
- **Números negativos**: Manejo correcto de enteros negativos incluyendo `INT_MIN`
- **Contador de caracteres**: Retorna el número total de caracteres impresos
- **Valores hexadecimales**: Soporte para mayúsculas y minúsculas con prefijo `0x` para punteros

## 🚀 Instalación

### Requisitos Previos

- GCC o cualquier compilador de C compatible
- Make
- Sistema operativo Unix/Linux o macOS

### Compilación

1. Clona el repositorio:
```bash
git clone https://github.com/ncara42/ft_printf.git
cd ft_printf/ft_printf
```

2. Compila la biblioteca:
```bash
make
```

Esto generará el archivo `libftprintf.a`, una biblioteca estática que puedes enlazar con tus proyectos.

### Comandos del Makefile

- `make` o `make all`: Compila la biblioteca
- `make clean`: Elimina los archivos objeto
- `make fclean`: Elimina los archivos objeto y la biblioteca
- `make re`: Recompila completamente el proyecto (fclean + all)

## 📖 Uso

### Inclusión en tu Proyecto

1. Incluye el header en tu archivo fuente:
```c
#include "ft_printf.h"
```

2. Compila tu programa enlazando la biblioteca:
```bash
gcc -Wall -Wextra -Werror tu_programa.c -L. -lftprintf -o tu_programa
```

### Ejemplos de Uso

```c
#include "ft_printf.h"

int main(void)
{
    int num = 42;
    char *str = "Hola, mundo!";
    void *ptr = &num;
    
    // Imprimir diferentes tipos de datos
    ft_printf("Carácter: %c\n", 'A');
    ft_printf("Cadena: %s\n", str);
    ft_printf("Puntero: %p\n", ptr);
    ft_printf("Decimal: %d\n", num);
    ft_printf("Entero: %i\n", -42);
    ft_printf("Sin signo: %u\n", 4294967295u);
    ft_printf("Hexadecimal (min): %x\n", 255);
    ft_printf("Hexadecimal (may): %X\n", 255);
    ft_printf("Porcentaje: 100%%\n");
    
    // El valor de retorno es el número de caracteres impresos
    int count = ft_printf("Total de caracteres: ");
    ft_printf("%d\n", count);
    
    return 0;
}
```

### Salida Esperada:
```
Carácter: A
Cadena: Hola, mundo!
Puntero: 0x7ffeeb2a3a4c  (la dirección variará en cada ejecución)
Decimal: 42
Entero: -42
Sin signo: 4294967295
Hexadecimal (min): ff
Hexadecimal (may): FF
Porcentaje: 100%
Total de caracteres: 21
```

## 🔧 Detalles Técnicos

### Estructura del Proyecto

```
ft_printf/
├── includes/
│   └── ft_printf.h          # Archivo de cabecera con prototipos
├── srcs/
│   ├── ft_printf.c          # Función principal y lógica de parsing
│   ├── ft_putchar.c         # Imprime un carácter
│   ├── ft_putstr.c          # Imprime una cadena
│   ├── ft_putnbr.c          # Imprime un número entero
│   ├── ft_putunsigned.c    # Imprime un número sin signo
│   ├── ft_puthex.c          # Imprime número hexadecimal
│   └── ft_putptr.c          # Imprime un puntero
├── Makefile                 # Script de compilación
└── README.md               # Este archivo
```

### Arquitectura de la Implementación

1. **ft_printf**: Función principal que recibe una cadena de formato y argumentos variádicos
   - Utiliza `va_list`, `va_start`, y `va_end` para manejar argumentos variables
   - Itera sobre la cadena de formato buscando especificadores `%`

2. **ft_print_loop**: Recorre la cadena de formato carácter por carácter
   - Detecta el símbolo `%` y delega al manejador de conversión
   - Imprime caracteres literales directamente

3. **conversion**: Identifica el tipo de conversión y llama a la función correspondiente
   - Utiliza `va_arg` para extraer el argumento correcto del stack
   - Maneja cada especificador de formato

4. **Funciones auxiliares**: Cada una maneja un tipo específico de salida
   - Implementación recursiva para números (optimización de código)
   - Control preciso del conteo de caracteres
   - Gestión de casos especiales (NULL, valores mínimos, etc.)

### Consideraciones de Implementación

- **Sin buffer**: Todas las salidas se realizan directamente con `write(1, ...)`
- **Recursión**: Las funciones numéricas utilizan recursión para simplificar el código
- **Compilación estricta**: Compilado con flags `-Wall -Wextra -Werror` para máxima calidad
- **Norminette**: Código cumple con la Norma de 42 School
- **Sin funciones prohibidas**: No se utiliza la familia de funciones `printf` estándar

## 🧪 Testing

Para probar la función, puedes crear un archivo `main.c`:

```c
#include "ft_printf.h"

int main(void)
{
    int ret1, ret2;
    
    // Comparar con printf estándar
    ret1 = ft_printf("ft_printf: %d %s %x\n", 42, "test", 255);
    ret2 = printf("printf: %d %s %x\n", 42, "test", 255);
    
    ft_printf("ft_printf retornó: %d\n", ret1);
    printf("printf retornó: %d\n", ret2);
    
    return 0;
}
```

Compilar y ejecutar:
```bash
gcc -Wall -Wextra -Werror main.c -L. -lftprintf -o test
./test
```

## 📝 Limitaciones Conocidas

- No implementa flags de formato (-, +, 0, #, espacio)
- No soporta especificadores de ancho de campo
- No soporta especificadores de precisión
- No implementa modificadores de longitud (l, ll, h, hh)

Estas limitaciones son intencionales según los requisitos del proyecto de 42 School.

## 👤 Autor

**ncaravac** (ncara42)
- Email: ncaravac@student.42.fr
- GitHub: [@ncara42](https://github.com/ncara42)

## 📄 Licencia

Este proyecto es parte del currículum de 42 School y está disponible para propósitos educativos.

## 🎓 Contexto Académico

Este proyecto es parte de la rama obligatoria del currículum de 42 School. El objetivo es recrear una versión simplificada de `printf` para comprender:

- Funciones variádicas en C
- Manejo de diferentes tipos de datos
- Conversión de números a diferentes bases
- Gestión de memoria y buffers
- Buenas prácticas de programación en C

## 🔗 Recursos Adicionales

- [Manual de printf](https://man7.org/linux/man-pages/man3/printf.3.html)
- [Funciones variádicas en C](https://en.cppreference.com/w/c/variadic)
- [42 School](https://www.42.fr/)

---

*Desarrollado con 💻 en 42 School*
