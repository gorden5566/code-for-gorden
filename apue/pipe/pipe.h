/*
 * =====================================================================================
 *
 *       Filename:  pipe.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月23日 10时09分52秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden5566 (), gorden5566@126.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef PIPE_H
#define PIPE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <wait.h>
#include <unistd.h>
#include <fcntl.h>

#include <errno.h>

#define MAXLINE 100

void client(int readfd, int writefd);
void server(int readfd, int writefd);

#endif
