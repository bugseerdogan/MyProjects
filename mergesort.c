#include<stdio.h>
#include<stdlib.h>
  
/* Link list node */
struct node
{
    int data;
    struct node* next;
};
struct node* new_item(int val){
    struct node* pom = (struct node*)malloc(sizeof(struct node));
    pom -> data = val;
    pom -> next = NULL;
  
  return pom;
}

struct node* push_front(struct node* begin, int new_value){
   struct node* pom = new_item(new_value);
   pom -> next = begin;
   return pom;
 
}

int rand_number(int down, int up) {
    return (rand()%(up-down))+down;
}
 struct node* generate_random(int count, int down_bound, int up_bound) {
    int i;
    struct node* start = new_item(rand_number(down_bound,up_bound));
    for(i=1;i<count;i++) {
        start = push_front(start, rand_number(down_bound,up_bound));
    }
    return start;
}
/* function prototypes */
struct node* SortedMerge(struct node* a, struct node* b);
void FrontBackSplit(struct node* source,
struct node** frontRef, struct node** backRef);
 
/* sorts the linked list by changing next pointers (not data) */
void MergeSort(struct node** headRef)
{
  struct node* head = *headRef;
  struct node* a;
  struct node* b;
 
  /* Base case -- length 0 or 1 */
  if ((head == NULL) || (head->next == NULL))
  {
    return;
  }
 
  /* Split head into 'a' and 'b' sublists */
  FrontBackSplit(head, &a, &b); 
 
  /* Recursively sort the sublists */
  MergeSort(&a);
  MergeSort(&b);
 
  /* answer = merge the two sorted lists together */
  *headRef = SortedMerge(a, b);
}
 
/* See http://geeksforgeeks.org/?p=3622 for details of this 
   function */
struct node* SortedMerge(struct node* a, struct node* b)
{
  struct node* result = NULL;
 
  /* Base cases */
  if (a == NULL)
     return(b);
  else if (b==NULL)
     return(a);
 
  /* Pick either a or b, and recur */
  if (a->data <= b->data)
  {
     result = a;
     result->next = SortedMerge(a->next, b);
  }
  else
  {
     result = b;
     result->next = SortedMerge(a, b->next);
  }
  return(result);
}
 
/* UTILITY FUNCTIONS */
/* Split the nodes of the given list into front and back halves,
     and return the two lists using the reference parameters.
     If the length is odd, the extra node should go in the front list.
     Uses the fast/slow pointer strategy.  */
void FrontBackSplit(struct node* source,
          struct node** frontRef, struct node** backRef)
{
  struct node* fast;
  struct node* slow;
  if (source==NULL || source->next==NULL)
  {
    /* length < 2 cases */
    *frontRef = source;
    *backRef = NULL;
  }
  else
  {
    slow = source;
    fast = source->next;
 
    /* Advance 'fast' two nodes, and advance 'slow' one node */
    while (fast != NULL)
    {
      fast = fast->next;
      if (fast != NULL)
      {
        slow = slow->next;
        fast = fast->next;
      }
    }
 
    /* 'slow' is before the midpoint in the list, so split it in two
      at that point. */
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
  }
}

  void printList(struct node *node)
{
  while(node!=NULL)
  {
   printf("%d ", node->data);
   node = node->next;
  }
}
/* Drier program to test above functions*/
int main()
{

  struct node* zoznam1 = generate_random(40,0,80);
  struct node* zoznam2;
  printf("\n Before sorted:\n");
  printList(zoznam1);
  printf("\n");
  MergeSort(&zoznam1);
  printf("\n Sorted Linked List is: \n");
  printList(zoznam1);
  
 getchar();
  return 0;
}
