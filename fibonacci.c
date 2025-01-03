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

int main(){
    int n;
    printf("Enter the no. of terms: ");
    scanf("%d", &n);
    int *terms = generateFibonacciSeries(n);
    for (int i=0;i<n;i++){
        printf("%d\n", terms[i]);
    }
}