#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int n,key;
	clock_t start,end;
	double total_cputime;
	printf("ENTER HOW MANY RANDOM NUMBER DO YOU WANT\n");
	scanf("%d",&n);
	int a[n];
	start=clock();
	for(int i=0;i<n;i++)
	{
		a[i]=rand()%1000;
		
	}	
	for(int j=0;j<n;j++)
	{
	printf("%d\t",a[j]);
	}
	printf("\nEnter the key you want to search from the given array\n");
	scanf("%d",&key);
	for(int k=0;k<n;k++)
	{
		if(a[k]==key)
		{
			printf("element is present at %d\n",k);
		}
	}
	end=clock();
	total_cputime=((double)(end-start));
	printf("\nTotal cpu time =%f",total_cputime);
	total_cputime=((double)(end-start/CLOCKS_PER_SEC));
	printf("\nTotal Time in second = %f",total_cputime);
}
