#include <stdio.h>

void quick_sort(int low, int high,int s[]);
int partition(int low, int high,int s[]);

int count=1;

int main(){
	int s1[10]={12,81,5,3,77,94,1,46,11,25};
	int s2[20]={1,7,8,65,29,48,31,26,78,55,14,76,15,24,9,11,75,22,13,774};
	int s3[30]={19,82,18,54,76,81,22,49,33,15,24,68,78,15,23,146,87,219,512,78,618,249,159,597,1895,324,1954,2192,9,1912};
	printf("Before sorting\n");
	for(int i=0;i<10;i++)
		printf("%d ",s1[i]);
	printf("\n");
	quick_sort(0,9,s1);
	printf("After sorting\n");
	for(int i=0;i<10;i++)
		printf("%d ",s1[i]);
	printf("\n");
	printf("Time of this algo : %d",count);
	
	printf("\n");
	
	printf("Before sorting\n");
	for(int i=0;i<20;i++)
		printf("%d ",s2[i]);
	printf("\n");
	quick_sort(0,19,s2);
	printf("After sorting\n");
	for(int i=0;i<20;i++)
		printf("%d ",s2[i]);
	printf("\n");
	printf("Time of this algo : %d",count);
	
	printf("\n");
	
	printf("Before sorting\n");
	for(int i=0;i<30;i++)
		printf("%d ",s3[i]);
	printf("\n");
	quick_sort(0,29,s3);
	printf("After sorting\n");
	for(int i=0;i<30;i++)
		printf("%d ",s3[i]);
	printf("\n");
	printf("Time of this algo : %d",count);
	return 0;
}

void quick_sort(int low, int high,int s[]){
	int pivotpoint;

	if(high>low){
		pivotpoint=partition(low,high,s);
		quick_sort(low,pivotpoint-1,s);
		quick_sort(pivotpoint+1,high,s);
	}
}

int partition(int low, int high,int s[]){
	int i,j,tmp;
	int pivotitem,pivotpoint;

	pivotitem=s[low];
	j=low;
	for(i=low+1;i<=high;i++)
		if(s[i]<pivotitem){
			count++;
			j++;
			tmp=s[i];
			s[i]=s[j];
			s[j]=tmp;
		}

	pivotpoint = j;
	tmp=s[low];
	s[low]=s[pivotpoint];
	s[pivotpoint]=tmp;
	return pivotpoint;
}
