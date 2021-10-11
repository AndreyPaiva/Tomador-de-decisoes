#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <locale>
#include <ctime>

using namespace std;

int main(void){
    int cont = 1; //contador do número da opção
    int continuar = 1; //variável que indica intenção em adicionar mais opções
    vector <int> resultados; //quantidade de vezes que a opção foi sorteada
    vector <string> opcoes; //nome da opção a ser sorteada
    int resultado; //numero da opção sorteada
    
    setlocale(LC_ALL, "portuguese"); //alterar a linguagem do terminal para o português
    srand(time(NULL)); //seed baseada no tempo do sistema
    cout << "Como sou muito indeciso, criei um programa para que minhas decisoes sejam tomadas ao acaso." << endl;

    do{
        string a; //caractere auxiliar, pois o getline não estava funcionando em loop e o cin.ignore()
        //apagava a primeira letra
        string auxiliar = ""; //nome da opção
        cout << "Informe a " << cont <<"a opcao: " << endl;
        a = getchar(); //leitura do caractere auxiliar
        getline(cin, auxiliar); //leitura do nome da opção
        opcoes.push_back(a + auxiliar); //adicionando o nome da opção ao vector de nomes
        system("cls");
        cout << "Deseja continuar?" << endl;
        cout << "0 - Nao" << endl;
        cout << "1 - Sim" << endl;
        cout << "   Resposta: ";
        cin >> continuar; // leitura da intenção em continuar ou não
        system("cls");
        cont++; // incremento no contador
    }while(continuar); 

    for(int i=0; i<opcoes.size();i++){ //inicialização do vetor que guarda a quantidade de ocorrências
        resultados.push_back(0);
    }

    for(int i=1; i<=1000000; i++){
        int auxiliar;

        auxiliar = rand()%opcoes.size(); //sorteio
        resultados[auxiliar] += 1; //registro dos resultados obtidos
    }

    /*for(int i=0; i<resultados.size(); i++){
        cout << opcoes[i] << " - " << resultados[i] << endl;
    }*/ //exibe a quantidade de vezes que cada resultado foi obtido, para finalidade de testes

    int maior = 0; // variável que indica o maior número de ocorrências

    for(int i=0; i<resultados.size(); i++){ 
        if(resultados[i] > maior){ //verificação do maior número de ocorrências
            maior = resultados[i];
            resultado = i;
        }
        if(resultados[i] == maior){ 
            int moeda;

            moeda = rand()%2;
            if(moeda == 0){ //em caso de empate, joga-se uma moeda e o vencedor será escolhido como maior
                resultado = i;
            }
        }
    }

    cout << "A opcao escolhida foi: " << opcoes[resultado] << endl; //exibição do resultado do sorteio
    system("pause");
    return 0;
}