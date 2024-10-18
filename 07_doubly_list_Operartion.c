#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
struct node
{
    int data;
    struct node *next;
    struct node *prev; // New pointer to the previous node
};

struct node *head = NULL;

// Function to display the doubly linked list
void display()
{
    if (head != NULL)
    {
        printf("Display doubly linked list elements: ");
        struct node *temp = head;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
    else
    {
        printf("List is not created\n");
    }
}

// Function to create the doubly linked list
void create_list()
{
    struct node *temp, *new;
    int n;

    if (head == NULL)
    {                                                      // Check if the list is empty
        head = (struct node *)malloc(sizeof(struct node)); // Allocate memory for the first node
        printf("Enter element: ");
        scanf("%d", &n);
        head->data = n;
        head->next = NULL;
        head->prev = NULL; // The first node has no previous node
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
                new->next = NULL;
                new->prev = temp; // Set the previous pointer to the current last node
                temp->next = new;
                temp = new;
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
        new->prev = NULL;
        head->prev = new; // Update previous head's prev to the new node
        head = new;       // Update head to the new node
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
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL; // Update the new head's prev to NULL
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
        new->next = NULL;

        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = new;
        new->prev = temp; // Set the previous pointer to the last node
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
        struct node *temp = head;
        if (temp->next != NULL)
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->prev->next = NULL; // Update the second last node's next pointer
            printf("%d element is deleted\n", temp->data);
            free(temp);
        }
        else
        {
            printf("%d element is deleted\n", temp->data);
            free(temp);
            head = NULL;
        }
    }
    else
    {
        printf("Please first create_list, then delete element\n");
    }
}

void insert_at_index()
{
    if (head != NULL)
    {
        int n, index;
    lab:
        printf("Enter index: ");
        scanf("%d", &index);
        if (index == 0)
        {
            insert_at_first();
        }
        else
        {
            struct node *temp = head;
            int p = 0;
            while (temp != NULL)
            {
                temp = temp->next;
                p++;
            }
            if (index > p)
            {
                printf("Please enter index less than %d\n", p + 1);
                goto lab;
            }
            else if (index == p)
            {
                insert_at_last();
            }
            else
            {
                printf("Enter element: ");
                scanf("%d", &n);
                struct node *new;
                new = (struct node *)malloc(sizeof(struct node));
                new->data = n;
                temp = head;
                p = 0;
                while (p < index)
                {
                    temp = temp->next;
                    p++;
                }
                temp->prev->next = new;
                new->prev = temp->prev;
                new->next = temp;
                if (temp != NULL)
                {
                    temp->prev = new;
                }
            }
        }
    }
    else
    {
        printf("Please first create_list, then insert element\n");
    }
}

void delete_at_index()
{
    if (head != NULL)
    {
        int index;
    lab1:
        printf("Enter index: ");
        scanf("%d", &index);
        if (index == 0)
        {
            delete_at_first();
        }
        else
        {
            struct node *temp = head;
            int p = 0;
            while (temp != NULL)
            {
                p++;
                temp = temp->next;
            }
            if (index >= p)
            {
                printf("Please provide index less than %d\n", p);
                goto lab1;
            }
            else if (index == p - 1)
            {
                delete_at_last();
            }
            else
            {
                temp = head;
                p = 0;
                while (p < index)
                {
                    temp = temp->next;
                    p++;
                }
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                printf("Deleted element is %d\n", temp->data);
                free(temp);
            }
        }
    }
    else
    {
        printf("Please first create list, then delete\n");
    }
}

void search_element()
{
    if (head != NULL)
    {
        struct node *temp = head;
        int n;
        printf("Enter element to search in list: ");
        scanf("%d", &n);
        while (temp != NULL)
        {
            if (temp->data == n)
            {
                printf("%d element is found\n", n);
                return;
            }
            temp = temp->next;
        }
        printf("%d element is not found\n", n);
    }
    else
    {
        printf("First create list, then search\n");
    }
}

int main()
{
    int num;

    while (1)
    {
        printf("\nWelcome to my Doubly Linked List Program:\n");
        printf("Press 1 to create list\n");
        printf("Press 2 to display\n");
        printf("Press 3 to insert element at the first\n");
        printf("Press 4 to delete element at the first\n");
        printf("Press 5 to insert element at last\n");
        printf("Press 6 to delete element at the last\n");
        printf("Press 7 to insert element at index\n");
        printf("Press 8 to delete element at index\n");
        printf("Press 9 to search element in list\n");
        printf("Press 10 to exit\n");
        scanf("%d", &num);

        switch (num)
        {
        case 1:
            create_list(); // Pass the address of the head pointer
            break;
        case 2:
            display(); // Display the doubly linked list
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
        case 7:
            insert_at_index();
            break;
        case 8:
            delete_at_index();
            break;
        case 9:
            search_element();
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
