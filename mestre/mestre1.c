#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");

    // variáveis da carta 1
    char estado1;
    char codigo_carta1[10];
    char cidade1[25];
    int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;
    float densidade1, pibPerCapita1;

    // variáveis da carta 2
    char estado2;
    char codigo_carta2[10];
    char cidade2[25];
    int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;
    float densidade2, pibPerCapita2;

    // --- Entrada dos dados da Carta 1 ---
    printf("Cadastro da Carta 1\n");
    printf("Digite o Estado (A-H): ");
    scanf(" %c", &estado1);

    printf("Digite o Codigo da Carta (ex: A01): ");
    scanf(" %3s", codigo_carta1);

    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", cidade1);

    printf("Digite a Populacao: ");
    scanf("%d", &populacao1);

    printf("Digite a Area (em km2): ");
    scanf("%f", &area1);

    printf("Digite o PIB (em bilhoes de reais): ");
    scanf("%f", &pib1);

    printf("Digite o Numero de Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos1);

    // --- Entrada dos dados da Carta 2 ---
    printf("\nCadastro da Carta 2\n");
    printf("Digite o Estado (A-H): ");
    scanf(" %c", &estado2);

    printf("Digite o Codigo da Carta (ex: A01): ");
    scanf(" %3s", codigo_carta2);

    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", cidade2);

    printf("Digite a Populacao: ");
    scanf("%d", &populacao2);

    printf("Digite a Area (em km2): ");
    scanf("%f", &area2);

    printf("Digite o PIB (em bilhoes de reais): ");
    scanf("%f", &pib2);

    printf("Digite o Numero de Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos2);

    // --- Cálculos ---
    densidade1 = populacao1 / area1;
    densidade2 = populacao2 / area2;

    pibPerCapita1 = pib1 * 1000000000 / populacao1; // PIB convertido para reais
    pibPerCapita2 = pib2 * 1000000000 / populacao2;

    // --- Menu interativo: escolha dos atributos ---
    int opcao1, opcao2;

    printf("\n--- Menu de Atributos ---\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("6 - PIB per capita\n");
    printf("Escolha o PRIMEIRO atributo: ");
    scanf("%d", &opcao1);

    printf("\n--- Escolha do Segundo Atributo ---\n");
    for (int i = 1; i <= 6; i++) {
        if (i != opcao1) { // não mostra o atributo já escolhido
            switch (i) {
                case 1: printf("1 - População\n"); break;
                case 2: printf("2 - Área\n"); break;
                case 3: printf("3 - PIB\n"); break;
                case 4: printf("4 - Pontos Turísticos\n"); break;
                case 5: printf("5 - Densidade Demográfica\n"); break;
                case 6: printf("6 - PIB per capita\n"); break;
            }
        }
    }
    printf("Escolha o SEGUNDO atributo: ");
    scanf("%d", &opcao2);

    // --- Função para obter valor do atributo ---
    float valor1A=0, valor2A=0, valor1B=0, valor2B=0;

    switch(opcao1) {
        case 1: valor1A = populacao1; valor2A = populacao2; break;
        case 2: valor1A = area1; valor2A = area2; break;
        case 3: valor1A = pib1; valor2A = pib2; break;
        case 4: valor1A = pontosTuristicos1; valor2A = pontosTuristicos2; break;
        case 5: valor1A = densidade1; valor2A = densidade2; break;
        case 6: valor1A = pibPerCapita1; valor2A = pibPerCapita2; break;
        default: printf("Opção inválida!\n"); return 0;
    }

    switch(opcao2) {
        case 1: valor1B = populacao1; valor2B = populacao2; break;
        case 2: valor1B = area1; valor2B = area2; break;
        case 3: valor1B = pib1; valor2B = pib2; break;
        case 4: valor1B = pontosTuristicos1; valor2B = pontosTuristicos2; break;
        case 5: valor1B = densidade1; valor2B = densidade2; break;
        case 6: valor1B = pibPerCapita1; valor2B = pibPerCapita2; break;
        default: printf("Opção inválida!\n"); return 0;
    }

    // --- Comparação dos atributos ---
    float pontosCarta1 = 0, pontosCarta2 = 0;

    // Comparação atributo 1
    if (opcao1 == 5) { // densidade: menor vence
        pontosCarta1 += (valor1A < valor2A) ? 1 : (valor1A > valor2A ? 0 : 0.5);
        pontosCarta2 += (valor2A < valor1A) ? 1 : (valor2A > valor1A ? 0 : 0.5);
    } else {
        pontosCarta1 += (valor1A > valor2A) ? 1 : (valor1A < valor2A ? 0 : 0.5);
        pontosCarta2 += (valor2A > valor1A) ? 1 : (valor2A < valor1A ? 0 : 0.5);
    }

    // Comparação atributo 2
    if (opcao2 == 5) { // densidade: menor vence
        pontosCarta1 += (valor1B < valor2B) ? 1 : (valor1B > valor2B ? 0 : 0.5);
        pontosCarta2 += (valor2B < valor1B) ? 1 : (valor2B > valor1B ? 0 : 0.5);
    } else {
        pontosCarta1 += (valor1B > valor2B) ? 1 : (valor1B < valor2B ? 0 : 0.5);
        pontosCarta2 += (valor2B > valor1B) ? 1 : (valor2B < valor1B ? 0 : 0.5);
    }

    // --- Exibição dos resultados ---
    printf("\n--- Resultado da Comparação ---\n");
    printf("%s - Atributo 1: %.2f | Atributo 2: %.2f | Pontos: %.1f\n", cidade1, valor1A, valor1B, pontosCarta1);
    printf("%s - Atributo 1: %.2f | Atributo 2: %.2f | Pontos: %.1f\n", cidade2, valor2A, valor2B, pontosCarta2);

    if (pontosCarta1 > pontosCarta2) {
        printf("\nResultado Final: %s venceu!\n", cidade1);
    } else if (pontosCarta2 > pontosCarta1) {
        printf("\nResultado Final: %s venceu!\n", cidade2);
    } else {
        printf("\nResultado Final: Empate!\n");
    }

    return 0;
}
