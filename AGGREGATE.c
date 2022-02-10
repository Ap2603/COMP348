#include "AGGREGATE.h"
#include <stdio.h>
#include <math.h>

    float arr[] = {1,2,3,4,5,6,7};
    size_t n = sizeof(arr)/sizeof(arr[0]);

    /*Definition for min function*/
    float min(float* arr, int size){
        float minval = arr[0];
    for (int i = 1; i < size;i++){
       if(arr[i]<= minval)
        minval = arr[i];
    }
    return minval;
    };

    /*Definition for max function*/
    float max(float* arr, int size){
    float maxval = arr[0];
    for (int i = 1; i < size;i++){
       if(arr[i]>= maxval)
        maxval = arr[i];
    }
     return maxval;


    };
/*Definition for sum function*/
float sum(float* arr, int size){
float sum = 0;
for (int i = 0; i < size;i++){
    sum = sum + arr[i];
}
return sum;


};

/*Definition for average function*/
float avg(float* arr,int size){
    float avg;
    avg = sum(arr, size)/size;
    return avg;
};

/*Defintion for psuedo-average function*/
float psuedo_avg(float* arr,int size){
float psuedo_avg = (min(arr,size)+max(arr,size))/2;
return psuedo_avg;
}

/*Code for Question 4*/
float (*p[5]) (float* arr, int size) = {&min,&max, &sum, &avg, &psuedo_avg};

float arr2[] = {1,2,16,4,32,6,7,8,14,25};
float arr3[] = {4,2,9,55,31};
size_t S = sizeof(arr2)/sizeof(arr2[0]);
size_t S2 = sizeof(arr3)/sizeof(arr3[0]);



/*Code for Question 5*/

typedef float (*ptr) (float* arr, int size);

ptr m1 = &min;
ptr m2 = &max;
ptr s1 = &sum;
ptr a1 = &avg;
ptr pa1 = &psuedo_avg;



ptr p1[5] = {&min, &max, &sum, &avg, &psuedo_avg};
const char* funcnames[] = {"FMIN", "FMAX", "FSUM" , "FAVG" , "FPSUEDO_AVG"};

/*Main Driver:*/

int main(){

       printf("Starting Q3...\n\n");

       printf("The minimum value in the array is: %f" , min(arr,n));
       printf("\n");
       printf("The maximum value in the array is: %f" , max(arr,n));
       printf("\nThe sum of values in the array is: %f" , sum(arr,n));
       printf("\nThe average of the values in the array is: %f" , avg(arr,n));
       printf("\nThe psuedo-average of the values in the array is: %f" , psuedo_avg(arr,n));

       printf("\n\nStarting Q4...\n\n");


       for(int i = 0;i < 5; i++){
        float result = ((*p[i])(arr2,S));
        float result2 = ((*p[i])(arr3,S2));
        if (i ==0){
            printf("The minimum value in Array2 is: %f\n" , result);
            printf("The minimum value in Array3 is: %f\n" , result2);}
        if (i==1){
            printf("The maximum value in Array2 is: %f\n" , result);
            printf("The maximum value in Array3 is: %f\n" , result2);}
            if(i==2){
                printf("The sum of the values in Array2 is: %f\n" , result);
                printf("The sum of the values in Array3 is: %f\n" , result2);
            }
            if(i==3){
                printf("The average value in Array2 is: %f\n" , result);
                printf("The average value in Array3 is: %f\n" , result2);
            }
            if (i==4){
                printf("The psuedo-average value in Array2 is: %f\n" , result);
                printf("The psuedo-average value in Array3 is: %f\n" , result2);
            }
            }

            printf("\n\nStarting Q5...\n\n");


            for(int i = 0;i < 5; i++){
        float r = ((*p1[i])(arr2,S));
        float r2 = ((*p1[i])(arr3,S2));


            printf( "%s of Array2 is: %f\n" ,funcnames[i],  r);
            printf("%s of Array3 is: %f\n" ,funcnames[i] , r2);


         }

       return 0;



}
