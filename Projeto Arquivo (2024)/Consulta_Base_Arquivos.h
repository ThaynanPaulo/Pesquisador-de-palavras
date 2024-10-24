#ifndef _CONSULTA_BASE_ARQUIVO_
#define _CONSULTA_BASE_ARQUIVO_

/*! 
 *  Encontram-se os algoritmos de consulta de palavras em relação ao sistema de arquivos
*/

typedef struct Quantidade_Palavras
{
    char nome[TAMANHO_DA_PALAVRA];  // nome do arquivo
    int  quant; // quantidade de palavras

}Ordena_Quant_Palavra;

bool Consulta_Base_Insercao();
//void Consulta_Base_Insercao(); já é o padrão

bool Consulta_Base_Alfabetica();
bool Consulta_Base_Alfabetica(Hash tabela,char *nome_palavra );
bool Consulta_Base_Quantidade_Palavras();
void recupera_numero_Palavras(Ordena_Quant_Palavra *vetor, int Numero_Palavra_Arquivo_Log);     // exemplo ponteiro de função
void Ordena_Vetor_Quantidade_Palavra(Ordena_Quant_Palavra *vetor, int Numero_Palavra_Arquivo_Log);
void Apresenta_Vetor_Quantidade_Palavra(Ordena_Quant_Palavra *vetor, int Numero_Palavra_Arquivo_Log);


#endif // _TESTE_H_
