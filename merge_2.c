#include <stdio.h>

void merge_sort(int n, int s[]);
void merge(int h, int m, const int U[], const int V[], int s[]);

int count=1;

int main(){
	int s[8]={27,10,12,20,25,13,15,22};
	printf("Before sorting\n");
	for(int i=0;i<8;i++)
		printf("%d ",s[i]);
	printf("\n");
	merge_sort(8,s);
	printf("After sorting\n");
	for(int i=0;i<8;i++)
		printf("%d ",s[i]);
	printf("\n");
	printf("Time of this algo : %d",count);
	return 0;
}

void merge_sort(int n,int s[]){
	if(n>1){
		const int h=n/2;
		const int m=n-h;
		
		int U[h],V[m];

		for(int i=0;i<h;i++)
			U[i]=s[i];
		for(int i=0;i<m;i++)
			V[i]=s[h+i];

	printf("U : ");
	for(int c=0;c<h;c++)
		printf("%d ",U[c]);
	printf("    ");
	printf("V : ");
	for(int c=0;c<m;c++)
		printf("%d ",V[c]);
	printf("    ");
	printf("s : ");
	for(int c=0;c<8;c++)
		printf("%d ",s[c]);
	printf("\n");
	printf("1111\n");
	printf("\n");

		merge_sort(h,U);
		merge_sort(m,V);
	printf("U : ");
	for(int c=0;c<h;c++)
		printf("%d ",U[c]);
	printf("    ");
	printf("V : ");
	for(int c=0;c<m;c++)
		printf("%d ",V[c]);
	printf("    ");
	printf("s : ");
	for(int c=0;c<8;c++)
		printf("%d ",s[c]);
	printf("\n");

	printf("2222\n");
	printf("\n");

		merge(h,m,U,V,s);
	
		printf("U : ");
	for(int c=0;c<h;c++)
		printf("%d ",U[c]);
	printf("    ");
	printf("V : ");
	for(int c=0;c<m;c++)
		printf("%d ",V[c]);
	printf("    ");
	printf("s : ");
	for(int c=0;c<8;c++)
		printf("%d ",s[c]);
	printf("\n");
	printf("3333\n");
	printf("\n");
	}
}

void merge(int h, int m, const int U[], const int V[], int s[]){
	/*printf("U : ");
	for(int c=0;c<h;c++)
		printf("%d ",U[c]);
	printf("    ");
	printf("V : ");
	for(int c=0;c<m;c++)
		printf("%d ",V[c]);

	for(int c=0;c<8;c++)
		printf("%d ",s[c]);
	printf("\n");*/
	
	int i,j,k;
	i=1; j=1; k=1;
	while(i<=h && j<=m){
		count++;
		if(U[i-1] < V[j-1]){
			s[k-1] = U[i-1];
			i++;

		}
		else{
			s[k-1] = V[j-1];
			j++;
		}
		k++;
	}

	if(i-1>h)
		for(int c=0;c<m-j+2;c++)
			s[k+c-1]=V[j+c];
	else
		for(int c=0;c<h-i+2;c++)
			s[k+c-1]=U[i+c];
}

