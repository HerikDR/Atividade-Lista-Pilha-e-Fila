#include <iostream>
using namespace std;

struct Node {
    int valor;
    Node* anterior;
    Node* proximo;
};
struct DEQUE {
    Node* cabeca;
    Node* cauda;
    int tamanho;
};

void iniciar(DEQUE& deque){
    deque.cabeca = nullptr;
    deque.cauda = nullptr;
    deque.tamanho = 0;
}
void inserirInicio(DEQUE& deque, int valor){
    Node* novo = new Node{valor, nullptr, deque.cabeca};
    if (deque.cabeca != nullptr){
        deque.cabeca->anterior = novo;
    } else{
        deque.cauda = novo;
    }
    deque.cabeca = novo;
    deque.tamanho++;
    cout << "Elemento " << valor << " inserido no início." << endl;
}
void inserirFim(DEQUE& deque, int valor){
    Node* novo = new Node{valor, deque.cauda, nullptr};
    if (deque.cauda != nullptr){
        deque.cauda->proximo = novo;
    } else{
        deque.cabeca = novo;
    }
    deque.cauda = novo;
    deque.tamanho++;
    cout << "Elemento " << valor << " inserido no fim." << endl;
}
void exibirDeque(const DEQUE& deque){
    if (deque.tamanho == 0){
        cout << "O DEQUE está vazio!" << endl;
        return;
    }
    Node* atual = deque.cabeca;
    cout << "DEQUE: ";
    while (atual != nullptr){
        cout << atual->valor << " ";
        atual = atual->proximo;
    }
    cout << endl;
}
bool encontrarMax(DEQUE* d, int* max){
    bool resposta = false;
    if (d->tamanho == 0){
        return false;
    }
    Node* atual = d->cabeca;
    *max = atual->valor;
    resposta = true;

    while (atual != nullptr){
        if (atual->valor > *max){
            *max = atual->valor;
        }
        atual = atual->proximo;
    }
    return resposta;
}
void deletarDeque(DEQUE& deque){
    Node* atual = deque.cabeca;
    while (atual != nullptr){
        Node* temp = atual;
        atual = atual->proximo;
        delete temp;
    }
    deque.cabeca = nullptr;
    deque.cauda = nullptr;
    deque.tamanho = 0;
}
int main(){
    DEQUE deque;
    iniciar(deque);
    int opcao, valor, max;

    do {
        cout << "\nMenu:\n";
        cout << "1 - Inserir elemento no início\n";
        cout << "2 - Inserir elemento no fim\n";
        cout << "3 - Exibir deque\n";
        cout << "4 - Encontrar maior elemento\n";
        cout << "5 - Encerrar\n";
        cin >> opcao;
        switch (opcao){
            case 1:
                cout << "Digite um elemento a ser inserido no início: ";
                cin >> valor;
                inserirInicio(deque, valor);
                break;
            case 2:
                cout << "Digite um elemento a ser inserido no fim: ";
                cin >> valor;
                inserirFim(deque, valor);
                break;
            case 3:
                exibirDeque(deque);
                break;
            case 4:
                if (encontrarMax(&deque, &max)) {
                    cout << "O maior elemento é: " << max << endl;
                } else {
                    cout << "O deque está vazio!" << endl;
                }
                break;
            case 5:
                cout << "Encerrando...\n";
                break;

        }
    } while (opcao != 5);

    deletarDeque(deque);
    return 0;
}