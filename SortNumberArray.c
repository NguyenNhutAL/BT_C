/*
* File Name: SortArray.h
* Author: Nguyen Minh Nhut
* Date: 09/05/2023
* Description: sort the array of random numbers and print out how many times they appear in that array
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
/*
* Function: createArray
* Description: this function create the array of random numbers from 1 to 10
* Input:
*   arr[10]: array of 10 elements
* Output:
*   print 10 elements of this array
*/
void createArray(uint8_t arr[10]){
    srand( time(NULL) );//tao bien thoi gian
    for(uint8_t i=0 ; i<10 ; i++){
         
        arr[i] = rand() % 11; //tao mang ngau nhien tu 1 - 10
        printf("%d - ",arr[i]); //in ra gia tri vua tao

    }
}
/*
* Function: SortArray
* Description: this function sort and print a array of 10 elements
* Input:
*   arr[10]: array of 10 elements
* Output:
*   print 10 elements of sorted array
*/
void SortArray(uint8_t arr[10]){
    uint8_t temp;
    for(uint8_t i=0 ; i<10 ; i++)
        for(uint8_t j=i+1 ; j<10 ; j++)
            if( arr[i] > arr[j] ){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
    //in ra mang da sap xep
    for(uint8_t i=0 ; i<10 ; i++){
        printf("%d - ", arr[i]);
    }
}
/*
* Function: TimesAppearofNumber
* Description: this function count the times of Number in array
* Input:
*   arr[10]: array of 10 elements
* Output:
*   none
*/
void TimesAppearofNumber(uint8_t arr[10]){
    uint8_t count[10]={0};   

    for(uint8_t i=0 ; i<10 ; i++)
    count[arr[i]] ++;
    //in ra so lan xuat hien
    for(uint8_t i=1 ; i<=10 ; i++)
    printf("\nSo %d xuat hien %d lan", i,count[i]);

}
int main(int argc, char **argv){
    uint8_t array[10];
    createArray(&array[10]);
    printf("\n");
    SortArray(&array[10]);
    TimesAppearofNumber(&array[10]);
    return 0;
}