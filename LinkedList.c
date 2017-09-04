#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//Buğse Erdoğan-150112082
//Data Structures Project-1
//LINKED LISTS MULTIPLICATION
//This program multiplies two binary numbers.
//Numbers are taken from user as an input.
//Two binary numbers are put in two linked lists.Also their results is kept in another linked list.
//First my program checks scanning inputs are binary or not.If they are binary,numbers are automatically placed into linked list by program.
//Then it multiply numbers controlling carry bits.And again it place result into another linked list.
//Checking(Numbers are binary or not) is done with array implementaton.

//Create a new struct.
typedef struct mylist
{
int data;
struct mylist *next;
}number;

//Defining methods .
void insert(number **hd,int i);
void traverse(number *hd);
void reverse(number **hd);
void addlist(char a[],number **hd);
void addhead(number *hd1,number *hd);
void mul(number *hd1,number **hd2);
void multiply(number *hd1,int attempt,int x);
void copy(number *hd);
void freehead(number **hd);
void display(number *);

//Defining global pointers.
number *oh=NULL,*head3=NULL,*head4=NULL;

int main()
{
//Defining local pointers.
number *head1=NULL,*head2=NULL,*p,*s;

char a[500],b[500];
//Prompt the user to enter first binary number.
printf("Enter first binary number:");
gets(a);
addlist(a,&head1);
//Prompt the user to enter second binary number.
printf("Enter second binary number:");
gets(b);
addlist(b,&head2);

//p=head1;
//s=head2;

reverse(&head1);
reverse(&head2);
p=head1;
s=head2;
display(p);
display(s);

printf("\nx___________________________");
printf("\nAnswer Is:");

mul(head1,&head2);
freehead(&head1);
freehead(&head2);
freehead(&oh);
freehead(&head4);
traverse(head3);
freehead(&head3);
getch();
}
//Display method to print first and second binary number that entered by user.
void display(number *p)
{
    while (p != NULL)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
}
//Copy method to copy of the value that will inserted.
void copy(number *hd)
{
if(hd==NULL)
return;
while(hd!=NULL)
{
insert(&head3,hd->data);
hd=hd->next;
}
reverse(&head3);
}
//Multiply method to multiply two binary numbers by using pointers.
void mul(number *hd1,number **hd2)
{
int attempt=0,x;number *temp;
while(*hd2!=NULL)
{
temp=*hd2;
x=(*hd2)->data;
multiply(hd1,attempt,x);
attempt++;
*hd2=(*hd2)->next;
free(temp);
}
}
void multiply(number *hd1,int attempt,int x)
{
int a,sum=0,carry=0;
while(hd1!=NULL)
{
a=hd1->data*x+carry;
sum=a%2;
carry=a/2;
insert(&oh,sum);
hd1=hd1->next;
}
if(carry>0)
insert(&oh,carry);    
if(attempt==0)
{
copy(oh);
freehead(&oh);
return;
}
reverse(&oh);
while(attempt)
{
insert(&oh,0);
attempt--;
}
reverse(&head3);
addhead(oh,head3);  
freehead(&head3);
copy(head4);
freehead(&head4);
freehead(&oh);
}
//Freehead method to make &heads free.
void freehead(number **hd)
{
number *temp;
while(*hd!=NULL)
{
temp=*hd;
*hd=(*hd)->next;
free(temp);
}
*hd=NULL;
}
//Insert method to insert values to linked list that entered by user 
void insert(number **hd,int i)
{
number *t;
t=(number*)malloc(sizeof(number));
t->next=NULL;
t->data=i;
if(*hd==NULL)
{
*hd=t;
return;
}
t->next=*hd;
*hd=t;
}
//Traverse method to make traverse order.
void traverse(number *hd)
{
printf("\n");
while(hd!=NULL)
{
printf("%d",hd->data);
hd=hd->next;
}
}
//Reverse method 
void reverse(number **hd)
{
number *p,*q,*r;
if(*hd==NULL)
return;
p=*hd;
if(p->next==NULL)
return;
q=p->next;
if(q->next==NULL)
{
q->next=p;
p->next=NULL;
*hd=q;
return;
}
r=q->next;
while(r->next!=NULL)
{
q->next=p;
p=q;
q=r;
r=r->next;
}
q->next=p;
r->next=q;
(*hd)->next=NULL;
*hd=r;
}
//Addhead method to make addtion between results of multiplication.
void addhead(number *hd1,number *hd2)
{
int x,carry=0,sum=0;
while(hd1!=NULL&&hd2!=NULL)
{
x=(hd1)->data+(hd2)->data + carry;
sum=x % 2;
carry=x / 2;
insert(&head4,sum);
hd1=(hd1)->next;
hd2=(hd2)->next;
}
if(hd1==NULL&&hd2!=NULL)
{
while(hd2!=NULL)
{
x=(hd2)->data + carry;
sum=x % 2;
carry=x / 2;
insert(&head4,sum);
hd2=(hd2)->next;
}
}
else if(hd1!=NULL&&hd2==NULL)
{
while(hd1!=NULL)
{
x=(hd1)->data + carry;
sum=x % 2;
carry=x / 2;
insert(&head4,sum);
hd1=(hd1)->next;
}
}
if(carry>0)
insert(&head4,carry);
//reverse(hd3);
}
//Addlist method to check our number is binary or not.
void addlist (char a[],number **hd)
{
int i=0;

while(a[i]!= '\0')
{
	if(a[i]=='0' || a[i]=='1'){
	insert(hd,a[i]- '0');	
	i++;
	}
    else{
    	printf("You entered decimal.You have to enter a binary number.Please try again");
    	printf("\n");
        main();
    }
}

//display(*hd);

}
