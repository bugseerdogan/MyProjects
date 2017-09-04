/*Buðse Erdoðan
150112082
Project2-BinarySearchTree*/

//Libraries are imported.
#include<stdlib.h>
#include<stdio.h>
#include <string.h>

//Creating a binary tree node that includes id,name,surname,staj,depth and pointers that show right and left of node.
struct bin_tree {
	int id;
	char name[25];
	char surname[25];
	int staj;
	int depth;
	struct bin_tree * rightnode, * leftnode;
};
//Using typedef with structure to define a new data type and then use that data type to define structure variables directly as follows 
typedef struct bin_tree node;

//Method to compare that compares given file and input.If input is found,it will be printed
void compare(node *tree,int id,char *name,char *surname,int staj,int x,int y,int z,int t){
	 
	 	if(tree==NULL){
    		return;
    	}
	 //All checking inputs "greater or smaller" are small.
	 if(x==0 && y==0 && z==0 && t==0 ){
	
        //Compare name and surname with strcmp() and also check id and staj.
    	if((strcmp(name,tree->name))>0 && (strcmp(surname,tree->surname))>0 && (id > tree->id) && (staj > tree->staj)){
    		
			printf("%d  %s  %s  %d\n", tree->id, tree->name, tree->surname, tree->staj);
			
			
		
    	    }
    	    //If inputs are greater than,go to the leftnode.
    	    compare(tree->leftnode,id,name,surname,staj,x,y,z,t);
    	    //Else go to the rightnode
    	    compare(tree->rightnode,id,name,surname,staj,x,y,z,t);
    	

	 	
	 }
	    //Name,surname and id will be greater,staj will be smaller.
	  	else if(x==0 && y==0 && z==0 && t==1){
	  		if((strcmp(name,tree->name))>0 && (strcmp(surname,tree->surname))>0 && (id > tree->id) && (staj < tree->staj)){
    		
			printf("%d  %s  %s  %d\n", tree->id, tree->name, tree->surname, tree->staj);
			
			
		
    	    }
    	    compare(tree->leftnode,id,name,surname,staj,x,y,z,t);
    	    compare(tree->rightnode,id,name,surname,staj,x,y,z,t);
    	
	   	}
	    else if(x==0 && y==0 && z==1 && t==0){
	   	if((strcmp(name,tree->name))>0 && (strcmp(surname,tree->surname))>0 && (id < tree->id) && (staj > tree->staj)){
    		
			printf("%d  %s  %s  %d\n", tree->id, tree->name, tree->surname, tree->staj);
			
			
		
    	    }
    	    compare(tree->leftnode,id,name,surname,staj,x,y,z,t);
    	    compare(tree->rightnode,id,name,surname,staj,x,y,z,t);
	   		
	   	}
	   	else if(x==0 && y==0 && z==1 && t==1){
	   	if((strcmp(name,tree->name))>0 && (strcmp(surname,tree->surname))>0 && (id < tree->id) && (staj < tree->staj)){
    		
			printf("%d  %s  %s  %d\n", tree->id, tree->name, tree->surname, tree->staj);
			
		
		
    	    }
    	    compare(tree->leftnode,id,name,surname,staj,x,y,z,t);
    	    compare(tree->rightnode,id,name,surname,staj,x,y,z,t);
	   		
	   	}
	   	else if(x==0 && y==1 && z==0 && t==1){
	   		if((strcmp(name,tree->name))>0 && (strcmp(surname,tree->surname))<0 && (id > tree->id) && (staj < tree->staj)){
    		
			printf("%d  %s  %s  %d\n", tree->id, tree->name, tree->surname, tree->staj);
			
			
		
    	    }
    	    compare(tree->leftnode,id,name,surname,staj,x,y,z,t);
    	    compare(tree->rightnode,id,name,surname,staj,x,y,z,t);
	   		
	   	
	   }
	   else if(x==0 && y==1 && z==1 && t==0){
	  		if((strcmp(name,tree->name))>0 && (strcmp(surname,tree->surname))<0 && (id < tree->id) && (staj > tree->staj)){
    		
			printf("%d  %s  %s  %d\n", tree->id, tree->name, tree->surname, tree->staj);
			
			
		
    	    }
    	    compare(tree->leftnode,id,name,surname,staj,x,y,z,t);
    	    compare(tree->rightnode,id,name,surname,staj,x,y,z,t);
	  	} 
    	else if(x==0 && y==1 && z==1 && t==1){
	   	if((strcmp(name,tree->name))>0 && (strcmp(surname,tree->surname))<0 && (id < tree->id) && (staj < tree->staj)){
    		
			printf("%d  %s  %s  %d\n", tree->id, tree->name, tree->surname, tree->staj);
			
			
		
    	    }
    	    compare(tree->leftnode,id,name,surname,staj,x,y,z,t);
    	    compare(tree->rightnode,id,name,surname,staj,x,y,z,t);
	  }
	   else if(x==1 && y==0 && z==0 && t==0){
	   	 	if((strcmp(name,tree->name))<0 && (strcmp(surname,tree->surname))>0 && (id > tree->id) && (staj > tree->staj)){
    		
			printf("%d  %s  %s  %d\n", tree->id, tree->name, tree->surname, tree->staj);
			
			
		
    	    }
    	    compare(tree->leftnode,id,name,surname,staj,x,y,z,t);
    	    compare(tree->rightnode,id,name,surname,staj,x,y,z,t);
	   }
	    else if(x==1 && y==0 && z==0 && t==1){
	   	if((strcmp(name,tree->name))<0 && (strcmp(surname,tree->surname))>0 && (id > tree->id) && (staj < tree->staj)){
    		
			printf("%d  %s  %s  %d\n", tree->id, tree->name, tree->surname, tree->staj);
			
			
		
    	    }
    	    compare(tree->leftnode,id,name,surname,staj,x,y,z,t);
    	    compare(tree->rightnode,id,name,surname,staj,x,y,z,t);
	   }
	    else if(x==1 && y==0 && z==1 && t==0){
	   	if((strcmp(name,tree->name))<0 && (strcmp(surname,tree->surname))>0 && (id < tree->id) && (staj > tree->staj)){
    		
			printf("%d  %s  %s  %d\n", tree->id, tree->name, tree->surname, tree->staj);
			
			
		
    	    }
    	    compare(tree->leftnode,id,name,surname,staj,x,y,z,t);
    	    compare(tree->rightnode,id,name,surname,staj,x,y,z,t);
	   }
	    else if(x==1 && y==0 && z==1 && t==1){
	   	if((strcmp(name,tree->name))<0 && (strcmp(surname,tree->surname))>0 && (id < tree->id) && (staj < tree->staj)){
    		
			printf("%d  %s  %s  %d\n", tree->id, tree->name, tree->surname, tree->staj);
			
			
		
    	    }
    	    compare(tree->leftnode,id,name,surname,staj,x,y,z,t);
    	    compare(tree->rightnode,id,name,surname,staj,x,y,z,t);
	   	}
	   	else if(x==1 && y==1 && z==0 && t==0){
	   	if((strcmp(name,tree->name))<0 && (strcmp(surname,tree->surname))<0 && (id > tree->id) && (staj > tree->staj)){
    		
			printf("%d  %s  %s  %d\n", tree->id, tree->name, tree->surname, tree->staj);
			
			
		
    	    }
    	    compare(tree->leftnode,id,name,surname,staj,x,y,z,t);
    	    compare(tree->rightnode,id,name,surname,staj,x,y,z,t);
	   }   
	    else if(x==1 && y==1 && z==1 && t==0){
	   	if((strcmp(name,tree->name))<0 && (strcmp(surname,tree->surname))<0 && (id < tree->id) && (staj > tree->staj)){
    		
			printf("%d  %s  %s  %d\n", tree->id, tree->name, tree->surname, tree->staj);
			
			
		
    	    }
    	    compare(tree->leftnode,id,name,surname,staj,x,y,z,t);
    	    compare(tree->rightnode,id,name,surname,staj,x,y,z,t);
	   }
	   
	  
		if(x==1 && y==1 && z==1 && t==1){
	   		if((strcmp(name,tree->name))<0 && (strcmp(surname,tree->surname))<0 && (id < tree->id) && (staj < tree->staj)){
    		
			printf("%d  %s  %s  %d\n", tree->id, tree->name, tree->surname, tree->staj);
			
			
    	    }
    	    compare(tree->leftnode,id,name,surname,staj,x,y,z,t);
    	    compare(tree->rightnode,id,name,surname,staj,x,y,z,t);
	   	 }
	 
	 
}
//Insert method to given file elements to the binary search tree according to depth property.
void insert(node ** tree, int id, char *name, char *surname, int staj, int depth)
{
	
    node *temp = NULL;
    //If tree is not null,create a place by using malloc
    if(!(*tree))
    {
        temp = (node *)malloc(sizeof(node));
        
		temp->leftnode = temp->rightnode = NULL;
        temp->id = id;
        strcpy(temp->name,name);
        strcpy(temp->surname,surname);
        temp->staj = staj;
        temp->depth = depth;
        *tree = temp;
        return;
    }
   //If depth levels are 0,4,8,12:Nodes are ordered according to name.
    if(((*tree)->depth)%4==0){
      	
      	if(strcmp(name,(*tree)->name)<0 ){
      		insert(&((*tree)->leftnode), id,name,surname,staj,++depth);
      	}
    	else if(strcmp(name,(*tree)->name)>0 ){
        	insert(&((*tree)->rightnode), id,name,surname,staj,++depth);
   		}
	    
    }
    //If depth levels are 1,5,9,13:Nodes are ordered according to surname.
    else if(((*tree)->depth)%4==1){
    	
  		if(strcmp(surname,(*tree)->surname)<0 ){
      	  	insert(&((*tree)->leftnode),id,name,surname,staj,++depth);
        }
    	else if(strcmp(surname,(*tree)->surname)>0 )	{
        	insert(&((*tree)->rightnode),id,name,surname,staj,++depth);
   		}
   	
	}
	//If depth levels are 2,6,10,14:Nodes are ordered according to id.
	else if(((*tree)->depth)%4==2){
      	
      	if(id < ((*tree)->id) ){
      	  	insert(&((*tree)->leftnode),id,name,surname,staj,++depth);  
        }
    	else if(id > ((*tree)->id) ){
        	insert(&((*tree)->rightnode),id,name,surname,staj,++depth);
        }
        

    }
    //If depth levels are 3,7,11,15:Nodes are ordered according to number of internship.
    else if(((*tree)->depth)%4==3){
      	
      	if(staj < ((*tree)->staj) ){
      	  	insert(&((*tree)->leftnode), id,name,surname,staj,++depth);
        }
    	else if(staj > ((*tree)->staj) ){
        	insert(&((*tree)->rightnode), id,name,surname,staj,++depth);
   		}
      	
    }
     
}
//Method to print nodes in Preorder

void print_preorder(node * tree)
{

    
    if (tree)
    
	{

    	printf(" %d  %d  %s  %s  %d\n",tree->depth, tree->id, tree->name, tree->surname, tree->staj );
        print_preorder(tree->leftnode);
        print_preorder(tree->rightnode);
      
    
	
	}

}

//Method to print nodes in Inorder
void print_inorder(node * tree)
{
    
    if (tree)
    {
  
		print_inorder(tree->leftnode);
        printf(" %d  %d  %s  %s  %d\n",tree->depth, tree->id, tree->name, tree->surname, tree->staj );
        print_inorder(tree->rightnode);
      
    }
}

//Method to print nodes in Postorder
void print_postorder(node * tree)
{
    
	
	if (tree)
    {
    
        print_postorder(tree->leftnode);
        print_postorder(tree->rightnode);
        printf("%d  %d  %s  %s  %d\n",tree->depth, tree->id, tree->name, tree->surname, tree->staj );
        
    }
}
//Main method includes reading file statements and also menu for my project.
void main()
{
    
	node *root;
    root=NULL;
    
    FILE *fp;

	int id;
	char name[25];
	char surname[25];
	int staj;
	fp=fopen("code.txt","r");
	
		char singleLine[600];
		const char s[2] = " ";
        char *token;
        //If fp pointer is null
		if(fp==NULL){
		perror("Error opening file..");
		return (-1);
		}
		
		//printf("Text'ten cekilen veriler\n\n");
		
		//By using fgets,I read file.
		//Singleline is a char variable,600 is maximum character that will be read from file and fp is a pointer of File object.
 		while(!feof(fp)){
			fgets(singleLine,600,fp);
			if(strcmp(singleLine,"\n")==0){
				return;
			}
			
			
			//Strtok breaks string str into a series of tokens by using s.
	   		    token=strtok(singleLine,s);  
	      	//Convert ascii to int.Because ý take elements from file as a string.
	       		id=atoi(token);
	      		token=strtok(NULL,s);
	      	//Strcpy is used for name and surname.	
				strcpy(name,token);
	      	    token=strtok(NULL,s);
	      		
				strcpy(surname,token);
	      		token=strtok(NULL,s);
				
				staj=atoi(token);
	      	//Calling insert method to put elements from file to the tree.	
				  insert(&root,id,name,surname,staj,0);
		}
		fclose(fp); 
	   
	   //Menu items.
       while(1){
       	int ctrl;
		printf("\nTo List Inorder Traversal Please Press 1:\n");
		printf("\nTo List Postorder Traversal Please Press 2:\n");
		printf("\nTo List Preorder Traversal Please Press 3:\n");
		printf("\nTo Search a Key Please Press 4:\n");
		scanf("%d",&ctrl);
		if(ctrl==1){
			print_inorder(root);
			
		}
		if(ctrl==2){
			print_postorder(root);
		}
		if(ctrl==3){
			print_preorder(root);
		}
		if(ctrl==4){
	   
	   //		  
	   int a,b,c,d;
	   char name2[25],surname2[25];
	   int id2,staj2;
	   //Prompt the user to enter name,surname,id and number of internship and also taking check values"greater and smaller"
	   printf("enter name:");
	   scanf("%s",name2);
	   printf("If greater press 1,if smaller press 0:");
	   scanf("%d",&a);
	   printf("enter surname:");
	   scanf("%s",surname2);
	   printf("If greater press 1,if smaller press 0:");
	   scanf("%d",&b);
	   printf("enter id:");
	   scanf("%d",&id2);
	   printf("If greater press 1,if smaller press 0:");
	   scanf("%d",&c);
	   printf("enter staj:");
	   scanf("%d",&staj2);
	   printf("If greater press 1,if smaller press 0:");
	   scanf("%d",&d);
	   //Calling compare method to search .
	   compare(root,id2,name2,surname2,staj2,a,b,c,d);
   
       	
       }



       
			
		}
		

}    



    
