/*
* File Name: Whatday.h
* Author: Nguyen Minh Nhut
* Date: 09/05/2023
* Description: Tim Thu Khi Biet Ngay Thang Nam
*/
#include <stdio.h>
#include <stdint.h>

typedef struct{
    uint8_t ngay;
    uint8_t thang;
    uint16_t nam;
}Thoigian;

//Ngay thang nam goc 1/1/1 -> thu 6
const Thoigian ThoigianGoc = {1,1,1} ;

/*
* Function: SoNgayTrongThang
* Description: this function caculates the number of date in the month
* Input:
*   thang: month in year
* Output:
*   return number of that month
*/
uint8_t SoNgayTrongThang(uint8_t month){
    switch (month){

            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:   
            case 12:
                return 31;
                break;

            case 4:
            case 6:
            case 9:
            case 11:
                return 30;
                break;

            case 2:
                return 29;
                break;

            default:
                break;
    }
}

/*
* Function: tinhSoNamNhuan
* Description: This function calculates number of leap year
* Input:
*   year: 
* Output:
*   return number of leap year
*/
uint16_t tinhSoNamNhuan(uint16_t year) {
    uint16_t namNhuan=0;
    for(uint16_t i=0 ; i<=year ; i++){

        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
            namNhuan++;

        }
    return namNhuan;
}
/*
* Function: printThu
* Description: this function check the date
* Input:
*   SoThu: the date need to be check
* Output:
*   printing what date
*/
void printThu(uint8_t SoThu){
    switch (SoThu){

        case 0: printf("Thu 6\n");
        break;

        case 1: printf("Thu 7\n");
        break;

        case 2: printf("CN\n");
        break;

        case 3: printf("Thu 2\n");
        break;

        case 4: printf("Thu 3\n");
        break;

        case 5: printf("Thu 4\n");
        break;

        case 6: printf("thu 5\n");
        break;

        default:
        break;
    }
}

int main(){
    Thoigian date;
    uint16_t tongSoNgay;
    uint16_t count =0;

    /*Nhap ngay thang nam can tim*/
    printf("Nhap ngay, thang, nam can tinh\n .. .. .... : ");
    scanf("%d%d%d", &date.ngay, &date.thang, &date.nam );
    
    // tinh so ngay cua thang le
    for(uint16_t i=1; i<=(date.thang - 1); i++){

        count = count + SoNgayTrongThang(i);

    }

    // tinh so nam nhuan
    int soNamNhuan= tinhSoNamNhuan(date.nam); 

    // tinh tong so ngay
    tongSoNgay= (date.nam - soNamNhuan)*365 + soNamNhuan*366 + count + date.ngay;
    uint8_t SoThu = (tongSoNgay)%7;
    printThu(SoThu);
    return 0;
    
}