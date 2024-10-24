#ifndef _ESCREVE_H_
#define _ESCREVE_H_

/*! 
 *  Encontram-se os algoritmos de escrita nos logs de controle 
*/


void Escreve_No_Log_Arquivo(ARQUIVO *arquivo);
void Escreve_No_Log_Palavra(ARQUIVO *arquivo, Tabela_Hash tabela);
bool Escreve_No_Log_Controle(ARQUIVO *arquivo);


#endif
