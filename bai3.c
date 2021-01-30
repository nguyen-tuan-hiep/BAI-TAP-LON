#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<ctype.h>
#include "student.h"
#define DATA_PATH "./SV2021.dat"

void printMenu(){
	printf("\n1. Xem danh sach sinh vien");
	printf("\n2. Them sinh vien");
	printf("\n3. Tim sinh vien theo ten");
	printf("\n4. Thoat");
}

void printBreak(){
	int i;
    for (i = 0; i < 63; i++){
        printf("%c",95);
    }
    printf("\n");
}

void themSV(SV newSV){
    FILE *file = fopen(DATA_PATH, "ab+");
    int result = fwrite(&newSV, sizeof(SV), 1, file);
    assert(result != 0);
    fclose(file);
}

void nhapThongTin(){
	SV newStudent;
	char name[100];
	printf("Nhap ten sinh vien: "); fflush(stdin); gets(newStudent.name);
	printf("Nhap diem: "); scanf("%f",&newStudent.score);
	themSV(newStudent);
	printf("Them sinh vien thanh cong\n");
}

void printDanhSachSV(){
    FILE *file = fopen(DATA_PATH, "r");
    SV tmp;
    while (fread(&tmp, sizeof(SV), 1, file) )
    {
        printf("%c %28s %c %28.2f %c \n",124, tmp.name,124, tmp.score,124);
        printBreak();
    }
    fclose(file);
}

void printTable(){
	printBreak();
	printf("%c %28s %c %28s %c \n",124,"Name",124,"Score",124);
	printBreak();
}

void ketQuaTimKiem(char *timKiem){
	FILE *file = fopen(DATA_PATH, "r");
	SV search;
	while (fread(&search, sizeof(SV), 1, file)){
        if (!strstr(search.name, timKiem)){ 
            continue;                   
		}      
        printf("%c %28s %c %28.2f %c \n",124, search.name,124, search.score,124);
        printBreak();
    }
    fclose(file);
}

void timKiem(){
	char search[100];
	printf("Nhap ten sinh vien can tim: ");	fflush(stdin);	gets(search);
	printf("Ket qua tim kiem: \n");
	printTable();
	ketQuaTimKiem(search);
}	

int main(){
	printf("Chuong trinh quan ly du lieu sinh vien\n");
	printf("======================================");
    int luaChon;
    do{
        printMenu();
        printf("\nHay lua chon 1 trong cac option tren: ");
        scanf(" %d",&luaChon);
        switch(luaChon){
	        case 1:
	        	printf("\nDanh sach sinh vien:\n");
	            printTable();
	            printDanhSachSV();
	            break;
	        case 2:
	            nhapThongTin();
	            break;
	        case 3:
	            timKiem();
	            break;
	        case 4:
	            return 0;
	        default:
	            printf("Lua chon khong hop le! Xin hay chon 1 lua chon khac:\n");
	            break;
        }
    }while (luaChon != 4);
}

