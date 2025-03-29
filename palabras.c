#include <stdio.h>
#include <stdlib.h>

/*
   ## Ejercicio 2
Completar el programa `palabras.c` para que imprima las palabras que recibe desde la <em>entrada estándar</em>. Por ejemplo:
```
$ bin/palabras
Esto es un texto ↵
Esto
es
un
texto
Hola mundo ↵
Hola
```
*/
int main(void)
{
    char palabra[1024];
    int c;
    int i = 0;
    
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (i > 0) {
                palabra[i] = '\0';
                printf("%s\n", palabra);
                i = 0;
            }
        } else {
            palabra[i++] = c;
            if (i >= 1023) {
                palabra[i] = '\0';
                printf("%s\n", palabra);
                i = 0;
            }
        }
    }
    
    // Imprimir la última palabra si queda alguna
    if (i > 0) {
        palabra[i] = '\0';
        printf("%s\n", palabra);
    }
    
    exit(EXIT_SUCCESS);
}
