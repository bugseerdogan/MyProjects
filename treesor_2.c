#include <stdlib.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
struct node
{
    int data;
    struct node* next;
};
 
/* A Binary Tree node */
struct tree
{
    int data;
    struct tree* left;
    struct tree* right;
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
 
struct tree* treeSort(struct tree** sorted,struct node* header){
	
	
	if((*sorted)==NULL){
		(*sorted)=malloc(sizeof(struct tree));	
		(*sorted)->data=header->data;
		(*sorted)->left=NULL;
		(*sorted)->right=NULL;
	    //printf("\nA\n");
	     
	
	}
	
	
	while(header!=NULL){
		struct node *temp=malloc(sizeof(struct node));
		temp->data=header->data;
		temp->next=NULL;
	   
		if((*sorted)->data > temp->data){
			//printf("\nB\n");
			treeSort(&((*sorted)->left),temp);
		}
		if((*sorted)->data < temp->data){
			//printf("\nC\n");
			treeSort(&((*sorted)->right),temp);
		}
		 header=header->next;
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
void Inorder(struct tree *root) {
 if (root != NULL) {
  Inorder(root->left);
  printf(" %d ", root->data);
  Inorder(root->right);
 }
}
struct node* reverse(struct node* root) {
  struct node* new_root = 0;
  while (root) {
    struct node* next = root->next;
    root->next = new_root;
    new_root = root;
    root = next;
  }
  return new_root;
}
 
 
int main()
{
    /* Start with the empty list */
    clock_t t1, t2,t3;
    srand(time(NULL));
    long long int AVGBaseOp1=0,AVGBaseOp2=0,AVGBaseOp3=0,AVGBaseOp4=0;
	float AVGTime1=0,AVGTime2=0,AVGTime3=0,AVGTime4=0,Result1=0,Result2=0,Result3=0,Result4=0,Result5=0,Result6=0,Result7=0,Result8=0;
	float diff=0;
	long int Comparison;
	int k,i;
	printf("press 1 for insertion,2 for mergesort,3 for quicksort and 4 for treesort:");
	scanf("%d",&k);

  	struct tree *zoznam5=NULL;

    
	struct node* input1 = generate_random(1000,0,10);   /// 1000 INPUT
	struct node* input2 = generate_random(5000,0,10);   /// 5000 INPUT
	struct node* input3 = generate_random(10000,0,10);   /// 10000 INPUT
	struct node* input4 = generate_random(25000,0,10);   /// 25000 INPUT
	struct node* input5 = generate_random(50000,0,10);   /// 50000 INPUT
	struct node* input6 = generate_random(100000,0,10);   /// 100000 INPUT
	struct node* input7 = generate_random(250000,0,10);   /// 250000 INPUT
	struct node* input8 = generate_random(500000,0,10);   /// 500000 INPUT
    
 	
 	struct tree *zoznam2=NULL;
 
   	struct tree *header=input8;
    /* Convert List to BST */
	
 //	Inorder(zoznam2);
 	for(i=0;i<30;i++){
  	t1 = clock();
  //	header=treeSort(&zoznam2,header);
  	header=reverse(header);
  	treeSort(&zoznam2,header);
  	
	  t2 = clock();
  	  diff = (((float)t2 - (float)t1) / 1000000.0F ) * 1000;
  	  AVGTime4+=diff;
  	}
  Result6 = AVGTime4 /30 ;
  AVGTime4,diff=0;
  printf("\t");
  printf("Result6 = %lf",Result6);
  
  
 
    return 0;
}
