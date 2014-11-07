/*
 * =====================================================================================
 *
 *       Filename:  fduplex.c
 *
 *    Description:  全双工案例，在solaris上运行 
 *
 *        Version:  1.0
 *        Created:  2014年11月07日 22时02分42秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden5566 (), gorden5566@126.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "unpipc.h"

int main()
{
	int fd[2], n;
	char c;
	pid_t childpid;

	pipe(fd);

	if ( (childpid = fork()) == 0) { // child
		sleep(3);

		if ( (n = read(fd[0], &c, 1)) != 1 )
			exit(0);

		printf("child read %c\n", c);
		write(fd[0], "c", 1);
		exit(0);
	}

	// parent
	write(fd[1], "p", 1);
	if ( (n = read(fd[1], &c, 1)) != 1)
		exit(1);
	
	printf("parent read %c\n", c);
	exit(0);
}
