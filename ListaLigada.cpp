#include <iostream>
using namespace std;

struct Node{
    int valor;
    Node* anterior;
    Node* proximo;
};
struct ListaLigada{
    Node* cabeca;
    Node* cauda;
    int tamanho;
};
void iniciar(ListaLigada& lista){
    lista.cabeca = nullptr;
    lista.cauda = nullptr;
    lista.tamanho = 0;
}
void imprimir(const ListaLigada& lista){
    Node* atual = lista.cabeca;
    cout << "Lista: ";
    while (atual != nullptr){
        cout << atual->valor << " ";
        atual = atual->proximo;
    }
    cout << endl;
}
void inserir(ListaLigada& lista, int valor){
    Node* novo = new Node{valor, nullptr, nullptr};
    if (lista.cabeca == nullptr){
        lista.cabeca = novo;
        lista.cauda = novo;
    } else{
        Node* atual = lista.cabeca;
        while (atual != nullptr && atual->valor < valor){
            atual = atual->proximo;
        }
        if (atual == lista.cabeca){
            novo->proximo = lista.cabeca;
            lista.cabeca->anterior = novo;
            lista.cabeca = novo;
        } else if (atual == nullptr){
            lista.cauda->proximo = novo;
            novo->anterior = lista.cauda;
            lista.cauda = novo;
        } else{
            novo->proximo = atual;
            novo->anterior = atual->anterior;
            atual->anterior->proximo = novo;
            atual->anterior = novo;
        }
    }
    lista.tamanho++;
    imprimir(lista);
}
void remover(ListaLigada& lista, int indice){
    if (indice < 0 || indice >= lista.tamanho){
        cout << "Índice fora de alcance!" << endl;
        return;
    }
    Node* atual = lista.cabeca;
    for (int i = 0; i < indice; i++){
        atual = atual->proximo;
    }
    if (atual == lista.cabeca){
        lista.cabeca = atual->proximo;
        if (lista.cabeca != nullptr) lista.cabeca->anterior = nullptr;
    } else if (atual == lista.cauda){
        lista.cauda = atual->anterior;
        lista.cauda->proximo = nullptr;
    } else{
        atual->anterior->proximo = atual->proximo;
        atual->proximo->anterior = atual->anterior;
    }
    delete atual;
    lista.tamanho--;
    imprimir(lista);
}
void deletarLista(ListaLigada& lista){
    Node* atual = lista.cabeca;
    while (atual != nullptr){
        Node* temp = atual;
        atual = atual->proximo;
        delete temp;
    }
    lista.cabeca = nullptr;
    lista.cauda = nullptr;
    lista.tamanho = 0;
}
int main() {
    ListaLigada lista;
    iniciar(lista);
    int opcao, valor, indice;

    do{
        cout << "\nMenu:\n";
        cout << "1 - Inserir elemento\n";
        cout << "2 - Remover elemento por índice\n";
        cout << "3 - Encerrar\n";
        cin >> opcao;
        switch (opcao){
            case 1:
                cout << "Digite um valor a ser inserido: ";
                cin >> valor;
                inserir(lista, valor);
                break;

            case 2:
                cout << "Digite o índice do elemento: ";
                cin >> indice;
                remover(lista, indice);
                break;
            case 3:
                cout << "Encerrando...\n";
                break;
        }
    } while (opcao != 3);
    deletarLista(lista);
    return 0;
}
