#ifndef _TESTE_H_
#define TESTE_H_
#define TAMANHO 2000                // TABELA HASH INICIAL - PARA PRÉ-PROCESSAMENTO
#define QUANTIDADE_DE_LINHAS 200    // POR ARQUIVO
#define TAMANHO_DA_PALAVRA 35
#define TAMANHO_DO_CONTROLE 100
#define TAMANHO_VETOR_TEMPORARIO  500
#define TAMANHO_DA_FRASE    200


typedef struct nos
{
    char Palavra[TAMANHO_DA_PALAVRA];
    char Arquivo[TAMANHO_DA_PALAVRA];
    int  quantidade;
    int linha[QUANTIDADE_DE_LINHAS];
    int total_de_vezes_palavra;            //quant é sem repetição e total é com repetição;
    bool livre;
    nos *prox;
    nos *ant;

}Dados;

typedef Dados Tabela_Hash[TAMANHO];
typedef Dados *Hash[TAMANHO];


typedef struct dado
{
    char *nome_arquivo;
    int quantidade_palavras;
    int quantidade_palavras_nao_repetidas;
    char **Palavras_organizadas;
    int numero_do_arquivo;
    //int numero_de_arquivos;
    //Dados *dados;

}ARQUIVO;

typedef struct no
{
    no *prox;
    no *ant;
    ARQUIVO *arquivo;
}NoLISTA;

typedef struct
{
    no *ini;
    no *fim;
    int Quantidade_de_Arquivos;
}LISTA;

/*
typedef struct no
{

    int quantidade_palavras
    Dados *palavra;
    no *prox;
    no *ant;
}PALAVRAS;

*/

void Imprimir_Ajuda();

void Inicializar_Hash(Tabela_Hash tabela);
void Inicializar_Vetor_arquivo(ARQUIVO *arquivo);
void Inicializar_Lista(LISTA * lista);

bool is_empty(std::ifstream& pFile);

//procedimento de pre processamento de um arquivo na entrada:  como saida temos as struturas tabela e arquivo atualizadas e prontas para serem impressas
bool Dados_Arquivo(Tabela_Hash tabela, ARQUIVO *arquivo, char *nome);
void Atualiza_buffer(Tabela_Hash tabela, int pos, int linha, char palavra[], char *nome );


// tabela hash
int hash_funcao(char *palavra);
int colisao_funcao(Tabela_Hash tabela, int cont);



//void Remover_Arquivo(char *nome, LISTA *lista);

#endif // _TESTE_H_



