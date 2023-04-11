#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char nome[100];
    struct Node* prox;
} Node;

Node* criarNode(char nome[]) {
    Node* node = (Node*) malloc(sizeof(Node));
    strcpy(node->nome, nome);
    node->prox = NULL;
    return node;
}

Node* Insere(Node* ini, char nome[]) {
    if (ini == NULL) {
        ini = criarNode(nome);
        return ini;
    }

    Node* atual = ini;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }

    atual->prox = criarNode(nome);
    return ini;
}

void Imprime(Node* ini) {
    Node* atual = ini;
    while (atual != NULL) {
        if(atual->prox != NULL){
        printf("%s ", atual->nome);
        atual = atual->prox;
        }
        else if (atual->prox == NULL)
        {
        printf("%s", atual->nome);
        atual = atual->prox;
        }
    }
  printf("\n");
}

int main() {
    Node* ini = NULL;
    Node* amigo = NULL;

    // le a lista atual
    char input[1000];
    fgets(input, 1000, stdin);
    char* nome = strtok(input, " \n");
    while (nome != NULL) {
        ini = Insere(ini, nome);
        nome = strtok(NULL, " \n");
    }

    // le a lista de amigos
    fgets(input, 1000, stdin);
    nome = strtok(input, " \n");
    while (nome != NULL) {
        amigo = Insere(amigo, nome);
        nome = strtok(NULL, " \n");
    }

    // le o nome do amigo que vai receber a nova lista
    fgets(input, 1000, stdin);
    nome = strtok(input, " \n");
    if (strcmp(nome, "nao") == 0) {
        // adiciona a lista ao final da atual
        Node* atual = ini;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = amigo;
    } else {
  // insere a lista nova antes
    Node* prev = NULL;
    Node* atual = ini;
    while (atual != NULL && strcmp(atual->nome, nome) != 0) {
        prev = atual;
        atual = atual->prox;
    }
    if (atual != NULL) {
        if (prev != NULL) {
            prev->prox = amigo;
        } else {
            ini = amigo;
        }
        Node* fim = amigo;
        while (fim->prox != NULL) {
            fim = fim->prox;
        }
        fim->prox = atual;
    }
}
    // lista atualizda
    Imprime(ini);
    
    // liberar a memoria
    Node* atual = ini;
    while (atual != NULL) {
        Node* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    atual = amigo;
    while (atual != NULL) {
        Node* temp = atual;
        atual = atual->prox;
        
    }

    return 0;
}
