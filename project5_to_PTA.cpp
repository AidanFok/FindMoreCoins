#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int cmp(const void* ta, const void* tb){ //used for sort to make them decrease
	int* a = (int*)ta;
	int* b = (int*)tb;
	return *a<*b;
}
int dypr[10005][105], pre[10005][105]; //the table to record the info
int array[10005], ans[10005];   //the table to record the info,array for the coin you have
int main(){
	int i, j, n, m;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++){  //input the coins you have
		scanf("%d", &array[i]);
	}
	for(int h=1;h<=n;h++){ //sort the array decreased and make the array begin from [1]
	for(int k=1;k<=n-h;k++){
		  if(array[k]<array[k+1])
		{int t=array[k];array[k]=array[k+1];array[k+1]=t;}
		}
	}
	for (i = 0; i <= n; i++){     //initialize the recording table
	for (j = 0; j <= m; j++){
			dypr[i][j] = 0;
			pre[i][j] = 0;
		}
	}
	for (i = 0; i <= n; i++){   //initialize the table to make it contains value 0
		dypr[i][0] = 1;
	}
	for (i = 1; i <= n; i++){   //to make the table and make the i traverse
		for (j = array[i]; j <= m; j++){ //for each i ,traverse from the first array number 
			if (dypr[i - 1][j - array[i]]){  //to judge if sum of the list small than the sum
				dypr[i][j] = 1;//if we find it is small ,record it
				pre[i][j] = 1;//record to find the before value for the end finding path
			}
			else{
				dypr[i][j] = dypr[i - 1][j]; //if not , inherit the before value
			}
		}
	}
	if (!dypr[n][m]){  //no situation judge and output
		printf("No Solution\n");
	}
	else{
		int temp = 0;
		while (n>0){
			if (pre[n][m]){  //use it to find all the vlaue it contains
				ans[temp] = array[n];
				m = m - array[n];//the before way to research
				n = n - 1;
				temp++;
			}
			else
				n--;
		}
		for (i = 0; i<temp - 1; i++){
			printf("%d ", ans[i]);  //print the answer
		}
		printf("%d\n", ans[temp - 1]);
	}
	system("pause");
	return 0;
}