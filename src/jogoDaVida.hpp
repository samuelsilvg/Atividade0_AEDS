#ifndef JOGODAVIDA_HPP
#define JOGODAVIDA_HPP

#include <iostream>
#include <fstream>
using namespace std;
    
int getNumGeracoes();
int tamMatrizInicial();
void lerMatrizInicial(int **matrizInicial, int tamMatriz1);
void exibirMatrizAtual(int **matrizInicial, int tamMatriz1);
void salvarMatrizInicial(int **matrizInicial, int tamMatriz1);
void gerarMatrizAuxiliar(int **matrizInicial, int **matrizAuxiliar, int tamMatriz1);
void salvarMatrizAuxiliar(int **matrizAuxiliar, int tamMatriz1);
void editarMatrizInicial(int **matrizInicial, int **matrizAuxiliar, int tamMatriz1);

#endif //JOGODAVIDA_HPP