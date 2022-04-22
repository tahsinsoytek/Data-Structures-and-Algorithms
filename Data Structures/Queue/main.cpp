#include <iostream>
#include <cstdlib>
#include <ctime>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
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
class Queue
{
	public:
		Queue()
		{
			counter=0;
			front=NULL;
			rear=NULL;
		}
		bool IsEmpty()
		{
			return counter==0;
		}
		void Enqueue(int x)
		{
			Node* newNode=new Node();
			newNode->data=x;
			if(IsEmpty())
			{
			    front=newNode;
			    rear=newNode;
			}
			else
			{
			    rear->next=newNode;
			    rear=newNode;
			}
			counter++;
		}
		void Dequeue()
		{
			if(IsEmpty())
			{
				printf("Queue is empty\n");
			}
			else
			{
                Node* nextNode=front->next;
                delete front;
                front=nextNode;
                delete nextNode;
				counter--;
			}
		}
		void DisplayQueue()
		{
			if(IsEmpty())
			{
				printf("Queue is empty\n");
			}
			else
			{
				Node* CurrNode=front;
				int i=0;
				printf("\\*QUEUE*/\n");
				for(i=0;i<counter;i++)
				{
					if(i==0)
					{
						printf("front -->\t%d\n",CurrNode->data);
					}
					else if(i!=counter-1)
					{
						printf("\t\t%d\n",CurrNode->data);
					}
					else
					{
						printf("\t\t%d\t<-- rear\n",CurrNode->data);
					}
					CurrNode=CurrNode->next;
				}
			}
		}
	private:
		int counter;
		Node* front;
		Node* rear;
};


int main(int argc, char** argv) 
{
	int x,i;
	srand(time(0));
	Queue* q=new Queue();
	printf("How many number would you like to add to the list?\n");
	scanf("%d",&x);
	for(i=0;i<x;i++)
	{
		q->Enqueue(rand()%40);
	}
	q->DisplayQueue();
	q->Dequeue();
	q->DisplayQueue();
	for(i=0;i<x-1;i++)
	{
		q->Dequeue();
	}
	q->DisplayQueue();
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
