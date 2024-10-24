#ifndef _CONSULTA_BASE_ARQUIVO_
#define _CONSULTA_BASE_ARQUIVO_

/*! 
 *  Encontram-se os algoritmos de consulta de palavras em rela��o ao sistema de arquivos
*/

typedef struct Quantidade_Palavras
{
    char nome[TAMANHO_DA_PALAVRA];  // nome do arquivo
    int  quant; // quantidade de palavras

}Ordena_Quant_Palavra;

bool Consulta_Base_Insercao();
//void Consulta_Base_Insercao(); j� � o padr�o

bool Consulta_Base_Alfabetica();
bool Consulta_Base_Alfabetica(Hash tabela,char *nome_palavra );
bool Consulta_Base_Quantidade_Palavras();
void recupera_numero_Palavras(Ordena_Quant_Palavra *vetor, int Numero_Palavra_Arquivo_Log);     // exemplo ponteiro de fun��o
void Ordena_Vetor_Quantidade_Palavra(Ordena_Quant_Palavra *vetor, int Numero_Palavra_Arquivo_Log);
void Apresenta_Vetor_Quantidade_Palavra(Ordena_Quant_Palavra *vetor, int Numero_Palavra_Arquivo_Log);


#endif // _TESTE_H_
