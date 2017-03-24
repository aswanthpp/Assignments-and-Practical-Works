//   Name: Aswanth P P 15CO112
//  Assignment Question-1 Subitted on sep-1 2016

//Compare Execution time of Each Sorting Algorithm

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

clock_t t;
double time1;
int min,i,j,pos,temp,n;

void bubble(int a[], int n);
void selection(int a[], int n);
void insertion(int a[], int n);
void merge_sort(int a[], int l, int r);
void merge(int a[], int l, int m, int r);
void quick(int a[], int low, int high);
int partition (int a[], int low, int high);
void swap(int* a, int* b);

void main()
{
 int k=50000, choice;
 int a[500000];
 printf("MENU\n");
 printf("1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Merge Sort\n5. Quick Sort\n\n");
 
 printf("Enter Your Choice\n");
 scanf("%d",&choice);

 for(i=0;i<500000;i++)
 a[i] =rand();
 
 switch(choice)
 {
    case 1: printf("\nBubble Sort\n");
           while(k<=500000)
           {
             t = clock();
             bubble(a,k);
             t = clock() - t;

             time1 = ((double) (t)) / CLOCKS_PER_SEC;
             printf("%d  :  %lf\n",k,time1);
             k+=25000;
           }
           break;
   case 2: printf("\nSelection Sort\n");
             while(k<=500000)
             {
             t = clock();
             selection(a,k);
             t = clock() - t;

             time1  = ((double) (t)) / CLOCKS_PER_SEC;
             printf("%d  :  %lf\n",k,time1);
             k+=25000;
             }
           break;
  
   case 3: printf("\nInsertion Sort\n");
           while(k<=500000)
           {
             t = clock();
             insertion(a,k);
             t = clock() - t;
             
             time1 = ((double) (t)) / CLOCKS_PER_SEC;
             printf("%d  :  %lf\n",k,time1);
             k+=25000;
           }
           break;
   case 4: printf("\nMerge Sort\n");
           while(k<=500000)
           {
             t = clock();
             merge_sort(a,0,k-1);
             t = clock() - t;

             time1 = ((double) (t)) / CLOCKS_PER_SEC;
             printf("%d  :  %lf s\n",k,time1);
             k+=25000;
           }
           break;
   case 5: printf("\nQuick Sort\n");
           while(k<=500000)
           {
             t = clock();
             quick(a,0,k-1);
             t = clock() - t;

             time1 = ((double)(t)) / CLOCKS_PER_SEC;
             printf("%d  :  %lf s\n",k,time1);
             k+=25000;
           }
           break;
   default: printf("Invalid Choice!!\n");
 }
}

void bubble(int a[], int  n)
{
 for(i=0;i<n-1;i++)
 {
   for(j=0;j<n-i-1;j++)
   {
     if(a[j]>a[j+1])
       swap(&a[j],&a[j+1]);
   }
 }
}

void selection(int a[], int n)
{
 for(i=0;i<n;i++)
 {
   min = a[i];
   
   for(j=i;j<n;j++)
   {
     if(a[j]<min)
     {
       min = a[j];
       pos = j;
     }
   }

  if(a[i]!=min)
  {
    a[pos] = a[i];
    a[i] = min;
  }
 }
}

void insertion(int a[], int n)
{
 for(i=1;i<n;i++)
 {
  j = i;
  while(j!=0 && (a[j] < a[j-1]))
  {
    swap(&a[j],&a[j-1]);
    j--;
  }
 }
}

void merge_sort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
 
        merge_sort(a, l, m);
        merge_sort(a, m+1, r);
 
        merge(a, l, m, r);
    }
}

void merge(int a[], int l, int m, int r)
{
    int k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1+ j];
 
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            a[k] = L[i++];
        else
            a[k] = R[j++];
        k++;
    }
 
    while (i < n1)
        a[k++] = L[i++];
 
    while (j < n2)
        a[k++] = R[j++];
}

void quick(int a[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(a, low, high);
 
        quick(a, low, pi - 1);
        quick(a, pi + 1, high);
    }
}

int partition (int a[], int low, int high)
{
    int pivot = a[high];
    int i = (low - 1),j;
 
    for (j = low; j <= high- 1; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[high]);
    return (i + 1);
}

void swap(int* a, int* b)
{
    temp = *a;
    *a = *b;
    *b = temp;
}
