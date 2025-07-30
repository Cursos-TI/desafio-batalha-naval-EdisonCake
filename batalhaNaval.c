#include <stdio.h>
#include <stdlib.h> // Para abs()

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

// Desenvolvido por Edison Antonio - 30/07/2025

#define TAM_TAB 10
#define TAM_HAB 5
#define AGUA 0
#define NAVIO 3
#define CONE 5
#define CRUZ 6
#define OCTAEDRO 7

void inicializarTabuleiro(int tabuleiro[TAM_TAB][TAM_TAB])
{
    for (int i = 0; i < TAM_TAB; i++)
        for (int j = 0; j < TAM_TAB; j++)
            tabuleiro[i][j] = AGUA;
}

void imprimirTabuleiro(int tabuleiro[TAM_TAB][TAM_TAB])
{
    printf("\nTabuleiro Final:\n\n");
    for (int i = 0; i < TAM_TAB; i++)
    {
        for (int j = 0; j < TAM_TAB; j++)
        {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void posicionarNavios(int tabuleiro[TAM_TAB][TAM_TAB])
{
    // Navio horizontal
    for (int i = 0; i < 4; i++)
        tabuleiro[2][1 + i] = NAVIO;

    // Navio vertical
    for (int i = 0; i < 3; i++)
        tabuleiro[5 + i][6] = NAVIO;

    // Diagonal ↘
    for (int i = 0; i < 4; i++)
        tabuleiro[i][i] = NAVIO;

    // Diagonal ↙
    for (int i = 0; i < 4; i++)
        tabuleiro[i][9 - i] = NAVIO;
}

void habilidadeCone(int matriz[TAM_HAB][TAM_HAB])
{
    int centro = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++)
    {
        for (int j = 0; j < TAM_HAB; j++)
        {
            if (i >= centro && abs(j - centro) <= i - centro)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

void habilidadeCruz(int matriz[TAM_HAB][TAM_HAB])
{
    int centro = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++)
    {
        for (int j = 0; j < TAM_HAB; j++)
        {
            if (i == centro || j == centro)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

void habilidadeOctaedro(int matriz[TAM_HAB][TAM_HAB])
{
    int centro = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++)
    {
        for (int j = 0; j < TAM_HAB; j++)
        {
            if (abs(i - centro) + abs(j - centro) <= centro)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

void aplicarHabilidade(int tabuleiro[TAM_TAB][TAM_TAB], int matrizHabilidade[TAM_HAB][TAM_HAB], int origemLinha, int origemColuna, int codigoHabilidade)
{
    for (int i = 0; i < TAM_HAB; i++)
    {
        for (int j = 0; j < TAM_HAB; j++)
        {
            if (matrizHabilidade[i][j] == 1)
            {
                int x = origemLinha + i;
                int y = origemColuna + j;
                if (x >= 0 && x < TAM_TAB && y >= 0 && y < TAM_TAB)
                {
                    if (tabuleiro[x][y] == AGUA)
                    {
                        tabuleiro[x][y] = codigoHabilidade;
                    }
                }
            }
        }
    }
}

int main()
{
    int tabuleiro[TAM_TAB][TAM_TAB];
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    inicializarTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);

    habilidadeCone(cone);
    habilidadeCruz(cruz);
    habilidadeOctaedro(octaedro);

    // Aplicando habilidades em pontos diferentes do tabuleiro
    aplicarHabilidade(tabuleiro, cone, 4, 2, CONE);         // Aplica cone a partir de (4,2)
    aplicarHabilidade(tabuleiro, cruz, 0, 3, CRUZ);         // Aplica cruz a partir de (0,3)
    aplicarHabilidade(tabuleiro, octaedro, 5, 5, OCTAEDRO); // Aplica octaedro a partir de (5,5)

    imprimirTabuleiro(tabuleiro);

    return 0;
}
