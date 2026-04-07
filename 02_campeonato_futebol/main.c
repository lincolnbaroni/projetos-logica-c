#include <stdio.h>
#include <string.h>
#define TIME 3

    typedef struct {
        char nome[20];
        int vit;
        int empat;
        int pontos;
        int saldoGols;
    } Time;
    
        int calcularPontos(int vitorias, int empates) {
            return (vitorias * 3) + empates;
        }

int main() {
    
    Time time[TIME];
    
    printf("CAMPEONATO DE FUTUBOL (PONTUAÇÃO E ESTATISTICAS)\n");
    printf("VITORIA: 3 PTS | EMPATE: 1 PTS | DERREETO: 0 PTS\n");
    printf("\n");
    
    for(int i = 0; i < TIME; i++) {
        printf("Nome do time: ");
        scanf(" %[^\n]", time[i].nome);
        
        printf("Numero de vitorias: ");
        scanf("%d", &time[i].vit);
        
        printf("Numero de empate: ");
        scanf("%d", &time[i].empat);
        
        printf("Saldo de GOLS: ");
        scanf("%d", &time[i].saldoGols);
        
        time[i].pontos = calcularPontos(time[i].vit, time[i].empat);
        printf("-------------------------------\n");
    }
    
    
    Time aux;
    
    for(int j = 0; j < TIME; j++) {
        for(int i = 0; i < TIME - 1; i++) {
            if(time[i].pontos < time[i+1].pontos || time[i].pontos == time[i+1].pontos && time[i].saldoGols < time[i+1].saldoGols) {
                aux = time[i];
                time[i] = time[i+1];
                time[i+1] = aux;
            }
        }
    }
    
    
    printf("RELATORIO FINAL DAS ESTATISTICA DOS TIMES\n");
    for(int i = 0; i < TIME; i++) {
        printf("Time: %s\n", time[i].nome);
        printf("Pontos: %d\n", time[i].pontos);
    }
    printf("-------------------------------\n");
    
    printf("TABELO DO CAMPEONATO\n");
    for(int i = 0; i < TIME; i++) {
        printf("%d°Lugar: [%s] | Pontos: %d\n", i + 1, time[i].nome, time[i].pontos);
    }
    

    return 0;
}
