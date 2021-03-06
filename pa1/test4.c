#include "types.h"
#include "stat.h"
#include "user.h"

#define NTHREAD 7

void *stack[NTHREAD];
int tid[NTHREAD];
void *retval[NTHREAD];

void *thread(void *arg){
	thread_exit((void *)gettid());
	return 0;
}

int
main(int argc, char **argv)
{
	int i;

	printf(1, "TEST4: ");

	for(i=0;i<NTHREAD;i++)
		stack[i] = malloc(4096);
	// printf(1, "1\n");
	for(i=0;i<NTHREAD; i++){
		tid[i] = thread_create(thread, 0, stack[i]);
		if(tid[i] == -1){
			printf(1, "WRONG\n");
			exit();
		}
	}
	// printf(1, "2\n");
	for(i=0;i<NTHREAD;i++){
		if(thread_join(tid[i], &retval[i]) == -1){
			printf(1, "WRONG\n");
			exit();
		}
	}
	// printf(1, "3\n");
	for(i=0;i<NTHREAD;i++){
		if(tid[i] != (int)retval[i]){
			printf(1, "WRONG\n");
			exit();
		}
	}
	//printf(1, "4\n");
	for(i=0;i<NTHREAD;i++)
		free(stack[i]);

	printf(1, "OK\n");

	exit();
}
