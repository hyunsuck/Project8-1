#include<stdio.h>
#include<conio.h>
#define SIZE 5

void enQueue(int);
void deQueue();
void display();

int cQueue[SIZE], front = -1, rear = -1;

void main()
{
    int choice, value;
    while (1) {
        printf("\n****** MENU ******\n");
        printf("1. Input data and Enqueue\n2. Dequeue and Print data\n3. Print Queue\n4. Exit\n");
        printf("Select Number: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1: printf("\nInput the data :  ");
            scanf("%d", &value);
            enQueue(value);
            break;
        case 2: deQueue();
            break;
        case 3: display();
            break;
        case 4: exit(0);
        default: printf("\nPlease select the correct choice!!!\n");
        }
    }
}
void enQueue(int value)
{
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1))
        printf("\nQueue is Full!\n");
    else {
        if (rear == SIZE - 1 && front != 0)
            rear = -1;
        cQueue[++rear] = value;
        if (front == -1)
            front = 0;
    }
}
void deQueue()
{
    if (front == -1 && rear == -1)
        printf("\nQueue is Empty!\n");
    else {
        printf("\nDequeue : %d\n", cQueue[front++]);
        if (front == SIZE)
            front = 0;
        if (front - 1 == rear)
            front = rear = -1;
    }
}
void display()
{
    if (front == -1)
        printf("\nQueue is Empty!!!\n");
    else {
        int i = front;
        printf("\nQueue(front =1 rear = 4) : \n");
        if (front <= rear) {
            while (i <= rear)
                printf("%d\t", cQueue[i++]);
        }
        else {
            while (i <= SIZE - 1)
                printf("%d\t", cQueue[i++]);
            i = 0;
            while (i <= rear)
                printf("%d\t", cQueue[i++]);
        }
    }
}