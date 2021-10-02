#include<stdio.h>  
#include<stdlib.h>
#include<time.h>
void mergeSort(int[],int,int);  
void merge(int[],int,int,int);  
int main ()  
{   int n;
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
     
    mergeSort(a,0,n);  
    printf("\nprinting the sorted elements");  
    for(int i=0;i<n;i++)  
    {  
        printf("\n%d\n",a[i]);  
    }  
      
      	end=clock();
	total_cputime=((double)(end-start));
	printf("\nTotal cpu time =%f",total_cputime);
	total_cputime=((double)(end-start/CLOCKS_PER_SEC));
	printf("\nTotal Time in second = %f",total_cputime);
}  
void mergeSort(int a[], int beg, int end)  
{  
    int mid;  
    if(beg<end)  
    {  
        mid = (beg+end)/2;  
        mergeSort(a,beg,mid);  
        mergeSort(a,mid+1,end);  
        merge(a,beg,mid,end);  
    }  
}  
void merge(int a[], int beg, int mid, int end)  
{  
    int i=beg,j=mid+1,k,index = beg;  
    int temp[5000];  
    while(i<=mid && j<=end)  
    {  
        if(a[i]<a[j])  
        {  
            temp[index] = a[i];  
            i = i+1;  
        }  
        else   
        {  
            temp[index] = a[j];  
            j = j+1;   
        }  
        index++;  
    }  
    if(i>mid)  
    {  
        while(j<=end)  
        {  
            temp[index] = a[j];  
            index++;  
            j++;  
        }  
    }  
    else   
    {  
        while(i<=mid)  
        {  
            temp[index] = a[i];  
            index++;  
            i++;  
        }  
    }  
    k = beg;  
    while(k<index)  
    {  
        a[k]=temp[k];  
        k++;  
    }  
}
