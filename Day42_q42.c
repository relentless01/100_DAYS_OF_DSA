/*Problem Statement:
Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue
*/

#include <stdio.h>

#define MAX 100

int queue[MAX];
int stack[MAX];

int front = 0, rear = -1;
int top = -1;

// enqueue
void enqueue(int x)
{
    rear++;
    queue[rear] = x;
}

// push into stack
void push(int x)
{
    top++;
    stack[top] = x;
}

// pop from stack
int pop()
{
    return stack[top--];
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &queue[i]);
        rear++;
    }

    // move queue elements to stack
    for(int i = front; i <= rear; i++)
    {
        push(queue[i]);
    }

    // move back to queue
    for(int i = front; i <= rear; i++)
    {
        queue[i] = pop();
    }

    printf("Reversed Queue: ");

    for(int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    printf("\n");

    return 0;
}