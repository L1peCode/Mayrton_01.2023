/****************************************************************** 
 * Nome: Lista de Pessoas com vetores                             *
 * Descricao: Implementacao de lista com uso de vetores (array).  *
 *            Esse codigo possui as principais operacoes da       *
 *            lista de pessoas, como:                             *
 *            criar lista,                                        *
 *            inserir elemento,                                   *
 *            remover elemento,                                   *
 *            buscar elemento,                                    *
 *            mostrar elementos,                                  *
 *            atualizar elementos,                                *
 *            excluir lista.                                      *
 * Autor: Mayrton Dias                                            *
 * Ultima alteracao: 29/04/2023                                   *
 ******************************************************************/

/*Include das bibliotecas*/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Definicao das constantes*/ 
#define TAM 5

/*Definicao das estruturas Pessoa e Lista*/ 
typedef struct{
    char nome[30]; 
    int idade; 
    float altura; 
    char sexo; 
} Pessoa;

typedef struct{
    int id;
    Pessoa *elementos;
} Lista;

/*Funcoes implementadas*/
int atualizarElemento(Lista*,char*, char*, int, float, char);
int buscarElemento(Lista*, char*);
Lista* criarLista();
Lista* excluirLista(Lista*);
void imprimirElementos(Lista*);
int inserirElemento(Lista*, char*, int, float, char);
int inserirElementoID(Lista*, char*, int, float, char, int);
int inserirElementoInicio(Lista*, char*, int, float, char);
int removerElemento(Lista*, int);
int removerElementoNome(Lista*, char*);

int main(){
    /*Ponteiro usado para a criacao da lista*/
    Lista *lista = NULL;
    imprimirElementos(lista);
    
    /*exemplo de como chamar as funcoes*/
    lista = criarLista();
    imprimirElementos(lista);
    
    printf("\nInserindo Ana\n");
    inserirElemento(lista, "Ana", 35, 1.67, 'F');
    imprimirElementos(lista);

    printf("\nInserindo Pedro\n");
    inserirElemento(lista, "Pedro", 45, 1.77, 'M');
    imprimirElementos(lista);

    printf("\nInserindo Joao\n");
    inserirElemento(lista, "Joao", 38, 1.47, 'M');
    imprimirElementos(lista);

    printf("\nInserindo Maria\n");
    inserirElemento(lista, "Maria", 18, 1.57, 'F');
    imprimirElementos(lista);

    printf("\nInserindo Jose\n");
    inserirElemento(lista, "Jose", 30, 1.87, 'M');
    imprimirElementos(lista);

    printf("\nInserindo Severino\n");
    inserirElemento(lista, "Severino", 50, 1.88, 'M');
    imprimirElementos(lista);
 
    printf("\nInserindo Pedro\n");
    removerElementoNome(lista, "Pedro");
    imprimirElementos(lista);

    int busca = buscarElemento(lista, "Mayrton");

    /*verificacao se o elemento retornado e valido*/
    if(busca != -1){
        printf("Encontrou o elemento: %d\n", busca);
        printf("Nome: %s \n", lista->elementos[busca].nome);
        printf("Idade: %d \n", lista->elementos[busca].idade);
        printf("Altura: %.2f \n", lista->elementos[busca].altura);
        printf("Sexo: %c \n\n", lista->elementos[busca].sexo);
    }else{
        printf("Pessoa nao encontrada\n");
    }

    atualizarElemento(lista, "Maria", "Mayrton", 32, 1.67, 'M');
    imprimirElementos(lista);

    removerElemento(lista, 1);
    imprimirElementos(lista);

    inserirElementoInicio(lista, "Joana", 14, 1.37, 'F');
    imprimirElementos(lista);

    inserirElementoID(lista, "Paulo", 31, 1.87, 'M', 3);
    imprimirElementos(lista);
    
    lista = excluirLista(lista);
    imprimirElementos(lista);
    return 0;
}


/* Nome: atualizarElemento
 * Parametros: lista  - ponteiro que possui o endereco lista
 *             busca  - elemento que sera buscado na lista
 *             nome   - novo nome da pessoa que sera alterado 
 *             idade  - idade da pessoa que sera alterada 
 *             altura - altura da pessoa que sera alterada 
 *             sexo   - sexo da pessoa que sera alterado 
 * Retorno: 1 - quando o valor e atualizado e 0 - caso contrario
 * Descricao: Funcao responsavel por atualizar a informacoes de uma pessoa
 *            da lista, caso a mesma esteja na lista indicada
 */
int atualizarElemento(Lista *lista, char *busca, char *nome, int idade, float altura, char sexo ){
    int i;

    /*Verificando se a lista foi criada*/
    if(lista == NULL){
        printf("A lista nao foi criada\n");
        return 0;
    }

    /*Percorrendo todas as pessoas presentes na lista*/
    for(i = 0; i < lista->id; ++i){
        /*Condicao que verifica se a pessoa da lista e igual a busca*/
        if(strcmp(lista->elementos[i].nome, busca) == 0){
            /*atualizando as informacoes da pessoa*/
            strcpy(lista->elementos[i].nome, nome);
            lista->elementos[i].idade = idade;
            lista->elementos[i].altura = altura;
            lista->elementos[i].sexo = sexo;
            return 1;
        }
    }
    return 0;
}


/* Nome: buscarElemento
 * Parametro: lista - ponteiro que possui o endereco lista
 *            nome  - nome da pessoas que sera buscada na lista
 * Retorno: o indice da pessoa encontrada, -1 caso contrario
 * Descricao: Funcao criada para buscar o nome de uma pessoa na lista
 */
int buscarElemento(Lista *lista, char *nome){
    int i;

    /*Verificando se a lista foi criada*/
    if(lista == NULL){
        printf("A lista nao foi criada\n");
        return -1;
    }

    /*Percorrendo todas as pessoas da lista*/
    for(i = 0; i < lista->id; ++i){
        /*Verificando se o nome da pessoa e igual ao nome buscado*/
        if(strcmp(lista->elementos[i].nome, nome) == 0){
            return i;
        }
    }

    /*Retorna -1 caso nao encontre o valor desejado*/
    return -1;
}


/* Nome: criarLista
 * Parametro: void 
 * Retorno: endereco do espaco de memoria reservado pelo malloc
 * Descricao: Funcao responsavel pela criacao da lista e inicializacao
 *            do campo id e alocacao do vetor de elementos
 */
Lista* criarLista(){
    /*solicitando espaco para a lista*/
    Lista *nova = (Lista*)malloc(sizeof(Lista));

    /*Verificando se o espaco foi resevado*/
    if(nova == NULL){
        printf("Nao tem espaco\n");
        return NULL;
    }

    /*Preparando os dados iniciais da lista*/
    nova->id = 0; 
    nova->elementos = (Pessoa*)malloc(TAM*sizeof(Pessoa));
    
    /*Verificando se o espaco foi resevado*/
    if(nova->elementos == NULL){
        printf("Nao tem espaco\n");
        free(nova);
        return NULL;
    }

    /*Retonando o espaco resevado*/
    return nova;
}


/* Nome: excluirLista
 * Parametro: lista - ponteiro que possui o endereco lista
 * Retorno: NULL para indicar que a lista foi excluida
 * Descricao: Funcao responsavel pela exclusao da lista
 */
Lista* excluirLista(Lista *lista){
    /*Liberando o espaco que foi reservado para o vetor elementos*/
    free(lista->elementos);
    
    /*Liberando o espaco que foi reservado para a lista*/
    free(lista);
    
    return NULL;
}


/* Nome: imprimirElementos
 * Parametro: lista - ponteiro que possui o endereco lista
 * Retorno: void
 * Descricao: Funcao criada para apresentar todas pessoas presentes na lista
 */
void imprimirElementos(Lista *lista){
    int i;

    /*Verificando se a lista foi criada*/
    if(lista == NULL){
        printf("A lista nao foi criada\n");
        return ;
    }

    /*Verificando se a lista e vazia*/
    if(lista->id == 0){
        printf("Lista vazia\n");
        return ;
    }

    /*Mostrando cada pessoa presente na lista*/
    for(i = 0; i < lista->id; ++i){
        printf("Nome: %s \t", lista->elementos[i].nome);
        printf("Idade: %d \t", lista->elementos[i].idade);
        printf("Altura: %.2f \t", lista->elementos[i].altura);
        printf("Sexo: %c \n\n", lista->elementos[i].sexo);
    }
    printf("\n");
}


/* Nome: inserirElemento
 * Parametros: lista  - ponteiro que possui o endereco lista
 *             nome   - nome da pessoa que sera adicionada 
 *             idade  - idade da pessoa que sera adicionada 
 *             altura - altura da pessoa que sera adicionada 
 *             sexo   - sexo da pessoa que sera adicionada 
 * Retorno: 1 se a pessoa foi adicionada, 0 - caso contrario
 * Descricao: Funcao criada para inserir uma pessoa no final da lista
 */
int inserirElemento(Lista *lista, char *nome, int idade, float altura, char sexo){
    
    /*Verificando se a lista foi criada*/
    if(lista == NULL){
        printf("A lista nao foi criada\n");
        return 0;
    }

    /*Verificando se existe espaco para inserir mais uma pessoa na lista*/
    if(lista->id < TAM){
        /*Inserindo as informacoes da pessoa na lista*/
        strcpy(lista->elementos[lista->id].nome, nome);
        lista->elementos[lista->id].idade = idade;
        lista->elementos[lista->id].altura = altura;
        lista->elementos[lista->id].sexo = sexo;
        /*Atualizando a quantidade de pessoas da lista*/
        ++(lista->id);
    }else{
        printf("Espaco esgotado\n");
        return 0;
    }

    return 1;
}


/* Nome: inserirElementoID
 * Parametros: lista   - ponteiro que possui o endereco lista
 *             nome    - nome da pessoa que sera adicionada 
 *             idade   - idade da pessoa que sera adicionada 
 *             altura  - altura da pessoa que sera adicionada 
 *             sexo    - sexo da pessoa que sera adicionada
 *             posicao - posicao que a pessoa sera adicionada na lista
 * Retorno: 1 se a pessoa foi adicionada, 0 - caso contrario
 * Descricao: Funcao criada para inserir uma pessoa na posicao indicada na lista
 */
int inserirElementoID(Lista *lista, char *nome, int idade, float altura, char sexo, int posicao){
    int i;

    /*Verificando se a lista foi criada*/
    if(lista == NULL){
        printf("A lista nao foi criada\n");
        return 0;
    }

    /*Verificando se existe espaco para inserir mais uma pessoa na lista*/
    if(lista->id < TAM){
        /*Verificando se a posicao esta dentro do intervalo permitido*/
        if(posicao < lista->id){
            /*Deslocando as pessoas apos posicao para o final da lista*/
            for(i = lista->id; i > posicao; --i){
                strcpy(lista->elementos[i].nome, lista->elementos[i-1].nome);
                lista->elementos[i].idade = lista->elementos[i-1].idade;
                lista->elementos[i].altura = lista->elementos[i-1].altura;
                lista->elementos[i].sexo = lista->elementos[i-1].sexo;
            }
            /*Inserindo a pessoa na posicao indicada da lista*/
            strcpy(lista->elementos[posicao].nome, nome);
            lista->elementos[posicao].idade = idade;
            lista->elementos[posicao].altura = altura;
            lista->elementos[posicao].sexo = sexo;
            /*Atualizando a quantidade de pessoas da lista*/
            ++(lista->id);
        }else{
            printf("Posicao fora o intervalo permitido\n");
            return 0;
        }
    }else{
        printf("Espaco esgotado\n");
        return 0;
    }

    return 1;
}


/* Nome: inserirElementoInicio
 * Parametros: lista  - ponteiro que possui o endereco lista
 *             nome   - nome da pessoa que sera adicionada 
 *             idade  - idade da pessoa que sera adicionada 
 *             altura - altura da pessoa que sera adicionada 
 *             sexo   - sexo da pessoa que sera adicionada
 * Retorno: 1 se a pessoa foi adicionada, 0 - caso contrario
 * Descricao: Funcao criada para inserir uma pessoa no inicio da lista
 */
int inserirElementoInicio(Lista *lista, char *nome, int idade, float altura, char sexo){
    int i;

    /*Verificando se a lista foi criada*/
    if(lista == NULL){
        printf("A lista nao foi criada\n");
        return 0;
    }

    /*Verificando se existe espaco para inserir mais uma pessoa na lista*/
    if(lista->id < TAM){
        /*Deslocando todas as pessoas para o final da lista*/
        for(i = lista->id; i > 0; --i){
            strcpy(lista->elementos[i].nome, lista->elementos[i-1].nome);
            lista->elementos[i].idade = lista->elementos[i-1].idade;
            lista->elementos[i].altura = lista->elementos[i-1].altura;
            lista->elementos[i].sexo = lista->elementos[i-1].sexo;
        }
        /*Inserindo a pessoa na primeira posicao da lista*/
        strcpy(lista->elementos[0].nome, nome);
        lista->elementos[0].idade = idade;
        lista->elementos[0].altura = altura;
        lista->elementos[0].sexo = sexo;
        /*Atualizando a quantidade de pessoas da lista*/
        ++(lista->id);
    }else{
        printf("Espaco esgotado\n");
        return 0;
    }
    return 1;
}


/* Nome: removerElemento
 * Parametro: lista - ponteiro que possui o endereco lista
 *            valor - posicao da pessoa que sera removida da lista
 * Retorno: 1 se a pessoa foi removida, 0 - caso contrario
 * Descricao: Funcao criada para remover uma pessoa da lista
 */
int removerElemento(Lista *lista, int valor){
    int i, j;

    /*Verificando se a lista foi criada*/
    if(lista == NULL){
        printf("A lista nao foi criada\n");
        return 0;
    }

    /*Verificando se a posicao e permitida*/
    if (valor < lista->id){
        /*Deslocando as pessoas para o final da lista*/
        for(j = valor; j < lista->id-1; ++j){
            strcpy(lista->elementos[j].nome, lista->elementos[j+1].nome);
            lista->elementos[j].idade = lista->elementos[j+1].idade;
            lista->elementos[j].altura = lista->elementos[j+1].altura;
            lista->elementos[j].sexo = lista->elementos[j+1].sexo;
        }
        /*Atualizando a quantidade de pessoas da lista*/
        --(lista->id);
        return 1;
    }else{
        printf("Posicao invalida\n");
    }

    return 0;
}


/* Nome: removerElementoNome
 * Parametro: lista - ponteiro que possui o endereco lista
 *            nome  - nome da pessoa que sera removida da lista
 * Retorno: 1 se a pessoa foi removida, 0 - caso contrario
 * Descricao: Funcao criada para remover uma pessoa da lista
 */
int removerElementoNome(Lista *lista, char *nome){
    int i, j;

    /*Verificando se a lista foi criada*/
    if(lista == NULL){
        printf("A lista nao foi criada\n");
        return 0;
    }

    /*Percorre todos as pessoas da lista*/
    for(i = 0; i < lista->id; ++i){
        /*Verificando se nome da pessoa atual e igual ao nome da pessoa que sera removida*/
        if(strcmp(lista->elementos[i].nome, nome) == 0){
            /*Deslocando as pessoas apos posicao da pessoa que sera removida da lista*/
            for(j = i; j < lista->id-1; ++j){
                strcpy(lista->elementos[j].nome, lista->elementos[j+1].nome);
                lista->elementos[j].idade = lista->elementos[j+1].idade;
                lista->elementos[j].altura = lista->elementos[j+1].altura;
                lista->elementos[j].sexo = lista->elementos[j+1].sexo;
            }
            /*Atualizando a quantidade de pessoas da lista*/
            --(lista->id);
            return 1;
        }
    }

    return 0;
}
