/** @file symbol_table.h
 *  @version 1.1

#define PRIME 211 // 9901

/**
 * Tipo abstrato das entradas na tabela de Hash. (Obs.: futuramente, os campos
 * dessa struct poderao vir a ser alterados em funcao das necessidades.)
 * Na Etapa 1, nao e necessario entender o conteudo desses campos.
 * Sempre vao ser inseridos na tabela, e recuperado dela, ponteiros sobre tais
 * estruturas de dados abstratas.
 */
 #include <string.h>
 #include "symbol_table.h"
 #define PRIME 211 
 


/** \brief Inicializar a tabela de Hash.
 *
 * @param table, uma referencia sobre uma tabela de simbolos.
 * @return o valor 0 se deu certo.
 */
int init_table(symbol_t* table){

	
  	int x = 0;
    for(x = 0; x < PRIME; x++) {
        table->entries[x] = NULL;

    }
    return 0;
  	

}

/** \brief Destruir a tabela de Hash.
 *
 * 'free_table' eh o destrutor da estrutura de dados. Deve ser chamado pelo 
 * usuario no fim de seu uso de uma tabela de simbolos.
 * @param table, uma referencia sobre uma tabela de simbolos.
 */
void free_table(symbol_t* table){
	
	
}

int hpjw(void *key)
{
	char	*ptr;
	int		val = 0;
	ptr = (char *) key;
	while (*ptr != '\0') 
	{
		int tmp;
		val = (val << 4) + (*ptr);
		if ((tmp = (val & 0xf0000000)))
		{
			val = val ^ (tmp >> 24);
			val = val ^ tmp;
		}
		ptr++;
	}
	
	val = abs(val);
	
	return val  % PRIME;
}

/** \brief Retornar um ponteiro sobre a entrada associada a 'name'.
 *
 * Essa funcao deve consultar a tabela de simbolos para verificar se se encontra
 * nela uma entrada associada a um char* (string) fornecido em entrada. Para
 * a implementacao, sera necessario usar uma funcao que mapeia um char* a
 * um numero inteiro. Aconselha-se, por exemplo, consultar o livro do dragao
 * (Aho/Sethi/Ulman), Fig. 7.35 e a funcao HPJW.
 *
 * @param table, uma tabela de simbolos.
 * @param name, um char* (string).
 * @return um ponteiro sobre a entrada associada a 'name', ou NULL se 'name'
 *         nao se encontrou na tabela.
 */
 

entry_t* lookup(symbol_t table, char* name){
	int indice = hpjw(name);
	
	
	if(table.entries[indice] == NULL){
		return NULL;
	}	
	
	
	else{
		struct table_node_entry * aux_table = table.entries[indice];
				
		while(1){
			
			if((strcmp(aux_table->entry_data->name,name))== 0){
				return aux_table->entry_data;
			}
			else if(aux_table->next == NULL){
				break;
			}
			else{	
				aux_table = aux_table->next;
			}
		}
		
		return NULL;
	}	
	return NULL;
	
}

/** \brief Inserir uma entrada em uma tabela.
 *
 * @param table, uma tabela de simbolos.
 * @param entry, uma entrada.
 * @return um numero negativo se nao se conseguiu efetuar a insercao, zero se
 *   deu certo.
 */
int insert(symbol_t *table, entry_t *entry){
	int indice = hpjw(entry->name) ;
	
	
	if(lookup(*table, entry->name) != NULL){
		return -1;
	}
	
	struct table_node_entry *novo = malloc(sizeof(struct table_node_entry));
	novo->entry_data = entry;
	novo->next = NULL;
	
	

    if(table->entries[indice] == NULL) {
        table->entries[indice] = novo;
        
    } else {
        novo->next = table->entries[indice]; 
        table->entries[indice] = novo; 
        
    }
    
	return 0;
}

/** \brief Imprimir o conteudo de uma tabela.
 *
 * A formatacao exata e deixada a carga do programador. Deve-se listar todas
 * as entradas contidas na tabela atraves de seu nome (char*). Deve retornar
 * o numero de entradas na tabela.
 *
 * @param table, uma tabela de simbolos.
 * @return o numero de entradas na tabela.
 */
int print_table(symbol_t table){

	for(int i= 0; i<PRIME; i++){
		if(table.entries[i] != NULL){
			printf(" Achou: %i\n",i);
			struct table_node_entry* aux_table = table.entries[i];
			while(1){
				printf("Item: %s\n",aux_table->entry_data->name);	
				if(aux_table->next == NULL){
					break;
				}
				aux_table = aux_table->next;
			}
			printf(" --------------------------\n");
		}	
	}
}

/** \brief Imprimir o conteudo de uma tabela em um arquivo.
 *
 * A formatacao exata e deixada a carga do programador. Deve-se listar todas
 * as entradas contidas na tabela atraves de seu nome (char*). Deve retornar
 * o numero de entradas na tabela. A saida deve ser dirigida para um arquivo,
 * cujo descritor e passado em parametro.
 *
 * @param out, um descrito de arquivo (FILE*).
 * @param table, uma tabela de simbolos.
 * @return o numero de entradas na tabela.
 */
int print_file_table(FILE* out, symbol_t table);


