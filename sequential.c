#include <stdio.h>

int sequential_search(int n, const int s[], int x);

int count=1;

int main(){
	int s[30]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29};
	int x,d;
	printf("find number between 0 to ? : ");
	scanf("%d",&d);
	printf("which number(int) do you want to find : ");
	scanf("%d",&x);
	int ans=sequential_search(d,s,x);
	if(ans>=0)
		printf("%d is in s[%d]\n",x,ans);
	else	
		printf("%d is not exist in array s[]\n",x);
	printf("Time of this algo : %d ",count);

	return 0;
}

int sequential_search(int n,const int s[], int x){
	int loc=0;//loc is the location of the number in array s[]
	while(loc<n && s[loc] != x){
		count++;
		loc++;
	}
	if(loc>n-1)
		return -1;
}
