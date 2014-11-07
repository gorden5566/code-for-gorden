/*
 * =====================================================================================
 *
 *       Filename:  server.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年11月07日 19时20分23秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden5566 (), gorden5566@126.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "unpipc.h"

void server(int readfd, int writefd)
{
	int fd;
	ssize_t n;
	char buff[MAXLINE];

	if ( (n = read(readfd, buff, MAXLINE)) == 0) {
		exit(0);
	}

	buff[n] = '\0';

	if ( (fd = open(buff, O_RDONLY)) < 0) { // 无法打开
		snprintf(buff + n, sizeof(buff) - n, ": can't open, %s\n", strerror(errno));
		n = strlen(buff);
		write(writefd, buff, n);
	} else {
		while ( (n = read(fd, buff, MAXLINE)) > 0)
			write(writefd, buff, n);
		close(fd);
	}
}
