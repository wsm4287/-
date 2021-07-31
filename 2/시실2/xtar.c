#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#define BUF 100

int main(int argc, char **argv)
{
	int a;
	int b;
	int c;
	int fd_src1;
	int fd_src2;
	int fd_dest;
	char buffer[1];
	const char *file_src1 = NULL;
	const char *file_src2 = NULL;
	const char *file_dest = NULL;
	

	if(argc==5){


		file_src1 = argv[3];
		file_src2 = argv[4];
		file_dest = argv[2];

		fd_src1 = open(file_src1, O_RDONLY, 0755);
		fd_src2 = open(file_src2, O_RDONLY, 0755);
		fd_dest = open(file_dest, O_RDWR| O_CREAT, 0755 );


		write(fd_dest, file_src1, strlen(file_src1));
		write(fd_dest, "\n",1);
		while((a=read(fd_src1, buffer,1))!=0)
			write(fd_dest,buffer,1);
		write(fd_dest, "\n",1);
		write(fd_dest, file_src2, strlen(file_src2));
		write(fd_dest, "\n",1);
		while((a=read(fd_src2, buffer,1))!=0)
			write(fd_dest,buffer,1);
		write(fd_dest, "\n",1);

			
	
		close(fd_src1);
		close(fd_src2);
		close(fd_dest);

		}

		
	
	else if(argc==3){
		
		file_dest = argv[2];
		char *save=(char*)malloc(sizeof(char)*100);
		fd_dest = open(file_dest, O_RDONLY, 0755);
		int i=0;
		char *name = (char*)malloc(sizeof(char)*10);
		
		while(1){
			if(read(fd_dest,buffer,1)!=1)
				break;
			save[i++] = buffer[0];

		}
		i=0;

		while(1){
			if(save[i]=='\n')
				break;
			name[i]=save[i];
			i++;
		}
		
		
		fd_src1 = open(name, O_RDWR| O_CREAT, 0755);
		i++;
		
		while(1){
                        if(save[i]=='\n')
                                break;
                        write(fd_src1,save+i,1);
                        i++;

                }

		int j=0;
		for(j=0; j<10; j++)
			name[j]=0;
		j=0;
		i++;
		while(1){
                      		if(save[i]=='\n')
				break;
			name[j++]=save[i];
			
			i++;

                }
		i++;
         
	

		fd_src2 = open(name, O_RDWR| O_CREAT, 0755);


		while(1){
			if(save[i]=='\n')
                             		 break;
                        write(fd_src2,save+i,1);
			i++;
                        
                }


	

	
		close(fd_dest);
		close(fd_src1);
		close(fd_src2);	
		

		
	





	}


	return 0;

}
