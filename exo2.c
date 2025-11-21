#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort(int T[100], int n){
    int i , j , temp;

    for(i = 0 ; i < n -1 ; i++){
        for(j = i+ 1; j< n ; j++){
            if (T[j] < T[i]){
                temp = T[i];
                T[i] = T[j];
                T[j] = temp;
            }
        }
    }
}



void lessComplexityresort(int T[100], int n){
    for(int i = 0 ; i < n ; i++){
        int temp = T[i];
        int j = i - 1;
        while ( j>= 0 && T[j] > temp){
            T[j + 1] = T[j];
            j--;
        }
            T[j + 1] = temp;
    }
}
int binarysearch(int T[100], int n ,int val){
    lessComplexityresort(T, n);
    int mid;
    int left , right;
    left = 0;
    right = n;
    while(left <= right){
        mid = (left + right) / 2;
        if(T[mid] == val){
            return mid;
        }else if(T[mid]< val){
            left = mid + 1;
        }else{
            right = mid -1;
        }
    }
    return -1;
}


int linearserch(int T[100], int n , int val){
    for(int i = 0 ; i < n ; i++){
        if(T[i] == val){
            return i;
        }
    }
    return -1;
}

int main(void) {

    int T[100];
    int i;
    srand(time(NULL));
    for (i = 0; i < 100 ; i++){
        T[i] = rand() % 100;
    }
    struct timespec start, end;
    double duration;
    // sorting for 10 element
    clock_gettime(CLOCK_MONOTONIC, &start);
    sort(T, 10);
    clock_gettime(CLOCK_MONOTONIC, &end);
    duration = (end.tv_sec - start.tv_sec)*1e6 + (end.tv_nsec - start.tv_nsec) /1e3;

     printf("the procedure take for 10 element sorting  %lf microsecond", duration);

    // sorting for 50 elemnt
    clock_gettime(CLOCK_MONOTONIC, &start);
    sort(T, 50);
    clock_gettime(CLOCK_MONOTONIC, &end);
    duration = (end.tv_sec - start.tv_sec)*1e6 + (end.tv_nsec - start.tv_nsec) /1e3;
    printf("\n\nthe procedure take for 50 element sorting  %lf microsecond", duration);

    //sorting for 100 element
    clock_gettime(CLOCK_MONOTONIC, &start);
    sort(T, 100);
    clock_gettime(CLOCK_MONOTONIC, &end);
    duration = (end.tv_sec - start.tv_sec)*1e6 + (end.tv_nsec - start.tv_nsec) /1e3;
    printf("\n\nthe procedure take for 100 element sorting%lf microsecond", duration);

    int val ;
    printf("\nenter the value that you wanna search   ");
    scanf("%d", &val);
    //linaer search for 10 element
    clock_gettime(CLOCK_MONOTONIC, &start);
    linearserch(T, 10 ,val );
    clock_gettime(CLOCK_MONOTONIC, &end);
    duration = (end.tv_sec - start.tv_sec)*1e6 + (end.tv_nsec - start.tv_nsec) /1e3;
     printf("\nthe duration is for leanersearch %lf microsecond", duration);
    if( linearserch(T, 100 , val) == -1){
        printf("\n not found\n");
    }else{
        printf("\nthe position found  \n %d",  linearserch(T, 100 , val));
    }

    //linaer serch for 50 elment
    clock_gettime(CLOCK_MONOTONIC, &start);
    linearserch(T, 50 , val);
    clock_gettime(CLOCK_MONOTONIC, &end);
    duration = (end.tv_sec - start.tv_sec)*1e6 + (end.tv_nsec - start.tv_nsec) /1e3;
    printf("\nthe duration is for lnearsearch %lf microsecond", duration);
     if( linearserch(T, 100 , val) == -1){
        printf("\n not found\n");
    }else{
        printf("\nthe position found  \n %d",  linearserch(T, 100 , val));
    }

    //linear search for 100 elemnt
    clock_gettime(CLOCK_MONOTONIC, &start);
    linearserch(T, 100 , val);
    clock_gettime(CLOCK_MONOTONIC, &end);
    duration = (end.tv_sec - start.tv_sec)*1e6 + (end.tv_nsec - start.tv_nsec) /1e3;
    printf("\nthe duration  for linearsearch is %lf microsecond", duration);
     if( linearserch(T, 100 , val) == -1){
        printf("\n not found\n");
    }else{
        printf("\nthe position found  \n %d", linearserch(T, 100 , val) );
    }



    // resorting function time

    // sorting for 10 element
    clock_gettime(CLOCK_MONOTONIC, &start);
    lessComplexityresort(T, 10);
    clock_gettime(CLOCK_MONOTONIC, &end);
    duration = (end.tv_sec - start.tv_sec)*1e6 + (end.tv_nsec - start.tv_nsec) /1e3;

     printf("\nthe procedure take for 10 element sorting  %lf microsecond", duration);

    // sorting for 50 elemnt
    clock_gettime(CLOCK_MONOTONIC, &start);
    lessComplexityresort(T, 50);
    clock_gettime(CLOCK_MONOTONIC, &end);
    duration = (end.tv_sec - start.tv_sec)*1e6 + (end.tv_nsec - start.tv_nsec) /1e3;
    printf("\n\nthe procedure take for 50 element sorting  %lf microsecond", duration);

    //sorting for 100 element
    clock_gettime(CLOCK_MONOTONIC, &start);
    lessComplexityresort(T, 100);
    clock_gettime(CLOCK_MONOTONIC, &end);
    duration = (end.tv_sec - start.tv_sec)*1e6 + (end.tv_nsec - start.tv_nsec) /1e3;
    printf("\n\nthe procedure take for 100 element sorting  %lf microsecond", duration);



    // BinarySearch same as we did it td
    //{  the array need to be sorted before   }

       //Binarysearch for 10 element
    clock_gettime(CLOCK_MONOTONIC, &start);
    binarysearch(T, 10 ,val );
    clock_gettime(CLOCK_MONOTONIC, &end);
    duration = (end.tv_sec - start.tv_sec)*1e6 + (end.tv_nsec - start.tv_nsec) /1e3;
     printf("\nthe duration for binaryserach is%lf microsecond", duration);
    if( linearserch(T, 100 , val) == -1){
        printf("\n not found\n");
    }else{
        printf("\nthe position found  \n %d",  linearserch(T, 100 , val));
    }

    //Binaryserch for 50 elment
    clock_gettime(CLOCK_MONOTONIC, &start);
    binarysearch(T, 50 , val);
    clock_gettime(CLOCK_MONOTONIC, &end);
    duration = (end.tv_sec - start.tv_sec)*1e6 + (end.tv_nsec - start.tv_nsec) /1e3;
    printf("\nthe duration for binaryserach is %lf microsecond", duration);
     if( linearserch(T, 100 , val) == -1){
        printf("\n not found\n");
    }else{
        printf("\nthe position found  \n %d",  linearserch(T, 100 , val));
    }

    //Binarysearch for 100 elemnt
    clock_gettime(CLOCK_MONOTONIC, &start);
    binarysearch(T, 100 , val);
    clock_gettime(CLOCK_MONOTONIC, &end);
    duration = (end.tv_sec - start.tv_sec)*1e6 + (end.tv_nsec - start.tv_nsec) /1e3;
    printf("\nthe duration for binaryserach %lf microsecond", duration);
     if( linearserch(T, 100 , val) == -1){
        printf("\n not found\n");
    }else{
        printf("\nthe position found  \n %d", linearserch(T, 100 , val) );
    }




    return 0;
}