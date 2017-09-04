/************************************
 * Insertion sort on linked list    *
 *                                  *
 * *********************************/
 
 //List must be ended with next = null;


#include <stdio.h>
#include <stdlib.h>

struct Item{
   int value;
   struct Item* next;
};


/*
* create Item
* @param int value
* @return pointer on new struct Item
*/
struct Item* new_item(int val){
    struct Item* pom = (struct Item*)malloc(sizeof(struct Item));
    pom -> value = val;
    pom -> next = NULL;
  
  return pom;
}

/*
* print list
* @param first Item of list
*/
void print(struct Item* begin){
   struct Item * help = begin;
   while(help != NULL)
   {
      printf("%d ",help->value);
      help = help->next;
   }
}

/*
* Add new Item at the beginning of list
*/
struct Item* push_front(struct Item* begin, int new_value){
   struct Item* pom = new_item(new_value);
   pom -> next = begin;
   return pom;
 
}

/*
*   Add new Item at the end of list
*/
void push_back(struct Item* begin, int new_value){
    struct Item* pom = begin;
    struct Item* new_end = new_item(new_value);
    while(pom->next != NULL) {
        pom = pom -> next;
    }
    pom -> next = new_end;
}

/**
 * Add item to list ahead of defined position
 * 
 * @param begin - start of list
 * @param position - position before which we want to add item
 * @param new_Item - item we want to add
 * @return begin of list (if we dont insert at the beginning it equals begin)
*/
struct Item* insert(struct Item* begin, struct Item* position, struct Item* new_Item){
   //check if we add to the beginning
   if(begin == position) {
       new_Item -> next = begin;
       return new_Item;
   }
   
   struct Item* pom = begin;
   while(pom -> next != position) {
       pom = pom -> next;
   }
   
   new_Item -> next = pom -> next;
   pom -> next = new_Item;
   
   return begin;
 
}

/**
 * Generate random number in range <down,up>
 */
int rand_number(int down, int up) {
    return (rand()%(up-down))+down;
}

/**
 * Generate random list of length count and values in range <down_bound, up_bound-
 */
struct Item* generate_random(int count, int down_bound, int up_bound) {
    int i;
    struct Item* start = new_item(rand_number(down_bound,up_bound));
    for(i=1;i<count;i++) {
        start = push_front(start, rand_number(down_bound,up_bound));
    }
    return start;
}

struct Item* insertion_sort(struct Item* begin)
{

   struct Item* sorted = begin;
   struct Item* preaktual = begin; 
   struct Item* pom;
   struct Item* pom1;
   
   while(preaktual -> next != NULL) {
       
       pom = sorted;
	   while( preaktual ->next  != NULL && pom != preaktual -> next && pom -> value < preaktual->next->value)
        pom = pom -> next;
       
       if(preaktual -> next != pom) { 
           //element is moving
           //we must connect element before with element after
           pom1 = preaktual -> next;
           preaktual -> next = preaktual -> next -> next;
           sorted = insert(sorted,pom, pom1);
            
       }else{
        
        preaktual = preaktual -> next;
       }

   }
   
   

   return sorted;
}

struct Item* reverse(struct Item* root) {
  struct Item* new_root = 0;
  while (root) {
    struct Item* next = root->next;
    root->next = new_root;
    new_root = root;
    root = next;
  }
  return new_root;
}

int main( )
{
  struct Item* zoznam1 = generate_random(10,0,60);
  struct Item* zoznam2,*zoznam3,*zoznam4;

  ////random case
  printf("Random case without sorted:");
  print(zoznam1);
  printf("\n");
  printf("Random case sorted:");
  zoznam2 = insertion_sort(zoznam1);
  print(zoznam2);
   printf("\n");
   printf("Best case:");
   //this is for best case
  zoznam1=insertion_sort(zoznam2);
  print(zoznam1);
  ////////////
    printf("\n");
    /////worst case
    printf("worst case sorted:");
    zoznam3=reverse(zoznam1);
    print(zoznam3);
    printf("\n");
    printf("worst case:");
    zoznam4=insertion_sort(zoznam3);
    print(zoznam4);
    ///////////

}
