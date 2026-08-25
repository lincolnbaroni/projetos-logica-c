# 📚 Algoritmos: Pesquisa Binária e Bubble Sort

*Exercícios referentes ao conceito de Pesquisa Binária e Bubble Sort - Lógica de Programação.*

---

## 🟢 Nível 1: O Rastreador de IDs (A Estrutura Base)

**O Conceito:** Criar a estrutura clássica da pesquisa binária em um vetor simples de números inteiros para fixar as variáveis `inicio`, `fim` e `meio`.

**O Cenário:** Você tem uma lista ordenada de IDs de usuários válidos e precisa verificar se um ID específico tem permissão de acesso.

**O Exercício:**
* Na main, crie um vetor já ordenado: `int ids[8] = {12, 25, 33, 47, 58, 62, 79, 85};`.
* Crie uma função `int validarAcesso(int lista[], int tamanho, int idAlvo)`.
* Dentro da função, crie as variáveis `inicio = 0` e `fim = tamanho - 1`.
* Monte o laço `while (inicio <= fim)`.
* Calcule o meio. Se `lista[meio] == idAlvo`, retorne o meio. Se for menor, atualize o inicio. Se for maior, atualize o fim.
* Se o while acabar e não achar nada, retorne `-1`.
* Na main, peça um ID para o usuário, chame a função e imprima "Acesso Liberado" ou "Acesso Negado".

### 💻 Código

```c
#include <stdio.h>

int validarAcesso (int lista[], int tamanho, int idAlvo) {
    int inicio = 0;
    int fim = tamanho - 1;
   
   while(inicio <= fim) {
       int meio = (inicio + fim) / 2;
       
       if(lista[meio] == idAlvo) {
           return meio;
       }
       
       if(lista[meio] < idAlvo) {
           inicio = meio + 1;
       }
       
       if(lista[meio] > idAlvo) {
           fim = meio - 1;
       }
   }
   
   return -1;
}

int main() {
   int vetor[8] = {12, 25, 33, 47, 58, 62, 79, 85};
   int id;
   
   printf("Digite o alvo a ser procurado: ");
   scanf("%d", &id);
   
   int acesso = validarAcesso(vetor, 8, id);
   
   if(acesso != -1) {
       printf("[SUCESSO] ID encontrado acesso LIBERADO | ID: %d\n", acesso);
   } else {
       printf("[NEGADO] ID não encontrado acesso NEGADO");
   }

    return 0;
}
```

## 🟡 Nível 2: Catalogo de Produtos (Aplicação com Structs)
**O Conceito:** Estruturar uma pesquisa Binária por `IDs de usuaria` e retornar a gaveta inteira dessa mesma struct, para acessar os outros dados.

**Estrutura:** Crie uma struct Produto com: idProduto (int), nome (char) e preco (float).

**O Exercício:** 
* Na `main`, cadastre 4 produtos manualmente. Atenção: Cadastre-os em ordem crescente pelo idProduto!
* Crie a função `int buscarProduto(Produto catalogo[], int tamanho, int idDesejado)`.
* Na `main`peça o usuario o ID que deseja comprar, se achar, exiba o nome e o preço do produto. Se não achar retorne -1 como "Produto inexistente".

### 💻 Código

```c
#include <stdio.h>
#define prod 4

typedef struct {
    int idProduto;
    char nomeProd[50];
    float precoProd;
} Produto;
    
// FUNÇÃO ENCONTRAR PRODUTO
int buscarProduto(Produto catalogo[], int tamanho, int idAlvoProd) {
    int inicio = 0;
    int fim = tamanho - 1;
    
    while(inicio <= fim) {
        int meio = (inicio + fim) / 2;
        
        if(catalogo[meio].idProduto == idAlvoProd) {
            return meio;
        }
        
        if(catalogo[meio].idProduto < idAlvoProd) {
            inicio = meio + 1;
        }
        
        if(catalogo[meio].idProduto > idAlvoProd) {
            fim = meio - 1;
        }
    }
    
    return -1;
}
    
// FUNÇÃO ORDENAR PRODUTOS
void ordenarProd(Produto lista[], int tamanho) {
    Produto variAux;
    
    for(int i = 0; i < tamanho - 1; i++) {
        for(int j = 0; j < tamanho - i - 1; j++) {
            if(lista[i].idProduto > lista[i+1].idProduto) {
                variAux = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = variAux;
            }
        }
    }
        printf("LISTA DOS PRODUTOS DISPONIVEIS\n");
        for(int i = 0; i < tamanho; i++) {
            printf("Nome: %s | ID: %d | Preco: %.2f\n", lista[i].nomeProd, lista[i].idProduto, lista[i].precoProd);
        }
}
    
int main() {
    int idProcu;
    Produto produto1[prod];
    
    for(int i = 0; i < prod; i++) {
        printf("Nome do produto: ");
        scanf(" %[^\n]", produto1[i].nomeProd);
        
        printf("ID: ");
        scanf("%d", &produto1[i].idProduto);
        
        printf("Valor: ");
        scanf("%f", &produto1[i].precoProd);
        
        printf("---------------------------------\n");
    }
    
    ordenarProd(produto1, 4);
    printf("---------------------------------\n");
    
    printf("COMPRA DE PRODUTOS, DIGITE O ID\n");
    printf("ID do produto: ");
    scanf("%d", &idProcu);
    
    int resultado = buscarProduto(produto1, 4, idProcu);
    
    if(resultado != -1) {
        printf("[SUCESSO] produto encontrado\n");
        printf("Produto: %s | Preco: %.2f\n", produto1[resultado].nomeProd, produto1[resultado].precoProd);
    } else {
        printf("[NEGADO] Produto não encontrado na lista");
    }

    return 0;
}

```
---
## 🟠 Nível 3: Desafio da prova real que a Pesquisa Binário é superior a Pesquisa Sequencial.

**O Conceito:** Desafio criado com intuito de demonstrar que fazer da utilização de Pesquisa Binário entrega mais desempenho para a solução.

### 💻 Código

```c
#include <stdio.h>
#include <string.h>
#define veic 2

// ESTRUTURA DE DADOS
typedef struct {
    int idVeiculo;
    char modelo[50];
    float debitoMulta;
} Veiculo;
    
// FUNÇÃO ORGANIZAR STRUCT
void organizarPlacas (Veiculo lista[], int total) {
    Veiculo aux;
    
    for(int i = 0; i < total; i++) {
        for(int j = 0; j < total - 1; j++) {
            if(lista[j].idVeiculo > lista[j+1].idVeiculo) {
                aux = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = aux;
            }
        }
    }
}
    
// FUNÇÃO BUSCA AUTOMATICA
int buscarVeiculo(Veiculo list[], int total, int idAlvo) {
    int inicio = 0;
    int fim = total - 1;
    
    while(inicio <= fim) {
        int meio = (inicio+fim) / 2;
        
        if(list[meio].idVeiculo == idAlvo) {
            return meio;
        }
        
        if(list[meio].idVeiculo < idAlvo) {
            inicio = meio + 1;
        }
        
        if(list[meio].idVeiculo > idAlvo) {
            fim = meio - 1;
        }
    }
    
    return - 1;
}
    
int main() {
    Veiculo veiculo1[veic];
    
    printf("REGISTRO DE VEICULOS AUTOMOTIVOS\n");
    for(int i = 0; i < veic; i++) {
        int placaValid = 0;
        printf("VEICULO %d\n", i + 1);
        
        do {
            int placaValid = 0;
            
            printf("Placa (Maximo 7 digitos): ");
            scanf("%d", &veiculo1[i].idVeiculo);
            
            if(veiculo1[i].idVeiculo < 1000000 || veiculo1[i].idVeiculo > 9999999) {
                printf("Digitos incorretos, favor digitar quantidade digito correto\n");
                placaValid = 1;
            } 
            
        } while (placaValid == 1);
        
        printf("Modelo: ");
        scanf(" %[^\n]", veiculo1[i].modelo);
        
        printf("Multas: ");
        scanf("%f", &veiculo1[i].debitoMulta);
        
        printf("--------------------------\n");
    }
    
    organizarPlacas(veiculo1, veic);
    
    for(int i = 0; i < veic; i++) {
        printf("Placa: %d | Modelo: %s | Multa: %f\n", veiculo1[i].idVeiculo, veiculo1[i].modelo, veiculo1[i].debitoMulta);
    }
    
    int idPlacaVeic;
    
    printf("DIGITE A PLACA DO VEICULO PARA A BUSCA\n");
    printf("Placa do Veiculo: ");
    scanf("%d", &idPlacaVeic); // Correção do scanf original
    
    int acessoBusca = buscarVeiculo(veiculo1, veic, idPlacaVeic);
    
    if(acessoBusca != -1) {
        printf("Busca concluida com sucesso [SUCESSO] | %d\n", veiculo1[acessoBusca].idVeiculo);
    } else {
        printf("[NEGADO] Automovel nao encontrado\n");
    }
```
---

## 🟢 Desafio 1: A Guilda de Aventureiros (Filtros e Acumuladores).

**O Objetivo:** Praticar a varredura para encontrar não só um item especifico, mas da busca de vários itens buscando o resultado matemático final da variável acumuladora.

### 💻 Código

```c

#include <stdio.h>
#define total 3

typedef struct {
    int idMissao;
    char descric[50];
    float recompensa;
    int status;
} Missao;

void percorrerStatus(Missao lista[], int tamanho) {
    for(int i = 0; i < tamanho; i++) {
        if(lista[i].status == 0) {
          printf("Missao: %d\n", lista[i].idMissao);
          printf("Descricao: %s\n", lista[i].descric);
          printf("Recompensa: %.2f\n", lista[i].recompensa);
          printf("Status: %d\n", lista[i].status);
          printf("----------------------------------------\n");
        }
    }
}

float varrerVetorRecom(Missao lista[], int tamanho) {
    float acumuladorRecom = 0;
    
    for(int i = 0; i < tamanho; i++) {
        if(lista[i].status == 1) {
            acumuladorRecom += lista[i].recompensa;
        }
    }
    return acumuladorRecom;
}

int main() {
    Missao miss[total];
    
    printf("CADASTRO DAS MISSOES\n");
    for(int i = 0; i < total; i++) {
        printf("ID Missao: ");
        scanf("%d", &miss[i].idMissao);
        
        printf("Descricao: ");
        scanf(" %[^\n]", miss[i].descric);
        
        printf("Recompensa: ");
        scanf("%f", &miss[i].recompensa);
        
        printf("Status: ");
        scanf("%d",&miss[i].status);
        printf("----------------------------------------\n");
    }
    
    printf("MISSOA QUE NAO OBTEVE SUCESSO\n");
    percorrerStatus(miss, total);
    
    float resulMissSucesso = varrerVetorRecom(miss, total);
    
    printf("TOTAL FINANCEIRO DAS MISSOES QUE OBTEVE SUCESSO\n");
    printf("Total financeiro: %.2f", resulMissSucesso);

    return 0;
}

```
