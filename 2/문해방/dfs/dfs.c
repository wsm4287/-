#include<stdio.h>
#define MAX 100 


int matrix[MAX][MAX];
int visited[MAX] = {0,};
int dot_num,line_num,starting_dot,end_dot,ans = 0;

void dfs(int dot,int st)
{
	int i,check;
	if(dot == end_dot){
	if(ans<st) ans = st;
	 return;
	}
	for(i=0;i<dot_num;i++){
		if((matrix[dot][i] != -1) && (visited[i] != 1)){
			visited[i] = 1;
			printf("adding %d and %d\n",st,matrix[dot][i]);
			dfs(i,st+matrix[dot][i]);
			visited[i] = 0;
		}
	}
}

int main()
{
	int i,j,start,end,line_temp;
	scanf("%d %d",&dot_num,&line_num);
	scanf("%d %d",&starting_dot,&end_dot);
	for(i=0;i<dot_num;i++){
		for(j=0;j<dot_num;j++){
			if(i == j) matrix[i][j] = 0;
			else matrix[i][j] = -1;
		}
	}
	for(i=0;i<line_num;i++){
		scanf("%d %d %d",&start,&end,&line_temp);
		matrix[start][end] = line_temp;
		matrix[end][start] = line_temp;
	}

	visited[starting_dot] = 1;
	dfs(starting_dot,0);
	printf("ans is :%d",ans);
}
