#include <stdio.h>
#include <stdlib.h>

// Node structure for circular doubly linked list
struct node
{
    int data;
    struct node *next;
    struct node *prev; // Pointer to the previous node
};

struct node *head = NULL;

// Function to display the circular doubly linked list
void display()
{
    if (head != NULL)
    {
        struct node *temp = head;
        printf("Display circular doubly linked list elements: ");
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    }
    else
    {
        printf("List is not created\n");
    }
}

// Function to create the circular doubly linked list
void create_list()
{
    struct node *temp, *new;
    int n;

    if (head == NULL)
    {
        head = (struct node *)malloc(sizeof(struct node)); // Allocate memory for the first node
        printf("Enter element: ");
        scanf("%d", &n);
        head->data = n;
        head->next = head; // Point to itself
        head->prev = head; // Point to itself
        temp = head;

        while (1)
        {
            printf("If you want to enter more elements press 1: ");
            scanf("%d", &n);
            if (n == 1)
            {
                new = (struct node *)malloc(sizeof(struct node)); // Allocate memory for the new node
                printf("Enter element: ");
                scanf("%d", &n);
                new->data = n;
                new->next = head;    // Point the new node's next to head (circular nature)
                new->prev = temp;    // Set the previous pointer to the current last node
                temp->next = new;    // Update the current last node's next to the new node
                head->prev = new;    // Update the head's previous pointer to the new node
                temp = new;          // Move temp to the new node
            }
            else
            {
                break;
            }
        }
    }
    else
    {
        printf("Already created linked list\n");
    }
}

void insert_at_first()
{
    if (head != NULL)
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        int n;
        printf("Enter element: ");
        scanf("%d", &n);
        new->data = n;
        new->next = head;
        new->prev = head->prev;     // Point the new node's prev to the last node
        head->prev->next = new;     // Last node's next points to the new node
        head->prev = new;           // Update head's prev to new
        head = new;                 // Update head to the new node
    }
    else
    {
        printf("Please first create_list, then insert element\n");
    }
}

void delete_at_first()
{
    if (head != NULL)
    {
        struct node *temp = head;
        if (head->next == head) // Only one element
        {
            head = NULL;
        }
        else
        {
            head->prev->next = head->next; // Last node points to the second node
            head->next->prev = head->prev; // Second node's prev points to last node
            head = head->next;             // Update head to the second node
        }
        printf("%d element is deleted\n", temp->data);
        free(temp);
    }
    else
    {
        printf("Please first create_list, then delete element\n");
    }
}

void insert_at_last()
{
    if (head != NULL)
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        int n;
        printf("Enter element: ");
        scanf("%d", &n);
        new->data = n;
        new->next = head;           // New node's next points to head
        new->prev = head->prev;     // New node's prev points to the current last node
        head->prev->next = new;     // Last node's next points to the new node
        head->prev = new;           // Head's prev points to the new node
    }
    else
    {
        printf("Please first create_list, then insert element\n");
    }
}

void delete_at_last()
{
    if (head != NULL)
    {
        struct node *temp = head->prev; // Last node
        if (temp == head) // Only one element
        {
            head = NULL;
        }
        else
        {
            temp->prev->next = head; // Second last node's next points to head
            head->prev = temp->prev; // Head's prev points to second last node
        }
        printf("%d element is deleted\n", temp->data);
        free(temp);
    }
    else
    {
        printf("Please first create_list, then delete element\n");
    }
}

// Other functions like insert_at_index, delete_at_index, search_element can follow similarly

int main()
{
    int num;

    while (1)
    {
        printf("\nWelcome to my Circular Doubly Linked List Program:\n");
        printf("Press 1 to create list\n");
        printf("Press 2 to display\n");
        printf("Press 3 to insert element at the first\n");
        printf("Press 4 to delete element at the first\n");
        printf("Press 5 to insert element at last\n");
        printf("Press 6 to delete element at the last\n");
        printf("Press 10 to exit\n");
        scanf("%d", &num);

        switch (num)
        {
        case 1:
            create_list(); // Pass the address of the head pointer
            break;
        case 2:
            display(); // Display the circular doubly linked list
            break;
        case 3:
            insert_at_first();
            break;
        case 4:
            delete_at_first();
            break;
        case 5:
            insert_at_last();
            break;
        case 6:
            delete_at_last();
            break;
        case 10:
            exit(0); // Exit the program
        default:
            printf("Entered wrong number\n");
            break;
        }
    }

    return 0;
}
