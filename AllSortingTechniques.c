#include <stdio.h>
#include <stdlib.h>


void Swap(int *x, int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
void BubbleSort(int A[], int n)
{
    int i,j,flag;
    for(i=0; i<n-1; i++)
    {
        flag=0;
        for(j=0; j<n-i-1; j++)
        {
            if(A[j] > A[j+1]){
                Swap(&A[j], &A[j+1]);
                flag=1;
            }
        }
        if(flag==0)
            printf(" Array is Already Sorted :\n\n");
            break;
    }

}

//Insertion Sort
void InsertionSort (int A[], int n)
{
    for(int i=1; i<n; i++)
    {
        int j = i-1;
        int x = A[i];
        while(j>-1 && A[j] > x){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
    printf(" Array after Sorting :\n\n");
}

// Selection Sort
void SelectionSort(int A[], int n)
{
    int i,j,k;
    for(i=0; i<n-1; i++)
    {
        for(j=k=i; j<n; j++)
        {
            if(A[j] < A[k])
                k = j;
        }
        Swap(&A[i], &A[k]);
    }
    printf(" Array after Sorting :\n\n");
}

// Quick Sort
int Partition(int A[], int l, int h)
{
    int pivot = A[l];
    int i=l, j=h;
    do{
        do{
            i++;
        }while(A[i] <= pivot);
        do{
            j--;
        }while(A[j] > pivot);

        if(i<j)
            Swap(&A[i], &A[j]);
    }while(i<j);

    Swap(&A[l], &A[j]);
    return j;
}
// Quick Sort
void QuickSort(int A[], int l, int h)
{
    int j;
    if(l<h)
    {
        j = Partition(A, l, h);
        QuickSort(A,l,j);
        QuickSort(A,j+1,h);
    }
}

int main()
{
    int A[] = {8,2,6,21,7,9,18,65535}; // int highest element
    int i,n=8;

    // BubbleSort(A,n);
    // InsertionSort(A, n);
    // SelectionSort(A, n);
    QuickSort(A,0,n-1);
    for(i=0; i<7; i++)
        printf(" %d\n",A[i]);
    printf("\n");

    return 0;


}
