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

int* get_even_num(int series[], int size){
    int* evenSeries = (int*)malloc(size * sizeof(int));
    int j = 0;
    for(int i =1; i<size; i++){
        if(series[i]%2==0){
            evenSeries[j++]=series[i];
        }
    }
    return evenSeries;
}

int bugSumSeries(int *series, int n){
    /*A function to return the bug sum of the 
    series - always 1 less than the expected sum*/

    //args = series (array containing the terms)
    //n = size of the series

    int bugSum = 0;

    for (int i=2;i<n;i++){
        bugSum += series[i];
    }

    return bugSum;
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
    int *eveterms = get_even_num(terms,n);
    int sizeEven = sizeof(eveterms) / sizeof(int);
    for (int i=0;i<sizeEven;i++){
        printf("%d\n", eveterms[i]);
    }

    bugSum = bugSumSeries(terms, n);
    printf("Bugsum of the series - %d", bugSum);
    
}