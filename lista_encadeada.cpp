#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/**
 * Criando uma estrutura para comportar a lista encadeada
 */

struct listaEncadeada {
    int valor;
    struct listaEncadeada *itemProximo;
};

/**
 * Definindo os protótipos das funções
 */

listaEncadeada* inserirElemento(listaEncadeada* listaCriada, int valor);
listaEncadeada* buscarElemento(listaEncadeada* listaCriada, int valorProcurado);
listaEncadeada* removerElemento(listaEncadeada* listaCriada, int valorElemento);
listaEncadeada* menorElemento(listaEncadeada* listaCriada);
void imprimirLista(listaEncadeada* listaCriada);

int main() {
    listaEncadeada* listaCriada = NULL;

    listaCriada = inserirElemento(listaCriada, 10);
    listaCriada = inserirElemento(listaCriada, 101);

    listaCriada = removerElemento(listaCriada, 101);

// Inserindo valores entre 0 e 100
    srand(time(NULL));
    for(int iterador = 0; iterador <= 5; iterador++) {

        listaCriada = inserirElemento(listaCriada, (rand() % 100));
    }


    imprimirLista(listaCriada);
}

/**
 * [inserirElemento insere um elemento ao final de uma determinada lista]
 * @param  listaCriada
 * @param  valor
 * @return             listaEncadeada
 */
listaEncadeada* inserirElemento(listaEncadeada* listaCriada, int valor) {

    // Primeiro vamos criar um item com o valor informado e o próximo
    // apontando para nulo

    listaEncadeada* novoElemento = new listaEncadeada;
    novoElemento->valor = valor;
    novoElemento->itemProximo = NULL;
    novoEle

    // Se a lista está vazia, simplesmente adicionamos o item a lista

    if(listaCriada == NULL) {
        listaCriada = novoElemento;
    } else {
        // A lista não está vazia, precisamos encontrar o último ítem para
        // adicionar ao final

        listaEncadeada* lista = listaCriada;

        for(; lista->itemProximo != NULL; lista = lista->itemProximo);
            lista->itemProximo = novoElemento;

    }

    return listaCriada;
}

/**
 * [buscarElemento busca um elemento dado uma determinada lista]
 * @param  listaCriada
 * @param  valorProcurado
 * @return                listaEncadeada
 */
listaEncadeada* buscarElemento(listaEncadeada* listaCriada, int valorProcurado) {
    // Primeiro verificamos se a lista está vazia, para não fazermos iterações
    // desnecessárias

    if(listaCriada == NULL) {
        cout << "A lista estah vazia. Nao ha valores para procurar";
        return NULL;
    } else {

        listaEncadeada* lista = listaCriada;

        // A lista possui itens, vamos iterar sobre eles procurando o valor
        for(; lista != NULL && lista->valor != valorProcurado; lista = lista->itemProximo);

            if(lista == NULL) {
                cout << "O valor nao foi encontrado na lista.";
                return NULL;
            } else {
                return lista;
            }
    }
}

/**
 * [removerElemento remove um item de uma determinada lista]
 * @param  listaCriada   [description]
 * @param  valorElemento [description]
 * @return               [description]
 */
listaEncadeada* removerElemento(listaEncadeada* listaCriada, int valorElemento) {
    // Primeiro verificamos se a lista está vazia, para não fazermos iterações
    // desnecessárias

    if(listaCriada == NULL) {
        cout << "A lista estah vazia. Nao ha valores para remover";
        return NULL;
    } else {

      // Existe itens na lista. precisamos encontrar o item para remoção

      listaEncadeada* itemAnterior = NULL;
      listaEncadeada* lista = listaCriada;

      // Procurando o valor a ser removido
      while(lista != NULL && lista->valor != valorElemento) {
        itemAnterior = lista;
        lista = lista->itemProximo;
      }

      // Não encontrou o valor procurado na determinada lista
      if (lista == NULL) return NULL;

      // O elemento é o primeiro da lista
      if(itemAnterior == NULL) {
            listaEncadeada* temporarioAtual = lista;
            lista = lista->itemProximo;
            delete temporarioAtual;

            return lista;
      } else {

        // Não é o primeiro da fila.
        itemAnterior->itemProximo = lista->itemProximo;

        delete lista;
        return listaCriada;
      }

    }
}

/**
 * [imprimirLista imprime os elementos de uma determinada lista]
 * @param listaCriada
 */
void imprimirLista(listaEncadeada* listaCriada) {
    listaEncadeada* lista = listaCriada;

    for(; lista != NULL; lista = lista->itemProximo) {
        cout << lista->valor << " -> ";
    }

    cout << "NULL" << endl;
}

