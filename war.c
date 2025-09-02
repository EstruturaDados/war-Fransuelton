// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO
// ============================================================================
//
// ============================================================================
//
// OBJETIVOS:
// - Modularizar completamente o código em funções especializadas.
// - Implementar um sistema de missões para um jogador.
// - Criar uma função para verificar se a missão foi cumprida.
// - Utilizar passagem por referência (ponteiros) para modificar dados e
//   passagem por valor/referência constante (const) para apenas ler.
// - Foco em: Design de software, modularização, const correctness, lógica de jogo.
//
// ============================================================================

// Inclusão das bibliotecas padrão necessárias para entrada/saída, alocação de memória, manipulação de strings e tempo.
#include <stdio.h>
#include <string.h>

// --- Constantes Globais ---
// Definem valores fixos para o número de territórios, missões e tamanho máximo de strings, facilitando a manutenção.
#define TAM_NOME_STRING 30
#define TAM_COR_STRING 10
#define MAX_TERRITORIOS 5

// --- Estrutura de Dados ---
// Define a estrutura para um território, contendo seu nome, a cor do exército que o domina e o número de tropas.
// O uso do typedef simplifica o uso da struct, tornando o código mais simples e legível
typedef struct
{
    char nome[TAM_NOME_STRING];
    char cor[TAM_COR_STRING];
    int tropas;
} Territorio;

// --- Protótipos das Funções ---
// Declarações antecipadas de todas as funções que serão usadas no programa, organizadas por categoria.
// Funções de setup e gerenciamento de memória:
// Funções de interface com o usuário:
// Funções de lógica principal do jogo:
// Função utilitária:
void limparBufferEntrada();

// --- Função Principal (main) ---
// Função principal que orquestra o fluxo do jogo, chamando as outras funções em ordem.
int main()
{
    // Declaração do array de territórios que armazenará todos os dados do jogo
    Territorio territorios[MAX_TERRITORIOS];

    // Exibição do cabeçalho inicial do programa
    printf("=================================================\n");
    printf("      PROJETO WAR ESTRUTURADO - NÍVEL NOVATO    \n");
    printf("===============================================\n\n");
    printf("[!] Cadastre os 5 territórios iniciais do mundo!\n\n");

    // Loop para cadastro inicial de todos os territórios
    // Coleta dados de entrada do usuário para cada território: nome, cor do exército e número de tropas
    for (int totalTerritorios = 0; totalTerritorios < MAX_TERRITORIOS; totalTerritorios++)
    {
        printf("--- Cadastrando %dº Território ---\n\n", totalTerritorios + 1);

        // Entrada do nome do território usando fgets para permitir espaços
        printf("Nome do Território: ");
        fgets(territorios[totalTerritorios].nome, TAM_NOME_STRING, stdin);

        // Entrada da cor do exército que domina o território
        printf("Cor do Exército: ");
        fgets(territorios[totalTerritorios].cor, TAM_COR_STRING, stdin);

        // Entrada do número de tropas presentes no território
        printf("Número de tropas: ");
        scanf("%d", &territorios[totalTerritorios].tropas);
        limparBufferEntrada();

        printf("\n\n");
    }

    // Confirmação de que o cadastro foi concluído com sucesso
    printf("[✔] Cadastro inicial concluído com sucesso!\n\n");

    // Exibição do cabeçalho da seção de visualização dos dados
    printf("================================================\n");
    printf("          MAPA DO MUNDO - ESTADO ATUAL          \n");
    printf("===============================================\n\n");

    // Loop para exibição de todos os territórios cadastrados
    // Apresenta de forma organizada todos os dados coletados anteriormente
    for (int totalTerritorios = 0; totalTerritorios < MAX_TERRITORIOS; totalTerritorios++)
    {
        printf("%dº Território:\n\n", totalTerritorios + 1);
        printf("- Nome: %s", territorios[totalTerritorios].nome);
        printf("- Cor: %s", territorios[totalTerritorios].cor);
        printf("- Tropas: %d", territorios[totalTerritorios].tropas);
    }

    // Retorna 0 indicando que o programa foi executado com sucesso
    return 0;
}

// limparBufferEntrada():
// Função utilitária para limpar o buffer de entrada do teclado (stdin), evitando problemas com leituras consecutivas de scanf e getchar.
void limparBufferEntrada()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}