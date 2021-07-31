//-----------------------------------------------------------
//
// SSE2033 : System Software Experiment 2 (Fall 2019)
//
// Skeleton Code for PA#3
//
// Oct 28, 2019.
// CSI, Sungkyunkwan University
//
// Forked by http://csapp.cs.cmu.edu/public/ics2/code/ecf/shellex.c
//-----------------------------------------------------------


/* $begin shellmain */
#define MAXARGS   128
#define MAXLINE	  256
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>

/* function prototypes */
void eval(char *cmdline);
void m_path(char **argv);
void my_ls(char **argv);
void my_man(char **argv);
void my_grep(char **argv);
void my_sort(char **argv);
void my_awk(char **argv);
void my_bc(char **argv);
void my_head(char **argv);
void my_tail(char **argv);
void my_cat(char **argv);
void my_cp(char **argv);
void my_mv(char **argv);
void my_rm(char **argv);
void my_cd(char **argv);
void my_pwd();
void my_exit(char **argv);
void end(int sig);
int parseline(char *buf, char **argv);
int builtin_command(char **argv); 
int re_in(char **argv, int fd);
int re_out(char **argv, int fd);
void pipeline(char **argv);
void my_sig(int sig);
int pp[5];
int num=0;
int x= 0;
int in = 0;
int out =0;

int main() 
{
    signal(SIGINT,end);
    signal(SIGTSTP,end);
    signal(SIGCHLD, my_sig);
    char cmdline[MAXLINE]; /* Command line */
	char* ret;
    while (1) {
	/* Read */
	printf("swsh> ");                   
	ret = fgets(cmdline, MAXLINE, stdin); 
	if (feof(stdin) || ret == NULL)
	    exit(0);

	/* Evaluate */
	eval(cmdline);
    } 
}
/* $end shellmain */
  
/* $begin eval */
/* eval - Evaluate a command line */
void eval(char *cmdline) 
{
    char *argv[MAXARGS]; /* Argument list execve() */
    char buf[MAXLINE];   /* Holds modified command line */
    int bg;              /* Should the job run in bg or fg? */
    pid_t pid;           /* Process id */
    strcpy(buf, cmdline);
    bg = parseline(buf, argv); 
    if (argv[0] == NULL)  
	return;   /* Ignore empty lines */

    if (!builtin_command(argv)) { 
	if ((pid = fork()) == 0) {   /* Child runs user job */
	    if (execv(argv[0], argv) < 0) {
		fprintf(stderr,"%s: Command not found.\n", argv[0]);
		exit(0);
	    }
	}

	/* Parent waits for foreground job to terminate */
	if (!bg) {
	    int status;
	    if (waitpid(pid, &status,  0) < 0)
			printf("waitfg: waitpid error");
	}
	else
	    printf("%d %s", pid, cmdline);
    }
    return;
}

/* If first arg is a builtin command, run it and return true */
int builtin_command(char **argv) 
{
    if (!strcmp(argv[0], "quit")) /* quit command */
	exit(0);  
    if (!strcmp(argv[0], "&"))    /* Ignore singleton & */
	return 1;

	int k;
	in = out = num = 0;
	for(k=0; argv[k]!=NULL; k++){
		if(strcmp(argv[k],"<")==0)
			in = k+1;
		else if(strcmp(argv[k],">")==0)
			out = k+1;
		else if(strcmp(argv[k], ">>")==0)
			out = k+1;
		else if(strcmp(argv[k], "|")==0)
			pp[num++] = k+1;
	}	
	if(num!=0){
		pipeline(argv);
		return 1;
		}
	if(!strcmp(argv[0], "ls"))
	{

		my_ls(argv);
		return 1;
	}
 
	if(!strcmp(argv[0], "man"))
	{
		my_man(argv);
		return 1;
	}

	if(!strcmp(argv[0], "grep"))
	{
		my_grep(argv);
		return 1;
	}

	if(!strcmp(argv[0], "sort"))
	{
		my_sort(argv);
		return 1;
	}
	if(!strcmp(argv[0], "awk"))
	{
		my_awk(argv);
		return 1;
	}

	if(!strcmp(argv[0], "bc"))
	{
		my_bc(argv);
		return 1;
	}			// type1

	if(!strcmp(argv[0], "head"))
	{
		my_head(argv);
		return 1;
	}

	if(!strcmp(argv[0], "tail"))
	{
		my_tail(argv);
		return 1;
	}

	if(!strcmp(argv[0], "cat"))
	{
		my_cat(argv);
		return 1;
	}

	if(!strcmp(argv[0], "cp"))
	{
		my_cp(argv);
		return 1;
	}			//type2
	

	if(!strcmp(argv[0], "mv"))
	{
		my_mv(argv);
		return 1;
	}

	if(!strcmp(argv[0], "rm"))
	{
		my_rm(argv);
		return 1;
	}

	if(!strcmp(argv[0], "cd"))
	{
		my_cd(argv);
		return 1;
	}			//type3

	if(!strcmp(argv[0], "pwd"))
	{
		my_pwd();
		return 1;
	}	

	if(!strcmp(argv[0], "exit"))
	{
		my_exit(argv);
		return 1;
	}			//type4


	if(!strncmp(argv[0],"./",2))
	{
		my_path(argv);
		return 1;
	}

	

    return 0;                     /* Not a builtin command */
	
}
/* $end eval */

/* $begin parseline */
/* parseline - Parse the command line and build the argv array */
int parseline(char *buf, char **argv) 
{
    char *delim;         /* Points to first space delimiter */
    int argc;            /* Number of args */
    int bg;              /* Background job? */

    buf[strlen(buf)-1] = ' ';  /* Replace trailing '\n' with space */
    while (*buf && (*buf == ' ')) /* Ignore leading spaces */
	buf++;

    /* Build the argv list */
    argc = 0;
    while ((delim = strchr(buf, ' '))) {
	argv[argc++] = buf;
	*delim = '\0';
	buf = delim + 1;
	while (*buf && (*buf == ' ')) /* Ignore spaces */
	       buf++;
    }
    argv[argc] = NULL;
    x=argc;
    
    if (argc == 0)  /* Ignore blank line */
	return 1;

    /* Should the job run in the background? */
    if ((bg = (*argv[argc-1] == '&')) != 0)
	argv[--argc] = NULL;

    return bg;
}
/* $end parseline */

void my_path(char **argv)
{
	pid_t pid; 
	int status;

	if((pid=(fork()==0))){
		int fd[2];
		if(pipe(fd)<0) end(2);

		if(in!=0){
			if(re_in(argv,fd[0])==-1)
				return;
			if(out!=0)
				out = out - 2;
		}
		if(out!=0){
			if(re_out(argv,fd[1])==-1)
				return;
		}
		execv(argv[0], argv);
	}

	in = 0;
	out = 0;

	waitpid(pid, &status,  WUNTRACED);
	waitpid(pid, &status,  WNOHANG);
}

void my_ls(char **argv)
{
	pid_t pid; 
	int status;

	if((pid=(fork()==0))){
		int fd[2];
		if(pipe(fd)<0) end(2);

		if(in!=0){
			if(re_in(argv,fd[0])==-1)
				return;
			if(out!=0)
				out = out - 2;
			}	
		if(out!=0){
			if(re_out(argv,fd[1])==-1)
				return;
		}
		execv("/bin/ls", argv);
	}


	in = 0;
	out = 0;

	waitpid(pid, &status,  WUNTRACED);
	waitpid(pid, &status,  WNOHANG);

}

void my_man(char **argv)
{
	pid_t pid; 
	int status;	

	if((pid=(fork()==0))){
		execv("/usr/bin/man", argv);
	}


	waitpid(pid, &status,  WUNTRACED);
	waitpid(pid, &status,  WNOHANG);

}

void my_grep(char **argv)
{
	pid_t pid; 
	int status;
	
	if((pid=(fork()==0))){
		int fd[2];
		if(pipe(fd)<0) end(2);
		if(in!=0){
			if(re_in(argv,fd[0])==-1)
				return;
			if(out!=0)
				out = out - 2;
			}	
		if(out!=0){
			if(re_out(argv,fd[1])==-1)
				return;
		}

		execv("/bin/grep", argv);
	}


	in = 0;
	out = 0;	

	waitpid(pid, &status,  WUNTRACED);
	waitpid(pid, &status,  WNOHANG);
}
void my_sort(char **argv)
{
	pid_t pid; 
	int status;	

	if((pid=(fork()==0))){
		int fd[2];
		if(pipe(fd)<0) end(2);

		if(in!=0){
			if(re_in(argv,fd[0])==-1)
				return;
			if(out!=0)
				out = out - 2;
			}	
		if(out!=0){
			if(re_out(argv,fd[1])==-1)
				return;
		}

		execv("/usr/bin/sort", argv);
	}

	in = 0;
	out = 0;

	waitpid(pid, &status,  WUNTRACED);
	waitpid(pid, &status,  WNOHANG);

}
void my_awk(char **argv)
{
	pid_t pid; 
	int status;

	if((pid=(fork()==0))){
		int fd[2];
		if(pipe(fd)<0) end(2);

		if(in!=0){
			if(re_in(argv,fd[0])==-1)
				return;
			if(out!=0)
				out = out - 2;
			}	
		if(out!=0){
			if(re_out(argv,fd[1])==-1)
				return;
		}
		execv("/usr/bin/awk", argv);
	}

	in = 0;
	out = 0;		

	waitpid(pid, &status,  WUNTRACED);
	waitpid(pid, &status,  WNOHANG);

}
void my_bc(char **argv)
{
	pid_t pid; 
	int status;	


	if((pid=(fork()==0))){
		int fd[2];
		if(pipe(fd)<0) end(2);

		if(in!=0){
			if(re_in(argv,fd[0])==-1)
				return;
			if(out!=0)
				out = out - 2;
			}	
		if(out!=0){
			if(re_out(argv,fd[1])==-1)
				return;
		}

		execv("/usr/bin/bc", argv);
	}

	in = 0;
	out = 0;

	waitpid(pid, &status,  WUNTRACED);
	waitpid(pid, &status,  WNOHANG);
}

void my_head(char **argv)
{
	int fd[2];
	if(pipe(fd)<0) end(2);

	if(in!=0){
		pid_t pid;
		int status;
		
		if((pid=(fork()==0))){
			if(re_in(argv,fd[0])==-1)
				return;
			if(out!=0)
				out = out - 2;
			if(out!=0){
				if(re_out(argv,fd[1])==-1)
					return;
			}

			execv("/usr/bin/head", argv);
		}
		waitpid(pid, &status,  WUNTRACED);
		waitpid(pid, &status,  WNOHANG);
	}

	else{
		const char *file_src = NULL;

		int fd_src;
		int a;
		char buffer[1];
		char *l = (char*)malloc(sizeof(char)*1000);


		if(x==2){
			file_src = argv[1];
			fd_src = open(file_src, O_RDONLY, 0755);

			int i=0;
			while(((a=read(fd_src, buffer,1))!=0)&&(i<1000))
				l[i++]=buffer[0];
			l[i]='\0';
			int k=0;
			i=0;
	
			for(k=0; k<10; k++){
					while(1){
						printf("%c", l[i++]);
						if(l[i]=='\n')
							break;
						}		
			}
			printf("\n");
				
		}
		

		else{
			file_src = argv[3];
			fd_src = open(file_src, O_RDONLY, 0755);
	
			int i=0;
			while(((a=read(fd_src, buffer,1))!=0)&&(i<1000))
				l[i++]=buffer[0];
			l[i]='\0';
			int k=0;
			i=0;
			int j = atoi(argv[2]);
			for(k=0; k<j; k++){
					while(1){
						printf("%c", l[i++]);
						if(l[i]=='\n')
							break;
						}		
			}
			printf("\n");
			
		}
		free(l);
		close(fd_src);

		}
	in = 0;
	out = 0;


}
void my_tail(char **argv)
{
	int fd[2];
	if(pipe(fd)<0) end(2);

	if(in!=0){
		pid_t pid;
		int status;
		
		if((pid=(fork()==0))){
			if(re_in(argv,fd[0])==-1)
				return;
			if(out!=0)
				out = out - 2;
			if(out!=0){
				if(re_out(argv,fd[1])==-1)
					return;
			}
			execv("/usr/bin/tail", argv);
		}
		waitpid(pid, &status,  WUNTRACED);
		waitpid(pid, &status,  WNOHANG);
	}

	else{
		if(out!=0)
			re_out(argv,fd[1]);

		const char *file_src = NULL;

		int fd_src;
		int a;
		char buffer[1];
		char *l = (char*)malloc(sizeof(char)*1000);
		char *ta = (char*)malloc(sizeof(char)*100);

		if(x==2){
			file_src = argv[1];
			fd_src = open(file_src, O_RDONLY, 0755);
			int i=0;
			int n=-3;
			int p=0;
			while(((a=read(fd_src, buffer,1))!=0)&&(p<10)){
				lseek(fd_src,n--, SEEK_END);
				l[i++]=buffer[0];
				if(buffer[0]=='\n')
					p++;
				}
			l[i-1]='\0';
			i=i-2;
			int k=0;
			int t=0;
			p=0;

			for(k=0; k<10; k++){
					while(1){
						if(l[i--]=='\n')
							break;
						p++;
						}
					p++;
					for(t=p; t>=0; t--)
						ta[t] = l[i+p-t];
					ta[p]='\0';
					printf("%s", ta);	
					p=0;
			}
			printf("\n");	
		}
		

		else{
			int j = atoi(argv[2]);

			file_src = argv[3];
			fd_src = open(file_src, O_RDONLY, 0755);
			int i=0;
			int n=-3;
			int p=0;

			lseek(fd_src, -2, SEEK_END);
			while(((a=read(fd_src, buffer,1))!=0)&&(p<j)){
				lseek(fd_src,n--, SEEK_END);
				l[i++]=buffer[0];
				if(buffer[0]=='\n')
					p++;
				}
			l[i-1]='\0';
			i=i-2;
			int k=0;
			int t=0;
			p=0;
		
			for(k=0; k<j; k++){
					while(1){
						if(l[i--]=='\n')
							break;
						p++;
						}
					p++;
					for(t=p; t>=0; t--)
						ta[t] = l[i+p-t];
					ta[p]='\0';
					printf("%s", ta);	
					p=0;
			}
			printf("\n");	
		}	
		free(l);
		free(ta);
		close(fd_src);

		}
	in = 0;
	out = 0;
	

}
void my_cat(char **argv)
{
	int fd[2];
	if(pipe(fd)<0) end(2);

	if(in!=0){
		pid_t pid;
		int status;
		if((pid=(fork()==0))){
			if(re_in(argv,fd[0])==-1)
				return;
			if(out!=0)
				out = out - 2;
			if(out!=0){
				if(re_out(argv,fd[1])==-1)
					return;
			}

			execv("/bin/cat", argv);
		}
		waitpid(pid, &status,  WUNTRACED);
		waitpid(pid, &status,  WNOHANG);
	}

	else{
		if(out!=0)
			re_out(argv,fd[1]);

		const char *file_src = NULL;

		int fd_src;
		int a;
		char buffer[1];

		file_src = argv[1];
		fd_src = open(file_src, O_RDONLY, 0755);

		while((a=read(fd_src, buffer,1))!=0)
			if(write(1,buffer,1));	
		close(fd_src);

	}
	in = 0;
	out = 0;

	
}
void my_cp(char **argv)
{
	const char *file_src = NULL;
	const char *file_dest = NULL;
	
	int fd_src;
	int fd_dest;
	int a;
	char buffer[1];

	file_src = argv[1];
	file_dest = argv[2];
	fd_src = open(file_src, O_RDONLY, 0755);
	fd_dest = open(file_dest, O_RDWR| O_CREAT, 0755 );

	while((a=read(fd_src, buffer,1))!=0)
		if(write(fd_dest,buffer,1));	
	close(fd_src);
	close(fd_dest);

}
void my_mv(char **argv)
{
	const char *file_src = NULL;
	const char *file_dest = NULL;
	char *buf = (char*)malloc(sizeof(char)*100);

	int fd_src;
	int fd_dest;
	int a;
	char buffer[1];

	struct stat sb;
	stat(argv[1], &sb);
	switch (sb.st_mode & S_IFMT){
		case S_IFDIR:{
			errno = EISDIR;
			perror("");
			free(buf);
			return;
			}
		}

	int mode = R_OK & W_OK & X_OK;

	if(access(argv[1], mode)!=0){
		errno  = EACCES;
		perror("");
		free(buf);
		return ;
		}	

	stat(argv[x-1], &sb);
	
	int rename=0;
	switch (sb.st_mode & S_IFMT){
		case S_IFDIR :{
			strcpy(buf, "./");
			strcat(buf, argv[x-1]);
			strcat(buf, "/");
			break;
		}
		default : rename=1;
	}

	int i;
	for(i=1; i<x-1; i++){
		
		char *q = (char*)malloc(sizeof(char)*100);
		strcpy(q,buf);
		file_src = argv[i];
		strcat(q, argv[i]);
		if(rename== 0)
			file_dest = q;
		else
			file_dest = argv[2];

		fd_src = open(file_src, O_RDONLY, 0755);
		fd_dest = open(file_dest, O_RDWR| O_CREAT, 0755 );

		if(fd_src==-1){
			errno  = ENOENT;
			perror("");
			free(buf);
			close(fd_src);
			close(fd_dest);
			return ;
			}

		while((a=read(fd_src, buffer,1))!=0)
			if(write(fd_dest,buffer,1));
		
		free(q);
		close(fd_src);
		close(fd_dest);
		unlink(argv[i]);
	}
	free(buf);
}
void my_rm(char **argv)
{

	int i;
	struct stat sb;
	const char *file_src = NULL;
	for(i=0; i<x-1; i++){
		int fd_src;
		stat(argv[i+1], &sb);

		switch (sb.st_mode & S_IFMT){
			case S_IFDIR:{
				errno = EISDIR;
				perror("");
				return;
				}
		}

		file_src = argv[i+1];
		fd_src = open(file_src, O_RDONLY, 0755);	
		if(fd_src==-1){
			errno  = ENOENT;
			perror("");
			return ;
		}

		int mode = R_OK & W_OK & X_OK;

		if(access(argv[i+1], mode)!=0){
			errno  = EACCES;
			perror("");
			close(fd_src);
			return ;
			}	

		close(fd_src);
		unlink(argv[i+1]);
		}

}
void my_cd(char **argv)
{
	char *path;
	struct stat sb;
	if(x > 1){
		stat(argv[1], &sb);
		switch (sb.st_mode & S_IFMT){
			case S_IFDIR: {
				path = argv[1]; 
				break;
				}
			default : {
				errno = ENOTDIR;
				perror("");
				return;
				}
			}
		int mode = R_OK & W_OK & X_OK;

		if(access(argv[1], mode)!=0){
			errno  = EACCES;
			perror("");
			return ;
			}	
	}
	else {
		path = ".";
	}
	if(chdir(path));

}
void my_pwd()
{
	char buf[100];
	if(getcwd(buf,100));
	printf("%s\n", buf);	
}
void my_exit(char **argv)
{
	printf("exit\n");
	if(x==1)
		exit(0);
	else{
		int a = atoi(argv[1]);
		exit(a);	
	}
}

void end(int sig){
	kill(-1,SIGCHLD);
}

void my_sig(int sig){
	while(wait(0)>0);
}

int re_in(char **argv, int fd){
	int i;
	if(!argv[in]){
		errno = EACCES;
		perror("swsh");
		return -1;
	}
	else{
		if((fd=open(argv[in],O_RDONLY)) ==-1){
			perror("swsh");
			return -1;
		}
	}

	dup2(fd,0);
	close(fd);

	for(i = in-1; argv[i]!=NULL; i++){
		argv[i] = argv[i+2];
	}
		
		argv[i]=NULL;
	return 1;

}

int re_out(char **argv, int fd){
	int i;
	if(!argv[out]){
		errno = EACCES;
		perror("swsh");
		return -1;
		}
	else{
		if((fd=open(argv[out],O_RDWR | O_CREAT, 0755)) ==-1){
			perror("swsh");
			return -1;
		}
		if(strcmp(argv[out-1],">>")==0)
			lseek(fd,0,SEEK_END);
	}

	dup2(fd,1);
	close(fd);
	for(i = out-1; argv[i]!=NULL; i++){
		argv[i] = argv[i+2];
	}
	
		argv[i]=NULL;

	return 1;
}

void pipeline(char **argv){
	int i;
	int k = 0;
	pid_t pid1, pid2;
	int fd[2];
	int status1, status2;
	
	char **buf = (char **)malloc(sizeof(char *)*(pp[k]));
	char **buf2 = (char **)malloc(sizeof(char *)*(x-pp[k]+2));

	for(i=0; i < pp[k]-1; i++){
		buf[i] = (char *) malloc(sizeof(char)*20);
		strcpy(buf[i], argv[i]);
	}
	buf[i]= NULL;
	for(i= 0; argv[i+pp[k]]!=NULL; i++){
		buf2[i] = (char *) malloc(sizeof(char)*20);
		strcpy(buf2[i], argv[i+pp[k]]);
	}
	buf2[i] =NULL;

	
	k=0;
	
	if(pipe(fd)<0) end(2);

	in = out = num = 0;

	if((pid1=(fork()==0))){
		x = pp[k]-1;
		dup2(fd[1],1);
		close(fd[0]);
		close(fd[1]);
		builtin_command(buf);
	}
	waitpid(pid1, &status1,  WUNTRACED);
	waitpid(pid1, &status1,  WNOHANG);
		

	if((pid2=(fork()==0))){
		x = x - pp[k]+1;
		dup2(fd[0],0);
		close(fd[0]);
		close(fd[1]);
		builtin_command(buf2);
	}

	waitpid(pid2, &status2,  WUNTRACED);
	waitpid(pid2, &status2,  WNOHANG);
	
	

	for(i=0; i<pp[k]; i++){
		free(buf[i]);
	}

	for(i=0; i<x-pp[k]+2; i++){
		free(buf2[i]);
	}
	free(buf);
	free(buf2);

}
