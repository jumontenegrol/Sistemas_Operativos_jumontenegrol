#include <stdio.h>
#include <stdlib.h>

int main() {
    char nombre[30];
    char apellido[30];
    int edad;
    int estatura;

    printf("Ingrese su nombre: ");
    scanf("%s", nombre);
    printf("Ingrese su apellido: ");
    scanf("%s", apellido);
    printf("Ingrese su edad: ");
    scanf("%d", &edad);
    printf("Ingrese su estatura (en cm): ");
    scanf("%d", &estatura);

    // Abrir archivo en modo escritura
    FILE *archivo = fopen("datos.txt", "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    // Guardar los datos en el archivo
    fprintf(archivo, "%s %s %d %d\n", nombre, apellido, edad, estatura);

    fclose(archivo);

    printf("Datos guardados en datos.txt\n");

    return 0;
}
