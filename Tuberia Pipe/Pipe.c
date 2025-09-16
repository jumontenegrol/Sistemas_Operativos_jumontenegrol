#include <stdio.h>      
#include <stdlib.h>     
#include <unistd.h>     
#include <sys/types.h>  
#include <sys/wait.h>   

int main() {
    int pipefd[2];      
    char buffer[10];
    pid_t pid;
    int r;

    // Crear la tubería
    if (pipe(pipefd) < 0) {
        perror("Error al crear el pipe");
        exit(1);
    }

    // Crear un hijo
    pid = fork();
    if (pid < 0) {
        perror("Error en fork");
        exit(1);
    }

    if (pid == 0) {  
        // ----- Proceso Hijo -----
        close(pipefd[0]); // cerrar el extremo de lectura (no lo usa)
        write(pipefd[1], "Hola", 4);  // enviar "hola"
        
        close(pipefd[1]); // cerrar extremo de escritura
        exit(0);
    } else {  
        // ----- Proceso Padre -----
        close(pipefd[1]); // cerrar el extremo de escritura (no lo usa)
        
        r = read(pipefd[0], buffer, sizeof(buffer) - 1);
        if (r < 0) {
            perror("Error en read");
            exit(1);
        }
        buffer[r] = '\0';  // asegurarse que sea string válido
        printf("Padre recibió: %s\n", buffer);
        
        close(pipefd[0]); // cerrar extremo de lectura
        wait(NULL);       // esperar a que el hijo termine
    }

    return 0;
}
