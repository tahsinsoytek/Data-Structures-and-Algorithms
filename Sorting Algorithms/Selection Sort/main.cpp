#include <iostream>
#include <ctime>
#include <cstdlib>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//Ýlk elemaný al diðer tüm elemanlarla kýyasla en küçüðüyle yer deðiþtir.
void sortOperation(int x[],int n)
{
	int i,j,index,number;
	for(i=0;i<n-1;i++)
	{
		number=x[i];
		index=i;
		for(j=i+1;j<n;j++)
		{
			if(number>x[j])
			{
				number=x[j];
				index=j;
			}
		}
		x[index]=x[i];
		x[i]=number;
	}
}
int main(int argc, char** argv) 
{
	int size;
	srand(time(0));
	printf("How many numbers do you want in the array:");
	scanf("%d",&size);
	int array[size];
	for(int i=0;i<size;i++)
	{
		array[i]=(rand()%(size*10));
	}
	for(int i=0;i<size;i++)
	{
		printf("%d.number is:%d\n",i+1,array[i]);
	}
	printf("After sorting...\n");
	sortOperation(array,size);
	for(int i=0;i<size;i++)
	{
		printf("%d.number is:%d\n",i+1,array[i]);
	}
	return 0;
}

