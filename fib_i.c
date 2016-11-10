#include <stdio.h>

int Fibonacci_sequence_i(int n);

int count=1;

int main(){
	int n,ans;
	
	printf("Please input n for fib(n) : ");
	scanf("%d",&n);
	
	ans=Fibonacci_sequence_i(n);
	printf("Result : %d\n",ans);
	
	printf("Time of this algo : %d ",count);

	return 0;
}

int Fibonacci_sequence_i(int n){
	int i;
	int f[n+1];

	f[0]=0;
	if(n>0){
		f[1]=1;
		for(i=2;i<=n;i++){
			count++;
			f[i]=f[i-1]+f[i-2];
		}
	}
	return f[n];
}
