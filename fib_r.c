#include <stdio.h>

int Fibonacci_sequence_r(int n);

int count=1;

int main(){
	int n,ans;
	
	printf("Please input n for fibr(n) : ");
	scanf("%d",&n);
	
	ans=Fibonacci_sequence_r(n);
	printf("Result : %d\n",ans);

	printf("Time of this algo : %d\n",count);

	return 0;
}

int Fibonacci_sequence_r(int n){
	if(n<=1){
		count++;
		return n;
	}
	else
		return Fibonacci_sequence_r(n-1)+Fibonacci_sequence_r(n-2);
}

