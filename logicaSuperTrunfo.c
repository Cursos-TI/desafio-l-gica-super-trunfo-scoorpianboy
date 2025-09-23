#include <stdio.h>

int main() {
    /* ======================================================
       SUPER TRUNFO - NÍVEIS: NOVATO + AVENTUREIRO + MESTRE
       ====================================================== */

    /* -------------------------
       DECLARAÇÃO DAS VARIÁVEIS
       ------------------------- */

    /* Carta 1 */
    char estado1[50];             /* Nome do estado (ex: São Paulo) */
    char codigo1[4];              /* ex: A01 */
    char cidade1[50];             /* Nome da cidade */
    unsigned long int pop1;       /* População */
    float area1;                  /* Área */
    float pib1;                   /* PIB em bilhões */
    int pontos1;                  /* Pontos turísticos */

    /* Carta 2 */
    char estado2[50];
    char codigo2[4];
    char cidade2[50];
    unsigned long int pop2;
    float area2;
    float pib2;
    int pontos2;

    /* Calculadas */
    float dens1, dens2;
    float pibpc1, pibpc2;
    float invdens1, invdens2;

    /* Super Poder */
    float super1, super2;

    const float FATOR_PIB = 1e9f; /* bilhões -> reais */

    /* -------------------------
          ENTRADA DE DADOS 
       ------------------------- */

    printf("=== Super Trunfo de Cidades ===\n");
    printf("ATENCAO:\n");
    printf("- INTEIROS: SEM ponto (ex.: 1234567)\n");
    printf("- DECIMAIS: COM ponto (ex.: 1521.11)\n\n");

    /* ---- Carta 1 ---- */

    printf("Carta 1 - Estado (nome completo): ");
    scanf(" %49[^\n]", estado1);

    printf("Carta 1 - Codigo (ex.: A01): ");
    scanf(" %3s", codigo1);

    printf("Carta 1 - Nome da Cidade: ");
    scanf(" %49[^\n]", cidade1);

    printf("Carta 1 - Populacao (ex.: 12325000): ");
    scanf(" %lu", &pop1);

    printf("Carta 1 - Area em km2 (ex.: 1521.11): ");
    scanf(" %f", &area1);

    printf("Carta 1 - PIB em bilhoes (ex.: 699.28): ");
    scanf(" %f", &pib1);

    printf("Carta 1 - Numero de Pontos Turisticos (ex.: 50): ");
    scanf(" %d", &pontos1);

    printf("\n");

    /* ---- Carta 2 ---- */
    printf("Carta 2 - Estado (nome completo): ");
    scanf(" %49[^\n]", estado2);

    printf("Carta 2 - Codigo (ex.: B02): ");
    scanf(" %3s", codigo2);

    printf("Carta 2 - Nome da Cidade: ");
    scanf(" %49[^\n]", cidade2);

    printf("Carta 2 - Populacao (ex.: 6748000): ");
    scanf(" %lu", &pop2);

    printf("Carta 2 - Area em km2 (ex.: 1200.25): ");
    scanf(" %f", &area2);

    printf("Carta 2 - PIB em bilhoes (ex.: 300.50): ");
    scanf(" %f", &pib2);

    printf("Carta 2 - Numero de Pontos Turisticos (ex.: 30): ");
    scanf(" %d", &pontos2);

    printf("\n");

    /* -------------------------
       CÁLCULOS IMPORTANTES ;)
       ------------------------- */

    dens1 = (float)pop1 / area1;
    dens2 = (float)pop2 / area2;

    pibpc1 = (pib1 * FATOR_PIB) / (float)pop1;
    pibpc2 = (pib2 * FATOR_PIB) / (float)pop2;

    invdens1 = 1.0f / dens1;   // A váriavel invdens, significa inverso da densidade ;)
    invdens2 = 1.0f / dens2;

    super1 = (float)pop1 + area1 + pib1 + (float)pontos1 + pibpc1 + invdens1;
    super2 = (float)pop2 + area2 + pib2 + (float)pontos2 + pibpc2 + invdens2;

    /* ----------------------------
       EXIBICAO DAS CARTAS
       ----------------------------*/
    printf("=== Carta 1 ===\n");
    printf("Estado: %s\n", estado1);
    printf("Codigo: %s\n", codigo1);
    printf("Cidade: %s\n", cidade1);
    printf("Populacao: %lu\n", pop1);
    printf("Area: %.2f km2\n", area1);
    printf("PIB: %.2f bilhoes de reais\n", pib1);
    printf("Pontos Turisticos: %d\n", pontos1);
    printf("Densidade Populacional: %.2f hab/km2\n", dens1);
    printf("PIB per Capita: %.2f reais\n", pibpc1);
    printf("Inverso da Densidade: %.2f\n", invdens1);
    printf("Super Poder: %.2f\n\n", super1);

    printf("=== Carta 2 ===\n");
    printf("Estado: %s\n", estado2);
    printf("Codigo: %s\n", codigo2);
    printf("Cidade: %s\n", cidade2);
    printf("Populacao: %lu\n", pop2);
    printf("Area: %.2f km2\n", area2);
    printf("PIB: %.2f bilhoes de reais\n", pib2);
    printf("Pontos Turisticos: %d\n", pontos2);
    printf("Densidade Populacional: %.2f hab/km2\n", dens2);
    printf("PIB per Capita: %.2f reais\n", pibpc2);
    printf("Inverso da Densidade: %.2f\n", invdens2);
    printf("Super Poder: %.2f\n\n", super2);

    /* -------------------------
       COMPARACOES (0/1)
       ------------------------- */

    int r_pop   = (pop1 > pop2);
    int r_area  = (area1 > area2);
    int r_pib   = (pib1 > pib2);
    int r_pts   = (pontos1 > pontos2);
    int r_dens  = (dens1 < dens2);   /* menor vence */
    int r_pibpc = (pibpc1 > pibpc2);
    int r_super = (super1 > super2);

    printf("=== Comparacao de Cartas ===\n");
    printf("Populacao: %s venceu (%d)\n",            r_pop   ? "Carta 1" : "Carta 2", r_pop);
    printf("Area: %s venceu (%d)\n",                 r_area  ? "Carta 1" : "Carta 2", r_area);
    printf("PIB: %s venceu (%d)\n",                  r_pib   ? "Carta 1" : "Carta 2", r_pib);
    printf("Pontos Turisticos: %s venceu (%d)\n",    r_pts   ? "Carta 1" : "Carta 2", r_pts);
    printf("Densidade (menor vence): %s venceu (%d)\n", r_dens ? "Carta 1" : "Carta 2", r_dens);
    printf("PIB per Capita: %s venceu (%d)\n",       r_pibpc ? "Carta 1" : "Carta 2", r_pibpc);
    printf("Super Poder: %s venceu (%d)\n",          r_super ? "Carta 1" : "Carta 2", r_super);

    return 0;
}
