#include <iostream>
#include <cstdlib>
#include <ctime>
class Node
{
	public:
		Node()
		{
		    next=NULL;
		}
	int data;
	Node* next;
};
class List
{
	public:
		List()
		{
			head=NULL;
		}
		bool IsEmpty()
		{
			return head==NULL;
		}
		Node* InsertNode(int index,int x)
		{
		   if(index<1)
		   {
				return NULL;
		   }
		   int currIndex=1;
		   Node* currNode=head;
		   while(currIndex<index&&currNode)
		   {
		   	    currNode=currNode->next;
		   	    currIndex++;
		   }
		   if(currIndex>1&&currNode==NULL)
		   {
		   	    return NULL;
		   }
		   Node* newnode=new Node;
		   if(IsEmpty())
		   {
		   	    head=new Node;
		   	    head->next=newnode;
		   	    newnode->data=x;
		   }
		   else if(currNode->next==NULL)
		   {
		   	    currNode->next=newnode;
		   	    newnode->data=x;
		   }
		   else
		   {
		   	    newnode->next=currNode->next;
		   	    currNode->next=newnode;
		   	    newnode->data=x;
		   }
		   return newnode;			
		}
		int DeleteNode(int x)
		{
			Node* currNode=head->next;
			Node* prevNode=NULL;
			int index=1;
			if(IsEmpty())
			{
				printf("List is empty");
				return 0;
			}
			while(currNode)
			{
				if(currNode->data!=x)
				{
					prevNode=currNode;
					currNode=currNode->next;
					index++;
				}
				else if(index==1)
				{
				    head=currNode->next;
				    delete currNode;
				    return index;
				}
				else
				{
					prevNode->next=currNode->next;
					delete currNode;
					return index;
				}
			}
			return 0;
		}
		int FindNode(int x)
		{
			int index=1;
			Node* currNode=head->next;
			if(IsEmpty())
			{
				printf("List is empty");
				return 0;
			}
			while(currNode)
			{ 
				if(currNode->data==x)
				{
					return index; 
				}
				currNode=currNode->next;
				index++;
			}
			return 0;
		}
		void DisplayList()
		{
			int counter=1;
			Node* currNode=head->next;
			while(currNode)
			{
				printf("%d.number:%d",counter,currNode->data);
				printf("\n");
				currNode=currNode->next;
				counter++;
			}
		}
	private:
		Node* head;
};
int main(int argc,char *argv[])
{
	srand(time(0));
	int i=0;
	int x;
	List* list=new List();
	list->InsertNode(1,15);
	if(list->IsEmpty())
	{
		printf("List is empty");
	}
	else
	{
		printf("List is not empty");
		printf("\n");
	}
	printf("How many numbers do you want to add:");
	scanf("%d",&x);
	for(i=0;i<x;i++)
	{
		list->InsertNode(i+1,rand()%100);
	}
	list->InsertNode(x+2,98);
	list->DisplayList();
	for(i=0;i<x;i++)
	{
		list->InsertNode(rand()%(x*2),rand()%1500);
	}
	list->DisplayList();
	printf("Index of searched number:%d",list->FindNode(98));
	printf("\n");
	printf("Index of deleted number:%d",list->DeleteNode(15));
	printf("\n");
	list->DisplayList();
	return 0;
}



