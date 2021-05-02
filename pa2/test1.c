#include "types.h"
#include "stat.h"
#include "user.h"

int 
main(int argc, char *argv[])
{
	int parent = getpid();
	int child;
	
	if ((child = fork()) == 0)
	{	
		// printf(1, "Hi!2 %d\n", getnice(getpid()));
		setnice(parent, 5);
		// printf(1, "Hi!5 %d\n", getnice(getpid()));	
	}
	else
	{	
		// printf(1, "Hi!1 %d\n", getnice(getpid()));
		setnice(child, 10);
		// printf(1, "Hi!3 %d\n", getnice(getpid()));
		if (getnice(parent) != 5)
			printf(1, "ERROR!!");
		else if (getnice(child) != 10) 
			printf(1, "ERROR!!");
		else
		{
			printf(1, "Parent: %d\n", getnice(parent));
			printf(1, "Child: %d\n", getnice(child));
		}
		// printf(1, "Hi!4 %d\n", getnice(getpid()));
		wait();
		// printf(1, "Hi!7 %d\n", getnice(getpid()));
	}
	// printf(1, "Hi!6 %d\n", getnice(getpid()));
	exit();
}