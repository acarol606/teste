
#ifndef arvore_h
#define arvore_h 
#include <stdio.h>
#include <stdlib.h>
#include "figuras.h"

typedef void* ArvB;
typedef void* No;
typedef void* Item;

ArvB criaArvore();
void inserirEsquerda(No no, Item valor);
void inserirDireita(No no, Item valor);
void inserir(ArvB arv, Item info);
void imprimir(No raiz);
int tamanho(No raiz);

No getRaiz(ArvB arv);

// na função buscar, coloquei pra retornar o conteúdo do nó que buscamos ao invés de retornar um inteiro
Item buscar(No raiz, Item  chave); // a chave vai ser as coordenadas x, y, que são float
//int buscar(No *raiz, int chave);

No remover(No raiz, Item chave);

// provavelmente na função de buscar vai ter que alterar bastante coisa quando for transofmrar em ternária:
/*
Item buscar(No *raiz, float chave1, float chave2) {
    if(raiz == NULL) {
        //return 0;
        return NULL;
    } else {
        if(raiz->conteudo->x == chave1 && raiz->conteudo->y == chave2)
            return raiz->conteudo;  // vai retornar a struct da figura inteira
        else {
            if(chave < raiz->conteudo)
                return buscar(raiz->esquerda, chave);
            else
                return buscar(raiz->direita, chave);
        }
    }
}
*/

#endif