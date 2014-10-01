/*
 * =====================================================================================
 *
 *       Filename:  client.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月23日 10时10分24秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden5566 (), gorden5566@126.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "pipe.h"

void client(int readfd, int writefd)
{
	size_t len;
	ssize_t n;
	char buff[MAXLINE];

	fgets(buff, MAXLINE, stdin);

	len = strlen(buff);
	if (buff[len - 1] == '\n') {
		len--;
	}

	write(writefd, buff, len);

	while ( (n = read(readfd, buff, MAXLINE)) > 0) {
		write(STDOUT_FILENO, buff, n);
	}
}
