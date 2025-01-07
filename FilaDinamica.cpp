#include <iostream>
using namespace std;

struct Node {
    int valor;
    Node* proximo;
};
struct Fila {
    Node* frente;
    Node* tras;
    int tamanho;
};

void iniciar(Fila& fila){
    fila.frente = nullptr;
    fila.tras = nullptr;
    fila.tamanho = 0;
}
bool estaVazia(const Fila& fila){
    return fila.tamanho == 0;
}
void inserirNaFila(Fila& fila, int valor){
    Node* novo = new Node{valor, nullptr};
    if (estaVazia(fila)){
        fila.frente = novo;
    } else{
        fila.tras->proximo = novo;
    }
    fila.tras = novo;
    fila.tamanho++;
    cout << "Elemento " << valor << " inserido na fila." << endl;
}
void excluirDaFila(Fila& fila){
    if (estaVazia(fila)) {
        cout << "Não há elementos na fila!" << endl;
        return;
    }
    Node* temp = fila.frente;
    fila.frente = fila.frente->proximo;
    if (fila.frente == nullptr){
        fila.tras = nullptr;
    }
    cout << "Elemento " << temp->valor << " excluído da fila." << endl;
    delete temp;
    fila.tamanho--;
}
void exibirFila(const Fila& fila){
    if (estaVazia(fila)){
        cout << "A fila está vazia!" << endl;
        return;
    }
    Node* atual = fila.frente;
    cout << "Fila: ";
    while (atual != nullptr){
        cout << atual->valor << " ";
        atual = atual->proximo;
    }
    cout << endl;
}
void deletarFila(Fila& fila){
    while (!estaVazia(fila)){
        excluirDaFila(fila);
    }
}

int main(){
    Fila fila;
    iniciar(fila);
    int opcao, valor;

    do {
        cout << "\nMenu:\n";
        cout << "1 - Inserir elemento na fila\n";
        cout << "2 - Excluir elemento da fila\n";
        cout << "3 - Exibir fila\n";
        cout << "4 - Encerrar\n";
        cin >> opcao;
        switch (opcao){
            case 1:
                cout << "Digite um elemento a ser inserido na fila: ";
                cin >> valor;
                inserirNaFila(fila, valor);
                break;
            case 2:
                excluirDaFila(fila);
                break;
            case 3:
                exibirFila(fila);
                break;
            case 4:
                cout << "Encerrando...\n";
                break;

        }
    } while (opcao != 4);

    deletarFila(fila);
    return 0;
}
