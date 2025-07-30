#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

// Desenvolvido por Edison Antonio - 30/07/2025
void imprimirMatriz(int matriz[5][5], const char *nome)
{
    printf("\n🔥 Habilidade: %s\n\n", nome);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void habilidadeCone(int matriz[5][5])
{
    // Zera a matriz
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            matriz[i][j] = 0;

    // Formato de cone
    matriz[0][2] = 1;
    matriz[1][1] = matriz[1][2] = matriz[1][3] = 1;
    for (int j = 0; j < 5; j++)
        matriz[2][j] = 1;
}

void habilidadeCruz(int matriz[5][5])
{
    // Zera a matriz
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            matriz[i][j] = 0;

    // Cruz
    for (int j = 0; j < 5; j++)
        matriz[1][j] = 1;

    matriz[0][2] = 1;
    matriz[1][2] = 1;
    matriz[2][2] = 1;
}

void habilidadeOctaedro(int matriz[5][5])
{
    // Zera a matriz
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            matriz[i][j] = 0;

    // Octaedro
    matriz[0][2] = 1;
    matriz[1][1] = matriz[1][2] = matriz[1][3] = 1;
    matriz[2][2] = 1;
}

int main()
{
    int matriz[5][5];

    // Habilidade Cone
    habilidadeCone(matriz);
    imprimirMatriz(matriz, "CONE");

    // Habilidade Cruz
    habilidadeCruz(matriz);
    imprimirMatriz(matriz, "CRUZ");

    // Habilidade Octaedro
    habilidadeOctaedro(matriz);
    imprimirMatriz(matriz, "OCTAEDRO");

    return 0;
}
