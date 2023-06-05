/*
* File Name: arrangeArray.c
* Author: Nguyen Minh Nhut
* Date: 09/05/2023
* Description: Arrange Character Array 
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct Word {
    char* ptr;
    uint8_t length;
};

typedef struct Word W;

int main() {
    /* Tao chuoi arr */
    char arr[] = "Mr. Biden were critical of the way people were treated at the border under the Trump administration";
    /* Dem tong so luong ki tu trong mang arr*/
    uint8_t count = 0; //Tao bien dem toan bo ki tu trong mang
    /*Ngung dem khi gap ki tu \0*/
    while (arr[count] != '\0') 
    {
        count++;
    }
    /*Cap phat bo nho dong*/
    W *words = (W*) malloc(sizeof(W) * count);

    uint8_t word_count = 0; // Tao bien dem tung ky tu trong mang
    uint8_t i = 0;
    ///Dem do dai cua 1 word
    while (i < count) {

        if (arr[i] != ' ') {

            uint8_t word_start = i;
            while (i < count && arr[i] != ' ') {

                i++;
                
            }
            uint8_t word_length = i - word_start;       //do dai 1 word
            words[word_count].ptr = &arr[word_start];   //gan dia chi dau tien cua word
            words[word_count].length = word_length;     //gan do dai cua word
            word_count++;

        }
        i++;

    }
    // print ra chuoi theo chieu nguoc lai
    for (uint8_t i = word_count - 1; i >= 0; i--) {

        for (uint8_t j = 0; j < words[i].length; j++) {

            printf("%c", words[i].ptr[j]);

        }
        printf(" ");
        
    }
    free(words);
    return 0;
}