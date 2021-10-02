#include<stdio.h>  
#include<stdlib.h>
#include<time.h>
void quicksort (int [], int, int);
int main()
{
    int list[50];
     clock_t start,end,temp;
	double total_cputime;
    int size, i;
 	start=clock();
    printf("Enter the number of elements: ");
    scanf("%d", &size); 
    for (i = 0; i < size; i++)
        list[i]=rand()%1000;
     for (i = 0; i < size; i++)
        printf("%d ", list[i]);
    quicksort(list, 0, size - 1);
    printf("\nAfter applying quick sort\n");
    for (i = 0; i < size; i++)
        printf("%d ", list[i]);
    printf("\n");
    end=clock();
    total_cputime=((double)(end-start));
    printf("Total CPU time in milliseconds: %lf\n",total_cputime);
    total_cputime=((double)(end-start)/CLOCKS_PER_SEC);
    printf("Total CPU time in seconds: %lf\n",total_cputime);
    return 0;
}
void quicksort(int list[], int low, int high)
{
    int pivot, i, j, temp;
    if (low < high)
    {
        pivot = low;
        i = low;
        j = high;
        while (i < j) 
        {
            while (list[i] <= list[pivot] && i <= high)
            {
                i++;
            }
            while (list[j] > list[pivot] && j >= low)
            {
                j--;
            }
            if (i < j)
            {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
        temp = list[j];
        list[j] = list[pivot];
        list[pivot] = temp;
        quicksort(list, low, j - 1);
        quicksort(list, j + 1, high);
    }
}
