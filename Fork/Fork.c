#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define N 400000000

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Error en fork");
        return 1;
    }

    if (pid == 0) {
        long suma_hijo = 0;
        for (int i = 0; i < N; i++) {
            suma_hijo += i; 
        }
        printf("Hijo (PID %d) terminó. Suma = %ld\n", getpid(), suma_hijo);
    } 
    else {
        wait(NULL); 
        long suma_padre = 0;
        for (int i = 0; i < N; i++) {
            suma_padre += i * 2;  
        }
        printf("Padre (PID %d) terminó. Suma *2= %ld\n", getpid(), suma_padre);
    }

    return 0;
}
