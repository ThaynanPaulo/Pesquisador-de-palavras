#include <iostream>
#include <getopt.h>
#include <cstdlib>
#include <fstream>
#include <string.h>
#include <time.h>
#include "Apaga.h"
#include "teste.h"
#include "escreve.h"
#include "consulta_palavra.h"
#include "Consulta_Base_Arquivos.h"
#include "Forma_da_Busca.h"

using namespace std;

/*! 
 *  Esse programa é um pesquisador de palavras num sistema de arquivos
*/

#define VERSION "scs_1.0"

#define no_argument 0
#define required_argument 1
#define optional_argument 2

int main(int argc, char * argv[]) {
    
    Tabela_Hash Tabela_controle_Hash;			//Nomes Claros e Significativos
    Hash tab;
    ARQUIVO *arquivo = (ARQUIVO*) new ARQUIVO;
    LISTA *lista_de_arquivos = (LISTA*) new LISTA;
    lista_de_arquivos->ini->arquivo = (ARQUIVO*) new ARQUIVO; 

    Inicializar_Hash(Tabela_controle_Hash);
    Inicializar_Vetor_arquivo(arquivo);
    Inicializar_Lista(lista_de_arquivos);
    
	bool timer = false;					
    clock_t tempoInicial, tempoFinal;
    double tempo_gasto;
    
    int index;
    int Controle_do_Menu=0;
    bool Ajuda_Flag = false;
    
    const struct option longopts[] = {
    
    {"Exibir_Menu_Ajuda",       no_argument,        0, 'h'},

    {"Inserir_Arquivo",     required_argument,  0, 'i'},                //modo de gerencialmente
    {"Remover_Arquivo",      required_argument,  0, 'r'},
    {"Listar_Base_Arquivo_por_Insercao",      no_argument,        0, 'e'},
    {"Listar_Base_Arquivo_por_Ordem_Alfabetica",      no_argument,        0, 'a'},
    {"Listar_Base_Arquivo_por_Quantidade_Palavras",    no_argument,  0, 'p'},

    {"Pesquisa_AND",      required_argument,        0, 'd'},          //modo de busca
    {"Pesquisa_OR",       required_argument,        0, 'o'},
    {"Exibir_resultados_Por_Ordem_Alfabetica",      no_argument,        0, 'b'},
    {"Exibir_resultados_Por_Quantidade_Palavras",       no_argument,        0, 'q'},
    {"Exibir_resultados_Por_Ordem_Insercao",    no_argument,  0, 'c'},

    {"Apresentar_Tempo_De_Busca",     no_argument,  0, 's'},
    {"Nao_Apresentar_Tempo_De_Busca",      no_argument,  0, 'n'},
    {0,0,0,0},
    };

      if( argc < 2) {
            Imprimir_Ajuda();
        }

  //desativa as mensagens de erro do getopt
    opterr=0;

    while(Controle_do_Menu != -1) {
      
    	Controle_do_Menu = getopt_long(argc, argv, "hi:r:eapd:o:bqcsn", longopts, &index);

    	switch (Controle_do_Menu) {

      		case '?':      // erro - opcao desconhecida
            	std::cout << "Opcao " << (char) optopt << " eh invalida." << std::endl;
            	break;
            
      		case -1:      // erro - opcao desconhecida
            	std::cout << "Fim da linha de comando." << std::endl;
            	tempoFinal = clock();
            	break;

      		case 'h':        
        		if (Ajuda_Flag) {
            		std::cout << "Flag 'h' repetida" << std::endl;
            		break;
        		}
        
        		Ajuda_Flag = true;
        		Imprimir_Ajuda();
        		break;

      		case 'i':     //inserir arquivo
        		std::cout << "Tentando inserir arquivo no banco de arquivos. "  << std::endl;

        		if(Dados_Arquivo(Tabela_controle_Hash,arquivo, optarg) != 0) {
        			
	            	cout << "Tentando inserir o arquivo: " << optarg << endl;
	            	
	              	Escreve_No_Log_Palavra(arquivo, Tabela_controle_Hash);
	              	Escreve_No_Log_Arquivo(arquivo);
	              	Escreve_No_Log_Controle(arquivo);
	        	}
              
        		cout << endl;
        		index = optind;

		        if (argv[index] != NULL  && argv[index][0]!='-') {
		            
		            while(index < argc && argv[index][0]!='-') {
		                
		                cout << "Tentando inserir o arquivo " << argv[index] << endl;
		                
		                if(Dados_Arquivo(Tabela_controle_Hash,arquivo, argv[index]) != 0) {
		                    
		                      Escreve_No_Log_Palavra(arquivo, Tabela_controle_Hash);
		                      Escreve_No_Log_Arquivo(arquivo);
		                      Escreve_No_Log_Controle(arquivo);
		                }
		                      
		                cout << endl;
		                index++;
		            }
		            optind = index-1;
		        }
		        break;

	         case 'r':       // remover arquivo
	        	cout << "Tentando remover o arquivo " << optarg << endl;
	        
	        	Remove_Log_Controle(optarg);
	        
	        	index = optind;
	        	cout << endl;
	        
		        if (argv[index] != NULL  && argv[index][0]!='-') {
		
		            while(index < argc && argv[index][0]!='-') {
		                
		                cout << "Tentando remover o arquivo " << argv[index] << endl;
		                Remove_Log_Controle(argv[index]);
		                index++;
		                cout << endl;
		            }
		            optind = index-1;
		            cout << endl;
		        }
		        break;
	
	      	case 'e':        																	//EVITE COMENTÁRIOS DESNECESSÁRIOS 
	        	std::cout << "Listar banco de arquivos por ordem de insercao: " << std::endl;
	        	Consulta_Base_Insercao();
	
	      	case 'a':         
	        	std::cout << "Listar banco de arquivos por ordem alfabética" << std::endl;
	        	Consulta_Base_Alfabetica();
	        	break;
	
	      	case 'p':         
	        	std::cout << "Listar banco de arquivos por ordem de palavras: " << std::endl;
	        	Consulta_Base_Quantidade_Palavras();
	        	break;

      		case 'd':         // busca feita com and
		        std::cout << "Argumento and: "  << std::endl;
		        
		        Consulta_Palavra(optarg, tab);
		        Apresentar_Lista_Frase(tab, optarg);
		        
		        index = optind;
		        
		        if (argv[index] != NULL  && argv[index][0]!='-') {
		            while(index < argc && argv[index][0]!='-') {
		    
		                index++;
		            }
		            optind = index-1;
		        }
		        break;

      		case 'o':             // busca feita com or
		        std::cout << "Argumento or" << std::endl;
		        
		        Consulta_Palavra(optarg, tab);
		        Apresentar_Lista_Frase(tab, optarg);
		        
		        index = optind;
		        
		        if (argv[index] != NULL  && argv[index][0]!='-') {
		            while(index < argc && argv[index][0]!='-') {
		                index++;
		            }
		            optind = index-1;
		        }
		        break;

	      	case 'b':            
	        	std::cout << "Imprimir ordem alfabetico: " << std::endl;
	        	break;
	        
	      	case 'q':         
	        	std::cout << "Imprimir decrescente de vezes que a palavra aparece: " << std::endl;
	        	break;
        
      		case 'c':         
        		std::cout << "Imprirmir na ordem de inserção: "  << std::endl;
        		break;
        
		    case 's':           
		        std::cout << "Registra o tempo: " << std::endl;
		        tempoInicial = clock();
		        timer = true;
		        break;
        
		    case 'n':           
		        std::cout << " Não Registra o tempo " << std::endl;
		        timer = false;
		        break;
    	}	
   }

    if(timer == true) {
    
	tempo_gasto = double (tempoFinal - tempoInicial) /CLOCKS_PER_SEC;
    cout << "O tempo gasto foi de:" << tempo_gasto  << endl;
    }

  return 0;
}
