CC = g++
CFLAGS = -std=c++11

all: main.o CmdManager.o Course.o CourseManager.o
	$(CC) $(CFLAGS) CmdManager.o Course.o CourseManager.o main.o -o cmsys

CmdManager.o: CmdManager.cpp CmdManager.h
	$(CC) $(CFLAGS) -c CmdManager.cpp

CourseManager.o: CourseManager.cpp CourseManager.h
	$(CC) $(CFLAGS) -c CourseManager.cpp

Course.o: Course.cpp Course.h
	$(CC) $(CFLAGS) -c Course.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm -f *.o 
