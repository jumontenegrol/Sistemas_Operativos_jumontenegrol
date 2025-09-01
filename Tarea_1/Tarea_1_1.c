#include <stdio.h>
#include <stdlib.h>

struct Usuario {
    char nombre[30];
    char apellido[30];
    int edad;
    int estatura;
}
int main() {
    struct Usuario u;

    // Abrir archivo en modo lectura
    FILE *archivo = fopen("datos.txt", "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo. ¿Ya corriste Tarea_1?\n");
        return 1;
    }

    // Leer los datos del archivo
    fscanf(archivo, "%s %s %d %d", u.nombre, u apellido, &u.edad, &u.estatura);

    fclose(archivo);

    printf("Hola %s %s\n", u.nombre, u.apellido);
    printf("Tu edad es: %d\n", u.edad);
    printf("Tu estatura es: %d cm\n",u.estatura);

    return 0;
}