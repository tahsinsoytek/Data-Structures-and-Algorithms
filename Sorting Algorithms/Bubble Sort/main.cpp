#include <iostream>
#include <cstdlib>
#include <ctime>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void sortingOperation(int x[],int n)
{
	int temp,i,j;
	bool b;
	for(i=0;i<n-1;i++)
	{
		b=false;
		for(j=0;j<n-i-1;j++)
		{
			if(x[j]>x[j+1])
			{
				temp=x[j];
				x[j]=x[j+1];
				x[j+1]=temp;
				b=true;
			}	
		}
		if(!b)
		{
			return;
		}
	}
}

int main(int argc, char** argv) 
{
	int size,i;
	srand(time(0));
	printf("Enter the array size:");
	scanf("%d",&size);
	int array[size];
	for(i=0;i<size;i++)
	{
		array[i]=rand()%(size*5);
	}
	for(i=0;i<size;i++)
	{
		printf("%d\n",array[i]);
	}
	sortingOperation(array,size);
	printf("After sorting\n");
	for(i=0;i<size;i++)
	{
		printf("%d.number is:%d\n",i+1,array[i]);
	}
	return 0;
}
