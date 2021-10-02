#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int n;
void insertionSort(int arr[])
{
	int i,j;
	

	for(i=1;i<n;i++)
	{
		j = i-1;
		int x = arr[i];
		while(arr[j]>x&&j>-1)
		{
			arr[j+1] = arr[j];
			j--;	
		}
		
		arr[j+1] = x;
		
	}
}

int binarySearch(int arr[], int l, int h, int key)
{
	int mid;
	
	while(l<=h)
	{
		mid = (l+h)/2;
		if(key==arr[mid])
		{
			return 1;
		}
		else if(key<arr[mid])
		{
			h = mid - 1;
		}
		else 
		{
			l = mid + 1;
		}
	}
	return -1;	
}

int main()
{
	printf("\nEnter the size of the array : \n");
	scanf("%d",&n);
	int arr[n];


	
	int i;
	for(i=0;i<n;i++)
	{
		arr[i] = rand()%100;
	}
	printf("\nThe array is : \n");
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	
	insertionSort(arr);
	int key;
	printf("\nThe sorted array is : \n");
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\nEnter the key to be searched : \n");
	scanf("%d",&key);
	clock_t start, end;
    double cpu_time_used;
    start = clock();
	if(binarySearch(arr,0,n-1,key)==1){
		printf("Key Found");	
	}
	else
	{
		printf("Key not found");
	}
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("\nTime taken : %f",cpu_time_used);
	return 0;
	
}
