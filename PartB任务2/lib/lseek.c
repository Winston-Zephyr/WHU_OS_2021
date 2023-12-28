#include "type.h"
#include "stdio.h"
#include "const.h"
#include "protect.h"
#include "string.h"
#include "fs.h"
#include "proc.h"
#include "tty.h"
#include "console.h"
#include "global.h"
#include "proto.h"

PUBLIC int mlseek(int fd, int offset, int whence)
{
	printf("In lseek!\n");
	MESSAGE msg;
	msg.type = LSEEK;
	msg.FD   = fd;
	msg.OFFSET = offset;
	msg.WHENCE = whence;

	send_recv(BOTH, TASK_FS, &msg);
	return msg.CNT;
}
