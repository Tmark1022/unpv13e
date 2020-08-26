/***************************************************
* setvbuf 设置数据缓冲区方法  和 强制fflush
***************************************************/

#include	"unp.h"
#include <stdio.h>

void
str_echo(int sockfd)
{
	char		line[MAXLINE];
	FILE		*fpin, *fpout;

	fpin = Fdopen(sockfd, "r");
	fpout = Fdopen(sockfd, "w");
	
	// method 1	
	/*
	if (0 != setvbuf(fpout, NULL, _IOLBF, 0)) {
		err_ret("setvbuf error");
	}
	*/

	while (Fgets(line, MAXLINE, fpin) != NULL) {
		Fputs(line, fpout);
		// method 2
		fflush(fpout);
	}
}
