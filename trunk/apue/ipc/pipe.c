/*
 * =====================================================================================
 *
 *       Filename:  pipe.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月24日 10时29分27秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden5566 (), gorden5566@126.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAXLINE 100

int main(void)
{
	int	n, fd[2];
	pid_t	pid;
	char	line[MAXLINE];

	if (pipe(fd) < 0) {
		//err_sys("pipe error");
	}

	if ( (pid = fork()) < 0) {
		//err_sys("fork error");
	} else if (pid > 0) {
		close(fd[0]);
		write(fd[1], "hello world\n", 12);
	} else {
		close(fd[1]);
		n = read(fd[0], line, MAXLINE);
		write(STDOUT_FILENO, line, n);
	}

	exit(0);
}
