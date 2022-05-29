STACK_TYPE = ${TYPE}

ifeq ($(STACK_TYPE), list)
        LIBS=stack_list.o stack_list_library.o
else ifeq ($(STACK_TYPE), vector)
        LIBS=stack_vector.o stack_vector_library.o
endif

CC=cc

CFLAGS=-std=c99 -c

all: main clean

main: main.o lab2_library_other.o $(LIBS)
        $(CC) main.o lab2_library_other.o $(LIBS) -o main

main.o: main.c
        $(CC) $(CFLAGS) main.c

lab2_library_other.o: lab2_library_other.c
        $(CC) $(CFLAGS) lab2_library_other.c

stack_list_library.o: stack_list_library.c
        $(CC) $(CFLAGS) stack_list_library.c

stack_vector_library.o : stack_vector_library.c
        $(CC) $(CFLAGS) stack_vector_library.c

stack_list.o : stack_list.c
        $(CC) $(CFLAGS) stack_list.c

stack_vector.o : stack_vector.c
        $(CC) $(CFLAGS) stack_vector.c

clean:
        rm -rf *.o

