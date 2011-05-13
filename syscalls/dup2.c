/*
 * SYSCALL_DEFINE2(dup2, unsigned int, oldfd, unsigned int, newfd)
 */
#include "trinity.h"
#include "sanitise.h"

struct syscall syscall_dup2 = {
	.name = "dup2",
	.num_args = 2,
	.arg1name = "oldfd",
	.arg1type = ARG_FD,
	.arg2name = "newfd",
	.arg2type = ARG_FD,
};