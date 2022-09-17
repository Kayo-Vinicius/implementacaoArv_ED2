#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int numero;
	struct no *direita;
	struct no *esquerda; 
}NO;

NO* criar(int numero){
	NO *raiz = (NO*)malloc(sizeof(NO));
	raiz->numero = numero;
	raiz->esquerda = NULL;
	raiz->direita = NULL;
	return raiz;
} 

void adicionar(NO *raiz, int valor){
	if(valor < raiz->numero){
		if(raiz->esquerda == NULL)
			raiz->esquerda = criar(valor);
		else
			adicionar(raiz->esquerda, valor);
	}
	else{
		if(raiz->direita == NULL)
			raiz->direita = criar(valor);
		else
			adicionar(raiz->direita, valor);
		
	}
}

void imprimir(NO *raiz){
	if(raiz != NULL){
		imprimir(raiz->esquerda);
		printf("%d ", raiz->numero);
		imprimir(raiz->direita);
	}
}

//Questão 5
//Função que conta a altura de uma arvore
int alturaArvore(NO *raiz){
    if(raiz == NULL){
		 return -1;
	}
	else{
		int esquerda = alturaArvore(raiz->esquerda);
		int direita = alturaArvore(raiz->direita);
        if(esquerda > direita)
			return esquerda + 1;
		else
		    return direita + 1;
	}
}

//Questão 2
//Função que conta o numero de nós de uma arvore
int numeroDeNos(NO *raiz){
	if(raiz == NULL){
		return 0;
	}else{
		return 1 + numeroDeNos(raiz->esquerda) + numeroDeNos(raiz->direita); 
	}
}

//Questão 3
//Função que conta o numero de nós não folha de uma arvore
int numNosNaoFolha(NO *raiz){
	if(raiz == NULL){
		return 0;
	}
	else if((raiz->esquerda) != NULL && (raiz->direita) != NULL){
		return 1 + numNosNaoFolha(raiz->esquerda) + numNosNaoFolha(raiz->direita); 
	}
}

//Questão 7
//Função que conta o maior numero de uma arvore
int maiorNumero(NO *raiz){
	if(raiz->direita != NULL){
		maiorNumero(raiz->direita);
	}else if(raiz->direita == NULL){
		return raiz->numero;
	}
}

//Questão
//Função para remover nó de uma arvore
void removerNo(NO** pRaiz, int valor){
    if(*pRaiz == NULL){  
       printf("\nNumero nao existe na arvore!\n");
       return;
    }
	
    if(valor < (*pRaiz)->numero){
    	removerNo(&(*pRaiz)->esquerda, valor);
	}
    else{
        if(valor > (*pRaiz)->numero){
        	removerNo(&(*pRaiz)->direita, valor);
		}
        else{   
            NO *pAux = *pRaiz;
			   
            if (((*pRaiz)->esquerda == NULL) && ((*pRaiz)->direita == NULL)){
                free(pAux);
                (*pRaiz) = NULL; 
            }else{    
                if ((*pRaiz)->esquerda == NULL){ 
                    (*pRaiz) = (*pRaiz)->direita;
                    pAux->direita = NULL;
                    free(pAux);
				    pAux = NULL;
                }else{           
                    if((*pRaiz)->direita == NULL){
                        (*pRaiz) = (*pRaiz)->esquerda;
                        pAux->esquerda = NULL;
                        free(pAux); 
					    pAux = NULL;
                    }else{   
                        pAux = (*pRaiz)->esquerda;  
                        pAux->esquerda = (*pRaiz)->esquerda;    
                        pAux->direita = (*pRaiz)->direita;
                        (*pRaiz)->esquerda = (*pRaiz)->direita = NULL;
                        free((*pRaiz));  
				        *pRaiz = pAux;  
				        pAux = NULL;   
                    }
                }
            }
        }
    }
}

void removerImpar(NO **auxRaiz){
	NO *aux = *auxRaiz;

	if(*aux%2 == 0 )
}

int main() {
    
	NO *raiz = NULL;
	
	raiz = criar(50);
	adicionar(raiz, 60);
	adicionar(raiz, 80);
	adicionar(raiz, 99);
	adicionar(raiz, 30);
	adicionar(raiz, 40);
	adicionar(raiz, 20);
	adicionar(raiz, 10);
	adicionar(raiz, 25);
	adicionar(raiz, 65);
	adicionar(raiz, 77);
	adicionar(raiz, 83);
  

	imprimir(raiz);

	printf("\nAltura da Arvore: %d", alturaArvore(raiz));
	printf("\nNumero de Nos da Arvore: %d", numeroDeNos(raiz));
	printf("\nMaior Numero da Arvore: %d", maiorNumero(raiz));
	printf("\nNumero de Nos não folha da Arvore: %d", numNosNaoFolha(raiz));
	printf("\n");
	
	removerNo(&raiz, 77);
	imprimir(raiz);
	
	return 0;
}