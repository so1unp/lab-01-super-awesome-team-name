#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <archivo_encriptado>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int fd_in = open(argv[1], O_RDONLY, O_CREAT);
    int fd_out = open("mensaje_desencriptado.txt", O_CREAT, 0644);
    
    if (fd_in == -1 || fd_out == -1) {
        perror("Error al abrir archivos");
        exit(EXIT_FAILURE);
    }

    unsigned char buffer[8];
    
    while (read(fd_in, buffer, 8) == 8) {
        write(fd_out, &buffer[7], 1);
    }

    close(fd_in);
    close(fd_out);
    exit(EXIT_SUCCESS);
}
