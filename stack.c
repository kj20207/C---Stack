#include <stdio.h>
#include <stdlib.h>
 
typedef struct stack_node{
	int value;
	struct stack_node *next;
               
} stack_node;
 
struct stack{
	int size;
	struct stack_node *head;
};
 
 
int stack_initialize(struct stack **stack);
 
int stack_push(struct stack **stack, int value);
 
int stack_peek(struct stack **stack);
 
int stack_pop(struct stack **stack);
 
int stack_size(struct stack **stack);
 
int stack_destroy(struct stack **stack);
 
 
void main(){
 
	struct stack *stack;
	stack_initialize(&stack);
	printf("Size %d\n", stack->size);
	
	int i;
	printf("Push values\n");
	for(int i = 1; i <= 5; i++){
		stack_push(&stack, i);
		int peek = stack_peek(&stack);
		printf("%d ", peek);
	}
	printf("Size %d\n", stack->size);
	
	printf("Pop values\n");
	for(int i = 1; i <= 6; i++){
		int removed = stack_pop(&stack);
		int size = stack_size(&stack);
		printf("%d ", removed);
	}
	printf("Size %d\n", stack->size);
	//stack_destroy(&stack);
}
 
 
 
 
 
 
int stack_initialize(struct stack **stack){
	*stack = malloc(sizeof(struct stack));
	(*stack)->size = 0;
	(*stack)->head = NULL;
}
 
int stack_push(struct stack **stack, int value){
	struct stack_node *node;
	node = malloc(sizeof(struct stack_node));
	node->value = value;

	if(stack_size(stack) > 0){
		node->next = (*stack)->head;
	}
	else{
		node->next = NULL;
	}
   
	(*stack)->head = node;
	(*stack)->size += 1;

	return 1;
}
 
int stack_peek(struct stack **stack){
	if(stack_size(stack) > 0){
		return (*stack)->head->value;
	}
	else return -1;
}
 
int stack_pop(struct stack **stack){
 
	if(stack_size(stack) == 0)
					return -1;


	int popped = (*stack)->head->value;
   
	struct stack_node *temp;
	temp = (*stack)->head;

	if(stack_size(stack) > 1){
		(*stack)->head = (*stack)->head->next;
		free(temp);
	}
	else{
		free(temp);
		(*stack)->head = NULL;
	}

	(*stack)->size -= 1;

	return popped;
               
}
 
int stack_size(struct stack **stack){
	return (*stack)->size;
}
 
int stack_destroy(struct stack **stack){
	while(stack_size(stack) > 0){
		stack_pop(stack);
	}
	free(*stack);
}