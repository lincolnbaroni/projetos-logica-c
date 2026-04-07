#include <stdio.h>
#include <string.h>

    typedef struct {
        char placa[10];
        int horaEntrada;
        int horaSaida;
    } Carro;

int main() {

    int q = 0;
    int tempTotal[10];
    float valorPag[10];
    float totalArrec = 0;
    char cad;
    
    Carro carro[10];
    
    printf("-------| GERENCIAMENTO DE CARROS (ENTRADA E SAÍDA) |-------\n");
    printf("VALOR: R$ 5,00 POR HORA\n");
    
    
    do {
        
        do {
            printf("Placa do CARRO (exatos 7 caracteres): ");
            scanf("%7s", carro[q].placa);
            
            if(strlen(carro[q].placa) != 7) {
                printf("ERRO, digite ate 7 caracteres para a placa\n");
            }
            
            
        } while (strlen(carro[q].placa) != 7);
            
            printf("Hora de entrada: ");
            scanf("%d", &carro[q].horaEntrada);
            
            printf("Hora de saida: ");
            scanf("%d", &carro[q].horaSaida);
            
            tempTotal[q] = (carro[q].horaSaida - carro[q].horaEntrada);
            valorPag[q] = (tempTotal[q] * 5);
            
            totalArrec += valorPag[q];
        
        printf("------------------------------------------------\n");
        
        printf("Deseja continuar cadastrando mais carros (S | N): ");
        scanf(" %c", &cad);
        
        q++;
        
        printf("------------------------------------------------\n");
        
    } while ((cad == 'S' || cad == 's') && q < 10);
    
    printf("REGISTROS DOS VEICULOS CADASTRADOS\n");
    
    for(int i = 0; i < q; i ++) {
        printf("Veiculo (placa): %s | Tempo permanente: %d | Valor a pagar: %.2f\n", carro[i].placa, tempTotal[i], valorPag[i]);
    }
    printf("Total no dia: %.2f\n", totalArrec);
    
    return 0;
}
