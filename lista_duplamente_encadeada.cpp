#include <iostream>
#include <cstdlib>
#include <ctime>

/**
 * Fábio Luciano  - 1224290128
 * Jano Guimarães - 1224290055
 */

using namespace std;

/**
 * Criando uma estrutura para comportar a lista duplamente encadeada
 */

struct listaDuplamenteEncadeada {
    struct listaDuplamenteEncadeada* itemAnterior;
    struct listaDuplamenteEncadeada* itemProximo;
    int valor;
};

/**
 * Inicio - Definição de protótipos
 */

listaDuplamenteEncadeada* inserirElemento(listaDuplamenteEncadeada* listaCriada, int valor,  listaDuplamenteEncadeada* aposPonteiro = NULL);
listaDuplamenteEncadeada* buscarElemento(listaDuplamenteEncadeada* listaCriada, int valorProcurado);
listaDuplamenteEncadeada* removerElemento(listaDuplamenteEncadeada* listaCriada, int valorElemento);
listaDuplamenteEncadeada* menorElemento(listaDuplamenteEncadeada* listaCriada);

bool possuiAnterior(listaDuplamenteEncadeada* listaCriada);
bool possuiProximo(listaDuplamenteEncadeada* listaCriada);
void imprimirLista(listaDuplamenteEncadeada* listaCriada);
int desenhaMenuOpcoes();

/**
 * Fim - Definição de protótipos
 */

int main() {
    int opcaoRecebida, valorInformado, valorApos;
    listaDuplamenteEncadeada* listaCriada = NULL;

    while(opcaoRecebida = desenhaMenuOpcoes()){

        if(opcaoRecebida == 1){
            cout << "Digite um valor para incluir na lista:" << endl;
            cin >> valorInformado;
            listaCriada = inserirElemento(listaCriada, valorInformado);
        } else if(opcaoRecebida == 2) {
            cout << "Digite um valor para incluir na lista:" << endl;
            cin >> valorInformado;

            cout << "Inserir depois de: " << endl;
            cin >> valorApos;

            listaDuplamenteEncadeada* endereco = buscarElemento(listaCriada, valorApos);
            listaCriada = inserirElemento(listaCriada, valorInformado, endereco);
        } else if(opcaoRecebida == 3){
            cout << "Digite um valor para excluir da lista:" << endl;
            cin >> valorInformado;
            listaCriada =  removerElemento(listaCriada, valorInformado);
        } else if(opcaoRecebida == 4){
             break;
        }

    }

    cout << "###########################" << endl;
    cout << "# Lista final             #" << endl;
    cout << "###########################" << endl;
    imprimirLista(listaCriada);

}

/**
 * [inserirElemento insere um elemento ao final de uma determinada lista]
 * @param  listaCriada
 * @param  valor
 * @return listaDuplamenteEncadeada - a lista passada com o item adicionado
 */
listaDuplamenteEncadeada* inserirElemento(listaDuplamenteEncadeada* listaCriada, int valor, listaDuplamenteEncadeada* aposPonteiro) {

    // Primeiro vamos criar um item com o valor informado e o próximo
    // apontando para nulo

    listaDuplamenteEncadeada* novoElemento = new listaDuplamenteEncadeada;
    novoElemento->valor = valor;
    novoElemento->itemProximo = NULL;
    novoElemento->itemAnterior = NULL;

    // Se a lista está vazia, simplesmente adicionamos o item a lista

    if(listaCriada == NULL) {
        listaCriada = novoElemento;
    } else {
        // A lista não está vazia, precisamos encontrar o último ítem para
        // adicionar ao final

        listaDuplamenteEncadeada* lista = listaCriada;

        if(aposPonteiro != NULL) {
            for(; possuiProximo(lista) && lista != aposPonteiro; lista = lista->itemProximo);
        } else {
            for(; possuiProximo(lista); lista = lista->itemProximo);
        }

        if(aposPonteiro == NULL) {
            lista->itemProximo = novoElemento;
            novoElemento->itemAnterior = lista;
        } else {
            listaDuplamenteEncadeada* proximoItem = lista->itemProximo;

            lista->itemProximo = novoElemento;
            novoElemento->itemAnterior = lista;
            novoElemento->itemProximo = proximoItem;
            proximoItem->itemAnterior = lista->itemProximo;
        }
    }

    cout << "Item adicionado" << endl;
    imprimirLista(listaCriada);

    return listaCriada;
}

/**
 * [buscarElemento busca um elemento dado uma determinada lista]
 * @param  listaCriada
 * @param  valorProcurado
 * @return                listaDuplamenteEncadeada
 */
listaDuplamenteEncadeada* buscarElemento(listaDuplamenteEncadeada* listaCriada, int valorProcurado) {
    // Primeiro verificamos se a lista está vazia, para não fazermos iterações
    // desnecessárias

    if(listaCriada == NULL) {
        cout << "A lista estah vazia. Nao ha valores para procurar";
        return NULL;
    } else {

        listaDuplamenteEncadeada* lista = listaCriada;

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
 * @param  listaCriada
 * @param  valorElemento
 * @return A lista inicial com o item removido
 */
listaDuplamenteEncadeada* removerElemento(listaDuplamenteEncadeada* listaCriada, int valorElemento) {
    // Primeiro verificamos se a lista está vazia, para não fazermos iterações
    // desnecessárias

    if(listaCriada == NULL) {
        cout << "A lista estah vazia. Nao ha valores para remover" << endl;
        return NULL;
    } else {

      // Existe itens na lista. precisamos encontrar o item para remoção

      listaDuplamenteEncadeada* lista = listaCriada;

      // Procurando o valor a ser removido
      while(lista != NULL && lista->valor != valorElemento) {
        lista = lista->itemProximo;
      }

      // Não encontrou o valor procurado na determinada lista
      if (lista == NULL) {
        cout << "O valor informado nao foi encontrado na lista, portanto nao serah removido" << endl;

        return NULL;
      }

      // O elemento é o primeiro da lista
      if(lista->itemAnterior == NULL) {
            listaDuplamenteEncadeada* celulaRemover = lista;
            lista = celulaRemover->itemProximo;
            lista->itemAnterior = NULL;

            delete celulaRemover;

            cout << "Item removido" << endl;
            imprimirLista(lista);

            return lista;
      } else {

        listaDuplamenteEncadeada* celulaAnterior = lista->itemAnterior;
        listaDuplamenteEncadeada* celulaProxima = lista->itemProximo;

        celulaAnterior->itemProximo = lista->itemProximo;

        if(celulaProxima != NULL)
            celulaProxima->itemAnterior = lista->itemAnterior;

        delete lista;

        imprimirLista(listaCriada);
        return listaCriada;
      }

    }
}

bool possuiAnterior(listaDuplamenteEncadeada* listaCriada) {
    if(listaCriada->itemAnterior != NULL) {
        return true;
    }

    return false;
}

bool possuiProximo(listaDuplamenteEncadeada* listaCriada) {
    if(listaCriada->itemProximo != NULL) {
        return true;
    }

    return false;
}

int desenhaMenuOpcoes() {
    int opcaoSelecionada;

    cout<<"Digite uma opção"<<endl;
    cout << "###########################" << endl;
    cout << "# 1 - Inserir novo item   #" << endl;
    cout << "# 2 - Inserir apos um itm #" << endl;
    cout << "# 3 - Remover item        #" << endl;
    cout << "# 4 - Sair                #" << endl;
    cout << "###########################" << endl;

    cin >> opcaoSelecionada;

    return opcaoSelecionada;
}


/**
 * [imprimirLista imprime os elementos de uma determinada lista]
 * @param listaCriada
 */

void imprimirLista(listaDuplamenteEncadeada* listaCriada) {
    listaDuplamenteEncadeada* lista = listaCriada;

    for(; lista != NULL; lista = lista->itemProximo) {
        cout << "Endereco atual: " <<  lista << endl;
        cout << "Valor atual: " << lista->valor << endl;
        cout << "Endereco anterior: " << lista->itemAnterior << endl;
        cout << "Endereco proximo: " << lista->itemProximo << endl;

        if(lista->itemProximo != NULL)  {
            cout << "~~~~~~" << endl;
        }
    }

    cout << "---" << endl;
}
