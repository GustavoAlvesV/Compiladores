/** @file symbol_table.h
 *  @version 1.1
 */
#ifndef _SYMBOL_TABLE_H_
#define _SYMBOL_TABLE_H_

#include <stdio.h>
#include <stdlib.h>

#define PRIME 211 // 9901


typedef struct {
   char* name;  /**< um string que representa o nome de uma variavel. */
   double valor;
   int type;    /**< representacao do tipo da variavel. */
   int size;    /**< numero de Bytes necessarios para armazenamento. */
   int desloc;  /**< Endereco da proxima variavel. */
   void* codigo; /**< qualquer informacao extra. */
   int extra; /**< Valor da variável */
} entry_t ;



/** \brief Nodo da lista encadeada de entradas da tabela de simbolos
 *
 * Para cada hash calculado, a tabela de simbolos possui uma lista encadeada.
 * Seriam as entradas que dão conflito, todas mapeadas no indice certo da tabela.
 *
 */
struct table_node_entry {
   entry_t * entry_data;
   struct table_node_entry * next;
};

/** \brief Encapsulacao de um tipo abstrato que se chamara 'symbol_t'
 *
 * Voce deve inserir, entre o 'typedef' e o 'symbol_t', a estrutura de dados
 * abstrata que voce ira implementar.
 *
 */
typedef struct {
    struct table_node_entry* entries[PRIME];
}    /* A COMPLETAR */ symbol_t ;


int init_table(symbol_t* table) ;


void free_table(symbol_t* table) ;

entry_t* lookup(symbol_t table, char* name) ;


int insert(symbol_t* table, entry_t* entry) ;


int print_table(symbol_t table);


int print_file_table(FILE* out, symbol_t table);

#endif
