#include <iostream>
#include "mpi.h"

using namespace std;

int x, y, n, p;

int main(int argc, char* argv[]){

	p = atoi(argv[1]);	
	n = atoi(argv[2]);
	x = atoi(argv[3]);
	y = atoi(argv[4]);

	int rank, s;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	s = y/p;

	if(rank == 0){
		int **cell;
	        cell = new int*[y];
		for(int i=0; i<y; i++)
			cell[i] = new int[x];
	
		int x1, y1;
	
		while(!cin.eof()){
			cin >> x1 >> y1;
			cell[y1][x1] = 1;
		}

		int **part = new int*[s];
		for(int i=0; i<s; i++)
			part[i] = new int[x];
	
		for(int k=0; k<p; k++){
			for(int i=0; i<s; i++){
				for(int j=0; j<x; j++){
					part[i][j] = cell[i+k*s][j];
				}
			}
			MPI_Send(&part, x*s, MPI_INT, k, 0, MPI_COMM_WORLD);
		}

		for(int k=0; k<p; k++){
			MPI_Recv(&part, x*s, MPI_INT, k, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			for(int i=0; i<s; i++){
				for(int j=0; j<x; j++){
					cell[i+k*s][j] = part[i][j];
				}
			}
		}

		delete[] part;

		for(int i=1 ; i<y+1; i++){
			for(int j=1; j<x+1; j++){
				if(cell[i][j])
					cout << j << i << endl;
			}
		}
	
		delete[] cell;


	}

	else{
		int **part2 = new int*[s];
		for(int i=0; i<s; i++)
			part2[i] = new int[x];
		MPI_Recv(&part2, x*s, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		
		int *su = new int[x];
		int *ru = new int[x];
		int *sd = new int[x];
		int *rd = new int[x];
		

		for(int k=0; k<n; k++){	
		
			if(rank>1){
				MPI_Recv(&ru, x, MPI_INT, rank-1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				for(int i=0; i<x; i++) su[i] = part2[0][i];
				MPI_Send(&su, x, MPI_INT, rank-1, 0, MPI_COMM_WORLD);
			}
			if(rank<p-1){
				MPI_Recv(&rd, x, MPI_INT, rank+1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				for(int i=0; i<x; i++) sd[i] = part2[s-1][i];
				MPI_Send(&sd, x, MPI_INT, rank+1, 0, MPI_COMM_WORLD);
			}
				
			
		
			int **temp;
			temp = new int*[s];
			for(int i=0; i<s; i++)
				temp[i] = new int[x];
		
			int num, h, w;
	
			for(h=0; h<s; h++){
				for(w=0; w<x; w++){

				if(h==0){
					if(w!=0 && w!=x-1) num = ru[w-1]+ru[w]+ru[w+1]+part2[h][w-1]+part2[h][w+1]+part2[1][w-1]+part2[1][w]+part2[1][w+1];
					else if(w==0) num = ru[w]+ru[w+1]+part2[h][w+1]+part2[1][w]+part2[1][w+1];
					else num = ru[w-1]+ru[w]+part2[h][w-1]+part2[1][w-1]+part2[1][w];
				}
				else if(h==s-1){
					if(w!=0 && w!=x-1) num = part2[h-1][w-1]+part2[h-1][w]+part2[h-1][w+1]+part2[h][w-1]+part2[h][w+1]+rd[w-1]+rd[w]+rd[w+1];
					else if(w==0) num = part2[h-1][w]+part2[h-1][w+1]+part2[h][w+1]+rd[w]+rd[w+1];
					else num = part2[h-1][w-1]+part2[h-1][w]+part2[h][w-1]+rd[w-1]+rd[w];
				}
				else{
					if(w!=0 && w!=x-1) num = part2[h-1][w-1]+part2[h-1][w]+part2[h-1][w+1]+part2[h][w-1]+part2[h][w+1]+part2[h+1][w-1]+part2[h+1][w]+part2[h+1][w+1];
					else if(w==0) num = part2[h-1][w]+part2[h-1][w+1]+part2[h][w+1]+part2[h][w]+part2[h][w+1];
					else num = part2[h-1][w-1]+part2[h-1][w]+part2[h][w-1]+part2[h][w-1]+part2[h][w];

				}

				if(num == 3) temp[h][w] = 1;
				else if(num == 2 && part2[h][w]==1) temp[h][w] = 1;
				else if(num > 3 && part2[h][w]==1) temp[h][w] = 0;

				}

	
			}
			for(h=0; h<s; h++){
				for(w=0; w<x; w++){
					part2[h][w] = temp[h][w];
				}
			}

			MPI_Send(&part2, x*s, MPI_INT, 0, 0, MPI_COMM_WORLD);

			delete[] temp;
			delete[] su;
			delete[] ru;
			delete[] sd;
			delete[] rd;
			delete[] part2;
		}
	}

	MPI_Finalize();

	return 0;
}