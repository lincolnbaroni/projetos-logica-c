#include <stdio.h>
#define PRODUTO 3

// STRUCTC
    typedef struct {
        int id;
        char nome[50];
        float preco;
        int estoque;
    } Produto;
    
// FUNÇÃO EXIBIR PRODUTO
    void exibirProdutos(Produto a[]) {
        for(int i = 0; i < 3; i++) {
            
            printf("Nome: %s\n", a[i].nome);
            printf("ID: %d\n", a[i].id);
            printf("Preco: %.2f\n", a[i].preco);
            printf("Estoque: %d\n", a[i].estoque);
            printf("-------------------------------------\n");
        }
    }
    
// FUNÇÃO ORDENAR POR PRECO
    void ordenarPorPreco(Produto lista[]) {
        Produto aux;
        
        for(int i = 0; i < PRODUTO; i++) {
            for(int i = 0; i < PRODUTO - 1; i++) {
                if(lista[i].preco > lista[i+1].preco || lista[i].preco == lista[i+1].preco && lista[i].estoque > lista[i+1].estoque) {
                    aux = lista[i];
                    lista[i] = lista[i+1];
                    lista[i+1] = aux;
                }
            }
        }
        
        for(int i = 0; i < PRODUTO; i++) {
            printf("Nome: %s | Preco: %.2f\n", lista[i].nome, lista[i].preco);
        }
    }

int main() {
    
    printf("----| SISTEMA DE ESTOQUE (PRODUTOS) |----\n");
    
    Produto produtos[PRODUTO];
    
    for(int i = 0; i < PRODUTO; i++) {
        printf("Nome do produto: ");
        scanf(" %[^\n]", produtos[i].nome);
        
        printf("ID produto: ");
        scanf("%d", &produtos[i].id);
        
        printf("Preco: ");
        scanf("%f", &produtos[i].preco);
        
        printf("Estoque: ");
        scanf("%d", &produtos[i].estoque);
        
        printf("-------------------------------------\n");
    }
    
    printf("--- LISTA DOS PRODUTOS CADASTRADOS ---\n");
    exibirProdutos(produtos);
    
    printf("--- LISTA DO PRECO DO MENOR PARA O MAIOR ---\n");
    ordenarPorPreco(produtos);

    return 0;
}
