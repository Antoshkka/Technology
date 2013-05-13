#include <iostream>
#include <cstring>
#include <conio.h>
#include <malloc.h>
using namespace std;

void qs(char *items, int left, int right){
    int i, j ;
    char x, y;
    i = left; j = right;

/* ������� ��������. ��� ���������� */
    x = items[( left+right) / 2 ] ;

/* ��������� �������� � ���������� ������� */
    do {
        while((items[i] < x) && (i < right)) i++;
        while((x < items[j]) && (j > left)) j--;

        if(i <= j) {
            y = items[i];
            items[i] = items[j];
            items[j] = y;
            i++; j-- ;
        }
    } while(i <= j );

/* ���� ������ �� ������������ �������� ������� ���������� */
    if(left < j) qs(items, left, j ) ;
    if(i < right) qs(items, i, right);
}


void quicksort (char *items, int len){
    /* ��� ������ ������ ���������� � ���������� ���� ������. */
    qs(items, 0, len-1);
}

int main() {
    char *str,s[500];
	printf("Enter the massive: ");
	scanf("%s",&s);
	str=(char*)malloc(strlen(s)*sizeof(char));
	strcpy(str,s);
	strcpy(s,"");
	printf("\nYour Massive: %s",str);
    quicksort(str, strlen(str));
    printf("\nSorted massive: %s",str);
    getch();
	return 0;
}



