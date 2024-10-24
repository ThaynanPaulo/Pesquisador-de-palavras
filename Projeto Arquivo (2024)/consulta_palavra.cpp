#include <iostream>
#include <getopt.h>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include "teste.h"
#include "consulta_palavra.h"
#include "Consulta_Base_Arquivos.h"
using namespace std;

/*! 
 *  Encontram-se os algoritmos de apresentação das frases em que se encontram as palavras do sistema de arquivos
*/


void Inicializar_Hash_Recupera(Hash tab)
{
    //tab[40]->quantidade = 100;
    //cout << tab[40]->quantidade << endl;

int i;
for(i = 0; i < TAMANHO; i++)
{
tab[i] = NULL;
}

}

void  Apresentar_Lista_Frase(Hash tabela, char *nome )
{

    int contador_linhas = 0, linha_correta_atual = 0;

    char nome_palavra[TAMANHO_DA_PALAVRA];
	strcpy(nome_palavra, nome);
    strupr(nome_palavra);

    int pos = hash_funcao(nome_palavra);
    char linha[TAMANHO_DA_FRASE];
    Dados *aux;
    aux = tabela[pos];


    /*
    cout << aux->prox->quantidade << endl;
    cout << aux->prox->prox->quantidade << endl;
    cout << aux->prox->prox->prox->quantidade << endl;
    */
    while(aux != NULL)
    {

        ifstream arquivo_ler;
        arquivo_ler.open(aux->Arquivo);
        if(!arquivo_ler.is_open())
        {
           cout << "Não foi encontrado o log de arquivo: banco de arquivos está vazio, portanto não há o que consultar." << endl;
           arquivo_ler.clear();
           //return 0;
        }
        else if(is_empty(arquivo_ler))
        {
            cout << "arquivo vazio, não há o que consulta." << endl;
            //system("PAUSE > null");
            //return 0;
        }
        else
        {
                cout << "Foram encontrados " << aux->quantidade << " linhas no arquivo " << aux->Arquivo << endl;
                while(! arquivo_ler.eof())
                {
                   arquivo_ler.getline(linha, TAMANHO_DA_FRASE);
                    if(contador_linhas == aux->linha[linha_correta_atual])
                    {

                        cout << "-" << linha << endl;

                        linha_correta_atual++;

                    }
                    else if(linha_correta_atual == aux->quantidade)
                    {
                    break;
                    }
                    contador_linhas++;
                    arquivo_ler.clear();
                    //cout << linha_correta_atual << endl;
                    //cout << contador_linhas << endl;
                    //cout << aux[pos]->Arquivo << endl;
                    //cout << aux->quantidade << endl;
                    //system("PAUSE > null");


                }
        }

        contador_linhas = 0;
        linha_correta_atual = 0;

        arquivo_ler.close();
        aux = aux->prox;
        cout << endl;
    }


}


void  Apresentar_Lista_Frase(Hash tabela, int pos )
{

    int contador_linhas = 0, linha_correta_atual = 0;

    char linha[TAMANHO_DA_FRASE];
    Dados *aux;
    aux = tabela[pos];

cout << tabela[0]->quantidade << "kmsaç" << endl;
cout << tabela[0]->Arquivo << "kmsaç" << endl;
cout << tabela[0]->linha[tabela[0]->quantidade - 1] << "kmsaç" << endl;

    /*
    cout << aux->prox->quantidade << endl;
    cout << aux->prox->prox->quantidade << endl;
    cout << aux->prox->prox->prox->quantidade << endl;
    */
    while(aux != NULL)
    {

        ifstream arquivo_ler;
        arquivo_ler.open(aux->Arquivo);
        if(!arquivo_ler.is_open())
        {
           cout << "Não foi encontrado o log de arquivo: banco de arquivos está vazio, portanto não há o que consultar." << endl;
           arquivo_ler.clear();
           //return 0;
        }
        else if(is_empty(arquivo_ler))
        {
            cout << "arquivo vazio, não há o que consulta." << endl;
            //system("PAUSE > null");
            //return 0;
        }
        else
        {
                cout << "Foram encontrados " << aux->quantidade << " linhas no arquivo " << aux->Arquivo << endl;
                while(! arquivo_ler.eof())
                {
                   arquivo_ler.getline(linha, TAMANHO_DA_FRASE);
                    if(contador_linhas == aux->linha[linha_correta_atual])
                    {

                        cout << "-" << linha << endl;

                        linha_correta_atual++;

                    }
                    else if(linha_correta_atual == aux->quantidade)
                    {
                    break;
                    }
                    contador_linhas++;
                    arquivo_ler.clear();
                    //cout << linha_correta_atual << endl;
                    //cout << contador_linhas << endl;
                    //cout << aux[pos]->Arquivo << endl;
                    //cout << aux->quantidade << endl;
                    //system("PAUSE > null");


                }
        }

        contador_linhas = 0;
        linha_correta_atual = 0;

        arquivo_ler.close();
        aux = aux->prox;
        cout << endl;
    }


}

void Inserir_Lista_Palavra(Hash tabela, int pos, char nome[TAMANHO_DA_PALAVRA], char palavra[TAMANHO_DA_PALAVRA], int quant,  int total_com_repeticao, int vetor[])
{

    //cout << "klsçda" << quant << endl;
    Dados *novo = (Dados*) new Dados;
    Dados *aux2, *aux;

    if(tabela[pos] == NULL)
    {
    strcpy(novo->Arquivo, nome);
    strcpy(novo->Palavra, palavra);
    novo->quantidade = quant;
    novo->prox = NULL;
    novo->ant = NULL;
    novo->quantidade = quant;
    novo->total_de_vezes_palavra = total_com_repeticao;
    for(int i = 0; i < quant; i++)
    {
        novo->linha[i] = vetor[i];
    }
    tabela[pos] = novo;
    }
    else
    {
    //cout << tabela[pos]->quantidade << endl;
    //system("PAUSE > null");


        aux = tabela[pos];
        aux2 = NULL;
        while(aux != NULL)
        {
            aux2 = aux;
            aux = aux->prox;
        }

        novo->total_de_vezes_palavra = total_com_repeticao;
        novo->quantidade = quant;
        for(int i = 0; i < quant; i++)
        {
            novo->linha[i] = vetor[i];
        }
        strcpy(novo->Arquivo, nome);
        strcpy(novo->Palavra, palavra);

        aux2->prox = novo;
        novo->ant = aux2;
        novo->prox = NULL;
    }

}



bool recupera_palavras_arquivo(char nome[TAMANHO_DA_PALAVRA], char palavra[TAMANHO_DA_PALAVRA],Hash tabela)
{


    char  v[TAMANHO_VETOR_TEMPORARIO], ve[TAMANHO_DA_PALAVRA];      // ver se o arquivo está no banco
    int i =0, r = 0, j = 0;

    ifstream arquivo_ler_principal;

    arquivo_ler_principal.open(nome);

	if(!arquivo_ler_principal.is_open())
	{
		cout << "Não foi encontrado o arquivo: cjhgfcft" << endl;
		arquivo_ler_principal.clear();
		return 0;
	}

    arquivo_ler_principal.close();


    char nome_arquivo[TAMANHO_DA_PALAVRA];
    strcpy(nome_arquivo, nome);
    strcat(nome_arquivo,"LogPal.txt");

    char nome_palavra[TAMANHO_DA_PALAVRA];
	strcpy(nome_palavra, palavra);
    strupr(nome_palavra);


    ifstream arquivo_ler;

    arquivo_ler.open(nome_arquivo);



	if(!arquivo_ler.is_open())
	{
		cout << "Não foi encontrado o arquivo:" << endl;
		arquivo_ler.clear();
		return 0;
	}
    else
    {
        while(! arquivo_ler.eof())
        {

            v[i]  = arquivo_ler.get();
            ve[r] = v[i];
            r++;



            if(v[i] == ' ' || v[i] == '\n')
            {


                ve[r] = '\0';
                ve[r - 1] = '\0';
                int j = 0;


                if(strcmp(nome_palavra, ve) == 0)       //BUSCA SEQUENCIAL DENTRO DO ARQUIVO NA QUAL SE PROCURA  A PALAVRA. ENCONTRANDO ARMAZENA-SE OS VALORES DE QUANTIDADE DE LINHAS E POSIÇÕES DA MESMA
                {

                int pos = hash_funcao(nome_palavra);
                /*if(strcmp(tabela[pos]->Palavra, palavra) != 0 && tabela[pos]->livre == false)
                {
                   //pos = colisao_funcao(tabela, pos);
                }
                */
                //cout << "palavra encontrada" <<endl;
                int c, d;

                arquivo_ler >> c;
                d = c;
                int vetor[c];

                for(int j = 0; j < c; j++)
                {
                    arquivo_ler >> vetor[j];
                    if(vetor[j] == vetor[j-1])
                    {
                        j--;
                        c--;

                    }
                }

                Inserir_Lista_Palavra(tabela, pos, nome, palavra, c, d, vetor);
                arquivo_ler.close();
                //cout << c << "quantidade de linhas" << endl;
                return true;
                }
                else if (strcmp(nome_palavra, ve) < 0)
                {
                cout << "palavra não encontrada no arquivo: "<< nome << endl;
                arquivo_ler.close();
                return false;
                }

            r = 0;

            }

    }
}


}





void Consulta_Palavra(char *nome_palavra, Hash tab)
{
    //Hash tab;
    int i = 0;
    char nome[TAMANHO_DO_CONTROLE][TAMANHO_DA_PALAVRA];
    char nomeses[TAMANHO_DA_PALAVRA];
    //Inicializar_Hash_Recupera(tab);

    ifstream arquivo_ler;
    arquivo_ler.open("Log_Controle.txt");
    if(!arquivo_ler.is_open())
    {
       cout << "Não foi encontrado o log de arquivo: banco de arquivos está vazio, portanto não há o que consultar." << endl;
       arquivo_ler.clear();
       //return 0;
    }

    else if(is_empty(arquivo_ler))
    {
        cout << "arquivo vazio, não há o que consultar." << endl;
        //system("PAUSE > null");
        //return 0;
    }
    else
    {

        while(! arquivo_ler.eof())      //Armazena os nomes do arquivo num vetor temporário
        {


                arquivo_ler >> nome[i];
                /*cout << nome[i] << endl;
                cout << "cfscasmdksa" <<endl;
                system("PAUSE > null");
                */
                i++;
        }
        arquivo_ler.close();

        for(int j = 0; j < i; j++)
        {

            recupera_palavras_arquivo(nome[j], nome_palavra, tab);
            //cout << "cfscasmdksa" <<endl;
            //system("PAUSE > null");
        }
        strcpy(nomeses, nome_palavra);
        int pos = hash_funcao(nomeses);
        //cout << tab[pos]->quantidade << endl;
        //Consulta_Base_Alfabetica(tab, nome_palavra);
        //Apresentar_Lista_Frase(tab, nome_palavra);




    }







}
