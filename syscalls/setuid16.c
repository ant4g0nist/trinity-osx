/*
 * SYSCALL_DEFINE1(setuid16, old_uid_t, uid)
 */
#include "trinity.h"
#include "sanitise.h"

struct syscall syscall_setuid16 = {
	.name = "setuid16",
	.num_args = 1,
	.arg1name = "uid",
};
