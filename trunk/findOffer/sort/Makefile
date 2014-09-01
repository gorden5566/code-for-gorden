#compilers
CC = gcc
XX = g++

#for debug
CFLAGS = -Wall -O -g

#target file name
TARGET = ./main

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.cpp
	$(XX) $(CFLAGS) -c $< -o $@

#source files(*.c, *.cpp)
SOURCES = $(wildcard *.c *.cpp)
#object files(*.o)
OBJS = $(patsubst %.c, %.o, $(patsubst %.cpp, %.o, $(SOURCES)))

$(TARGET) : $(OBJS)
	$(XX) $(OBJS) -o $(TARGET)

clean:
	rm -rf *.o $(TARGET)
