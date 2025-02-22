#include <stdio.h>

int main(void) {
    // Estrutura para Facilitar na criação das cartas--------------------------------------------
    struct CartaSuperTrunfo {
        char estado;                                      //Estado
        char codigo[4];                                   //Código da cidade
        char nomeCidade[50];                              //Nome da cidade
        int populacao;                                    //População da cidade
        float area;                                       //Area da cidade em M²
        float pib;                                        //Produto interno bruto da cidade
        unsigned int pontosTuristicos;                             //contagem de pontos turisticos da cidade
        float densidadePopulacao,pibPerCapita,superPoder; //densidade, PIB e Superpoder, tudo junto pela velocidade
    };

    struct CartaSuperTrunfo carta1, carta2;

    //-------------------------------------------------------------------------------------------------

    //Mensagem de boas vindas e explicação do jogo seguindo o raciocinio do jogo de um colega----------

    printf("****  Bem-vindo ao Super Trunfo - Cidades! ****\n");
    printf("** Nesta Versão Simplificada, jogaremos com duas cartas. **\n");
    printf("** Cada carta representa uma cidade com suas caracteristicas. **\n");
    printf("** O jogo comparará os valores e determinará quem vence em cada atributo. **\n");
    printf("** Vamos começar! **\n\n");

    //--------------------------------------------------------------------------------------------------

    //Entrada de dados - Carta 1------------------------------------------------------------------------

    printf("Escolha uma letra entre 'A' e 'H' para representar um dos oito Estados: ");
    scanf(" %c", &carta1.estado);

    printf("Escolha um número de 1 a 4 para o código da carta: ");
    int numeroCodigo;
    scanf("%d", &numeroCodigo);
    sprintf(carta1.codigo, "%c%02d", carta1.estado, numeroCodigo);

    printf("Digite o Nome da Cidade: ");
    getchar();
    scanf(" %[^\n]", carta1.nomeCidade);

    printf("Digite a População: ");
    scanf("%u", &carta1.populacao);

    printf("Digite a área em (km²): ");
    scanf("%f", &carta1.area);

    printf("Digite o PIB: ");
    scanf("%f", &carta1.pib);

    printf("Digite o número de Pontos Turísticos: ");
    scanf("%d", &carta1.pontosTuristicos);

    carta1.densidadePopulacao = (float)carta1.populacao / carta1.area;
    carta1.pibPerCapita = carta1.pib * 1e9 / carta1.populacao;

    carta1.superPoder = (float)carta1.populacao + carta1.area + carta1.pib + carta1.pontosTuristicos + carta1.pibPerCapita + (1 / carta1.densidadePopulacao) * (carta1.densidadePopulacao > 0);

    //------------------------------------------------------------------------------------------------------------------

    // Exibindo a primeira carta----------------------------------------------------------------------------------------
    printf("\n*** Carta 1: ***\n");
    printf("Estado: %c\n", carta1.estado);
    printf("Código: %s\n", carta1.codigo);
    printf("Cidade: %s\n", carta1.nomeCidade);
    printf("População: %u\n", carta1.populacao);
    printf("Área: %.2f km²\n", carta1.area);
    printf("PIB: %.2f Bilhões de reais\n", carta1.pib);
    printf("Número de Pontos Turísticos: %d\n", carta1.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km².\n", carta1.densidadePopulacao);
    printf("PIB per Capita: %.2f reais\n", carta1.pibPerCapita);

    //--------------------------------------------------------------------------------------------------------------------

    //Solicitando Entrada de dados para a segunda carta-------------------------------------------------------------------

    printf("\n-----Carta 2:-----\n");

    printf("Escolha uma letra entre 'A' e 'H' para representar um dos oito Estados: ");
    scanf(" %c", &carta2.estado);

    printf("Escolha um número de 1 a 4 para o código da carta: ");
    int numeroCodigo2;
    scanf("%d", &numeroCodigo2);
    sprintf(carta2.codigo, "%c%02d", carta2.estado, numeroCodigo2);

    printf("Digite o nome da Cidade: ");
    scanf(" %[^\n]", carta2.nomeCidade); // Corrigido aqui

    printf("Digite a População: ");
    getchar();
    scanf("%u", &carta2.populacao);

    printf("Digite a área em (km²): ");
    scanf("%f", &carta2.area);

    printf("Digite o PIB: ");
    scanf("%f", &carta2.pib);

    printf("Digite o número de pontos Turísticos: ");
    scanf("%d", &carta2.pontosTuristicos);

    carta2.densidadePopulacao = (float)carta2.populacao / carta2.area;
    carta2.pibPerCapita = carta2.pib * 1e9 / carta2.populacao;

    carta2.superPoder = (float)carta2.populacao + carta2.area + carta2.pib + carta2.pontosTuristicos + carta2.pibPerCapita + (1 / carta2.densidadePopulacao) * (carta2.densidadePopulacao > 0);

    // Exibindo a segunda carta:
    printf("\nCarta 2:\n");
    printf("Estado: %c\n", carta2.estado);
    printf("Código: %s\n", carta2.codigo);
    printf("Cidade: %s\n", carta2.nomeCidade); // Corrigido aqui
    printf("População: %u\n", carta2.populacao);
    printf("Área: %.2f km²\n", carta2.area);
    printf("PIB: %.2f Bilhões de reais\n", carta2.pib);
    printf("Número de Pontos Turísticos: %d\n", carta2.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km².\n", carta2.densidadePopulacao);
    printf("PIB per Capita: %.2f reais\n\n", carta2.pibPerCapita);

    //----------------------------------------------------------------------------------------------------------------------

    //Começo da implementação de lógica no código reaproveitado-------------------------------------------------------------

    if(carta1.populacao > carta2.populacao) {
        printf("A carta 1 possui uma População maior que da carta 2 de %u, O que aumenta suas chances de ganhar!\n",carta1.populacao);

    } else {
        printf("A carta 2 possui uma População maior que da carta 1 de %u, O que aumenta suas chances de ganhar!\n", carta2.populacao);
    }



    return 0;
}