/*
 * =====================================================================================
 *
 *       Filename:  server.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月23日 10时16分28秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden5566 (), gorden5566@126.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "pipe.h"

void server(int readfd, int writefd)
{
	int fd;
	ssize_t n;
	char buff[MAXLINE + 1];

	if ((n = read(readfd, buff, MAXLINE)) == 0) {
		printf("end-of-file while reading pathname\n");
		return;
	}

	buff[n] = '\0';

	if ((fd = open(buff, O_RDONLY)) < 0) {
		snprintf(buff + n, sizeof(buff) - n, ": can't open, %s\n", strerror(errno));
		n = strlen(buff);
		write(writefd, buff, n);
	} else {
		while ((n = read(fd, buff, MAXLINE)) > 0) {
			write(writefd, buff, n);
		}

		close(fd);
	}
}
