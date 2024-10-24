#include <iostream>
#include <getopt.h>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include "teste.h"
#include "Consulta_Base_Arquivos.h"
#include "consulta_palavra.h"

using namespace std;
typedef void (*func) (Ordena_Quant_Palavra *vetor, int Numero_Palavra_Arquivo_Log);

/*! 
 *  Encontram-se os algoritmos de consulta de palavras em relação ao sistema de arquivos
*/

bool Consulta_Base_Insercao()
{
    char nome[TAMANHO_DA_PALAVRA][TAMANHO_DO_CONTROLE];
    int i = 0;
    ifstream arquivo_ler;
    arquivo_ler.open("Log_Controle.txt");
    if(!arquivo_ler.is_open())
    {
       cout << "O banco de arquivo está vazio, não há o que apresentar." << endl;
       arquivo_ler.clear();
       return 0;
    }
    else if(is_empty(arquivo_ler))
    {
        cout << "arquivo vazio, não há arquivos no banco de arquivos para ser apresentado." << endl;
        return 0;
    }
    else
    {
        while(! arquivo_ler.eof())
        {
            arquivo_ler >> nome[i];
            i++;
        }

    arquivo_ler.close();

    for(int j = 0; j < i; j++)
    {
        cout << "-" << nome[j] << endl;
    }

    }


}

bool Consulta_Base_Alfabetica()
{
    char nome[TAMANHO_DA_PALAVRA][TAMANHO_DO_CONTROLE];
    int i = 0;
    ifstream arquivo_ler;
    arquivo_ler.open("Log_Controle.txt");
    if(!arquivo_ler.is_open())
    {
       cout << "O banco de arquivo está vazio, não há o que apresentar." << endl;
       //arquivo_ler.clear();
       return 0;
    }
    else if(is_empty(arquivo_ler))
    {
        cout << "arquivo vazio, não há arquivos no banco de arquivos para ser apresentado." << endl;
        return 0;
        //system("PAUSE > null");
    }
    else
    {
        while(! arquivo_ler.eof())
        {
            arquivo_ler >> nome[i];
            i++;
        }

        arquivo_ler.close();

        char aux[TAMANHO_DA_PALAVRA];

        for(int r = 0; r < i; r++)              // ordenando os arquivos tendo como base a ordem alfabética
        {
            for(int s = r+1; s < i; s++)
            {
                if (strcmp(nome[r],nome[s])>0)
                    {
                       strcpy(aux,nome[s]);
                       strcpy(nome[s],nome[r]);
                       strcpy(nome[r], aux);
                    }
            }

        }


        for(int j = 0; j < i; j++)
        {
                cout << "-" << nome[j] << endl;
        }

    }


}


bool Consulta_Base_Alfabetica(Hash tabela,char *nome)
{


    int contador_linhas = 0, linha_correta_atual = 0;

    char nome_palavra[TAMANHO_DA_PALAVRA];
	strcpy(nome_palavra, nome);
    strupr(nome_palavra);

    int pos = hash_funcao(nome_palavra);
    char linha[TAMANHO_DA_FRASE];
    Dados *aux1, *aux2, *aux3, *aux4, *aux5, *aux6;
    aux1 = tabela[pos];
    aux2 = tabela[pos]->prox;

    cout << tabela[pos]->Arquivo << endl;
    cout << tabela[pos]->prox->Arquivo << endl;
    cout << tabela[pos]->prox->prox->Arquivo << endl <<endl;
    cout << aux1->Arquivo << endl;
    cout << aux2->Arquivo << endl <<endl;

    system("PAUSE > null");
    while(aux1->prox != NULL)
    {


        while(aux2 != NULL)
        {

            cout << tabela[pos]->Arquivo << endl;
            cout << tabela[pos]->prox->Arquivo << endl;
            cout << tabela[pos]->prox->prox->Arquivo << endl <<endl;
            cout << aux1->Arquivo << endl;
            cout << aux2->Arquivo << endl <<endl;



            if(strcmp(aux1->Arquivo, aux2->Arquivo) > 0)
            {


                if(aux1->prox == aux2)
                {
                    if(aux1->ant == NULL && aux2->prox == NULL)
                    {

                        cout<< "klçsda" << endl;
                        system("PAUSE > null");
                        aux3->prox = aux2;




                    }
                    else if(aux1->ant == NULL && aux2->prox != NULL)
                    {



                        //aux3 = aux1->ant; = é NULL;
                        aux3 = aux2->prox;
                        aux3->ant = aux1;
                        aux1->prox  = aux3;
                        aux2->prox = aux1;
                        aux2->ant = NULL;


                    }
                    else if(aux1->ant != NULL && aux2->prox == NULL)
                    {


                        aux3 = aux1->prox;
                        aux4 = aux1->ant;

                        aux5 = aux2->prox;     //NULL
                        aux6 = aux2->ant;

                        aux6->prox = aux1;
                        aux1->prox = NULL;
                        aux1->ant = aux6;

                        aux3->ant = aux2;
                        aux4->prox = aux2;
                        aux2->prox = aux3;
                        aux2->ant = aux4;

                    }
                    else
                    {

                        aux3 = aux1->prox;
                        aux4 = aux1->ant;

                        aux5 = aux2->prox;     //NULL
                        aux6 = aux2->ant;


                        aux6->prox = aux1;
                        aux5->ant  = aux1;
                        aux1->prox = aux5;
                        aux2->ant  = aux6;

                        aux3->ant = aux2;
                        aux4->prox = aux2;
                        aux2->prox = aux3;
                        aux2->ant = aux4;
                    }

                }
                else
                {
                    if(aux1->ant == NULL && aux2->prox == NULL)
                    {

                        cout<< "klçsda" << endl;
                        system("PAUSE > null");

                        aux3 = aux1->prox;
                        aux4 = aux1->ant;   //NULL

                        aux5 = aux2->prox;  //NULL
                        aux6 = aux2->ant;

                        aux6->prox = aux1;
                        aux1->ant = aux6;
                        aux1->prox = NULL;

                        aux3->ant = aux2;
                        aux2->prox = aux3;
                        aux2->ant = NULL;
                    }
                    else if(aux1->ant == NULL && aux2->prox != NULL)
                    {



                        aux3 = aux1->prox;
                        aux4 = aux1->ant;   //NULL

                        aux5 = aux2->prox;
                        aux6 = aux2->ant;

                        aux3->ant = aux2;
                        aux2->ant = NULL;
                        aux2->prox = aux3;





                        aux1->prox = aux5;
                        aux1->ant  = aux6;
                        aux6->prox = aux1;
                        aux5->ant  = aux1;


                    }
                    else if(aux1->ant != NULL && aux2->prox == NULL)
                    {


                        aux3 = aux1->prox;
                        aux4 = aux1->ant;

                        aux5 = aux2->prox;     //NULL
                        aux6 = aux2->ant;

                        aux6->prox = aux1;
                        aux1->prox = NULL;
                        aux1->ant = aux6;

                        aux3->ant = aux2;
                        aux4->prox = aux2;
                        aux2->prox = aux3;
                        aux2->ant = aux4;

                    }
                    else
                    {

                        aux3 = aux1->prox;
                        aux4 = aux1->ant;

                        aux5 = aux2->prox;     //NULL
                        aux6 = aux2->ant;


                        aux6->prox = aux1;
                        aux5->ant  = aux1;
                        aux1->prox = aux5;
                        aux2->ant  = aux6;

                        aux3->ant = aux2;
                        aux4->prox = aux2;
                        aux2->prox = aux3;
                        aux2->ant = aux4;
                    }

            cout << tabela[pos]->Arquivo << endl;
            cout << tabela[pos]->prox->Arquivo << endl;
            cout << tabela[pos]->prox->prox->Arquivo << endl <<endl;
            cout << aux1->Arquivo << endl;
            cout << aux2->Arquivo << endl <<endl;


                }

            }


            aux2 = aux2->prox;

        }

        aux1 = aux1->prox;
        aux2 = aux1->prox;


    }

}



void recupera_numero_Palavras(Ordena_Quant_Palavra *vetor, int Numero_Palavra_Arquivo_Log)
{

    char nome[TAMANHO_DA_PALAVRA];
    for(int j = 0; j < Numero_Palavra_Arquivo_Log; j++)
    {



        ifstream arquivo_ler_log;
        strcpy(nome, vetor[j].nome);

        strcat(nome, "LogArq.txt");
        strupr(nome);
        arquivo_ler_log.open(nome);


        if(!arquivo_ler_log.is_open())
        {
            cout << "Não foi encontrado o arquivo de log: a base está vazia" << endl;
            arquivo_ler_log.clear();

        }

        arquivo_ler_log >> vetor[j].quant;

        //cout << vetor[j].quant << endl;
        //cout << vetor[j].nome << endl;
        //system("PAUSE > null");
        arquivo_ler_log.close();
    }



}

void Ordena_Vetor_Quantidade_Palavra(Ordena_Quant_Palavra *vetor, int Numero_Palavra_Arquivo_Log)
{
    Ordena_Quant_Palavra aux[1];

    //cout << i<< "dasds" << endl;
    //system("PAUSE > null");

    for(int r = 0; r < Numero_Palavra_Arquivo_Log; r++)          //ordenando tendo como base a quantidade de  palavras (descescente
    {
        for(int s = r+1; s < Numero_Palavra_Arquivo_Log; s++)
        {
            if (vetor[r].quant > vetor[s].quant)
                {
                    aux[0] = vetor[r];
                    vetor[r]= vetor[s];
                    vetor[s] = aux[0];
                }
        }

    }

}
void Apresenta_Vetor_Quantidade_Palavra(Ordena_Quant_Palavra *vetor, int Numero_Palavra_Arquivo_Log)
{



    for(int j = Numero_Palavra_Arquivo_Log - 1; j >= 0; j--)
    {
        cout << "-" << vetor[j].nome << " " << vetor[j].quant << endl;

    }



}

bool Consulta_Base_Quantidade_Palavras()
{


    Ordena_Quant_Palavra vetor[TAMANHO_DO_CONTROLE];
    char nome[TAMANHO_DA_PALAVRA];

    int i = 0;
    ifstream arquivo_ler;
    arquivo_ler.open("Log_Controle.txt");
    if(!arquivo_ler.is_open())
    {
        cout << "O banco de arquivo está vazio, não há o que apresentar." << endl;
        arquivo_ler.clear();
        return 0;
    }
    /*
    else if(is_empty(arquivo_ler))
    {
        cout << "arquivo vazio, não há o que remover." << endl;
        system("PAUSE > null");
    }
    */
    else
    {

        while(! arquivo_ler.eof())
        {
            arquivo_ler >> nome;// abrindo arquivo  com dados do arquivo
            strcpy(vetor[i].nome, nome);
            //cout << i << endl;
            i++;

        }
    }



arquivo_ler.close();




//cout << "nijlads" << endl;
//system("PAUSE > null");

func funcoes;           // exemplo de ponteiro de função - usado para facilitar o manuseio das etapas necessárias a apresentação dos arquivos ordenados por quantidade de palavras

funcoes = recupera_numero_Palavras;
funcoes(vetor, i);

funcoes = Ordena_Vetor_Quantidade_Palavra;
funcoes(vetor, i);

funcoes = Apresenta_Vetor_Quantidade_Palavra;
funcoes(vetor, i);









}
