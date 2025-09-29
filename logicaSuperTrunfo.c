#include <stdio.h>

int main() {
    /* ==================================================
       SUPER TRUNFO - Nível NOVATO + AVENTUREIRO + MESTRE
       ================================================== */

    char estado1[50], codigo1[4], cidade1[50];
    unsigned long int pop1;
    float area1, pib1;
    int pontos1;

    char estado2[50], codigo2[4], cidade2[50];
    unsigned long int pop2;
    float area2, pib2;
    int pontos2;

    float dens1, dens2;
    float pibpc1, pibpc2;

    const float FATOR_PIB = 1e9f;

    printf("=== Super Trunfo de Cidades (Nivel Mestre) ===\n\n");

    /* Carta 1 */
    printf("Carta 1 - Estado: ");                scanf(" %49[^\n]", estado1);
    printf("Carta 1 - Codigo (ex.: A01): ");     scanf(" %3s", codigo1);
    printf("Carta 1 - Cidade: ");                scanf(" %49[^\n]", cidade1);
    printf("Carta 1 - Populacao: ");             scanf(" %lu", &pop1);
    printf("Carta 1 - Area (km2): ");            scanf(" %f", &area1);
    printf("Carta 1 - PIB (bilhoes): ");         scanf(" %f", &pib1);
    printf("Carta 1 - Pontos Turisticos: ");     scanf(" %d", &pontos1);
    printf("\n");

    /* Carta 2 */
    printf("Carta 2 - Estado: ");                scanf(" %49[^\n]", estado2);
    printf("Carta 2 - Codigo (ex.: B02): ");     scanf(" %3s", codigo2);
    printf("Carta 2 - Cidade: ");                scanf(" %49[^\n]", cidade2);
    printf("Carta 2 - Populacao: ");             scanf(" %lu", &pop2);
    printf("Carta 2 - Area (km2): ");            scanf(" %f", &area2);
    printf("Carta 2 - PIB (bilhoes): ");         scanf(" %f", &pib2);
    printf("Carta 2 - Pontos Turisticos: ");     scanf(" %d", &pontos2);
    printf("\n");

    /* Cálculos obrigatórios */
    dens1 = (float)pop1 / area1;
    dens2 = (float)pop2 / area2;
    pibpc1 = (pib1 * FATOR_PIB) / (float)pop1;
    pibpc2 = (pib2 * FATOR_PIB) / (float)pop2;

    /* Menus dinâmicos com switch */
    int a1, a2;

    printf("===== MENU 1/2 – Escolha o 1o atributo =====\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Demografica (menor vence)\n");
    printf("6 - PIB per capita\n");
    printf("Sua escolha (1-6): ");
    if (scanf("%d", &a1) != 1 || a1 < 1 || a1 > 6) { printf("Opcao invalida.\n"); return 0; }

    printf("\n===== MENU 2/2 – Escolha o 2o atributo (diferente do 1o) =====\n");
    for (int i = 1; i <= 6; i++) {
        if (i == a1) continue;
        switch (i) {
            case 1: printf("1 - Populacao\n"); break;
            case 2: printf("2 - Area\n"); break;
            case 3: printf("3 - PIB\n"); break;
            case 4: printf("4 - Pontos Turisticos\n"); break;
            case 5: printf("5 - Densidade Demografica (menor vence)\n"); break;
            case 6: printf("6 - PIB per capita\n"); break;
        }
    }
    printf("Sua escolha (1-6): ");
    if (scanf("%d", &a2) != 1 || a2 < 1 || a2 > 6 || a2 == a1) { printf("Opcao invalida.\n"); return 0; }

    /* Pegar valores dos atributos escolhidos (if-else encadeado) */
    double c1_a1=0, c2_a1=0, c1_a2=0, c2_a2=0;
    int a1_menor = 0, a2_menor = 0;

    if (a1 == 1) { c1_a1 = (double)pop1;      c2_a1 = (double)pop2; }
    else if (a1 == 2) { c1_a1 = area1;        c2_a1 = area2; }
    else if (a1 == 3) { c1_a1 = pib1;         c2_a1 = pib2; }
    else if (a1 == 4) { c1_a1 = (double)pontos1; c2_a1 = (double)pontos2; }
    else if (a1 == 5) { c1_a1 = dens1;        c2_a1 = dens2; a1_menor = 1; }
    else if (a1 == 6) { c1_a1 = pibpc1;       c2_a1 = pibpc2; }

    if (a2 == 1) { c1_a2 = (double)pop1;      c2_a2 = (double)pop2; }
    else if (a2 == 2) { c1_a2 = area1;        c2_a2 = area2; }
    else if (a2 == 3) { c1_a2 = pib1;         c2_a2 = pib2; }
    else if (a2 == 4) { c1_a2 = (double)pontos1; c2_a2 = (double)pontos2; }
    else if (a2 == 5) { c1_a2 = dens1;        c2_a2 = dens2; a2_menor = 1; }
    else if (a2 == 6) { c1_a2 = pibpc1;       c2_a2 = pibpc2; }

    /* Exibição por atributo + if-else (densidade inverte) */
    printf("\n===== RESULTADOS POR ATRIBUTO =====\n");

    /* Atributo 1 */
    printf("\nAtributo 1 (%d): Carta 1 = %.6f | Carta 2 = %.6f\n", a1, c1_a1, c2_a1);
    if (!a1_menor) {
        if (c1_a1 > c2_a1) printf("Vencedora no Atributo 1: Carta 1 (%s)\n", cidade1);
        else if (c1_a1 < c2_a1) printf("Vencedora no Atributo 1: Carta 2 (%s)\n", cidade2);
        else printf("Empate no Atributo 1\n");
    } else {
        if (c1_a1 < c2_a1) printf("Vencedora no Atributo 1: Carta 1 (%s)\n", cidade1);
        else if (c1_a1 > c2_a1) printf("Vencedora no Atributo 1: Carta 2 (%s)\n", cidade2);
        else printf("Empate no Atributo 1\n");
    }

    /* Atributo 2 */
    printf("\nAtributo 2 (%d): Carta 1 = %.6f | Carta 2 = %.6f\n", a2, c1_a2, c2_a2);
    if (!a2_menor) {
        if (c1_a2 > c2_a2) printf("Vencedora no Atributo 2: Carta 1 (%s)\n", cidade1);
        else if (c1_a2 < c2_a2) printf("Vencedora no Atributo 2: Carta 2 (%s)\n", cidade2);
        else printf("Empate no Atributo 2\n");
    } else {
        if (c1_a2 < c2_a2) printf("Vencedora no Atributo 2: Carta 1 (%s)\n", cidade1);
        else if (c1_a2 > c2_a2) printf("Vencedora no Atributo 2: Carta 2 (%s)\n", cidade2);
        else printf("Empate no Atributo 2\n");
    }

    /* Soma + operador ternário no resultado final */
    double soma1 = c1_a1 + c1_a2;
    double soma2 = c2_a1 + c2_a2;

    printf("\n===== SOMA DOS ATRIBUTOS =====\n");
    printf("Carta 1 - %s (%s): %.6f\n", cidade1, estado1, soma1);
    printf("Carta 2 - %s (%s): %.6f\n", cidade2, estado2, soma2);

    printf("\nResultado final: %s\n",
        (soma1 > soma2) ? "Carta 1 venceu pela maior soma!"
                        : (soma1 < soma2) ? "Carta 2 venceu pela maior soma!"
                                          : "Empate!");

    return 0;
}
