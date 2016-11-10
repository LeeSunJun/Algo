#include <cstdio>
#include <cmath>
#include <iostream>

typedef int index;
int ifact(int a);

class graph {
private:
	index i, j, k;
	int *W, **D,**P,*DD;
	int city = 0, minlength = 0;

public:
	void Get_state() {
		printf("How many Cities do you want to visit(less than 10) : ");
		scanf_s("%d", &city);

		W = (int*)malloc(sizeof(int)*(city*city + 1));

		for (int i = 1; i < city*city + 1; i++) {
			if((i-1)%city==0)
				printf("Input your W[%d][] (less than 1000,if there is no edge than input -1): ", i/city+1);
			scanf_s("%d", &W[i]);
			if (W[i] == -1)
				W[i] = 10000;
		}

		D = (int**)malloc(sizeof(int)*city+1);
		
		for(int i = 1;i<city+1;i++)
			D[i] = (int*)malloc(sizeof(int)*pow(2, city - 1));

		P = (int**)malloc(sizeof(int)*city + 1);
		for (int i = 1; i<city + 1; i++)
			P[i] = (int*)malloc(sizeof(int)*pow(2, city - 1));
		
		for (int i = 1; i < city + 1; i++)
			for (int j = 0; j < pow(2, city - 1); j++)
				P[i][j] = -1;

		for (int i = 1; i < city + 1; i++)
			for (int j = 0; j < pow(2, city - 1); j++)
				D[i][j] = j;

		DD = (int*)malloc(sizeof(int)*(city + 1));
		for (int i = 0; i < city + 1; i++)
			DD[i] = 0;
	}

	int min(int* T,int check2) {
		int tmp;
		tmp = 10000;
		for (int i = 0; i < check2; i++)
			if (tmp > T[i])
				tmp = T[i];
		return tmp;
	}

	void travel() {
		for (i = 2; i <= city; i++) {
			D[i][0] = W[city*(i - 1) + 1];
		}

		for (k = 1; k <= city - 2; k++)//subset을 이루는 원소 갯수
			for (i = 2; i <= city; i++) {//subset에 들어가지 않는 v1이후에 출발점이되는 vertax
				int check = 0;
				for (int j = 0; j < pow(2, city - 1); j++) {
					int tmp = 0, b = 0, preD = 0, z = 0;
					tmp = j;

					for (int x = city - 2; x >= 0; x--)//check : subset의 원소 갯수, DD[n] : (초기값 -1) subset의 원소값을 대입
						if (tmp >= pow(2, x)) {
							tmp = tmp - pow(2, x);
							check++;
							DD[city - x] = city - x;
						}

					int *T;
					T = (int*)malloc(sizeof(int)*(city + 1)); // subset의 원소가 2개 이상일때 여러 경로의 최소값을 위한 공간

					for (int k = 0; k < city + 1; k++)
						T[k] = 10000;

					for (int n = 2; n < city + 1; n++) {
						int jj, b;
						bool c = true;

						jj = j;

						for (int x = 1; x < city + 1; x++)
							if (DD[x] == i) {
								c = false;
							}

						if (check == k && DD[n] != 0 && c) {
							jj = jj - pow(2, city - DD[n]);
							T[n] = W[city*(i - 1) + DD[n]] + D[DD[n]][jj];//path의 길이 계산
							D[i][j] = min(T, city + 1);

							if (z == 0)
								P[i][j] = DD[n];
							else if (z != 0)
								if (preD != D[i][j] && preD != 0)
									P[i][j] = DD[n];
							//만약 path의 길이가 갱신되면 P[][]을 갱신

							preD = D[i][j];
							z++;
						}
					}
					z = 0;
					preD = 0;
					check = 0;
					for (int n = 0; n < city + 1; n++)
						DD[n] = 0;
				}
			}

		//모든원소를 subset으로 갖는 D,P 계산
		int check = 0;
		int tmp = 0, b = 0, preD = 0, z = 0;
		tmp = pow(2, city - 1) - 1;

		for (int x = city - 2; x >= 0; x--)
			DD[city - x] = city - x;

		int *T;
		T = (int*)malloc(sizeof(int)*(city + 1));

		for (int k = 0; k < city + 1; k++)
			T[k] = 10000;

		int jj;

		for (int n = 2; n < city + 1; n++) {
			jj = pow(2, city - 1) - 1;
			jj = jj - pow(2, city - DD[n]);
			T[n] = W[DD[n]] + D[DD[n]][jj];
			D[1][(int)pow(2, city - 1) - 1] = min(T, city + 1);

			if (z == 0)
				P[1][(int)pow(2, city - 1) - 1] = DD[n];
			else if (z != 0)
				if (preD != D[1][(int)pow(2, city - 1) - 1] && preD != 0)
					P[1][(int)pow(2, city - 1) - 1] = DD[n];

			preD = D[1][(int)pow(2, city - 1) - 1];
			z++;
		}
		minlength = D[1][(int)pow(2, city - 1) - 1];
	}

	void show_info(){
		printf("minlength : %d\n", minlength);
		
		//optimal tour 출력
		int h = (int)pow(2, city - 1) - 1,a = P[1][h] ;
		printf("Path : 1,");//시작지점
		for (int j = 1; j < city; j++) {
			printf(" %d,", a);
			h = h-pow(2,city-a);
			a = P[a][h];
		}
		printf(" 1\n"); //도착지점

	}
};

int main() {
	graph* G = new graph();
	G->Get_state();
	G->travel();
	G->show_info();


	system("pause");
	return 0;
}