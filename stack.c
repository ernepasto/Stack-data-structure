#include <stdio.h>
#include <stdlib.h>
//#include <limits.h>

struct Stack {
    int top; // Indicatore della posizione del primo elemento nello stack
    unsigned capacity; // Capacità dello stack
    int *array; // Puntatore all'array di elementi presenti nello stack
};

/* Funzione per la creazione dello stack della capacità passata come parametro */
struct Stack * createStack(unsigned capacity) {
    
    // Allocazione della memoria per lo stack
    struct Stack *stack = (struct Stack *) calloc(1, sizeof(struct Stack));

    // Inizializzazione dei valori dello stack
    stack->capacity = capacity;
    stack->top = -1;

    // Allocazione della memoria per l'array che conterrà i valori dello stack
    stack->array = (int *) calloc(capacity, sizeof(int));

    return stack;
};

/* Funzione per controllare se lo stack è pieno */
int isFull(struct Stack *stack) {
    return (stack->top == stack->capacity - 1) ? 1 : 0;
};

/* Funzione per controllare se lo stack è vuoto */
int isEmpty(struct Stack *stack) {
    return (stack->top == -1) ? 1 : 0;
};

/* Funzione per inserire un elemento nello stack */
void push(struct Stack *stack, int number) {
    
    if (isFull(stack)) {
        printf("\nThe stack is full!");
        return;
    }

    // Il primo elemento aumenta di uno
    stack->top = stack->top + 1;

    // Inseriento dell'elemento nell'array che rappresenta lo stack
    stack->array[stack->top] = number;

    printf("\n%d pushed to stack", number);

};

// Funzione per rimuovere il primo elemento in cima allo stack
void pop(struct Stack *stack) {

    if (isEmpty(stack)) {
        printf("\nThe stack is empty!");
        return;
    }

    // Rimozione dell'elemento dall'array che rappresenta lo stack
    int number = stack->array[stack->top];
    stack->array[stack->top] = 0;

    // Il primo elemento diminuisce di uno
    stack->top = stack->top - 1;

    printf("\n%d removed from stack", number);

};

// Funzione per stampare l'intero stack
void print(struct Stack *stack) {

     if (isEmpty(stack)) {
        printf("\nThe stack is empty!");
        return;
    }

    int i = 0;
    printf("\n");

    while(i < stack->capacity) {
        printf("\n%d", stack->array[i]);
        i++;
    }
};

int main() {

    // Creazione di un nuovo stack
    struct Stack *stack = createStack(3);
    
    push(stack, 1);
    push(stack, 100);
    push(stack, 1000);

    pop(stack);
    push(stack, 2000);

    push(stack, 3000); 

    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);

    print(stack);

    // Liberazione della memoria utilizzata per lo stack
    free(stack);

    return 0;
};