#include <iostream>
#include <getopt.h>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include "teste.h"
#include "escreve.h"
using namespace std;

/*! 
 *  Encontram-se os algoritmos de escrita nos logs de controle 
*/


bool Escreve_No_Log_Controle(ARQUIVO *arquivo)
{
    char nome[TAMANHO_DO_CONTROLE][TAMANHO_DA_PALAVRA];
    int i = 0;


    for( int j = 0; j < TAMANHO_DO_CONTROLE; j++)
    {
    strcpy(nome[j], " ");
    }

    /*
    ofstream arquivo_es;
    arquivo_es.open("Log_Controle.txt");

	if(!arquivo_es.is_open())
	{
		cout << "Não foi encontrado o arquivo:" << endl;
		arquivo_es.clear();
        arquivo_es.open("Log_Controle.txt");
        arquivo_es << "       uihul " << endl;
    //arquivo_es.close();
    //return 0;
	}
	*/

    //system("PAUSE > null");
    ifstream arquivo_ler;
    arquivo_ler.open("Log_Controle.txt");
    if(!arquivo_ler.is_open())
	{
		cout << "Não foi encontrado o arquivo de controle: novo arquivo 'Log_controle.txt' será criado e primeiro nome de arquivo armazenado." << endl;
		arquivo_ler.close();
	}
    if(is_empty(arquivo_ler))
    {
        arquivo_ler.close();
        ofstream arquivo_escrever;
        arquivo_escrever.open("Log_Controle.txt");
        arquivo_escrever << strupr(arquivo->nome_arquivo);

        cout << "arquivo inserido ao banco de arquivos com sucesso." << endl;
        //system("PAUSE > null");
        return 0;
    }
    else
    {
        while(! arquivo_ler.eof())
        {
                arquivo_ler >> nome[i];
                //cout << nome[i] << endl;
                //cout << arquivo->nome_arquivo<< endl;
                //cout << "ljkçwmafkçl" << endl;
                //system("PAUSE > null");

                if(strcmp(nome[i], strupr(arquivo->nome_arquivo)) == 0)
                {
                    cout << "Existe um arquivo com mesmo nome no banco. Renomeie para inserção." << endl;
                    return 0;
                }
                i++;
        }
    }

    arquivo_ler.close();

    strcpy(nome[i],arquivo->nome_arquivo);
    i++;
    ofstream arquivo_escrever;
    arquivo_escrever.open("Log_Controle.txt");

    for( int j = 0; j < i; j++)
    {
    if( j == i - 1)
    {
        arquivo_escrever << strupr(nome[j]) << '\0';
    }
    else
    {
    //cout << nome[i] << endl;
    arquivo_escrever << strupr(nome[j]) << " ";
    }
    }

    cout << "arquivo inserido ao banco de arquivos com sucesso." << endl;
    //cout << "scmdksa" <<endl;
    //system("PAUSE > null");
return 0;

}

void Escreve_No_Log_Arquivo(ARQUIVO *arquivo)
{
    //cout << "scmdksa" <<endl;
    //system("PAUSE > null");

    char nome[TAMANHO_DA_PALAVRA];

	strcpy(nome, arquivo->nome_arquivo);
	strcat(nome, "LogArq.txt");
    strupr(nome);

    ofstream arquivo_escrever;
    arquivo_escrever.open(nome);

	if(!arquivo_escrever.is_open())
	{
		cout << "Não foi encontrado o arquivo:  novo log de palavra ('nome do arquivo'LogArq.txt) para esse arquivo será criado." << endl;
		arquivo_escrever.clear();
	}
    arquivo_escrever << arquivo->quantidade_palavras <<  " ";
    arquivo_escrever << arquivo->quantidade_palavras_nao_repetidas <<  " ";
    arquivo_escrever << arquivo->numero_do_arquivo <<  " ";
    //cout << arquivo->quantidade_palavras << endl;
    //cout << "scmdksa" <<endl;
    //system("PAUSE > null");
}

void Escreve_No_Log_Palavra(ARQUIVO *arquivo, Tabela_Hash tabela)
{

    //system("PAUSE > null");

    char nome[30];
    ofstream arquivo_escrever;
	strcpy(nome, arquivo->nome_arquivo);
	strcat(nome, "LogPal.txt");
    strupr(nome);
	//cout << arquivo->nome_arquivo << endl;
	//cout << nome << endl;

    arquivo_escrever.open(nome);

	if(!arquivo_escrever.is_open())
	{
		cout << "Não foi encontrado o arquivo: novo log de palavra ('nome do arquivo'LogPal.txt) para esse arquivo será criado." << endl;
		arquivo_escrever.clear();
	}


	for(int i = 0; i < arquivo->quantidade_palavras_nao_repetidas; i++)
    {
        int pos = hash_funcao(arquivo->Palavras_organizadas[i]);
        if(pos < 0)
        {
            pos = pos * (-1);
        }
        arquivo_escrever << tabela[pos].Palavra <<  " ";
        arquivo_escrever << tabela[pos].quantidade << " ";
        for(int  j = 0; j < tabela[pos].quantidade; j++)
        {
        if(j == 0)
        {
        arquivo_escrever <<  tabela[pos].linha[j];
        }
        else
        {
        arquivo_escrever << " " <<  tabela[pos].linha[j];
        }

        }
        arquivo_escrever << endl;

    }

arquivo_escrever.close();
}





