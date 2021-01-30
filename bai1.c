#include<stdio.h>
long long fact(int n){
	if(n==1){
		return 1;
	}
	return n * fact(n-1);
}
long long combination(int k,int n){
	long long numerator = 1;
	int i;
	if(k>=n-k){
		for(i=k+1;i<=n;i++){
			numerator *= i;
		}
		return numerator/fact(n-k);
	}else if(k<n-k){
		for(i=n-k+1;i<=n;i++){
			numerator *= i;
		}
		return numerator/fact(k);
	}
}
int main(){
	int n,k;
	printf("Enter n :");
	scanf("%d",&n);
	printf("\nEnter k :");
	scanf("%d",&k);
	printf("\nk-combination of n is %lld",combination(k,n));
	return 0 ;
}

