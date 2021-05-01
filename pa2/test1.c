#include "types.h"
#include "stat.h"
#include "user.h"

int 
main(int argc, char *argv[])
{
	int parent = getpid();
	int child;
	// printf(1, "Parnt_id: %d\n", parent);

	if ((child = fork()) == 0)
	{	
		// printf(1, "hi1!\n");
		setnice(parent, 5);
		// printf(1, "Parent: %d\n", getnice(parent));
	}
	else
	{	
		// printf(1, "aSDASD\n");
		// printf(1, "Parent: %d\n", getnice(parent));
		setnice(child, 10);
		// printf(1, "Child: %d\n", getnice(child));
		if (getnice(parent) != 5)
			printf(1, "ERROR1!!\n");
		else if (getnice(child) != 10) 
			printf(1, "ERROR2!!\n");
		else
		{
			printf(1, "Parent: %d\n", getnice(parent));
			printf(1, "Child: %d\n", getnice(child));
		}
		wait();
	}
	// printf(1, "hi2!");
	exit();
}