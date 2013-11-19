#include <iostream>

using namespace std;

/**
 * Criação das estruturas necessárias para implementação da pilha
 */
 struct Elemento {
    const char* informacao;
    struct Elemento* anterior;
};

struct Pilha {
    Elemento* topo;
};

/**
 * Definição dos protótipos
 */

 Pilha* criarPilha();
 Pilha* empilharElemento(Pilha* ponteiroPilha, const char* informacao);
 Pilha* desempilharElemento(Pilha* ponteiroPilha);
 void passarTopo(Pilha* pilhaOrigem, Pilha* pilhaAlvo);
 bool estaVazia(Pilha* ponteiroPilha);
 int retornaTamanho(Pilha* ponteiroPilha);

/**
 * [main description]
 * @return [description]
 */
 int main() {
    Pilha* pilhaP;
    Pilha* pilhaQ;
    Pilha* pilhaR;

    pilhaP = criarPilha();
    pilhaQ = criarPilha();
    pilhaR = criarPilha();

    pilhaP = empilharElemento(pilhaP, "d");
    pilhaP = empilharElemento(pilhaP, "c");
    pilhaP = empilharElemento(pilhaP, "b");
    pilhaP = empilharElemento(pilhaP, "a");

    passarTopo(pilhaP, pilhaQ); // a
    passarTopo(pilhaP, pilhaR); // b
    passarTopo(pilhaP, pilhaQ); // c
    passarTopo(pilhaP, pilhaR); // d
    passarTopo(pilhaQ, pilhaP); // c
    passarTopo(pilhaQ, pilhaR); // a
    passarTopo(pilhaP, pilhaR); // a


    retornaTamanho(pilhaP);
    retornaTamanho(pilhaQ);
    retornaTamanho(pilhaR);

    return 0;
}

/**
 * [criarPilha description]
 * @return Pilha*
 */
 Pilha* criarPilha() {
    Pilha* ponteiroPilha = new Pilha;
    ponteiroPilha->topo = NULL;

    return ponteiroPilha;
}

/**
 * [empilharElemento description]
 * @param  ponteiroPilha [description]
 * @param  informacao    [description]
 * @return               [description]
 */
 Pilha* empilharElemento(Pilha* ponteiroPilha, const char* informacao) {
    Elemento* elemento = new Elemento;
    elemento->informacao = informacao;
    elemento->anterior = ponteiroPilha->topo;
    ponteiroPilha->topo = elemento;

    return ponteiroPilha;
}

/**
 * [desempilharElemento description]
 * @param  ponteiroPilha [description]
 * @return               [description]
 */
 Pilha* desempilharElemento(Pilha* ponteiroPilha) {
    if(estaVazia(ponteiroPilha)){
        cout << "A pilha estah vazia. Nada a se fazer";
        return ponteiroPilha;
    }

    Elemento* elementoAnterior = ponteiroPilha->topo->anterior;
    ponteiroPilha->topo = elementoAnterior;

    return ponteiroPilha;
}

void passarTopo(Pilha* pilhaOrigem, Pilha* pilhaAlvo) {
    Elemento* elementoAnterior = NULL;

    if(!estaVazia(pilhaAlvo)) {
        elementoAnterior = pilhaAlvo->topo;
    }

    pilhaAlvo->topo = pilhaOrigem->topo;
    desempilharElemento(pilhaOrigem);

    pilhaAlvo->topo->anterior = elementoAnterior;
}

/**
 * [estaVazia description]
 * @param  ponteiroPilha [description]
 * @return               [description]
 */
 bool estaVazia(Pilha* ponteiroPilha) {
    if(ponteiroPilha->topo == NULL)  {
        return true;
    }

    return false;
}

/**
 * [retornaTamanho description]
 * @param  ponteiroPilha [description]
 * @return               [description]
 */
 int retornaTamanho(Pilha* ponteiroPilha) {
    Pilha* pilhaAuxiliar = ponteiroPilha;
    int contador = 0;

    if(!estaVazia(ponteiroPilha)) {
        while(true) {
            cout << pilhaAuxiliar->topo->informacao << endl;
            pilhaAuxiliar = desempilharElemento(pilhaAuxiliar);
            contador++;

            if(estaVazia(pilhaAuxiliar)) break;
        }
    }

    cout << "------" << endl;
    return contador;
}
