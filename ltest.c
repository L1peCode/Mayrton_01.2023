/*Definicao das estruturas Celular e Lista*/ 

#include <stdio.h>
#include <stdlib.h>
#define TAM 5

Typedef struct{
char cor[20];
char Marca[20];
float Tamanho;
float Valor;

} celular;

typedef struct{
    int id;
   celular *elementos;
} Lista;

/*função main*/

int atualizarElemento(Lista*, char*, char, float, float);
int buscarElemento(Lista*, char*);
Lista* criarLista();
Lista* excluirLista(Lista*);
int inserirElemento(Lista*, char*, char, float, float);
int removerElemento(Lista*, int);
int removerElementoNome(Lista*, int*);

int main(){

   /*a criacao da lista*/

Lista* criarLista(){
    Lista *nova = (Lista*)malloc(sizeof(Lista));
    if(nova == NULL){
        printf("Nao tem espaco\n");
        return NULL;
    }

    nova->id = 0; 
    nova->elementos = (celular*)malloc(TAM*sizeof(celular));
    if(nova->elementos == NULL){
        printf("Nao tem espaco\n");
        free(nova);
        return NULL;
    }
    return nova;
}

/*a inserir Elementos*/

int inserirElemento(Lista *lista, int valor){
    
    if(lista == NULL){
        printf("A lista nao foi criada\n");
        return 0;
    }
  
    if(lista->id < TAM){
        lista->elementos[lista->id] = valor;
        ++(lista->id);
    }else{
        printf("Espaco esgotado\n");
        return 0;
    }

    return 1;
}

/*a remover Elementos*/

int removerElemento(Lista *lista, int valor){
    int i, j;
    if(lista == NULL){
        printf("A lista nao foi criada\n");
        return 0;
    }
    for(i = 0; i < lista->id; ++i){
        if(lista->elementos[i] == valor){
            for(j = i; j < lista->id-1; ++j){
                lista->elementos[j] = lista->elementos[j+1];
            }
            --(lista->id);
            return 1;
        }
    }
    
    return 0;
}


    /*buscando*/

int busca = buscarElemento(lista, "iphone");
 if(busca != -1){
        printf("Encontrou o elemento: %d\n", busca);
        printf("Cor: %s \n", lista->elementos[busca].cor);
        printf("Marca: %d \n", lista->elementos[busca].marca);
        printf("Tamanho: %.2f \n", lista->elementos[busca].tamanho);
        printf("Valor: %c \n\n", lista->elementos[busca].valor);
    }else{
        printf("Pessoa nao encontrada\n");
    }

/* atualizar Elemento e remover elemento*/

    atualizarElemento(lista, "iphone", "iphone", rosa, ‘iphone’, 12 cm, 1000);
    imprimirElementos(lista);

    removerElemento(lista, 1);
    imprimirElementos(lista);

    inserirElementoInicio(lista, "LG", preto, ‘LG’,10cm, 800);
    imprimirElementos(lista);

    inserirElementoID(lista, "Lenovo", preto, ‘LG’,10cm, 800, 3);
    imprimirElementos(lista);
    
    lista = excluirLista(lista);
    imprimirElementos(lista);
    return 0;
}

int atualizarElemento(Lista *lista, char *busca, char *cor, char marca, float tamanho, float valor){
    int i;
    if(lista == NULL){
        printf("A lista nao foi criada\n");
        return 0;
    }

    for(i = 0; i < lista->id; ++i){
        if(strcmp(lista->elementos[i].nome, busca) == 0){
            strcpy(lista->elementos[i].nome, cor);
            lista->elementos[i].marca = marca;
            lista->elementos[i].tamanho = tamanho;
            lista->elementos[i].valor = valor;
            return 1;
        }
    }
    return 0;
}

/* Buscar Elemento*/

int buscarElemento(Lista *lista, char *nome){
    int i;
    if(lista == NULL){
        printf("A lista nao foi criada\n");
        return -1;
    }

    for(i = 0; i < lista->id; ++i){
        if(strcmp(lista->elementos[i].nome, nome) == 0){
            return i;
        }
    }
    return -1;
}

/*excluirLista */
Lista* excluirLista(Lista *lista){
    free(lista->elementos);
    free(lista);
    return NULL;
}
