#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[])
{
	int ID;
	ID = atoi(argv[1]);
	getnice(ID);
	exit();
}
