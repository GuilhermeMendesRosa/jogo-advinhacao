#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void) {
  int alternativa;
  int jogo[6];
  int i = 0;
  int qtd_jogos = 0;
  int i_fim = 0;
  int num_jogador;
  int tentativas;

  //caso jogador digite 4 o programa termina

  while (alternativa != 4) {
    //mostrando o menu do jogo
    printf("\n-----------------------");
    printf("\n1) Novo jogo\n2) Ver ultimos 5 jogos\n3) Limpar Historico\n4) Sair\n");
    printf("-----------------------\n");
    scanf("%d", &alternativa);
    

    //if para caso o jogador digite uma opção inválida(que não esteja entre 1 e 4)

    if (alternativa < 1 || alternativa > 4) {
    printf("\nAlternativa invalida! Informe de 1 a 4!\n\n");
    }
    if (alternativa == 1) {
      //usar uma variável com a quantidade de jogos, para o programa saber quantos mostrar na hora de ver o histórico
      qtd_jogos++;

      //gerando um número aleatório
      srand(time(NULL));
      int num_pc = rand() % 100;
      printf("%d\n", num_pc);
  

      //pedindo um número ao jogador e salvando
      tentativas = 0;
      while (num_jogador != num_pc) {
        tentativas += 1;
        printf("\nDigite um numero entre 0 e 100: ");
        scanf("%d", &num_jogador);
        if (num_jogador > num_pc) {
          printf("Muito alto, tente novamente!\n\n");
        } else if (num_jogador < num_pc) {
          printf("Muito baixo, tente novamente!\n\n");
        }
      }
      //mostrando quantas tentativas para acertar
      printf("Parabens, voce acertou em %d tentativas!\n\n", tentativas);

      //salvando histórico de tentativas
      jogo[5] = jogo[4];
      jogo[4] = jogo[3];
      jogo[3] = jogo[2];
      jogo[2] = jogo[1];
      jogo[1] = tentativas;
    } 

    //mostrando histórico de tentativas
    if (alternativa == 2) {
      printf("\nHistorico de Tentativas:\n");
      if (qtd_jogos == 0) {
        printf("  Nenhum jogo na memoria\n");
      } else {
        i_fim = 5;
        if (qtd_jogos < 5) {
          i_fim = qtd_jogos;
        }
        int num_jogo = 0;      
          for (i = i_fim; i >= 1; i--) {
          num_jogo++; 
          printf("  Jogo %d: %d\n", num_jogo, jogo[i]);
        }
      }
    }

    //zerando a memória
    if (alternativa == 3) {
      qtd_jogos = 0;
      for (i = 1; i <= 5; i++) {
        jogo[i] = 0;
      }

    }

  }
  return 0;
}
