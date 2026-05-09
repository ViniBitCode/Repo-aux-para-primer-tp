#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *archivo_entrada, *archivo_salida;
    char* conjunto_palabras = "";
    int prueba;
    archivo_entrada = fopen("entrada.txt", "r"); 
    archivo_salida = fopen("entrada.txt", "w");
    if (archivo_entrada != NULL)
    {
        fscanf(archivo_entrada,"%d", &prueba);
        printf("El conjunto de palabras es: %d" + prueba);
        printf("Hola mundo");
        fclose(archivo_entrada);
    }
    else
    {
        printf("El archivo entrada.txt no ha podido abrirse");
    }

    return 0;
}
