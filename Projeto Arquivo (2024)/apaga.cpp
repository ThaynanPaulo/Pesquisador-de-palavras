#include <iostream>
#include <getopt.h>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include "teste.h"
#include "apaga.h"
using namespace std;

/*! 
 *  Encontram-se os algoritmos de remoção de palavras do sistema de arquivos
*/


void Remove_Log_Palavra( char *nome_entrada)
{
    char nome[TAMANHO_DA_PALAVRA];
	strcpy(nome, nome_entrada);
	strcat(nome, "LogPal.txt");
	cout << nome << endl;
	remove("lista.txtlog_palavra.txt /0");

}

void Remove_Log_Arquivo( char *nome_entrada)
{
    char nome[TAMANHO_DA_PALAVRA];
	strcpy(nome, nome_entrada);
	strcat(nome, "LogPal.txt");
	cout << nome << endl;
	remove("LISTA.TXTLog_Arquivo.txt");

}


bool Remove_Log_Controle(char *nome_entrada)
{



    int i =0; int confirma = 0;

    char nome[TAMANHO_DO_CONTROLE][TAMANHO_DA_PALAVRA];
    for( int j = 0; j < TAMANHO_DO_CONTROLE; j++)
    {
    strcpy(nome[j], " ");
    }

    char nomes[TAMANHO_DA_PALAVRA];
    strcpy(nomes, nome_entrada);
    strupr(nomes);

    ifstream arquivo_ler;
    arquivo_ler.open("Log_Controle.txt");
    if(!arquivo_ler.is_open())
    {
       cout << "Não foi encontrado o log de arquivo: banco de arquivos está vazio, portanto não há o que remover." << endl;
       arquivo_ler.clear();
       return 0;
    }

    if(is_empty(arquivo_ler))
    {
        cout << "arquivo vazio, não há o que remover." << endl;
        //system("PAUSE > null");
        return 0;
    }
    else
    {

        while(! arquivo_ler.eof())      //BUSCA SEQUENCIAL ITERATIVA DENTRO DO ARQUIVO PELO NOME - SE FOR IGUAL REMOVE SE NÃO, MANTÉM O ARQUIVO COMO O ORIGINAL
        {


                arquivo_ler >> nome[i];
                /*cout << nome[i] << endl;
                cout << nomes << endl;
                cout << "cfscasmdksa" <<endl;
                system("PAUSE > null");
                */


                if(strcmp(nome[i], nomes) == 0)
                {
                    for(int t = 0; t < 2; t++)
                    {
                        /*

                        if(remove(nomes) == 0)
                        {
                            cout << "Arquivo removido com sucesso." << endl;
                        }

                        if(remove(strcat(nomes, "LogArq.txt")) == 0)
                        {
                            cout << "swfeqmksd" << endl;
                        }
                        if(remove(strcat(nomes, "LOGPAL.TXT")) == 0)
                        {
                              cout << "tergeksd" << endl;
                        }
                    */
                    }



                    //Remove_Log_Palavra(nome_entrada);
                    //Remove_Log_Arquivo(nome_entrada);
                    confirma = 1;
                }
                i++;

        }
    }

arquivo_ler.close();

//cout << i <<endl;
//system("PAUSE > null");


if(confirma == 1)
    {

        if( i == 1)
        {
            remove("Log_Controle.txt");
        }
        else
        {
            ofstream arquivo_escrever;
            arquivo_escrever.open("Log_Controle.txt");
            if(!arquivo_escrever.is_open())
            {
                cout << "Não foi encontrado o arquivo:" << endl;
                arquivo_escrever.clear();
                return 0;
            }
            else
            {
                for(int j = 0; j < i; j++)
                {
                    if(strcmp(nome[j], nomes) == 0)
                    {

                    }
                    else
                    {
                        arquivo_escrever << nome[j] << " ";
                    }

                }

            }
        arquivo_ler.close();
        }
    }
    else
    {
    ifstream arquivo_ler_tentativa;
    arquivo_ler_tentativa.open(nome_entrada);
    if(!arquivo_ler_tentativa.is_open())
    {
       cout << "Não foi encontrado o arquivo: adicione-o a pasta atual e insira-o." << endl;
       arquivo_ler.clear();
       return 0;
    }
    else
    {
        cout << "O arquivo está na pasta mais ainda não foi adicionado ao banco de arquivos." << endl;
        return 0;
    }


    }



}
