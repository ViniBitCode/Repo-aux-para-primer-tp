#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *archivo_entrada, *archivo_salida;

    archivo_entrada = fopen("archivos .txt/entrada.txt", "r");
    char palabras_a_analizar[256]; // Ver otra manera de hacer strings en C para que realmente se puedan meter de longitud desconocida

    archivo_salida = fopen("archivos .txt/salida.txt", "w");

    if (archivo_entrada != NULL)
    {
        fscanf(archivo_entrada, "%255s", palabras_a_analizar);
        printf("El conjunto de palabras es: %s", palabras_a_analizar);

        // Debatir forma para desglosar las palabras...
        // . Ir sacando de a 1 en base a la coma y meterlas en una estrucutura tipo Pila para LIFO
        //      . Propongo LIFO por como muestra en las imagenes la manera en la que salen las palabras

        fclose(archivo_entrada);
        fclose(archivo_salida);
    }
    else
    {
        printf("El archivo entrada.txt no ha podido abrirse");
    }

    return 0;
}
