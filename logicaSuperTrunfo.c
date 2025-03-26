#include <stdio.h>
#include <string.h>

// Definindo uma estrutura para armazenar as informações da carta
typedef struct {
    char nome[50];
    int populacao;
    int pib;
    int densidade_demografica;
    int expectativa_vida;
    int area;
} Carta;

// Função para escolher os atributos
void escolher_atributos(char* atributo_1, char* atributo_2) {
    char atributos[5][30] = {"População", "PIB", "Densidade Demográfica", "Expectativa de Vida", "Área"};
    int escolha_1, escolha_2;

    // Exibindo o menu para o primeiro atributo
    printf("Escolha o primeiro atributo:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s\n", i + 1, atributos[i]);
    }

    // Recebe a escolha do primeiro atributo
    do {
        printf("Escolha o primeiro atributo (1-5): ");
        scanf("%d", &escolha_1);
    } while (escolha_1 < 1 || escolha_1 > 5);

    // Atribui o nome do atributo escolhido
    strcpy(atributo_1, atributos[escolha_1 - 1]);

    // Exibindo o menu para o segundo atributo, sem o primeiro atributo já escolhido
    printf("\nEscolha o segundo atributo (não pode ser o mesmo do primeiro):\n");
    for (int i = 0; i < 5; i++) {
        if (i != escolha_1 - 1) {
            printf("%d. %s\n", i + 1, atributos[i]);
        }
    }

    // Recebe a escolha do segundo atributo
    do {
        printf("Escolha o segundo atributo (1-5, mas não o mesmo do anterior): ");
        scanf("%d", &escolha_2);
    } while (escolha_2 < 1 || escolha_2 > 5 || escolha_2 == escolha_1);

    // Atribui o nome do atributo escolhido
    strcpy(atributo_2, atributos[escolha_2 - 1]);
}

// Função para comparar as cartas
void comparar_cartas(Carta carta1, Carta carta2, char* atributo_1, char* atributo_2) {
    int valor_1_1, valor_1_2, valor_2_1, valor_2_2;
    int soma_1, soma_2;

    // Atribuindo os valores dos atributos das cartas
    if (strcmp(atributo_1, "População") == 0) {
        valor_1_1 = carta1.populacao;
        valor_2_1 = carta2.populacao;
    } else if (strcmp(atributo_1, "PIB") == 0) {
        valor_1_1 = carta1.pib;
        valor_2_1 = carta2.pib;
    } else if (strcmp(atributo_1, "Densidade Demográfica") == 0) {
        valor_1_1 = carta1.densidade_demografica;
        valor_2_1 = carta2.densidade_demografica;
    } else if (strcmp(atributo_1, "Expectativa de Vida") == 0) {
        valor_1_1 = carta1.expectativa_vida;
        valor_2_1 = carta2.expectativa_vida;
    } else {
        valor_1_1 = carta1.area;
        valor_2_1 = carta2.area;
    }

    if (strcmp(atributo_2, "População") == 0) {
        valor_1_2 = carta1.populacao;
        valor_2_2 = carta2.populacao;
    } else if (strcmp(atributo_2, "PIB") == 0) {
        valor_1_2 = carta1.pib;
        valor_2_2 = carta2.pib;
    } else if (strcmp(atributo_2, "Densidade Demográfica") == 0) {
        valor_1_2 = carta1.densidade_demografica;
        valor_2_2 = carta2.densidade_demografica;
    } else if (strcmp(atributo_2, "Expectativa de Vida") == 0) {
        valor_1_2 = carta1.expectativa_vida;
        valor_2_2 = carta2.expectativa_vida;
    } else {
        valor_1_2 = carta1.area;
        valor_2_2 = carta2.area;
    }

    // Comparando os valores dos atributos e calculando a soma
    if (strcmp(atributo_1, "Densidade Demográfica") == 0) {
        valor_1_1 = (valor_1_1 < valor_2_1) ? valor_1_1 : valor_2_1;
    } else {
        valor_1_1 = (valor_1_1 > valor_2_1) ? valor_1_1 : valor_2_1;
    }

    if (strcmp(atributo_2, "Densidade Demográfica") == 0) {
        valor_1_2 = (valor_1_2 < valor_2_2) ? valor_1_2 : valor_2_2;
    } else {
        valor_1_2 = (valor_1_2 > valor_2_2) ? valor_1_2 : valor_2_2;
    }

    soma_1 = valor_1_1 + valor_1_2;
    soma_2 = valor_2_1 + valor_2_2;

    // Exibindo o resultado
    printf("\nResultado da Comparação:\n");
    printf("Carta 1: %s\n", carta1.nome);
    printf(" - %s: %d | %s: %d | Soma: %d\n", atributo_1, valor_1_1, atributo_2, valor_1_2, soma_1);
    printf("Carta 2: %s\n", carta2.nome);
    printf(" - %s: %d | %s: %d | Soma: %d\n", atributo_1, valor_2_1, atributo_2, valor_2_2, soma_2);

    if (soma_1 > soma_2) {
        printf("\nA carta %s venceu a rodada!\n", carta1.nome);
    } else if (soma_1 < soma_2) {
        printf("\nA carta %s venceu a rodada!\n", carta2.nome);
    } else {
        printf("\nEmpate!\n");
    }
}

int main() {
    Carta carta1 = {"Brasil", 211, 2000, 25, 75, 8515767};
    Carta carta2 = {"Japão", 126, 5000, 400, 84, 377975};

    char atributo_1[30], atributo_2[30];

    printf("Bem-vindo ao sistema de comparação de cartas!\n");

    // Escolher os atributos
    escolher_atributos(atributo_1, atributo_2);

    // Comparar as cartas
    comparar_cartas(carta1, carta2, atributo_1, atributo_2);

    return 0;
}
