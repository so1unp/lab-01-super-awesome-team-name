#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

/**
 * Primer argumento: nombre del archivo de texto a leer
 */
int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <archivo>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Inicializar generador de números aleatorios
    srand(time(NULL));

    // Abrir archivo con llamada al sistema open()
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Error al abrir archivo");
        exit(EXIT_FAILURE);
    }

    unsigned char buffer;
    unsigned char random_bytes[7];
    
    // Abrir archivo de salida para guardar el mensaje encriptado
    int fd_out = open("mensaje_encriptado.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_out == -1) {
        perror("Error al crear archivo de salida");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Leer byte por byte
    while (read(fd, &buffer, 1) > 0) {
        for (int i = 0; i < 7; i++) {
            random_bytes[i] = rand() % 256;
            write(fd_out, &random_bytes[i], 1);
        }
        write(fd_out, &buffer, 1);
    }

    close(fd_out);
    close(fd);
    exit(EXIT_SUCCESS);
}
