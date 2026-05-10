#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

typedef enum
{
    INICIAL,
    CERO,
    DECIMAL,
    OCTAL,
    HEXADECIMAL,
    HEXADECIMAL_X,
    ERROR
} Estados;

struct Palabra
{
    char caracter;
    Estados estado;
};

void evaluar_estado(struct Palabra *);

int main(int argc, char *argv[])
{
    FILE *archivo_entrada, *archivo_salida;

    archivo_entrada = fopen("archivos .txt/entrada.txt", "r");
    archivo_salida = fopen("archivos .txt/salida.txt", "w");

    struct Palabra *palabra_analizar;
    palabra_analizar->caracter = 0;
    palabra_analizar->estado = INICIAL;

    if (archivo_entrada != NULL)
    {
        while ((palabra_analizar->caracter = fgetc(archivo_entrada)) != EOF)
        {

            if (palabra_analizar->caracter != ',')
            {

                printf("%c", palabra_analizar->caracter);
                evaluar_estado(palabra_analizar);
            }
            else
            {
                if (palabra_analizar->estado == ERROR)
                {
                    printf(" NO RECONOCIDA");
                }
                else if (palabra_analizar->estado == DECIMAL)
                {
                    printf(" DECIMAL");
                }

                palabra_analizar->caracter = 0;
                palabra_analizar->estado = INICIAL;
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

Estados tabla_transiciones[7][6] = {
    {INICIAL, CERO, DECIMAL, DECIMAL, ERROR, ERROR},
    {CERO, OCTAL, OCTAL, ERROR, ERROR, HEXADECIMAL_X},
    {DECIMAL, DECIMAL, DECIMAL, DECIMAL, ERROR, ERROR},
    {HEXADECIMAL_X, HEXADECIMAL, HEXADECIMAL, HEXADECIMAL, HEXADECIMAL, ERROR},
    {HEXADECIMAL, HEXADECIMAL, HEXADECIMAL, HEXADECIMAL, HEXADECIMAL, ERROR},
    {OCTAL, OCTAL, OCTAL, ERROR, ERROR, ERROR},
    {ERROR, ERROR, ERROR, ERROR, ERROR, ERROR},
};

void evaluar_estado(struct Palabra *palabra)
{
    // Voy a hacer comparaciones para cada fila en base a la TT hecha en clase

    // Compara la primer fila
    if (palabra->estado == tabla_transiciones[0][0])
    {
        if (palabra->caracter == 0)
        {
            palabra->estado = tabla_transiciones[1][0];
        }
        else if (isdigit(palabra->caracter))
        {
            printf("Caracter: %d", palabra->caracter);
            if (palabra->caracter == '1')
            {
               printf("Hola");
            }
            
            palabra->estado = tabla_transiciones[2][0];
        }
        else
        {
            palabra->estado = tabla_transiciones[6][0];
        }
    }

    // Compara la tercer fila
    if (palabra->estado == tabla_transiciones[2][0])
    {

        if (isdigit(palabra->caracter))
        {

            palabra->estado = tabla_transiciones[2][0];
        }
        else
        {
            palabra->estado = tabla_transiciones[6][0];
        }
    }

    if (palabra->caracter == 'X' || palabra->caracter == 'x' && palabra->estado == tabla_transiciones[1][0])
    {
        palabra->estado = tabla_transiciones[3][0];
    }

    if (palabra->caracter == 'X' || palabra->caracter == 'x' && palabra->estado == tabla_transiciones[3][0])
    {
        palabra->estado = tabla_transiciones[6][0];
    }
}
