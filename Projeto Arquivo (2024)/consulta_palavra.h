#ifndef _CONSULTA_PALAVRA_H
#define _CONSULTA_PALAVRA_H

/*! 
 *  Encontram-se os algoritmos de apresentação das frases em que se encontram as palavras do sistema de arquivos
*/


void Consulta_Palavra(char *nome_palavra, Hash tab);
void Inicializar_Hash_Recupera(Hash tabela);                                          // procedimento para consultar se determinada palavra faz parte de um arquivo
bool recupera_palavras_arquivo(char *nome, char *palavra, Hash tabela);             //varre o arquivo para ver se encontra a paçavra (true se sim e false se não)
void Inserir_Lista_Palavra(Hash tabela, int pos, char nome[TAMANHO_DA_PALAVRA], char palavra[TAMANHO_DA_PALAVRA], int quant, int total_com_repeticao, int vetor[]);
    //caso encontre coloca valores na lista usando a função como base

void  Apresentar_Lista_Frase(Hash tabela,char *nome );
void  Apresentar_Lista_Frase(Hash tabela, int pos);


#endif
