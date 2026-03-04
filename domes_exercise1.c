
/* Giorgos Manousos
AM:2022201800116

Michalis Koutsaggelis
AM:2022201800098 */








#include <stdio.h>
#include <stdlib.h>



typedef struct addedterm
{
int num;
struct addedterm *next;
}list;


typedef struct pointerlist
{
list *ptr;
struct pointerlist *prev;
}stack;


int count;
int *num_arr;
int* element_store;
stack* top=NULL;
stack* St_pointer=NULL;
list* List_pointer=NULL;



list* delete(list* head)
{
list* tmp;
tmp=head;
if(head==NULL)
return NULL;

head=head->next;
free(tmp);
return head;

}




list* insert(list* head, int num)
{
list* new;
new=(list*)malloc(sizeof(list));
new->next=head;
new->num=num;
return new;
}



stack * push1(int a, int b)
{
stack* new;
new=(stack*)malloc(sizeof(stack));
new->prev=top;
list *head=NULL;
head=insert(head, b);
head=insert(head, a); 
new->ptr=head;
return new;
}




stack * push2(int a, int b)
{
int i;
stack* new;
new=(stack*)malloc(sizeof(stack));
new->prev=top;
list *head=NULL;
for(i=count-2;i>=0;i--)
head=insert(head, element_store[i]);

head=insert(head, b);
head=insert(head, a); 
new->ptr=head;
return new;
}



void pop(void)
{
list* head=NULL;
stack* St_remove=top;
top=top->prev;
head=St_remove->ptr;
while(head!=NULL)
head=delete(head);
free(St_remove);

return;
}


int main(void)
{

int number, a, b, i, j, z, prostheteos_1;

do{

printf("Choose a number to print its addings.\n");
scanf("%d", &number);

if(number<=1){
printf("Invalid integer! Cannot create sums!");
continue;}

top=(stack*)malloc(sizeof(stack));
top->prev=NULL;
top->ptr=(list*)malloc(sizeof(list));
top->ptr->next=NULL;
top->ptr->num=number;

num_arr=(int*)malloc((number-1) * sizeof(int));
for(i=0;i<=(number-2);i++)
num_arr[i]=(i+1);              /* construct an integer array with all positive integers before the input number */



if(number%2==0)
{

for(i=0, j=number-2; i<=(number/2 - 1); i++, j--)
{

top=push1(num_arr[i], num_arr[j]);
if(i!=j)
top=push1(num_arr[j], num_arr[i]);

}

}



else if(number%2!=0)
{

for(i=0, j=number-2; i<=(number/2 - 1); i++, j--)
{

top=push1(num_arr[i], num_arr[j]);
top=push1(num_arr[j], num_arr[i]);


}

}

free(num_arr);

while(top!=NULL)
{
List_pointer=top->ptr;
printf("\n");
while(List_pointer!=NULL)
{
printf("%d ", List_pointer->num);
List_pointer=List_pointer->next;
}
List_pointer=top->ptr;
count=0;
while(List_pointer!=NULL)
{
count++;
List_pointer=List_pointer->next;
}

element_store=(int*)malloc((count-1)*sizeof(int));

List_pointer=top->ptr;
for(z=0;z<count-1;z++)
{
List_pointer=List_pointer->next;
element_store[z]=List_pointer->num;
}

a=top->ptr->num;
b=top->ptr->next->num;

if(a==1)
{
pop();
}


else if(a>1)
{
pop();
prostheteos_1 = a;
b = 1;
a = prostheteos_1 - 1;

while(a > 0)
{
top=push2(a, b);
a--;
b++;
}

}

free(element_store);
}

}while(number<=1);


return 0;
}


