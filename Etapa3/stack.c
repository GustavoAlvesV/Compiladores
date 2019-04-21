#include "stack.h"

/** @file stack.h
 *  @version 2.0
 */

/**  \brief Inicializar a pilha.
 *          Uso tipico: init_stack(&minha_pilha);
 *
 * Inicializa a pilha, alocando qualquer espaco na memoria que seja
 * necessario. Nao se deve efetuar nenhuma hipotese restritiva quanto ao numero
 * total de entradas que podera conter a pilha num dado instante.
 * 'init_stack' devera ser chamado pelo usuario deste estrutura de dados,
 * antes de poder usa-la. Qualquer referencia anterior que ele possa fazer a
 * uma pilha tera comportamento nao-especificado.
 *
 * @param s um ponteiro sobre uma pilha (stack*).
 * @return nada (void).
 */
 
void init_stack(stack* s){
    *s = (stack)malloc(sizeof(stack_node));
    (*s)->previous = NULL;
    (*s)->item = NULL;
}

/**  \brief Liberar a memoria usada pela pilha.
 *          Uso tipico: free_stack(&minha_pilha);
 *
 * 'free_stack' eh o destrutor da estrutura de dados de pilha. Deve liberar
 * qualquer espaco na memoria que tenha sido alocado para a implementacao
 * interna da pilha passada em argumento. Um acesso a uma pilha, depois da
 * chamada a 'free_stack' levara a um erro na execucao.
 *
 * @param s um ponteiro sobre uma pilha (stack*).
 * @return nada (void).
 */




void free_stack(stack* s)
{
	free(*s);
}

/** \brief Testar se a pilha esta vazia.
 *
 * Testa se a pilha esta vazia.
 * @param s  - uma pilha
 * @return
 *    - 0 se a pilha nao esta vazia,
 *    - um valor diferente de zero se a pilha esta vazia.
 */

int empty(stack s)
{
    if(s->previous == NULL){
        return(1);
    }
    else{
        return(0);
    }
}

/** \brief Empilhar um elemento na pilha.
 *         (O tipo do elemento é void *.)
 *
 * Empilha um elemento na pilha.
 * @param s, uma referencia sobre a pilha onde se deve inserir o elemento.
 * @param item, uma referencia sobre o elemento a ser inserido.
 * @return 0 se a insercao deu certo.
 */

int push(stack *s, void *item)
{
	stack Nova;
	init_stack(&Nova);
        Nova->item = item;
    	Nova->previous = *s;
    	*s = Nova;
    	if((*s) -> item == item){
	 return 0;
	 }
	 else return 1;
}

/** \brief Desempilhar o elemento no topo da pilha.
 *
 *  Desempilhaz o elemento no topo da pilha, e retorna-o. Remove este elemento
 *  da pilha.
 *  @param s, um ponteiro sobre a pilha de onde se deve tirar um elemento.
 *  @return o elemento que foi desempilhado, ou NULL se nao tinha como
 *  desempilhar alguma coisa.
 */

void* pop(stack* s)
{
	void* 	saiu;
	stack aux;
	
	if(empty(*s))
		return NULL;
		
	saiu = (*s)->item; 
    aux = (*s)->previous;
    free(*s);
    (*s) = aux;
    return saiu;
}

/** \brief Consultar o elemento no topo da pilha.
 *
 *  Retorna um ponteiro sobre o elemento no topo da pilha. Nao remove este
 *  elemento da pilha.
 *  @param s, a pilha de que se deve consultar o topo.
 *  @return o elemento, ou NULL se nao tinha nada no topo.
 */

void* top(stack s)
{
	if(empty(s)){
		return NULL;
	}
	return s->item;
	/*
    while(s -> previous != NULL ){
        printf("\n\n\n TOPO -----   %p", s ->item);
        s = s->previous;
    }
    printf("\n TOPO -----   %d", s ->item);*/
}


