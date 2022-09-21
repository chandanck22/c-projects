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
int Partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i=low, j=high;
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

    Swap(&A[low], &A[j]);
    return j;
}
void QuickSort(int A[], int low, int high)
{
    int j;
    if(low<high)
    {
        j = Partition(A, low, high);
        QuickSort(A,low,j);
        QuickSort(A,j+1,high);
    }
}


//Merge Sort
void MergeSort(int A[], int low, int mid, int high)
{
    int i=low, j=mid+1, k=low;
    int B[100];

    while(i<=mid && j<=high)
    {
        if(A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    for(; i<=mid; i++)
        B[k++] = A[i];
    for(; j<=high; j++)
        B[k++] = A[j];

    for(i=low; i<=high; i++)
        A[i] = B[i];
}
void IterativeMergeSort(int A[], int n)
{
    int p,low,high,mid,i;
    for(p=2; p<=n; p=p*2)
    {
        for(i=0; i+p-1<=n; i=i+p)
        {
            low=i;
            high=i+p-1;
            mid = (low+high)/2;
            MergeSort(A,low,mid,high);
        }
    }
    if(p/2<n)
        MergeSort(A,0,p/2-1,n);
}
void RecursiveMergeSort(int A[], int low, int high)
{
    int mid;
    if(low<high)
    {
        mid = (low+high)/2;
        RecursiveMergeSort(A,low,mid);
        RecursiveMergeSort(A,mid+1,high);
        MergeSort(A,low,mid,high);
    }
}

// Count Sort
int FindMax(int A[], int n)
{
    int max = 65535;
    int i;
    for(i=0; i<n; i++)
    {
        if(A[i] > max)
            max=A[i];
    }
    return max;
}
void CountSort(int A[], int n)
{
    int i,j,max,*C;
    max = FindMax(A,n);
    C = (int *)malloc(sizeof(int)*(max+1));

    for(i=0; i<max+1; i++)
    {
        C[i]=0;
    }
    for(i=0; i<n; i++)
    {
        C[A[i]]++;
    }
    i=0;j=0;
    while (j<max+1) {
        if(C[j] > 0){
            A[i++] = j;
            C[j]--;
        }else
            j++;
    }
}

// Bin/Bucket Sort
void BinSort(int A[], int n)
{
    int max = FindMax(A,n);
    int i,j;
    int bucket[max];

    // Bin initilised with NULL
    for(i=0; i<=max; i++)
    {
        bucket[i] = 0;
    }
    for(i=0; i<n; i++)
    {
        bucket[A[i]]++;
    }
    for(i=0,j=0; i<=max; i++)
    {
        while(bucket[i] > 0)
        {
            A[j++] = i;
            bucket[i]--;
        }
    }

}

// Shell Sort
void ShellSort(int A[], int n)
{
    int gap, i,j,temp;
    for(gap=n/2; gap>=1; gap /= 2)
    {
        for(i=gap; i<n; i++)
        {
            temp = A[i];
            j = i-gap;
            while(j>=0 && A[j]>temp)
            {
                A[j+gap] = A[j];
                j = j-gap;
            }
            A[j+gap] = temp;
        }
    }
}

// printing Arrys
void PrintArray(int A[], int n)
{
    for(int i=0; i<n; i++){
        printf(" %d\t",A[i]);
    }
    printf("\n\n");
}

int main()
{
    // int A[] = {8,2,6,21,7,9,18,65535}; // use in Quick Sort int highest element
    int A[] = {8,2,6,21,7,9,18,25};
    int i,n=8;

    // BubbloweSort(A,n);
    // InsertionSort(A, n);
    // SelowectionSort(A, n);
    // QuickSort(A,0,n-1);

    // IterativeMergeSort(A,n);
    // CountSort(A,n);
    // RecursiveMergeSort(A,0,n-1);
    PrintArray(A, n);
    BinSort(A, n);
    PrintArray(A, n);
    // ShellSort(A,n);


    return 0;


}
