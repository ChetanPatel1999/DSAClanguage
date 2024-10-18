#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
// Function to display the linked list
void display()
{
    if (head != NULL)
    {
        printf("Display linked list elements: ");
        struct node *temp = head;
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

// Function to create the linked list
void create_list()
{
    struct node *temp, *new;
    int n;

    if (head == NULL) // Check if the list is empty
    {
        head = (struct node *)malloc(sizeof(struct node)); // Allocate memory for the first node
        printf("Enter element: ");
        scanf("%d", &n);
        head->data = n;
        head->next = head;
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
                new->next = head;
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
void insert_at_frist()
{
    if (head != NULL)
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        int n;
        struct node *temp = head;
        printf("enter element : ");
        scanf("%d", &n);
        new->data = n;
        new->next = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = new;
        head = new;
    }
    else
    {
        printf("please frist create_list than insert element\n");
    }
}
void delete_at_frist()
{
    if (head != NULL)
    {
        struct node *temp = head;
        struct node *temp2 = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        head = head->next;
        temp->next = head;
        printf("%d element is deleted \n", temp2->data);
        free(temp2);
    }
    else
    {
        printf("please frist create_list than delete element\n");
    }
}
void insert_at_last()
{
    if (head != NULL)
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        int n;
        printf("enter element : ");
        scanf("%d", &n);
        new->data = n;
        new->next = head;
        struct node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = new;
    }
    else
    {
        printf("please frist create_list than insert element\n");
    }
}

void delete_at_last()
{
    if (head != NULL)
    {
        struct node *temp = head, *prev;
        if (temp->next != head)
        {
            while (temp->next != head)
            {
                prev = temp;
                temp = temp->next;
            }
            prev->next = head;
            printf("%d element is deleted \n", temp->data);
            free(temp);
        }
        else
        {
            printf("%d element is deleted \n", temp->data);
            free(temp);
            head = NULL;
        }
    }
    else
    {
        printf("please frist create_list than delete element\n");
    }
}
void insert_at_index()
{
    if (head != NULL)
    {
        int n, index;
    lab:
        printf("enter index : ");
        scanf("%d", &index);
        if (index == 0)
        {
            insert_at_frist();
        }
        else
        {
            struct node *temp = head;
            int p = 0;
            do
            {
                temp = temp->next;
                p++;
            } while (temp != head);
            if (index > p)
            {
                printf("please enter pos less then %d \n", p + 1);
                goto lab;
            }
            else if (index == p)
            {
                insert_at_last();
            }
            else
            {
                printf("enter element : ");
                scanf("%d", &n);
                struct node *prev, *new;
                new = (struct node *)malloc(sizeof(struct node));
                new->data = n;
                new->next = NULL;
                temp = head;
                p = 0;
                while (p < index)
                {
                    prev = temp;
                    temp = temp->next;
                    p++;
                }
                prev->next = new;
                new->next = temp;
            }
        }
    }
    else
    {
        printf("please frist create_list than insert element\n");
    }
}
void delete_at_index()
{
    if (head != NULL)
    {
        int index;
    lab1:
        printf("enter index : ");
        scanf("%d", &index);
        if (index == 0)
        {
            delete_at_frist();
        }
        else
        {
            struct node *temp = head;
            int p = 0;
            do
            {
                p++;
                temp = temp->next;
            } while (temp != head);
            if (index >= p)
            {
                printf("please provide pos less then %d\n", p);
                goto lab1;
            }
            else if (index == p - 1)
            {
                delete_at_last();
            }
            else
            {
                struct node *prev;
                temp = head;
                p = 0;
                while (p < index)
                {
                    prev = temp;
                    temp = temp->next;
                    p++;
                }
                prev->next = temp->next;
                printf("delete elemet is %d \n", temp->data);
                free(temp);
            }
        }
    }
    else
    {
        printf("please frist create list after delete\n");
    }
}
void search_element()
{
    if (head != NULL)
    {
        struct node *temp = head;
        int n;
        printf("enter element to search in list : ");
        scanf("%d", &n);
        do
        {
            if (temp->data == n)
            {
                printf("%d element is fond\n", n);
                return;
            }
            temp = temp->next;
        }while (temp != head);
        printf("%d element is not fond\n", n);
    }
    else
    {
        printf("frist create list than search\n");
    }
}
int main()
{
    int num;

    while (1)
    {
        printf("\nWelcome to my Linked List Program:\n");
        printf("Press 1 to create list\n");
        printf("Press 2 to display\n");
        printf("Press 3 to insert element at the frist\n");
        printf("Press 4 to delete element at the frist\n");
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
            display(); // Display the linked list
            break;
        case 3:
            insert_at_frist();
            break;
        case 4:
            delete_at_frist();
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
