/*
 * SYSCALL_DEFINE4(sendmmsg, int, fd, struct mmsghdr __user *, mmsg,
 *	unsigned int, vlen, unsigned int, flags)
 */

#define MSG_OOB         1
#define MSG_PEEK        2
#define MSG_DONTROUTE   4
#define MSG_TRYHARD     4       /* Synonym for MSG_DONTROUTE for DECnet */
#define MSG_CTRUNC      8
#define MSG_PROBE       0x10    /* Do not send. Only probe path f.e. for MTU */
#define MSG_TRUNC       0x20
#define MSG_DONTWAIT    0x40    /* Nonblocking io                */
#define MSG_EOR         0x80    /* End of record */
#define MSG_WAITALL     0x100   /* Wait for a full request */
#define MSG_FIN         0x200
#define MSG_SYN         0x400
#define MSG_CONFIRM     0x800   /* Confirm path validity */
#define MSG_RST         0x1000
#define MSG_ERRQUEUE    0x2000  /* Fetch message from error queue */
#define MSG_NOSIGNAL    0x4000  /* Do not generate SIGPIPE */
#define MSG_MORE        0x8000  /* Sender will send more */
#define MSG_WAITFORONE  0x10000 /* recvmmsg(): block until 1+ packets avail */
#define MSG_CMSG_CLOEXEC 0x40000000     /* Set close_on_exit for file
                                           descriptor received through
                                           SCM_RIGHTS */
#define MSG_CMSG_COMPAT 0x80000000      /* This message needs 32 bit fixups */

#include "trinity.h"
#include "sanitise.h"

struct syscall syscall_sendmmsg = {
	.name = "sendmmsg",
	.num_args = 4,
	.arg1name = "fd",
	.arg1type = ARG_FD,
	.arg2name = "mmsg",
	.arg2type = ARG_ADDRESS,
	.arg3name = "vlen",
	.arg3type = ARG_LEN,
	.arg4name = "flags",
	.arg4type = ARG_LIST,
	.arg4list = {
		.num = 19,
		.values = { MSG_OOB, MSG_PEEK, MSG_DONTROUTE, MSG_CTRUNC,
				MSG_PROBE, MSG_TRUNC, MSG_DONTWAIT, MSG_EOR,
				MSG_WAITALL, MSG_FIN, MSG_SYN, MSG_CONFIRM,
				MSG_RST, MSG_ERRQUEUE, MSG_NOSIGNAL, MSG_MORE,
				MSG_WAITFORONE, MSG_CMSG_CLOEXEC, MSG_CMSG_COMPAT },
	},
};
