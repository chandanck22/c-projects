#include <stdlib.h>
#include <stdio.h>
#include "linked-list.h"
#include "stack.h"


int main()
{
        int choice;
        // LINKED LIST
        int list_choice;
        // STACK
        int stack_choice, stack_item;
        struct Stack *stack;

        while(1)
        {
            printf("\n1.) Linked List: ");
            printf("\n2.) Stack\n");
            printf("3.) Exit\n");
            printf("\nEnter Your Choice: ");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1:
                while(1){

                        printf("\n\n                MENU                             \n");
                        printf("\n 1.Create     \n");
                        printf("\n 2.Display   \n");
                        printf("\n 3.Insert at the beginning    \n");
                        printf("\n 4.Insert at the end  \n");
                        printf("\n 5.Insert at specified position       \n");
                        printf("\n 6.Delete from beginning      \n");
                        printf("\n 7.Delete from the end        \n");
                        printf("\n 8.Delete from specified position     \n");
                        printf("\n 9.Exit       \n");
                        printf("\n--------------------------------------\n");
                        printf("\nEnter your choice:\t");
                        scanf("%d",&list_choice);
                        switch(list_choice)
                        {
                                case 1:
                                                create();
                                                break;
                                case 2:
                                                displayLinked();
                                                break;
                                case 3:
                                                insertAtHead();
                                                break;
                                case 4:
                                                insertAtEnd();
                                                break;
                                case 5:
                                                insertAtPosition();
                                                break;
                                case 6:
                                                deleteAtBegin();
                                                break;
                                case 7:
                                                deleteAtEnd();
                                                break;
                                case 8:
                                                deleteAtPosition();
                                                break;

                                case 9:
                                                exit(0);
                                                break;

                                default:
                                                printf("Invalid choice.\n");
                                                break;
                        }
                }
                break;

                case 2:
                while (1)
                {
                    printf("\n1. Create Stack. \n2. Push\n3. Pop\n4. Display\n5. Peek\n6. isEmpty\n7. isFull\n8. Top\n9. Exit\n");
                    printf("\n--------------------------------------\n");
                    printf("Enter your choice: ");
                    scanf("%d", &stack_choice);
                    switch (stack_choice) {
                        case 1:
                            createStack();
                        case 2:
                            printf("Enter data to push: ");
                            scanf("%d", &stack_item);
                            push(stack, stack_item);
                            break;
                        case 3:
                            pop(stack);
                            break;
                        case 4:
                            displayStack(stack);
                            break;
                        case 5:
                            printf("Top element is: %d\n", peek(stack));
                            break;
                        case 6:
                            if (isEmpty(stack)) {
                                printf("Stack is empty.\n");
                            } else {
                                printf("Stack is not empty.\n");
                            }
                            break;
                        case 7:
                            if (isFull(stack)) {
                                printf("Stack is full.\n");
                            } else {
                                printf("Stack is not full.\n");
                            }
                            break;
                        case 8:
                            if (isEmpty(stack)) {
                                printf("Stack is empty.\n");
                                break;
                            }
                            printf("Top element is: %d\n", stack->array[stack->top]);
                            break;
                        case 9:
                            printf("Exiting from program.\n");
                            exit(0);
                        default:
                            printf("Invalid choice.\n");
                    }
                }

                break;

                case 3:
                    exit(0);
                    break;

            }
        }

        return 0;
}
