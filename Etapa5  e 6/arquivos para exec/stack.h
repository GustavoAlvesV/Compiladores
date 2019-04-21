#ifndef __STACK_H__
#define __STACK_H__

#include <stdlib.h>
#include <stdio.h>

/** @file stack.h
 *  @version 2.0
 */



/** \brief Declaração da estrutura nodo da pilha
 */

typedef struct stack_node
    {
	struct stack_node* previous;
	void* item;
    } stack_node;

typedef stack_node *stack;




void init_stack(stack* s);

void free_stack(stack* s);

int empty(stack s);

int push(stack* s, void* item);

void* pop(stack* s);

void* top(stack s);

#endif
