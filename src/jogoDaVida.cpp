#include "jogoDaVida.hpp"
#include <iostream>
#include <fstream>

int getNumGeracoes(){
    int numGeracoes;
    cout << "\nDigite o numero de operacoes do jogo: ";
    cin >> numGeracoes;
    return numGeracoes;
}


int tamMatrizInicial(){
    ifstream file("datasets/input.mps");
    if(!file.is_open()){
        cout << "Erro na leitura do arquivo.";
    }

    // Leitura do tamanho da matriz quadratica inicial:
    int tamMatriz;
    file >> tamMatriz;
    file.close();

    return tamMatriz;
}


void lerMatrizInicial(int **matrizInicial, int tamMatriz1){
    ifstream file("datasets/input.mps");
    if(!file.is_open()){
        cout << "Erro na leitura do arquivo.";
    }

    // Pulando a primeira linha:
    string linha;
    getline(file, linha);

    // Leitura do arquivo:
    for(int i=0; i<tamMatriz1; i++){
        for(int j=0; j<tamMatriz1; j++){
            int c;
            file >> c; 
            matrizInicial[i][j] = c;
        }
    }

    cout << "\nMatriz inicial lida com sucesso.";
    file.close();
}


void exibirMatrizAtual(int **matrizInicial, int tamMatriz1){
    cout << "\n";
    cout << "Estado atual do tabuleiro: " << "\n";
    for(int i=0; i<tamMatriz1; i++){
        for(int j=0; j<tamMatriz1; j++){
            cout << matrizInicial[i][j] << "\t";
        }
        cout << "\n";
    }
}


void salvarMatrizInicial(int **matrizInicial, int tamMatriz1){
    ofstream file("datasets/geracoes.mps", ios::app);
    if(!file.is_open()){
        cout << "Erro na leitura do arquivo.";
    }

    file << "Matriz Original:\n";
    for(int i=0; i<tamMatriz1; i++){
        for(int j=0; j<tamMatriz1; j++){
            file << matrizInicial[i][j] << " ";
        }
        file << "\n";
    }
    file << "\n";

    cout << "\nMatriz inicial salva no arquivo geracoes.mps.";
    file.close();
}


void gerarMatrizAuxiliar(int **matrizInicial, int **matrizAuxiliar, int tamMatriz1){
    int contadorVizinhos = 0;
    for(int i = 0; i < tamMatriz1; i++) {
        for(int j = 0; j < tamMatriz1; j++) {
            contadorVizinhos = 0;
            
            // Condições para contar vizinhos:
            for(int k = i - 1; k <= i + 1; k++) {
                for(int l = j - 1; l <= j + 1; l++) {
                    if(k >= 0 && k < tamMatriz1 && l >= 0 && l < tamMatriz1) {
                        contadorVizinhos += matrizInicial[k][l];
                    }
                }
            }
            contadorVizinhos -= matrizInicial[i][j];
            
            // Determinando o estado da célula atual na matriz auxiliar:
            if(matrizInicial[i][j] == 1){
                if(contadorVizinhos < 2 || contadorVizinhos > 3){
                    matrizAuxiliar[i][j] = 0;
                }
                else {
                    matrizAuxiliar[i][j] = 1;
                }
            }
            else {
                if(contadorVizinhos == 3){
                    matrizAuxiliar[i][j] = 1;
                }
                else {
                    matrizAuxiliar[i][j] = 0;
                }
            }
        }
    }
    cout << "\nMatriz auxiliar gerada com sucesso.";
}


void salvarMatrizAuxiliar(int **matrizAuxiliar, int tamMatriz1){
    ofstream file("datasets/geracoes.mps", ios::app);
    if(!file.is_open()){
        cout << "Erro na leitura do arquivo.";
    }

    file << "Nova Matriz:\n";
    for(int i=0; i<tamMatriz1; i++){
        for(int j=0; j<tamMatriz1; j++){
            file << matrizAuxiliar[i][j] << " ";
        }
        file << "\n";
    }
    
    file << "\n";
    cout << "\nMatriz auxiliar salva com sucesso.";
    
    file.close();
}


void editarMatrizInicial(int **matrizInicial, int **matrizAuxiliar, int tamMatriz1){
    for(int i=0; i<tamMatriz1; i++){
        for(int j=0; j<tamMatriz1; j++){
            matrizInicial[i][j] = matrizAuxiliar[i][j];
        }
    }
}