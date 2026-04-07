#include <stdio.h>
#include <string.h>

    typedef struct {
        int num;
        char status;
        char nomeHosped[50];
        float valorDiar;
    } Quarto;
    
    void exibirMenu() {
        printf("--------------------------------------\n");
        printf("------ | HOTEL BARONISILVANIA | ------\n");
        printf("(1) - Realizaar Check-in\n");
        printf("(2) - Realizar Check-out\n");
        printf("(3) - Listar quartos\n");
        printf("(0) - SAIR\n");
    }

int main() {
    
    exibirMenu();
    int opcao;
    int numEscolhido;
    
    Quarto quartoS[5];

    for(int i = 0; i < 5; i++) {
        quartoS[i].num = 101 + i;
        quartoS[i].status = 'L';
        quartoS[i].valorDiar = 100;
        
    }
    
    do {
        
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        printf("--------------------------------------\n");
        
        switch(opcao) {
            case 1:
                printf("INICIANDO O CHECK-IN\n");
                printf("Numero do quarto: ");
                scanf("%d", &numEscolhido);
                    
                    for(int i = 0; i < 5; i++) {
                        if(numEscolhido == quartoS[i].num) {
                                if(quartoS[i].status == 'L') {
                                    quartoS[i].status = 'O';
                                    printf("Nome do Hospede: ");
                                    scanf(" %[^\n]", quartoS[i].nomeHosped);
                                }
                        }
                    }
                    
                printf("--------------------------------------\n");
                break;
                
            case 2:
                printf("INCIANDO O CHECK-OUT\n");
                printf("Numero do quarto: ");
                scanf("%d", &numEscolhido);
                
                for(int i = 0; i < 5; i++) {
                    
                    if(numEscolhido == quartoS[i].num) {
                        if(quartoS[i].status == 'O') {
                            printf("Valor total: %f\n", quartoS[i].valorDiar);
                            quartoS[i].status = 'L';
                            strcpy(quartoS[i].nomeHosped, "");
                            printf("Check-out realizado com sucesso, volte sempre!\n");
                        } else {
                            printf("O quarto ja esta livre\n");
                        }
                    }
                }
                    break;
                
            case 3:
                printf("QUARTOS DISPONIVEIS\n");
                for(int i = 0; i < 5; i++) {
                    if(quartoS[i].status == 'L') {
                        printf("Quarto: %d | Status: LIVRE\n", quartoS[i].num);
                        
                    } else {
                        printf("Quarto: %d | Status: OCUPADO | Nome Hospede: %s\n", quartoS[i].num, quartoS[i].nomeHosped);
                    }
                }
                printf("--------------------------------------\n");
                break;
                
            case 0:
                printf("FECHANDO O SISTEMA, OBRIGADO ATE A PROXIMA\n");
                break;
                
            default:
                printf("OPCAO INVALIDAS, TENTE NOVAMENTE\n");
        }
    } while (opcao != 0);
    
    return 0;
}
