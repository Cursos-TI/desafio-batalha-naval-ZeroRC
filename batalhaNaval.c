#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

#define TAMANHO_L 10
#define TAMANHO_C 10
#define HORIZONTAL 0
#define VERTICAL 1
#define AGUA 0
#define NAVIO 3

int validarPosicionar(int tabuleiro[TAMANHO_L][TAMANHO_C], int linha, int coluna, int orientacao) {

    if (linha >= TAMANHO_L || coluna >= TAMANHO_C) return 0;

    if (orientacao == HORIZONTAL) {
        if (coluna + NAVIO >= TAMANHO_C) return 0;

        for (int j = coluna; j < coluna + NAVIO; j++) {
            if (tabuleiro[linha][j] != AGUA) return 0;
        }

        for (int j = coluna; j < coluna + NAVIO; j++) {
            tabuleiro[linha][j]  = NAVIO;
        }

        return 1;
    }    

    if (linha + NAVIO >= TAMANHO_L) return 0;

        for (int i = linha; i < linha + NAVIO; i++) {
            if (tabuleiro[i][coluna] != AGUA) return 0;
        }

        for (int i = linha; i < linha + NAVIO; i++) {
            tabuleiro[i][coluna] = NAVIO;
        }

    return 1;
}

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
    int tabuleiro[TAMANHO_L][TAMANHO_C];

    for (int i = 0; i < TAMANHO_L; i++) {
        for (int j = 0; j < TAMANHO_C; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    int linha1 = 2, coluna1 = 4, orientacao1 = 0;

    int linha2 = 5, coluna2 = 9, orientacao2 = 1;

    if (!validarPosicionar(tabuleiro, linha1, coluna1, orientacao1)) {
        printf("Erro: não foi possível posicionar o navio 1!\n");
    }

    if (!validarPosicionar(tabuleiro, linha2, coluna2, orientacao2)) {
        printf("Erro: não foi possível posicionar o navio 2!\n");
    }

    printf("\nTabuleiro (%dx%d):\n\n", TAMANHO_L, TAMANHO_C);
    for (int i = 0; i < TAMANHO_L; i++) {
        for (int j = 0; j < TAMANHO_C; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
