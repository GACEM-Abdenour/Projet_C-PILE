#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define some constants
#define SCREEN_WIDTH 1000 
#define SCREEN_HEIGHT 700    
#define MAX_ELEMENTS 10 
#define ELEMENT_WIDTH 100 // Width of each element in the stack
#define ELEMENT_HEIGHT 50 // Height of each element in the stack
#define ELEMENT_GAP 10 // Gap between each element in the stack
#define BUTTON_WIDTH 150 // Width of each button
#define BUTTON_HEIGHT 50 // Height of each button
#define BUTTON_GAP 20 // Gap between each button
#define FONT_SIZE 20 // Font size for the text
    
// Define some colors
#define BACKGROUND_COLOR BLACK // Background color
#define ELEMENT_COLOR WHITE // Element color
#define BUTTON_COLOR DARKGRAY // Button color
#define TEXT_COLOR BLACK // Text color
#define MAX_COLOR RED // Color for highlighting the maximum element and button
#define MIN_COLOR BLUE // Color for highlighting the minimum element and button


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
void DrawStack(Stack *stack); // Draw the stack on the screen
void DrawButtons(Stack *stack); // Draw the buttons on the screen
void UpdateStack(Stack *stack); // Update the stack based on user input


// Main function
int main(void)
{

    // Initialize the window
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Primitive Pile Visualization");

    // Initialize the stack
    Stack stack;
    InitStack(&stack);

    // testing the git 1
    // Set the target FPS
    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update the stack
        UpdateStack(&stack);
    

        // Begin drawing
        BeginDrawing();

        // Clear the background
        ClearBackground(BACKGROUND_COLOR);

        // Draw the stack
        DrawStack(&stack);

        // Draw the buttons
        DrawButtons(&stack);

        

        // End drawing
        EndDrawing();
    }

    // Close window and OpenGL context
    CloseWindow();

    return 0;
}


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


// Peek the top value of the stack
int Peek(Stack *stack)
{
    int value = -1; // Initialize the value to -1
    if (!IsEmpty(stack)) // Check if the stack is not empty
    {
        value = stack->data[stack->top]; // Get the value at the top index
    }
    return value; // Return the value
}



// Check if the stack is empty
bool IsEmpty(Stack *stack)
{
    return (stack->top == -1); // Return true if the top index is -1
}


// Check if the stack is full
bool IsFull(Stack *stack)
{
    return (stack->top == MAX_ELEMENTS - 1); // Return true if the top index is the maximum index
}


// Get the maximum value in the stack
int GetMax(Stack *stack)
{
    int max = -1; // Initialize the maximum value to -1
    if (!IsEmpty(stack)) // Check if the stack is not empty
    {
        max = stack->data[0]; // Set the maximum value to the first element
        for (int i = 1; i <= stack->top; i++) // Loop through the rest of the elements
        {
            if (stack->data[i] > max) // If the current element is greater than the maximum value
            {
                max = stack->data[i]; // Update the maximum value
            }
        }
    }
    return max; // Return the maximum value
}


// Get the minimum value in the stack
int GetMin(Stack *stack)
{
    int min = -1; // Initialize the minimum value to -1
    if (!IsEmpty(stack)) // Check if the stack is not empty
    {
        min = stack->data[0]; // Set the minimum value to the first element
        for (int i = 1; i <= stack->top; i++) // Loop through the rest of the elements
        {
            if (stack->data[i] < min) // If the current element is less than the minimum value
            {
                min = stack->data[i]; // Update the minimum value
            }
        }
    }
    return min; // Return the minimum value
}





