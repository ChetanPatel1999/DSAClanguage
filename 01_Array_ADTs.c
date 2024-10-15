#include <stdio.h>
#include <stdlib.h>
struct myarray
{
  int t_size;
  int u_size;
  int *ptr;
};
void createarray(struct myarray *a, int t, int u)
{
  a->t_size = t;
  a->u_size = u;
  a->ptr = (int *)malloc(t * sizeof(int));
}
void setval(struct myarray *a)
{
  int i;
  int *temp = a->ptr;
  for (i = 0; i < a->u_size; i++)
  {
    scanf("%d", a->ptr);
    a->ptr++;
  }
  a->ptr = temp;
}
void display(struct myarray *a)
{
  int i;
  int *temp = a->ptr;
  for (i = 0; i < a->u_size; i++)
  {
    printf("%d ", *(a->ptr));
    a->ptr++;
  }
  printf("\n");
  a->ptr = temp;
}
void insertatlast(struct myarray *a, int n)
{
  if (a->u_size < a->t_size)
  {
    a->ptr[a->u_size] = n;
    a->u_size++;
  }
  else
  {
    printf("adt,s array size is full");
  }
}
void deleteatlast(struct myarray *a)
{
  a->u_size--;
}
void insert(struct myarray *a, int index,int n)
{
  if (a->u_size < a->t_size)
  {
    int i;
    for(i=a->u_size-1;i>=index;i--)
    {
       a->ptr[i+1]=a->ptr[i];
    }
    a->ptr[index]=n;
    a->u_size++;
  }
  else
  {
    printf("adt,s array size is full\n");
  }
}
void delete(struct myarray *a, int index)
{
  if (index<a->u_size )
  {
    int i;
    for(i=index;i<a->u_size-1;i++)
    {
       a->ptr[i]=a->ptr[i+1];
    }
    a->u_size--;
  }
  else
  {
    printf("please enter index less then %d\n",a->u_size);
  }
}
char* search(struct myarray *a , int ele )
{
  int i;
  int *temp=a->ptr;
  for(i=0;i < a->u_size ; i++)
  {
   if(ele == *(a->ptr))
   {
    a->ptr=temp;
    return "elemet is found";
   }
   a->ptr++;
  }
  a->ptr=temp;
  return "element is not found";
}
void main()
{
  struct myarray marks;
  createarray(&marks, 5, 3);
  printf("we are running set value now.. \n");
  setval(&marks);
  printf("we are running display value now.. \n");
  display(&marks);
  printf("%s",search(&marks,33));
  insertatlast(&marks, 45);
  printf("we are running display value now.. \n");
  display(&marks);
  insert(&marks,2,500);
  printf("we are running display value now.. \n");
  display(&marks);
  insert(&marks,2,800);
  printf("we are running display value now.. \n");
  display(&marks);
  delete(&marks,5);
  printf("we are running display value now.. \n");
  display(&marks);
}