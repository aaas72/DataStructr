#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


struct Node {
    char data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

// Function to create a new node
struct Node* newNode(char data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

void push(struct Stack* stack, char data) {
    struct Node* node = newNode(data);
    node->next = stack->top;
    stack->top = node;
}

char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Error: Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    struct Node* temp = stack->top;
    char data = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

char peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Error: Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return stack->top->data;
}

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

char* infixToPostfix(char* infix) {
    struct Stack* stack = createStack();
    int length = strlen(infix);
    char* postfix = (char*)malloc((length + 1) * sizeof(char));
    int j = 0; // Index for postfix expression

    for (int i = 0; infix[i] != '\0'; i++) {
        if (isdigit(infix[i])) {
            postfix[j++] = infix[i];
        }

        else if (infix[i] == '(') {
            push(stack, infix[i]);
        }

        else if (infix[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[j++] = pop(stack);
            }
            if (isEmpty(stack) || peek(stack) != '(') {
                printf("Error: Invalid expression\n");
                exit(EXIT_FAILURE);
            }
            pop(stack);
        }

        else {

            while (!isEmpty(stack) && precedence(infix[i]) <= precedence(peek(stack))) {
                postfix[j++] = pop(stack);
            }

            push(stack, infix[i]);
        }
    }

    while (!isEmpty(stack)) {
        if (peek(stack) == '(') {
            printf("Error: Invalid expression\n");
            exit(EXIT_FAILURE);
        }
        postfix[j++] = pop(stack);
    }

    postfix[j] = '\0';
    return postfix;
}

int evaluatePostfix(char* postfix) {
    struct Stack* stack = createStack();
    int length = strlen(postfix);

    for (int i = 0; i < length; i++) {
        if (isdigit(postfix[i])) {
            push(stack, postfix[i] - '0');
        }
        else {
            int operand2 = pop(stack);
            int operand1 = pop(stack);
            switch (postfix[i]) {
                case '+':
                    push(stack, operand1 + operand2);
                    break;
                case '-':
                    push(stack, operand1 - operand2);
                    break;
                case '*':
                    push(stack, operand1 * operand2);
                    break;
                case '/':
                    if (operand2 == 0) {
                        printf("Error: Division by zero\n");
                        exit(EXIT_FAILURE);
                    }
                    push(stack, operand1 / operand2);
                    break;
                default:
                    printf("Error: Invalid operator\n");
                    exit(EXIT_FAILURE);
            }
        }
    }


    if (isEmpty(stack) || stack->top->next != NULL) {
        printf("Error: Invalid expression\n");
        exit(EXIT_FAILURE);
    }
    int result = pop(stack);
    free(stack);
    return result;
}

int main() {
    char infix[100];
    printf("Enter an infix expression: ");
    scanf("%s", infix);


    char* postfix = infixToPostfix(infix);
    printf("Postfix expression: %s\n", postfix);

    // Evaluate the postfix expression
    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);

    free(postfix);
    return 0;
}
