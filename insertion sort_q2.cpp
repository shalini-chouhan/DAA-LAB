#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int n,key,j;
	clock_t start,end,temp;
	double total_cputime;
	printf("ENTER HOW MANY RANDOM NUMBER DO YOU WANT TO SORT\n");
	scanf("%d",&n);
	int a[n];
	start=clock();
	for(int i=0;i<n;i++)
	{
		a[i]=rand()%100;
		
	}	
	for(int s=0;s<n;s++)
	{
	printf("%d\t",a[s]);
	}
	
	for(int k=1;k<n;k++){
      temp=a[k];
      j=k-1;
      while((temp<a[j])&&(j>=0)){
         a[j+1]=a[j];
         j=j-1;
      }
      a[j+1]=temp;
   }
   printf("\n");
   for(int s=0;s<n;s++)
	{
	printf("%d\t",a[s]);
	}
	end=clock();
	total_cputime=((double)(end-start));
	printf("\nTotal cpu time =%f",total_cputime);
	total_cputime=((double)(end-start/CLOCKS_PER_SEC));
	printf("\nTotal Time in second = %f",total_cputime);
}
