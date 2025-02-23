#include <stdio.h>

// Estrutura para Facilitar na criação das cartas--------------------------------------------
  struct CartaSuperTrunfo {
      char estado;                                      //Estado
      char codigo[4];                                   //Código da cidade
      char nomeCidade[50];                              //Nome da cidade
      int populacao;                                    //População da cidade
      float area;                                       //Area da cidade em M²
      float pib;                                        //Produto interno bruto da cidade
      unsigned int pontosTuristicos;                    //contagem de pontos turisticos da cidade
      float densidadePopulacao,pibPerCapita,superPoder; //densidade, PIB e Superpoder, tudo junto pela velocidade
  };

//--------------------------------------------------------------------------------------------------------------------

struct CartaSuperTrunfo carta1, carta2;  //Aqui definimos a quantidade de cartas que serão registradas

//------------------------------------------------------------------------------------------------------------------

//Função criada para facilitar na criação de multiplas cartas e deixar o código mais limpo,sem repetições-----------

void preencherCarta(struct CartaSuperTrunfo *carta, const char *nomeCarta) {

    printf("\n===== Preenchendo %s =====\n", nomeCarta); // Lembrar que o nomeCarta é para exibir qual carta está sendo registrada!

    printf("Escolha uma letra entre 'A' e 'H' para representar um dos oito estados: ");
    scanf(" %c", &carta->estado);

    printf("Escolha um número de 1 a 4 para o código da carta: ");
    int numeroCodigo;
    scanf(" %d", &numeroCodigo);
    sprintf(carta->codigo, "%c%02d", carta->estado, numeroCodigo);

    getchar();  //Para limpar o buffer antes de ler a proxima string
    printf("Digite o nome da Cidade: ");
    scanf(" %[^\n]", carta->nomeCidade);

    printf("Digite a População: ");
    scanf("%d", &carta->populacao);

    printf("Digite a Area da Cidade (em km²): ");
    scanf("%f", &carta->area);

    printf("Digite o PIB: ");
    scanf("%f", &carta->pib);

    printf("Digite a Quantidade de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    carta->densidadePopulacao = carta->populacao /carta->area;
    carta->pibPerCapita = carta->pib * 1e9 / carta->populacao;
    carta->superPoder = carta->populacao + carta->area + carta->pib + carta->pontosTuristicos + carta->pibPerCapita;

    printf("✅ %s registrada com sucesso!\n", nomeCarta); // Mensagem final para mostrar que a carta foi registrada com sucesso em vez de mostrar 2x para evitar poluição visual

}

int main(void) {

    //-------------------------------------------------------------------------------------------------

    //Mensagem de boas vindas e explicação do jogo seguindo o raciocinio do jogo de um colega----------

    printf("****  Bem-vindo ao Super Trunfo - Cidades! ****\n");
    printf("** Nesta Versão Simplificada, jogaremos com duas cartas. **\n");
    printf("** Cada carta representa uma cidade com suas caracteristicas. **\n");
    printf("** O jogo comparará os valores e determinará quem vence em cada atributo. **\n");
    printf("** Vamos começar! **\n\n");

    //------------------------------------------------------------------------------------------------------------------

    // Chamando a função para preencher as cartas com mensagens identificando cada uma----------------------------------
    preencherCarta(&carta1, "Carta 1");
    preencherCarta(&carta2, "Carta 2");


    //Começo da implementação de lógica após atualizar o código reaproveitado

    //Comparar um atributo escolhido por mim----------------------------------------------------------------------------
    printf("\n📊 Comparação de cartas (População): \n\n");

    if (carta1.populacao > carta2.populacao) {
        printf("🔥 A carta 1 - %s venceu na disputa de população!  ela possui %u Habitantes! \n", carta1.nomeCidade, carta1.populacao);
    } else if (carta2.populacao > carta1.populacao) {
        printf("🔥 A carta 2 - %s venceu na disputa de população! ela possui %u Habitantes! \n", carta2.nomeCidade, carta2.populacao);
    } else {
        printf("⚖️ Empate! Ambas as cidades têm a mesma população.\n");
    }

    //------------------------------------------------------------------------------------------------------------------

    //


    return 0;
}