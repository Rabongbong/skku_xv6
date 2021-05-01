#include "syscall.h"
#include "traps.h"

#define SYSCALL(name) \
  .globl name; \
  name: \
    movl $SYS_ ## name, %eax; \
    int $T_SYSCALL; \
    ret

SYSCALL(fork)
SYSCALL(exit)
SYSCALL(wait)
SYSCALL(pipe)
SYSCALL(read)
SYSCALL(write)
SYSCALL(close)
SYSCALL(kill)
SYSCALL(exec)
SYSCALL(open)
SYSCALL(mknod)
SYSCALL(unlink)
SYSCALL(fstat)
SYSCALL(link)
SYSCALL(mkdir)
SYSCALL(chdir)
SYSCALL(dup)
SYSCALL(getpid)
SYSCALL(sbrk)
SYSCALL(sleep)
SYSCALL(uptime)
SYSCALL(shout)
SYSCALL(ps)
SYSCALL(thread_create)
SYSCALL(thread_join)
SYSCALL(thread_exit)
SYSCALL(gettid)  
/*SYSCALL(test1)
SYSCALL(test2)
SYSCALL(test3)
SYSCALL(test4)
SYSCALL(test5)
SYSCALL(test6)
SYSCALL(test7) */



