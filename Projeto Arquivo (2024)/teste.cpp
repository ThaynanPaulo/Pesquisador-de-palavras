#include <iostream>
#include <getopt.h>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include "teste.h"

using namespace std;



void Imprimir_Ajuda()
{

    cout << "opções:" << endl;
    cout << " ##Modo de Gerenciamento de Busca:" << endl << endl;
    cout <<"-h ou --ajuda: mostra essa tela e sai." << endl
     << "-i ou --Inserir: Inserir novo arquivo na base de dados." << endl
     << "-r ou --Remover: Remover arquivo na base de dados." << endl << endl;

     cout << "Exibição da base de arquivo:" << endl << endl
     << "-e ou --List_Insercao: Listar todos os arquivos da base tendo como base a ordem de Insercao." << endl
     << "-a ou --List_Alfabetico: Listar todos os arquivos da base tendo como base a ordem alfabética." << endl
     << "-p ou --List_Quant_Palavras: Listar todos os arquivos da base tendo como base A ordem decrescente da quantidade de palavras do arquivo." << endl << endl;

    cout << " ##Modo de Buscas:" << endl << endl;

    cout << "Argumento de Busca:" << endl << endl
    << "-d ou --bAND _And:A busca é feita por linhas dos arquivos texto que contém todas as palavras chave passadas como argumento de entrada." << endl
    << "-o ou --bOR : A busca é feita por linhas dos arquivos texto que contém ao menos uma das palavras chave passadas como argumento de entrada." << endl;

    cout << "Exibição do resultado da busca:" << endl << endl
    << "-b ou --Impress_Alfabetica: A impressão é feita exibindo os resultados em ordem alfabética do nome do arquivo." << endl
    << "-q ou --Impress_Quant_Palavras: A impressão é feita exibindo os resultados em ordem decrescente do número de vezes que as palavraschave ocorreram em cada arquivo." << endl
    << "-c ou --Impress_Insercao: A impressão é feita exibindo os resultados na ordem em que cada arquivo foi inserido na base." << endl;

    cout << "Contabilização do tempo:" << endl << endl
    << "-s ou --Temp_S: O programa deve registrar e exibir o tempo total de execução de da busca." << endl
    << "-n ou --Temp_N: O programa não deve registrar nem exibir o tempo total de execução da busca." << endl;
}


// Inicialização da Hash

void Inicializar_Hash(Tabela_Hash tabela)
{


    for(int i = 0; i < TAMANHO; i++)
      {
       tabela[i].quantidade = 0;
       tabela[i].livre = true;
       tabela[i].prox = NULL;
       tabela[i].ant = NULL;
       for(int j = 0; j < QUANTIDADE_DE_LINHAS; j++)
       {
           tabela[i].linha[j] = 0;
       }
       }

}


void Inicializar_Vetor_arquivo(ARQUIVO *arquivo)
{

    arquivo->numero_do_arquivo = 0;
    arquivo->quantidade_palavras = 0;
    arquivo->quantidade_palavras_nao_repetidas = 0;
}


void Inicializar_Lista(LISTA *lista)
{
    lista->ini = NULL;
    lista->fim = NULL;
    lista->Quantidade_de_Arquivos = 0;
}
int colisao_funcao(Tabela_Hash tabela, int cont)
{


 while( tabela[cont].livre == false )
        {
            cont = cont + 1;
        }
        return cont;
}

int hash_funcao(char *palavra)
{
   // system("PAUSE > null");
    palavra = strupr(palavra);
    int cont = 0, r = 0;
    while(palavra[r] != '\0')
    {
        r++;
    }
    for(int j = 0; j < r; j++)
    {
        cont = cont + palavra[j];
    }
    if(cont < 0)
    {
    cont = (-1) * cont;
    }
    //cout<< cont<< endl;
    return (unsigned int)  cont;

}

bool is_empty(std::ifstream& pFile)
{
return pFile.peek() == std::ifstream::traits_type::eof();
}


void Atualiza_buffer(Tabela_Hash tabela, int pos, int linha, char palavra[])
{

    strcpy(tabela[pos].Palavra, palavra);
    //tabela[pos].Documento = "lista.txt";
    tabela[pos].linha[tabela[pos].quantidade] = linha;
    tabela[pos].quantidade++;
    tabela[pos].livre = false;
    //tabela[pos].prox = NULL;
    //tabela[pos].ant = NULL;

}


bool Dados_Arquivo(Tabela_Hash tabela, ARQUIVO *arquivo, char *nome)
{

        //Tabela_Hash tabela;
    char a[TAMANHO_DA_PALAVRA], palavra[TAMANHO_DA_PALAVRA], **vetor_pra_ordenamento;
    int i  = 0, pos = 0, linha = 0, u = 0;

    vetor_pra_ordenamento = new char*[TAMANHO_VETOR_TEMPORARIO];
    for(int i = 0; i < TAMANHO_VETOR_TEMPORARIO; i++)
    {
    vetor_pra_ordenamento[i] = new char[TAMANHO_DA_PALAVRA];
    }

    ifstream arquivoentrada;
	//abre_arquivo(ifstream arquivoentrada);

		arquivoentrada.open(nome);

	if(!arquivoentrada.is_open())
	{
		cout << "Não foi encontrado o arquivo: Insera-no na pasta atual." << endl;
		arquivoentrada.clear();
		return false;
	}




    while(arquivoentrada.eof() != 1)
    {
        a[i] = arquivoentrada.get();

        if((a[i] >= 32 && a[i] <= 64) || (a[i] > 90 && a[i] < 97)  || (a[i] > 122 && a[i] < 128) || a[i] == '\n')
        {
        if(a[i] == '\n')
        {
            linha++;
        }

        if((a[0] >= 32 && a[0] <= 64) || (a[0] > 90 && a[0] < 97)  || (a[0] > 122 && a[0] < 128) || a[0] == '\n')
        {

        }
        else
        {

            a[i] = '\0';
            strcpy(palavra, a);
            strcpy(vetor_pra_ordenamento[u], strupr(palavra));
            u++;

            int pos = hash_funcao(a);

            //cout << tabela[pos].livre << endl;
            if(strcmp(tabela[pos].Palavra, palavra) != 0 && tabela[pos].livre == false)
            {
               pos = colisao_funcao(tabela, pos);
            }

            Atualiza_buffer(tabela, pos, linha, palavra);


            for(int j = 0; j <= i; j++ )
            {
               //cout << a[j];
                a[j] = ' ';
            }
            i = 0;
           //cout <<endl;
            }
        }
        else
        {
         i++;
        }


    }



    //ordenamento das palavras do arquivo
int total = u;
//system("PAUSE > null");


char *aux = (char*) new char;

for(int r = 0; r < u; r++)
{
    for(int s = r+1; s < u; s++)
    {
        if (strcmp(vetor_pra_ordenamento[r],vetor_pra_ordenamento[s])>0)
            {
               strcpy(aux,vetor_pra_ordenamento[s]);
               strcpy(vetor_pra_ordenamento[s],vetor_pra_ordenamento[r]);
               strcpy(vetor_pra_ordenamento[r], aux);
            }
    }

}


for(int q = 0; q < u; q++)
{
  //   cout << vetor_pra_ordenamento[q] << endl;

}



for(int p = 0; p < u - 1; p++)
{


    if(strcmp(vetor_pra_ordenamento[p], vetor_pra_ordenamento[p+1]) == 0)
    {
    //cout << strcmp(vetor_pra_ordenamento[p], vetor_pra_ordenamento[p+1]) << endl;
    //cout << u << endl;
    //cout << vetor_pra_ordenamento[p] << "||" << vetor_pra_ordenamento[p+ 1] << endl;

        for(i= p ; i < u - 1; i++)
        {
            //cout << vetor_pra_ordenamento[i] << "||" << vetor_pra_ordenamento[i+ 1] << "SDXSZ" << endl ;
            strcpy(vetor_pra_ordenamento[i],vetor_pra_ordenamento[i+1]);
            //cout << vetor_pra_ordenamento[i] << "||" << vetor_pra_ordenamento[i+ 1] << endl;
           // system("PAUSE > null");
        }
          u--;
          p--;

    }

}

/*
for(int q = 0; q < u; q++)
{
    cout << vetor_pra_ordenamento[q] << endl;

}
*/

  arquivoentrada.close();

  //ARQUIVO *arquivo = (ARQUIVO*) new ARQUIVO;
  strcpy(arquivo->nome_arquivo, nome);
  arquivo->quantidade_palavras = total;
  arquivo->quantidade_palavras_nao_repetidas = u;
  arquivo->Palavras_organizadas = vetor_pra_ordenamento;
  arquivo->numero_do_arquivo++;


return true;

/*
cout << tabela[152].Palavra << endl;
cout << tabela[152].quantidade << endl << endl;
for(int k = 0; k < tabela[152].quantidade; k++)
{
    cout << tabela[152].linha[k] << endl;

}
*/
}
