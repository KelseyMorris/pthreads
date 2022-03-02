# the compiler: gcc for C program, define as g++ for C++
  CC = gcc

  # compiler flags:
  #  -g    adds debugging information to the executable file
  #  -Wall turns on most, but not all, compiler warnings
  CFLAGS  = -g -Wall 
  # gcc -pthread -Wall -Wextra -g -o term term.c

  # the build target executable:
  TARGET = threads

  all: $(TARGET)

  $(TARGET): $(TARGET).c
	$(CC) $(CFLAGS)  -o $(TARGET) $(TARGET).c  -lpthread

  clean:
	$(RM) $(TARGET)