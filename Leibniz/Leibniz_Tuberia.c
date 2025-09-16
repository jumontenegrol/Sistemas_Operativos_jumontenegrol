#include <stdio.h>      
#include <stdlib.h>     
#include <unistd.h>     
#include <sys/types.h>  
#include <sys/wait.h>   

double pi = 0.0;
double suma_padre = 0.0, suma_hijo = 0.0;

int main()
{
  int pipefd[2];      
  
  if (pipe(pipefd) < 0) {
        perror("Error al crear el pipe");
        exit(1);
    }

    pid_t pid = fork();
    if (pid < 0) {
        perror("Error en fork");
        exit(1);
    }

  if (pid == 0)
  {
    close(pipefd[0]); 
    for (double i = 0; i < 500000000; i++){
      suma_hijo += 4.0 / ((4.0 * i) + 1.0);
    }
    write(pipefd[1], &suma_hijo, sizeof(suma_hijo));  
    close(pipefd[1]); 
    exit(0);
  }
  else
  {
    close(pipefd[1]); 
    for (double i = 1; i < 500000000; i++){
      suma_padre += 4.0 / ((4.0 * i) - 1.0);
    }
    wait(NULL);
        
    read(pipefd[0], &suma_hijo, sizeof(suma_hijo));
    close(pipefd[0]); 
    pi = suma_hijo - suma_padre;
    printf("%.20f\n", pi);
  }
  return 0;
}

