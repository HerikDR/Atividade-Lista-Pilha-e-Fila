#include <iostream>
#define TAMANHO_MAXIMO 100
using namespace std;

struct Pilha{
    int elementos[TAMANHO_MAXIMO];
    int topo;
};
void iniciar(Pilha& pilha){
    pilha.topo = -1;
}
bool estaVazia(const Pilha& pilha){
    return pilha.topo == -1;
}
bool estaCheia(const Pilha& pilha){
    return pilha.topo == TAMANHO_MAXIMO - 1;
}
void empilhar(Pilha& pilha, int valor){
    if (estaCheia(pilha)) {
        cout << "Pilha cheia!" << endl;
        return;
    }
    pilha.elementos[++pilha.topo] = valor;
    cout << "Elemento " << valor << " empilhado." << endl;
}
void desempilhar(Pilha& pilha){
    if (estaVazia(pilha)) {
        cout << "Não há elementos na pilha!" << endl;
        return;
    }
    cout << "Elemento " << pilha.elementos[pilha.topo--] << " desempilhado." << endl;
}
void exibirPilha(const Pilha& pilha){
    if (estaVazia(pilha)){
        cout << "A pilha está vazia!" << endl;
        return;
    }
    cout << "Pilha (topo p/ base):";
    for (int i = pilha.topo; i >= 0; i--){
        cout << pilha.elementos[i] << " ";
    }
    cout << endl;
}
void exibirPilhaInvertida(const Pilha& pilha) {
    if (estaVazia(pilha)){
        cout << "Nâo há elementos na pilha!" << endl;
        return;
    }
    cout << "Pilha invertida (base p/ topo): ";
    for (int i = 0; i <= pilha.topo; i++){
        cout << pilha.elementos[i] << " ";
    }
    cout << endl;
}
int main() {
    Pilha pilha;
    iniciar(pilha);
    int opcao, valor;

    do{
        cout << "\nMenu:\n";
        cout << "1 - Empilhar elemento\n";
        cout << "2 - Desempilhar elemento\n";
        cout << "3 - Exibir pilha\n";
        cout << "4 - Exibir pilha invertida\n";
        cout << "5 - Encerrar\n";
        cin >> opcao;
        switch (opcao) {
            case 1:
                cout << "Digite um valor a ser adicionado: ";
                cin >> valor;
                empilhar(pilha, valor);
                break;
            case 2:
                desempilhar(pilha);
                break;
            case 3:
                exibirPilha(pilha);
                break;
            case 4:
                exibirPilhaInvertida(pilha);
                break;
            case 5:
                cout << "Encerrando...\n";
                break;
        }
    } while (opcao != 5);

    return 0;
}