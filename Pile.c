#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>





// Define a struct for the stack
typedef struct Stack {
    int data[MAX_ELEMENTS]; // Array to store the data of the elements
    int top; // Index of the top element
    bool highlightMax; // Flag to indicate whether to highlight the maximum element
    bool highlightMin; // Flag to indicate whether to highlight the minimum element
    char inputValue[16]; // User input value as a string
    bool inputActive; // Flag to indicate if the user is entering a value
} Stack;




// Function prototypes
void InitStack(Stack *stack); // Initialize the stack
void Push(Stack *stack, int value); // Push a value to the stack
int Pop(Stack *stack); // Pop a value from the stack
int Peek(Stack *stack); // Peek the top value of the stack
bool IsEmpty(Stack *stack); // Check if the stack is empty
bool IsFull(Stack *stack); // Check if the stack is full
int GetMax(Stack *stack); // Get the maximum value in the stack
int GetMin(Stack *stack); // Get the minimum value in the stack




// Initialize the stack
void InitStack(Stack *stack)
{
    stack->top = -1; // Set the top index to -1
    stack->highlightMax = false; // Set the highlightMax flag to false
    stack->highlightMin = false; // Set the highlightMin flag to false
}





// Push a value to the stack
void Push(Stack *stack, int value)
{
    if (!IsFull(stack)) // Check if the stack is not full
    {
        stack->top++; // Increment the top index
        stack->data[stack->top] = value; // Store the value at the top index
    }
}




// Pop a value from the stack
int Pop(Stack *stack)
{
    int value = -1; // Initialize the value to -1
    if (!IsEmpty(stack)) // Check if the stack is not empty
    {
        value = stack->data[stack->top]; // Get the value at the top index
        stack->top--; // Decrement the top index
    }
    return value; // Return the value
}





