#include <stdio.h>
#include <stdlib.h>

// Defini��o da estrutura para os n�s da lista
struct numero {
    int num; // valor
    struct numero *prox; //proximo
};

typedef struct numero tipoNumero; //Numero

// Fun��o para inserir no in�cio da lista
tipoNumero* InserirIni(tipoNumero* ptLista, int num) {
    tipoNumero* novoNo = (tipoNumero*)malloc(sizeof(tipoNumero)); // Aloca mem�ria para o novo n�
    if (novoNo == NULL) {
        printf("Lista vazia.\n");
        exit(1);
    }

    novoNo->num = num; // Define o valor do novo n�
    novoNo->prox = ptLista; // Define o pr�ximo do novo n� como o in�cio da lista

    return novoNo; // Retorna o novo in�cio da lista
}

// Fun��o para inserir no final da lista
tipoNumero* InserirFim(tipoNumero* ptLista, int num) {
    tipoNumero* novoNo = (tipoNumero*)malloc(sizeof(tipoNumero)); // Aloca mem�ria para o novo n�
    if (novoNo == NULL) {
        printf("Lista vazia.\n");
        exit(1);
    }

    novoNo->num = num; // Define o valor do novo n�
    novoNo->prox = NULL; // Define o pr�ximo do novo n� como NULL (final da lista)

    if (ptLista == NULL) {
        return novoNo; // Se a lista estiver vazia, retorna o novo n� como in�cio da lista
    }

    tipoNumero* atual = ptLista;
    while (atual->prox != NULL) {
        atual = atual->prox; // Percorre a lista at� o �ltimo n�
    }

    atual->prox = novoNo; // Define o pr�ximo do �ltimo n� como o novo n�
    }
    return ptLista; // Retorna o in�cio da lista
}

// Fun��o para contar o n�mero de n�s na lista
int ContarNos(tipoNumero* ptLista) {
    int contador = 0;
    tipoNumero* atual = ptLista;
    while (atual != NULL) { //Percorre a lista enquanto o n� atual n�o for NULL.
        contador++;
        atual = atual->prox;
    }
    return contador; //Retorna o n�mero total de n�s na lista.
}

// Fun��o para inserir no meio da lista
tipoNumero* InserirMeio(tipoNumero* ptLista, int num) {
    int numNos = ContarNos(ptLista); // Conta o n�mero de n�s na lista
    int meio;

    if (numNos % 2 == 1) { // Calcula o �ndice do meio da lista
        // Inserir imediatamente antes do meio da lista
        meio = (numNos - 2) / 2;
    }
    else{
        // insere no meio
        meio = (numNos - 1) / 2;
    }

    tipoNumero* novoNo = (tipoNumero*)malloc(sizeof(tipoNumero)); // Aloca mem�ria para o novo n�
    if (novoNo == NULL) {
        printf("Lista vazia.\n");
        exit(1);
    }

    novoNo->num = num; // Define o valor do novo n�

    if (ptLista == NULL) {
        novoNo->prox = NULL;
        return novoNo; // Se a lista estiver vazia, retorna o novo n� como in�cio da lista
    }

    if (meio == 0) {
         //Inserir no in�cio da lista se ela estiver vazia
        novoNo->prox = ptLista;
        return novoNo;
    }

    tipoNumero* atual = ptLista;
    for (int i = 0; i < meio; i++) {
        atual = atual->prox; // Percorre a lista at� o n� anterior ao meio
    }

    novoNo->prox = atual->prox; // Define o pr�ximo do novo n�
    atual->prox = novoNo; // Define o pr�ximo do n� anterior ao meio como o novo n�

    return ptLista; // Retorna o in�cio da lista
}

// Fun��o para exibir todos os elementos da lista
void ExibirLista(tipoNumero* ptLista) {
    tipoNumero* atual = ptLista;
    while (atual != NULL) { //Enquanto o n� atual n�o for NULL, imprime o valor do n� e avan�a para o pr�ximo n�.
        printf("%d ", atual->num);
        atual = atual->prox;
    }
    printf("\n");
}

// Fun��o para destruir a lista (liberar mem�ria)
void DestruirLista(tipoNumero* ptLista) {
    tipoNumero* atual = ptLista;
    while (atual != NULL) {
        tipoNumero* proximo = atual->prox;
        free(atual); // Libera a mem�ria do n� atual
        atual = proximo; // Avan�a para o pr�ximo n�
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
            // Inserir no in�cio da lista (n�mero par)
            ptLista = InserirIni(ptLista, num);
        }
        else {
            // Inserir no final da lista (n�mero �mpar)
            ptLista = InserirFim(ptLista, num);
        }
    }

    ptLista = InserirMeio(ptLista, 0); // Inserir o n�mero 0 no meio da lista

    printf("Elementos da lista:\n");
    ExibirLista(ptLista);

    DestruirLista(ptLista); // Liberar mem�ria

    return 0;
}
