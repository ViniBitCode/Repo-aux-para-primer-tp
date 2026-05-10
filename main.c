#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *archivo_entrada, *archivo_salida;

    archivo_entrada = fopen("archivos .txt/entrada.txt", "r");
    int caracter;
    archivo_salida = fopen("archivos .txt/salida.txt", "w");

    if (archivo_entrada != NULL)
    {
        while ((caracter = fgetc(archivo_entrada)) != EOF)
        {
            if (caracter != ',')
            {
                printf("%c", caracter); // Imprimir carácter por carácter
            }
            else
            {
                printf("\n");
            }
        }

        fclose(archivo_entrada);
        fclose(archivo_salida);
    }
    else
    {
        printf("El archivo entrada.txt no ha podido abrirse");
    }

    return 0;
}
