#include "arvore.h";

// estrutura nó
typedef struct no {
    Item conteudo;
    struct no *esquerda, *direita;
} NoL;

// estrutura árvore com um ponteiro para um nó
typedef struct {
    NoL *raiz;
    int tam;
} ArvBL;

ArvB criaArvore() {
    ArvBL *arvore =(ArvBL*)malloc(sizeof(ArvBL));
    arvore->raiz = NULL;
    arvore->tam = 0;

    return arvore;
}

No getRaiz(ArvB arv) {
    ArvBL *arvore = arv;

    return arvore->raiz;
}

// procedimento para inserir um elemento na subárvore esquerda
void inserirEsquerda(No nov, Item valor) {
    NoL *no = nov;

    if(no->esquerda == NULL) {
      NoL *novo = (NoL*)malloc(sizeof(NoL));
        novo->conteudo = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        no->esquerda = novo;
    } else {
        if(valor < no->esquerda->conteudo)
            inserirEsquerda(no->esquerda, valor);
        if(valor > no->esquerda->conteudo)
            inserirDireita(no->esquerda, valor);
    }
}

// procedimento para inserir um elemento na subárvore direita
void inserirDireita(No nov, Item valor) {
    NoL *no = nov;
    if(no->direita == NULL) {
        NoL *novo = (NoL*)malloc(sizeof(NoL));
        novo->conteudo = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        no->direita = novo;
    } else {
        if(valor > no->direita->conteudo)
            inserirDireita(no->direita, valor);
        if(valor < no->direita->conteudo)
            inserirEsquerda(no->direita, valor);
    }
}

/*
    Procedimento para inserir um elemento na árvore
    faz uso dos dois procedimentos anteriores,
    inserindo à esquerda ou à direita
*/
void inserir(ArvB arv, Item info) {
    ArvBL *arvL = arv;
    NoL *infoL = info;

    if(arvL->raiz == NULL) {
        NoL *novo = (NoL*)malloc(sizeof(NoL));
        novo->conteudo = info;
        novo->esquerda = NULL;
        novo->direita = NULL;
        arvL->raiz = novo;
    } else {
        if(info < arvL->raiz->conteudo)
            inserirEsquerda(arvL->raiz, info);
        if(info > arvL->raiz->conteudo)
            inserirDireita(arvL->raiz, info);
    }
}

/*  nova versão para a inserção, mais resumida
    perceba que agora é só uma função
*/
No inserirNovaVersao(No raizv, Item valor) {
    NoL *raiz = raizv;

    if(raiz == NULL) {
        NoL *novo = (NoL*)malloc(sizeof(NoL));
        novo->conteudo = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        return novo;
    } else {
        if(valor < (int) raiz->conteudo)
            raiz->esquerda = inserirNovaVersao(raiz->esquerda, valor);
        if(valor > raiz->conteudo)
            raiz->direita = inserirNovaVersao(raiz->direita, valor);
        return raiz;
    }
}

// função que retorna o tamanho de uma árvore
// int tamanho(No *raiz) {
//     if(raiz == NULL)
//         return 0;
//     else
//         return 1 + tamanho(raiz->esquerda) + tamanho(raiz->direita);
// }

// função para buscar um elemento na árvore
Item buscar(No raizv, Item chave) {
    NoL *raiz = raizv;

    if(raiz == NULL) {
        return 0;
        //return NULL;
    } else {
        int idRaiz = getID(raiz->conteudo);
        int idChave = getID(chave);

        if(idRaiz == idChave)
            // return 1;
            return raiz->conteudo;
        else {
            if(idChave < idRaiz)
                return buscar(raiz->esquerda, chave);
            else
                return buscar(raiz->direita, chave);
        }
    }
}

/*  faz a impressão da árvore em ordem crescente
    esquerda - raiz - direita
*/
void imprimir(No raizv) {
    NoL *raiz = raizv;

    if(raiz != NULL) {
        imprimir(raiz->esquerda);
        printf("%d ", raiz->conteudo);
        imprimir(raiz->direita);
    }
}

// função para a remoção de um nó
No remover(No raizv, Item chave) {
    NoL *raiz = raizv;

    // 3 casos de remoção:
    // 1º : quando o nó que desejo remover é folha (não possui filhos);
    // 2º : quando o nó que desejo remover tem 1 filho (esquerda ou direita);
    // 3º : quando o nó que desejo remover tem os 2 filhos (caso mais difícil).
    
    if(raiz == NULL) {
        printf("Valor nao encontrado!\n");
        return NULL;
    } else {
        if(raiz->conteudo == chave) {
            // remove nós folhas (nós sem filhos)
            if(raiz->esquerda == NULL && raiz->direita == NULL) {
                free(raiz);
                return NULL;
            }
            else{
                // remover nós que possuem apenas 1 filho
                if(raiz->esquerda == NULL || raiz->direita == NULL){
                    NoL *aux;
                    if(raiz->esquerda != NULL)
                        aux = raiz->esquerda;
                    else
                        aux = raiz->direita;
                    free(raiz);
                    return aux;
                }
                else{
                    NoL *aux = raiz->esquerda;
                    while(aux->direita != NULL)
                        aux = aux->direita;
                    raiz->conteudo = aux->conteudo;
                    aux->conteudo = chave;
                    raiz->esquerda = remover(raiz->esquerda, chave);
                    return raiz;
                }
            }
        } else {
            if(chave < raiz->conteudo)
                raiz->esquerda = remover(raiz->esquerda, chave);
            else
                raiz->direita = remover(raiz->direita, chave);
            return raiz;
        }
    }
}