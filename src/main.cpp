#include "jogoDaVida.hpp"
#include <iostream>
using namespace std;

int main(){
    int numGeracoes = getNumGeracoes();
    int tamMatriz1 = tamMatrizInicial();

    // Alocando dinamicamente a matriz inicial:
    int** matrizInicial = new int*[tamMatriz1];
    for(int i=0; i<tamMatriz1; i++){
        matrizInicial[i] = new int[tamMatriz1];
    }

    // Lendo a matriz inicial do arquivo e salvando em geracoes.mps:
    lerMatrizInicial(matrizInicial, tamMatriz1);
    salvarMatrizInicial(matrizInicial, tamMatriz1);
    exibirMatrizAtual(matrizInicial, tamMatriz1);

    // Alocando dinamicamente a matriz auxiliar:
    int** matrizAuxiliar = new int*[tamMatriz1];
    for(int i=0; i<tamMatriz1; i++){
        matrizAuxiliar[i] = new int[tamMatriz1];
    }

    // Realizando as operacoes, de acordo com o numero enviado pelo usuario:
    for(int i=0; i<numGeracoes; i++){
        gerarMatrizAuxiliar(matrizInicial, matrizAuxiliar, tamMatriz1);
        salvarMatrizAuxiliar(matrizAuxiliar, tamMatriz1);
        editarMatrizInicial(matrizInicial, matrizAuxiliar, tamMatriz1);
        cout << endl;

        exibirMatrizAtual(matrizInicial, tamMatriz1);
    }

    // Finalizando o programa e destruindo as matrizes:
    cout << "\nProcesso de geracoes finalizado.\n";

    for(int i=0; i< tamMatriz1; i++){
        delete[] matrizInicial[i];
    }
    delete[] matrizInicial;

    for(int i=0; i< tamMatriz1; i++){
        delete[] matrizAuxiliar[i];
    }
    delete[] matrizAuxiliar;

    return 0;
}