#include<stdio.h>
#include<conio.h>
void sort(int n, int* ptr) { 
    int i, j, temp; 
    for (i = 0; i < n; i++) { 
        for (j = i + 1; j < n; j++) { 
            if (*(ptr + j) > *(ptr + i)) { 
                temp = *(ptr + i); 
                *(ptr + i) = *(ptr + j); 
                *(ptr + j) = temp; 
            } 
        } 
    } 
}
int main() { 
    int n,W,i;
	printf("Enter N: ");
	scanf("%d",&n);
	printf("Enter W: ");
	scanf("%d",&W);
	int g[n];
    for(i=0;i<n;i++){
    	scanf("%d",&g[i]);
	}
    sort(n, g);
     for(i=0;i<n;i++){
    	
    printf("%d ",g[i]);
	}
  	getch();
    return 0; 
} 

