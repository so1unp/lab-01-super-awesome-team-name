#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
   ## Ejercicio 1
Completar el programa `sum.c` para que retorne la suma de los números enteros indicados desde la línea de comandos o bien desde la entrada estándar (uno o más números por línea).

Por ejemplo, para sumar números indicadolos como argumentos al invocar el programa el comando sería así:
```
$ bin/sum 1 2 3
6
```

Para sumar números ingresados desde la entrada estándar, la ejecución sería así (`↵` representa un Enter y `^D` significa `Ctrl + D`, que ingresa un `EOF`):

Utilizar la funcion [`atoi()`](https://www.man7.org/linux/man-pages/man3/atoi.3.html) para convertir las cadenas de texto a números enteros.     
*/
extern char *strtok(char *str, const char *delim);
extern int atoi(const char *nptr);

int main(int argc, char *argv[])
{        
    int suma = 0;
    
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            suma += atoi(argv[i]);
        }
    } 
   
    else {
        char linea[100];
        char *token;

        while (fgets(linea, sizeof(linea), stdin) != NULL) {
            token = strtok(linea, " \t\n");
            
            while (token != NULL) {
                suma += atoi(token);
                token = (char *)strtok(NULL, " \t\n");
            }
            
            printf("%d\n", suma);
        }
    }
    
    if (argc > 1) {
        printf("%d\n", suma);
    }
    
    exit(EXIT_SUCCESS);
}
