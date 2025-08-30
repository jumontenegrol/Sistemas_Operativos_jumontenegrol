#include <stdio.h>
#include <stdlib.h>

int main() {
    char nombre[30];
    char apellido[30];
    int edad;
    int estatura;

    // Abrir archivo en modo lectura
    FILE *archivo = fopen("datos.txt", "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo. ¿Ya corriste Tarea_1?\n");
        return 1;
    }

    // Leer los datos del archivo
    fscanf(archivo, "%s %s %d %d", nombre, apellido, &edad, &estatura);

    fclose(archivo);

    printf("Hola %s %s\n", nombre, apellido);
    printf("Tu edad es: %d\n", edad);
    printf("Tu estatura es: %d cm\n", estatura);

    return 0;
}