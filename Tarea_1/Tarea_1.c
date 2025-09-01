#include <stdio.h>
#include <stdlib.h>

struct Usuario{
    char nombre[30];
    char apellido[30];
    int edad;
    int estatura;

}
int main() {
    struct Usuario p;

    printf("Ingrese su nombre: ");
    scanf("%s", p.nombre);
    printf("Ingrese su apellido: ");
    scanf("%s", p.apellido);
    printf("Ingrese su edad: ");
    scanf("%d", &p.edad);
    printf("Ingrese su estatura (en cm): ");
    scanf("%d", &p.estatura);

    // Abrir archivo en modo escritura
    FILE *archivo = fopen("datos.txt", "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    // Guardar los datos en el archivo
    fprintf(archivo, "%s %s %d %d\n", p.nombre, p.apellido, p.edad, p.estatura);

    fclose(archivo);

    printf("Datos guardados en datos.txt\n");

    return 0;
}
