#include <stdio.h>

// STRUCT DADOS
    typedef struct {
        int id;
        char nome[50];
        int idade;
        char status;
    } Paciente;
    
// FUNÇÃO EXIBIR MENU
    void exibirMenu() {
        printf("SISTEMA DE DADOS HOSPITALAR\n");
        printf("Escolha uma das opcao\n");
        printf("1 - Cadastrar Paciente\n");
        printf("2 - Lista por prioridade\n");
        printf("3 - Chamar paciente\n");
        printf("Opcao desejada: ");
    }    
    
// FUNÇÃO CADASTRAR PACIENTE
    void cadastrarPaciente(Paciente lista[], int *contador) {
        int indice = *contador;
        
        printf(" | NOVO CADASTROS | \n");
        printf("Digite seu nome: ");
        scanf(" %[^\n]", lista[indice].nome);
        
        printf("Digite sua idade: ");
        scanf("%d", &lista[indice].idade);
        
        lista[indice].id = indice + 1;
        lista[indice].status = 'A';
        
        printf("Paciente cadastrado com sucesso\n");
        printf("--------------------------------------\n");
        
        *contador = *contador + 1;
    }
    
// FUNÇÃO LISTA POR PRIORIDADE
	void listaPorPrioridade(Paciente lista[], int totalPacient) {
	    for(int i = 0; i < totalPacient; i++) {
	        printf("Nome: %s\n", lista[i].nome);
	        printf("ID: %d\n", lista[i].id);
	        printf("Idade: %d\n", lista[i].idade);
	        printf("Status: %c\n", lista[i].status);
	        printf("\n");
	    }
	    
		Paciente aux;
		for(int i = 0; i < totalPacient; i++) {
			for(int j = 0; j < totalPacient - 1; j++) {
				if(lista[j].idade > lista[j+1].idade) {
					aux = lista[j];
					lista[j] = lista[j+1];
					lista[j+1]= aux;
				}
			}
		}
		
		printf("---- LISTA ORDENADA DOS PACIENTES ----\n");
		for(int i = 0; i < totalPacient; i++) {
			printf("Nome: %s | Idade: %d\n", lista[i].nome, lista[i].idade);
		}
		printf("--------------------------------------\n");
	}
	
// FUNÇÃO CHAMAR PACIENTE 
    void chamarPaciente(Paciente lista[], int totalPacient) {
        int idPesq = 0;
        int achou = 0;
        
        printf("CHAMAR PACIENTE\n");
        printf("ID paciente: ");
        scanf("%d", &idPesq);
        
        for(int i = 0; i < totalPacient; i++) {
            if(idPesq == lista[i].id) {
                printf("Paciente encontrado | Nome: %s\n", lista[i].nome);
                lista[i].status = 'T';
                achou = 1;
                break;
            }
        }
        
        if(achou == 0) {
                printf("Id %d do paciente não encontrado na fila de espera\n", idPesq);
            }
    }

int main(int argc, char** argv) {
	
	Paciente paciente1[100];
    int opcao;
    int totalPacient = 0;
    
      do {
          exibirMenu();
          scanf("%d", &opcao);
          printf("-------------------------------\n");
          
          switch (opcao) {
            case 1:
                cadastrarPaciente(paciente1, &totalPacient);
                break;
                    
            case 2:
            	listaPorPrioridade(paciente1, totalPacient);
            	break;
            	
            case 3:
                chamarPaciente(paciente1, totalPacient);
        }       
          
          
      } while (opcao != 0);
	
	
	
	return 0;
}
