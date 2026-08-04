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

