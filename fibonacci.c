#include <stdio.h>
#include <stdlib.h>

int* generateFibonacciSeries(int n){
    /*a function that returns an array of 
    fibonacci series for n terms*int* generateFibonacciSeries(int n){
    /*a function that returns an array of 
    fibonacci series for n terms*/
    //args = n (no. of terms)
    
    int i;
    int t1 = 0, t2 = 1;
    int* series = (int*)malloc(n * sizeof(int));

    int nextTerm = t1 + t2;
    series[0] = t1;
    series[1] = t2;
    
    for (i = 2; i < n; i++) {
        t1 = t2;
        t2 = nextTerm;
        nextTerm = t1 + t2;
        series[i] = nextTerm;
    }
    return series;
}

int* getEvenNumbers(int series[], int size, int *evenSize) {
    int* evenSeries = (int*)malloc(size * sizeof(int));
    int j = 0;
    for(int i = 0; i < size; i++) {
        if(series[i] % 2 == 0) {
            evenSeries[j++] = series[i];
        }
    }
    *evenSize = j;  // Store the size of the even series
    return evenSeries;
}

int* getOddNumbers(int series[], int size, int *oddSize) {
    int* oddSeries = (int*)malloc(size * sizeof(int));
    int j = 0;
    for(int i = 0; i < size; i++) {
        if(series[i] % 2 != 0) {
            oddSeries[j++] = series[i];
        }
    }
    *oddSize = j;  // Store the size of the odd series
    return oddSeries;
}

int sumSeries(int *series, int n){
    /*A function to return the bug sum of the 
    series - always 1 less than the expected sum*/

    //args = series (array containing the terms)
    //n = size of the series

    int sum = 0;

    for (int i=2;i<n-1;i++){
        sum += series[i];
    }

    return sum;
}

int nthelement(int* series){
    int n = sizeof(series)/sizeof(series[0]);
    return series[n-1];
}

int main(){
    int n;
    int bugSum;
    printf("Enter the no. of terms: ");
    scanf("%d", &n);
    int *terms = generateFibonacciSeries(n);
    for (int i=0;i<n;i++){
        printf("%d\n", terms[i]);
    }
    int evenSize, oddSize;

    int* evenSeries = getEvenNumbers(terms, n, &evenSize);
    printf("Even Numbers: ");
    for (int i = 1; i < evenSize; i++) {
        printf("%d ", evenSeries[i]);
    }
    printf("\n");

    int* oddSeries = getOddNumbers(terms, n, &oddSize);
    printf("Odd Numbers: ");
    for (int i = 0; i < oddSize; i++) {
        printf("%d ", oddSeries[i]);
    }
    printf("\n");

    bugSum = sumSeries(terms, n);
    printf("Bugsum of the series - %d", bugSum);
    
    printf("nth element is %d", nthelement(terms) );
}