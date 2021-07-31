#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[])
{	
	int ID, value;
//	char x[100];
//	int i;
	ID = atoi(argv[1]);
	
/*	if(argv[2][0]!='-')
		value=atoi(argv[2]);
	else{
		for(i=1; argv[2][i]; i++)
			x[i-1]=argv[2][i];
		
		x[i]='\0';
		value = atoi(x);
		value = -1 * value;
	}*/
	value = atoi(argv[2]);
	setnice(ID, value);
	exit();
}
