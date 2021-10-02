#include<stdio.h>  
#include<stdlib.h>
#include<time.h>
void heapify(int a[], int n, int i)
{
    int largest = i,temp;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && a[l] > a[largest])
        largest = l;
    if (r < n && a[r] > a[largest])
        largest = r;
    if (largest != i) {
        temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        heapify(a, n, largest);
    }
}
void heapSort(int a[], int n)
{
    int temp;
    for(int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
    for (int i = n - 1; i > 0; i--) {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapify(a, i, 0);
    }
}
int main ()  
{   int n,i;
    clock_t start,end,temp;
	double total_cputime;
	printf("Enter the elements you want to enter\n");
	scanf("%d",&n);
	int a[n];
	start=clock();
	for(i=0;i<n;i++)
		a[i]=rand()%5000;
	for(i=0;i<n;i++)
        printf("%d ",a[i]);
    heapSort(a, n);
    printf("\nAfter applying the heap sort the array is: \n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    end=clock();
	total_cputime=((double)(end-start));
	printf("\nTotal cpu time =%f",total_cputime);
	total_cputime=((double)(end-start)/CLOCKS_PER_SEC);
	printf("\nTotal Time in second = %f",total_cputime);
    return 0;
}
