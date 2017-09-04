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




struct node *getTail(struct node *cur)
{
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
}
 
// Partitions the list taking the last element as the pivot
struct node *partition(struct node *head, struct node *end,
                       struct node **newHead, struct node **newEnd)
{
    struct node *pivot = end;
    struct node *prev = NULL, *cur = head, *tail = pivot;
 
    // During partition, both the head and end of the list might change
    // which is updated in the newHead and newEnd variables
    while (cur != pivot)
    {
        if (cur->data < pivot->data)
        {
            // First node that has a value less than the pivot - becomes
            // the new head
            if ((*newHead) == NULL)
                (*newHead) = cur;
 
            prev = cur;  
            cur = cur->next;
        }
        else // If cur node is greater than pivot
        {
            // Move cur node to next of tail, and change tail
            if (prev)
                prev->next = cur->next;
            struct node *tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }
 
    // If the pivot data is the smallest element in the current list,
    // pivot becomes the head
    if ((*newHead) == NULL)
        (*newHead) = pivot;
 
    // Update newEnd to the current last node
    (*newEnd) = tail;
 
    // Return the pivot node
    return pivot;
}
 
 
//here the sorting happens exclusive of the end node
struct node *quickSortRecur(struct node *head, struct node *end)
{
    // base condition
    if (!head || head == end)
        return head;
 
    struct node *newHead = NULL, *newEnd = NULL;
 
    // Partition the list, newHead and newEnd will be updated
    // by the partition function
    struct node *pivot = partition(head, end, &newHead, &newEnd);
 
    // If pivot is the smallest element - no need to recur for
    // the left part.
    if (newHead != pivot)
    {
        // Set the node before the pivot node as NULL
        struct node *tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;
 
        // Recur for the list before pivot
        newHead = quickSortRecur(newHead, tmp);
 
        // Change next of last node of the left half to pivot
        tmp = getTail(newHead);
        tmp->next =  pivot;
    }
 
    // Recur for the list after the pivot element
    pivot->next = quickSortRecur(pivot->next, newEnd);
 
    return newHead;
}
 
// The main function for quick sort. This is a wrapper over recursive
// function quickSortRecur()
void quickSort(struct node **headRef)
{
    (*headRef) = quickSortRecur(*headRef, getTail(*headRef));
    return;
}
 void printList(struct node *node)
{
  while(node!=NULL)
  {
   printf("%d ", node->data);
   node = node->next;
  }
}

int main()
{

  
  
  struct node* zoznam1 = generate_random(30,0,50);
  struct node* zoznam2;
  printf("\n Before sorted:\n");
  printList(zoznam1);
  printf("\n");
  quickSort(&zoznam1);
  printf("\n Sorted Linked List is: \n");
  printList(zoznam1);
  
 
  
    
 
    getchar();
 
    return 0;
}
