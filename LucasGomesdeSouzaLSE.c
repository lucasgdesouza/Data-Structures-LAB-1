#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura para os nós da lista
struct numero {
    int num; // valor
    struct numero *prox; //proximo
};

typedef struct numero tipoNumero; //Numero

// Função para inserir no início da lista
tipoNumero* InserirIni(tipoNumero* ptLista, int num) {
    tipoNumero* novoNo = (tipoNumero*)malloc(sizeof(tipoNumero)); // Aloca memória para o novo nó
    if (novoNo == NULL) {
        printf("Lista vazia.\n");
        exit(1);
    }

    novoNo->num = num; // Define o valor do novo nó
    novoNo->prox = ptLista; // Define o próximo do novo nó como o início da lista

    return novoNo; // Retorna o novo início da lista
}

// Função para inserir no final da lista
tipoNumero* InserirFim(tipoNumero* ptLista, int num) {
    tipoNumero* novoNo = (tipoNumero*)malloc(sizeof(tipoNumero)); // Aloca memória para o novo nó
    if (novoNo == NULL) {
        printf("Lista vazia.\n");
        exit(1);
    }

    novoNo->num = num; // Define o valor do novo nó
    novoNo->prox = NULL; // Define o próximo do novo nó como NULL (final da lista)

    if (ptLista == NULL) {
        return novoNo; // Se a lista estiver vazia, retorna o novo nó como início da lista
    }

    tipoNumero* atual = ptLista;
    while (atual->prox != NULL) {
        atual = atual->prox; // Percorre a lista até o último nó
    }

    atual->prox = novoNo; // Define o próximo do último nó como o novo nó
    }
    return ptLista; // Retorna o início da lista
}

// Função para contar o número de nós na lista
int ContarNos(tipoNumero* ptLista) {
    int contador = 0;
    tipoNumero* atual = ptLista;
    while (atual != NULL) { //Percorre a lista enquanto o nó atual não for NULL.
        contador++;
        atual = atual->prox;
    }
    return contador; //Retorna o número total de nós na lista.
}

// Função para inserir no meio da lista
tipoNumero* InserirMeio(tipoNumero* ptLista, int num) {
    int numNos = ContarNos(ptLista); // Conta o número de nós na lista
    int meio;

    if (numNos % 2 == 1) { // Calcula o índice do meio da lista
        // Inserir imediatamente antes do meio da lista
        meio = (numNos - 2) / 2;
    }
    else{
        // insere no meio
        meio = (numNos - 1) / 2;
    }

    tipoNumero* novoNo = (tipoNumero*)malloc(sizeof(tipoNumero)); // Aloca memória para o novo nó
    if (novoNo == NULL) {
        printf("Lista vazia.\n");
        exit(1);
    }

    novoNo->num = num; // Define o valor do novo nó

    if (ptLista == NULL) {
        novoNo->prox = NULL;
        return novoNo; // Se a lista estiver vazia, retorna o novo nó como início da lista
    }

    if (meio == 0) {
         //Inserir no início da lista se ela estiver vazia
        novoNo->prox = ptLista;
        return novoNo;
    }

    tipoNumero* atual = ptLista;
    for (int i = 0; i < meio; i++) {
        atual = atual->prox; // Percorre a lista até o nó anterior ao meio
    }

    novoNo->prox = atual->prox; // Define o próximo do novo nó
    atual->prox = novoNo; // Define o próximo do nó anterior ao meio como o novo nó

    return ptLista; // Retorna o início da lista
}

// Função para exibir todos os elementos da lista
void ExibirLista(tipoNumero* ptLista) {
    tipoNumero* atual = ptLista;
    while (atual != NULL) { //Enquanto o nó atual não for NULL, imprime o valor do nó e avança para o próximo nó.
        printf("%d ", atual->num);
        atual = atual->prox;
    }
    printf("\n");
}

// Função para destruir a lista (liberar memória)
void DestruirLista(tipoNumero* ptLista) {
    tipoNumero* atual = ptLista;
    while (atual != NULL) {
        tipoNumero* proximo = atual->prox;
        free(atual); // Libera a memória do nó atual
        atual = proximo; // Avança para o próximo nó
    }
}

int main() {
    tipoNumero* ptLista = NULL; // Criar lista vazia

    int num, metade;
    printf("Digite numeros positivos (ou negativos para encerrar):\n");
    while (1) {
        scanf("%d", &num);
        if (num < 0) {
            break; // Encerra a leitura
        }
        if (num == 0){
            // Inserir no meio da lista
            ptLista = InserirMeio(ptLista, num);
        }
        else if (num % 2 == 0) {
            // Inserir no início da lista (número par)
            ptLista = InserirIni(ptLista, num);
        }
        else {
            // Inserir no final da lista (número ímpar)
            ptLista = InserirFim(ptLista, num);
        }
    }

    ptLista = InserirMeio(ptLista, 0); // Inserir o número 0 no meio da lista

    printf("Elementos da lista:\n");
    ExibirLista(ptLista);

    DestruirLista(ptLista); // Liberar memória

    return 0;
}
