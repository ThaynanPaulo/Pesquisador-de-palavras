
#include <iostream>
#include <getopt.h>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include "teste.h"
#include "consulta_palavra.h"
#include "Forma_da_Busca.h"
using namespace std;

/*! 
 *  Encontram-se os algoritmos de busca de palavras em relação ao sistema de arquivos usando and e or
*/

void bor(int pos, int pos1, Hash tab)
{
    Hash tabela;
    Dados *novo = (Dados*) new Dados;
    novo = tabela[0];
    Dados *aux1, *aux2, *aux3, *aux4;
    aux1 = tab[pos];
    aux2 = tab[pos1];
    aux3 = tabela[0];
    aux4 = NULL;



    while(aux1 != NULL)
    {
        while(aux2 != NULL)
        {
            if(strcmp(aux1->Arquivo, aux2->Arquivo) == 0)
            {
                Dados *novo = (Dados*) new Dados;
                novo->quantidade = 0;
                cout << aux1->Arquivo << endl;
                for( int i = 0; i < aux1->quantidade; i++)
                {
                    cout << aux1->linha[i] << "dkçwa" << endl;
                    strcpy(novo->Arquivo, aux1->Arquivo);
                    //strcpy(novo->Palavra, aux1->Palavra);
                    novo->linha[novo->quantidade] = aux1->linha[i];
                    novo->quantidade++;
                }
                for( int j = 0; j < aux2->quantidade; j++)
                {
                             cout << "hblj" << aux2->linha[j] << "dkçwa" << endl;
                          for( int k = 0; k < novo->quantidade; k++)
                        {
                            if(novo->linha[k] != aux2->linha[j])
                            {
                                novo->linha[novo->quantidade] = aux2->linha[j];
                                novo->quantidade++;

                            }
                        }


                    }


                if(novo->quantidade != 0 && tabela[0] == NULL)
                {
                    novo->ant = NULL;
                    novo->prox = NULL;
                    cout << novo->linha[0] << "ekçwa"<< endl;
                    tabela[0] = novo;
                     cout << tabela[0]->linha[0] << "ekçwa"<< endl;


                }
                else if (novo->quantidade != 0 && tabela[0] != NULL)
                {

                    while(aux3 != NULL)
                    {
                        aux4 = aux3;
                        aux3 = aux3->prox;
                    }
                    aux4->prox = novo;
                    novo->ant = aux4;
                    novo->prox = NULL;
                }

                aux3 = tabela[0];
                aux4 = NULL;
            }
        aux2 = aux2->prox;
        }
    aux1 = aux1->prox;
    aux2 = tab[pos1];
    }


cout << tabela[0]->prox->quantidade << "kmsaç" << endl;
cout << tabela[0]->prox->Arquivo << "kmsaç" << endl;
cout << tabela[0]->prox->linha[tabela[0]->quantidade - 1] << "kmsaç" << endl;




}


void band(int pos, int pos1, Hash tab)
{
    Hash tabela;
    Dados *novo = (Dados*) new Dados;
    novo = tabela[0];
    Dados *aux1, *aux2, *aux3, *aux4;
    aux1 = tab[pos];
    aux2 = tab[pos1];
    aux3 = tabela[0];
    aux4 = NULL;



    while(aux1 != NULL)
    {
        while(aux2 != NULL)
        {
            if(strcmp(aux1->Arquivo, aux2->Arquivo) == 0)
            {
                Dados *novo = (Dados*) new Dados;
                novo->quantidade = 0;
                cout << aux1->Arquivo << endl;
                for( int i = 0; i < aux1->quantidade; i++)
                {

                    for( int j = 0; j < aux2->quantidade; j++)
                    {
                        if(aux1->linha[i] == aux2->linha[j])
                        {
                             cout << aux1->linha[i] << "dkçwa" << endl;

                                strcpy(novo->Arquivo, aux1->Arquivo);
                                strcpy(novo->Palavra, aux1->Palavra);
                                novo->linha[novo->quantidade] = aux1->linha[i];
                                novo->quantidade++;

                        }



                    }

                }

                if(novo->quantidade != 0 && tabela[0] == NULL)
                {
                    novo->ant = NULL;
                    novo->prox = NULL;
                    cout << novo->linha[0] << "ekçwa"<< endl;
                    tabela[0] = novo;
                     cout << tabela[0]->linha[0] << "ekçwa"<< endl;


                }
                else if (novo->quantidade != 0 && tabela[0] != NULL)
                {

                    while(aux3 != NULL)
                    {
                        aux4 = aux3;
                        aux3 = aux3->prox;
                    }
                    aux4->prox = novo;
                    novo->ant = aux4;
                    novo->prox = NULL;
                }

                aux3 = tabela[0];
                aux4 = NULL;
            }
        aux2 = aux2->prox;
        }
    aux1 = aux1->prox;
    aux2 = tab[pos1];
    }


cout << tabela[0]->quantidade << "kmsaç" << endl;
cout << tabela[0]->Arquivo << "kmsaç" << endl;
cout << tabela[0]->linha[tabela[0]->quantidade - 1] << "kmsaç" << endl;


//Apresentar_Lista_Frase(tab, 0);     // faze sobreposição de função!!


}
