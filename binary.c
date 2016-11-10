#include <stdio.h>

int binary_search(int n,const int s[],int x);

int count=1;

int main(){
	int s[30]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29};
	int x,d;
	printf("find number between 0 to ? : ");
	scanf("%d",&d);
	printf("which number(int) do you want to find : ");
	scanf("%d",&x);
	int ans=binary_search(d,s,x);
	if(ans>=0)
		printf("%d is in s[%d]\n",x,ans);
	else
		printf("%d is not exit in array s[]\n",x);
	printf("Time of this algo :  %d ",count);
	return 0;
}

int binary_search(int n,const int s[],int x){
	int loc=-1;//loc is the location of the number in array s[]
	int low,high,mid;

	low=0;
	high=n-1;
	
	while(low<=high && loc==(-1)){
		mid=(low+high)/2;
		count++;
		if(x==s[mid])
			loc=mid;
		else if(x<s[mid])
			high=mid-1;
		else
			low=mid+1;
	}
	return loc;
}


