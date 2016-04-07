/*Description:This program can make a linked list.
 *for more information please read README*/ 







#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
            }* start=NULL;

int AddbyIndex();
void AddtoFront();
int RemovebyIndex();
int RemovebyData();
void RemoveFirst();
int Showlist();




	
	
int AddbyIndex()//Adds a data to linked list by given index number
{
	int index; 
	int size=Showlist();
	printf("You can choose a Number from 1 to %d as Index.however,if you choose 1 Your data will be added to the front of the list\n if you choose %d your data will be added to the end of the list\n",size+1,size+1);
	printf("Index? :");
	scanf("%d",&index);
	if(index==1){
		
			AddtoFront();
			return 1;
	}
	

	if(index>size+1 || index<=0)//Checks if the given index is correct
	{
		printf("Invalid Number \n ");
		return 0;
	}

	else {
		struct node* before=start;struct node* after=start->next;

		for(int j=0;j<index-2;j++)
		{
			before=after;
			after=after->next;
		}
		
		printf("Enter the number you want to put after %d :",before->data);
		struct node *new=malloc(sizeof(struct node));
		   
		before->next=new;
		before=new;
		before->next=after;
		scanf("%d",&new->data);
		return 1;
	}

}



void AddtoFront()//Adds a data to the begining of the list
{
	struct node *new=malloc(sizeof(struct node));
	if(start==NULL)
	{
		
		start=new;
		start->next=NULL;
		printf("\nList is empty.Enter your first data :");
		scanf("%d",&start->data);
	}	
	else
	{
		new->next=start;
		start=new;
		printf("\nEnter a data to add to the front of the list: ");
		scanf("%d",&start->data);
	
}
}

int RemovebyIndex()//Removes a data by it's index number
{
	int index;
	int size=Showlist();
	printf("Enter the index Of Number you want to remove :");
	scanf("%d",&index);
    if(index>size || index<=0)//check if the given index is correct
{
		printf("Invalid Number\n");
		return 0;
}
if(index==1)
	RemoveFirst(start);
else
{

		struct node* before=start;
		struct node* current=start->next;
		for(int j=0;j<index-2;j++)
		{
			before=current;
			current=before->next;
        } 
        before->next=current->next;
        printf(" %d has been removed from the list \n ",current->data);
       free(current);
        
	  return 1;
}

	
		
    
    return 1;
   }








void RemoveFirst()//Removes the first data in the list
{
	struct node* head=start;
	printf(" %d has been removed from the list \n ",start->data);
	free(start);
	start=head->next;
	
	
	
	
}


	
int RemovebyData(int num)//Removes a specific data
{
	
    struct node* tmp=start;struct node* prv;
	while(tmp!=NULL)
		if(tmp->data==num)
		{
			if(tmp==start)
			{	
				RemoveFirst();
				return 1;
			
		    }
		  else
			{
				printf("%d has been removed from list\n",tmp->data);
				prv->next=tmp->next;
				free(tmp);
				return 1;
				
		 
	        }
        }
		
	else
	{
		prv=tmp;
		tmp=tmp->next;
	}
	
	
	

    return 0;
}







int Showlist()//This function shows the list
{
	int size=0;
	struct node* head=start;
	while(head!=NULL)
	{
		printf("%d:%d\t",size+1,head->data);
		head=head->next;
		size++;
	}
    printf("\n");
    return size;
		
		
}

//main
int main()
{
	int key=0;int num;
	
	printf("Hello\n");
	
    while(key!=5)//asks user what to do.
{  
		printf("1:ADD a data to list By INDEX\t2:REMOVE a data from list By INDEX\n3:REMOVE A given number from list\t4:SHOW THE LIST\t  5:EXIT\n");
		scanf("%d",&key);

		switch (key)
		{
			
		
			case 1:
			
				if(start==NULL)
				{
					AddtoFront();
					Showlist();
				}
				else
				{
					AddbyIndex();
					Showlist();
				}
			
		        break;
			case 2:
			if(start==NULL)
					{
						printf("There 's No data in this list \n ");
						
					}
			else
			{
				RemovebyIndex();
				Showlist();
		       
		    }
				break;
			case 3:
				if(start==NULL)
						{
							printf("There 's No data in this list \n ");
							
						}
			    else
			    {
					printf("Which number do you want to remove? \n");
					scanf("%d",&num);
					if(RemovebyData(num)==0)
						printf("%d doesn't exist in the list \n",num);
					Showlist();
					
				}
			    break;
		case 4:
			
				if(start==NULL)
					{
						printf("There 's No data in this list \n ");
					}
				else
				Showlist();
			
		        break;
		case 5:
				break;
	default:
		printf("Invalid Operation\n");
	    break;
}
}


return 0;

}


	



