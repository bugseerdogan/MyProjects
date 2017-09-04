/*    Buðse Erdoðan
      150112082-DATA STRUCTURE PROJECT3     */
#include "binomial.h"
#include "fatal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include  <math.h>

typedef struct BinNode *Position;
//Struct for binomial heap tree
struct BinNode
{
 char name[10];	
 ElementType extime,artime,priority;
 Position    LeftChild;
 Position    NextSibling;
};
//Element of binomial heap
struct Collection
{
 int CurrentSize;
 BinTree TheTrees[ MaxTrees ];
};

BinQueue Initialize( void )
{
 BinQueue H;
 int i;
 H = malloc( sizeof( struct Collection ) );
 if( H == NULL )
 FatalError( "Out of space!!!" );
 H->CurrentSize = 0;
 for( i = 0; i < MaxTrees; i++ )
 H->TheTrees[ i ] = NULL;
 return H;
}

static void DestroyTree( BinTree T )
{
  if( T != NULL )
  {
    DestroyTree( T->LeftChild );
    DestroyTree( T->NextSibling );
    free( T );
  }
}

void Destroy( BinQueue H )
{
  int i;
  for( i = 0; i < MaxTrees; i++ )
  DestroyTree( H->TheTrees[ i ] );
}

BinQueue MakeEmpty( BinQueue H )
{
 int i;
 Destroy( H );
 for( i = 0; i < MaxTrees; i++ )
 H->TheTrees[ i ] = NULL;
 H->CurrentSize = 0;
 return H;
}
//Insert elements to binomial heap.
BinQueue Insert( char name[], ElementType executionTime,ElementType arrivalTime,ElementType priority, BinQueue H )
{
 BinTree NewNode;
 BinQueue OneItem;
 int i;
 NewNode = malloc( sizeof( struct BinNode ) );
 if( NewNode == NULL )
 FatalError( "Out of space!!!" );
 NewNode->LeftChild = NewNode->NextSibling = NULL;
 NewNode->extime=executionTime;
 NewNode->artime=arrivalTime;
 NewNode->priority=priority;
 strcpy(NewNode->name,name);
       

 OneItem = Initialize( );
 OneItem->CurrentSize = 1;
 OneItem->TheTrees[ 0 ] = NewNode;
 return Merge( H, OneItem );
}

//Delete minumum element of binomial heap.
ElementType DeleteMin( BinQueue H )
{
 int i, j;
 int MinTree;  
 BinQueue DeletedQueue;
 Position DeletedTree, OldRoot;
 ElementType MinItem;

 if( IsEmpty( H ) )
 {
   Error( "Empty binomial queue" );
   MinItem=-Infinity;
   return MinItem;
  }
  MinItem = Infinity;
  for( i = 0; i < MaxTrees; i++ ){
    if( H->TheTrees[ i ] && H->TheTrees[ i ]->priority < MinItem )
    {
    //Update minumum element of binomial heap
     MinItem = H->TheTrees[ i ]->priority;
	 MinTree = i;
    }
   }

    DeletedTree = H->TheTrees[ MinTree ];
    OldRoot = DeletedTree;
    DeletedTree = DeletedTree->LeftChild;
    free( OldRoot );

    DeletedQueue = Initialize( );
    DeletedQueue->CurrentSize = ( 1 << MinTree ) - 1;
    for( j = MinTree - 1; j >= 0; j-- )
    {
        DeletedQueue->TheTrees[ j ] = DeletedTree;
        DeletedTree = DeletedTree->NextSibling;
        DeletedQueue->TheTrees[ j ]->NextSibling = NULL;
    }

    H->TheTrees[ MinTree ] = NULL;
    H->CurrentSize -= DeletedQueue->CurrentSize + 1;
    Merge( H, DeletedQueue );
    return MinItem;
}
//To find minumum element of binomial heap
ElementType FindMin( BinQueue H )
{
 int i;
 ElementType MinItem;
 if( IsEmpty( H ) )
            {
                Error( "Empty binomial queue" );
				MinItem=0;
                return MinItem;
            }

            MinItem = Infinity;
			
            for( i = 0; i < MaxTrees; i++ )
            {
                if( H->TheTrees[ i ] &&
                            H->TheTrees[ i ]->priority < MinItem ) {
                    MinItem = H->TheTrees[ i ]->priority;
				}	
            }

            return MinItem;
        }

// To find minumum node of binomial tree
BinTree FindMinNode( BinQueue H )
{
 	int i;
 	ElementType MinItem;
 	BinTree node;
 
 	if( IsEmpty( H ) )
            {
                puts( "Empty binomial queue" );
				MinItem=0;
            }

            MinItem = Infinity;
			
            for( i = 0; i < MaxTrees; i++ )
            {
                if( H->TheTrees[ i ] &&
                            H->TheTrees[ i ]->priority < MinItem ) {
                    MinItem = H->TheTrees[ i ]->priority;
					node =  H->TheTrees[ i ] ;
				}	
            }

            return node;
}

int IsEmpty( BinQueue H )
        {
            return H->CurrentSize == 0;
        }

int IsFull( BinQueue H )
        {
            return H->CurrentSize == Capacity;
        }
//Combine two binomial tree
BinTree CombineTrees( BinTree T1, BinTree T2 )
        {
            if( T1->priority > T2->priority )
                return CombineTrees( T2, T1 );
            T2->NextSibling = T1->LeftChild;
            T1->LeftChild = T2;
            return T1;
        }
//Merge two binomial tree
BinQueue Merge( BinQueue H1, BinQueue H2 )
        {
            BinTree T1, T2, Carry = NULL;
            int i, j;

            if( H1->CurrentSize + H2->CurrentSize > Capacity )
                Error( "Merge would exceed capacity" );

            H1->CurrentSize += H2->CurrentSize;
            for( i = 0, j = 1; j <= H1->CurrentSize; i++, j *= 2 )
            {
                T1 = H1->TheTrees[ i ]; T2 = H2->TheTrees[ i ];

                switch( !!T1 + 2 * !!T2 + 4 * !!Carry )
                {
                    case 0: /* No trees */
                    case 1: /* Only H1 */
                        break;
                    case 2: /* Only H2 */
                        H1->TheTrees[ i ] = T2;
                        H2->TheTrees[ i ] = NULL;
                        break;
                    case 4: /* Only Carry */
                        H1->TheTrees[ i ] = Carry;
                        Carry = NULL;
                        break;
                    case 3: /* H1 and H2 */
                        Carry = CombineTrees( T1, T2 );
                        H1->TheTrees[ i ] = H2->TheTrees[ i ] = NULL;
                        break;
                    case 5: /* H1 and Carry */
                        Carry = CombineTrees( T1, Carry );
                        H1->TheTrees[ i ] = NULL;
                        break;
                    case 6: /* H2 and Carry */
                        Carry = CombineTrees( T2, Carry );
                        H2->TheTrees[ i ] = NULL;
                        break;
                    case 7: /* All three */
                        H1->TheTrees[ i ] = Carry;
                        Carry = CombineTrees( T1, T2 );
                        H2->TheTrees[ i ] = NULL;
                        break;
                }
            }
            return H1;
        }
//Print element of binomial heap	
BinTree printTree(BinTree p, BinTree *r, int i)
{
		  BinTree t[20]={NULL}, q; int j;
		  for ( j=0; j<i; j++ ) t[j]= r[j];
		  i=0;
		  if (p!=NULL) { 
		     
			q=p->NextSibling;
			j=0;
			do {
			  while (q!=NULL) { 
			   
			    if (q->LeftChild != NULL) { r[i]=q->LeftChild; i++; }
			    q=q->NextSibling;
			  }
			  q=t[j++];
			} while (q!=NULL);
		  }
		  else return NULL;
		  
}
//Global variables

double emax;//used to find new priority queue
int x=0;//for checkext function
double a;

//Main function
int main(){
	
	int q;
	for(q=1;q<=10;q++){
		calculation(q);	
		printf("\n%d: %4.3lf",q,a);
	}
	return 0;
	getchar();
	
}


int calculation(int q)
{
	
    FILE *file,*write;
    double ext=0, art=0, priority=0;//Element of each node in binomial heap
    char name[10];//for process name;
    int i=0;//loop variable
    int j=0;//Array element
    double realtime=0;//real time
    double process=0;//sum of processes
    double waiting=0;//waiting time of each process
    double averagewaiting=0;//average waiting time
    double array[50];//save the arrival time
    BinQueue H1;//collection of binomial trees
    BinTree p, r[20]={NULL};//p includes element of BinTree;
    
	file = fopen("input.txt","r");
	
	if(file == 0)
	{
		puts("File does not exist!");
		exit(0);
	}
	/*Reading file and determine emax,sum of process
	  and taking hold of arrival time in an array*/
    while(!feof(file)) 
	{
     	if(EOF != fscanf(file,"%s%lf%lf",name, &ext, &art))
		 {
	     	array[j++]=art;
	     	if(ext > emax)
	     	{
	     		emax = ext;
	     	}
	     	process=process+1;
	     } 
	     else 
		 break;  
    }
    j=0;
	fclose(file);
	//Create Ýnitialize Heap
	H1 = Initialize( );

	file = fopen("input.txt","r");
	
	while (1){
		
		
		//Process of arrival time
		while(realtime>=array[j] && !feof(file))
		{
			fscanf(file,"%s%lf%lf",name, &ext, &art);
			
			//Check execution time in binomial heap
			for(i=0; i<MaxTrees; i++) 
			{
				p=H1->TheTrees[i];
				checkext(p, r, 0,ext);
		   }
		   //If execution times are equal each other,determine priority queue
		
	
			if(x==1)
			{
				priority=(ext+art)/100;
			}
			//Else priority queue equals to executýon týme
			else
			{
				priority=ext;
			}
			

			
			Insert(name,ext,art,priority,H1);
			//Next arrival time
			j++;
		}
	
	
		
		for(i=0; i<MaxTrees; i++)
		{
			p=H1->TheTrees[i];
	
		}
		
		//Find the node with highest priority queue in the binomial heaps
		BinTree min = FindMinNode(H1);


		//Calculate the process waiting time
		waiting=waiting+realtime-min->artime;
		
	
		
		//Delete highest priority queue
		DeleteMin(H1);
		//If minnode's execution time greater than quantum size 
		if(min->extime>q)
		{
			//Increasing real time
			realtime=realtime+q;
			//Calculate new execution time
			double eNew=min->extime-q;
			double c;
			c=1.0/exp(-pow(2.0*eNew/3.0/emax,3));
			//Calculate new priority queues
			priority=eNew*c;
			
			Insert(name,eNew,realtime,priority,H1);
		  //  printf("inserted is name  %s execution time %4.3lf arrival time %4.3lf priority %4.3lf\n\n",name,eNew,realtime,priority);
		}
		
		else
		{
			//If minnode's execution time equals to quantum size
			if(min->extime==q)
			{
				
				realtime=realtime+q;
			}
			
			else
			{
				//Increase real time
				realtime=realtime+min->extime;
			}
		}
		//If binomial heap is empty,check feof file
		if(IsEmpty(H1))
		{
		
			if(feof(file))
			{
			
				break;
			}
		}
	} 

	
	//Calculating average waiting time  
	averagewaiting=waiting/process;
	a=averagewaiting;
//	printf("%ld",averagewaiting);

	
	//Writing to file
	write=fopen("output.txt","a");
	/*If fýle does not opened*/
	if(write==0)
	{
		puts("File does not open\n");
		exit(0);
	}
	//Writing quantum and averagewaitingtime variables
	fprintf(write,"q= %d AWT= %4.3lf\n",q,averagewaiting);
	fclose(write);
	return 0;
}
//Checkýng exection time in binomial heap*/
int checkext(BinTree p,BinTree r[20],double a,double ext)
{
   
	if(p==NULL)
		return 0;
		x=0;
		//If tree p's execution time equals to execution time of process
		if(p->extime==ext)
		{
			x=1;//Same execution time
			return 1;
		}
    x=0;
    return 0;
}

