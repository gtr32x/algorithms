OBJECTS = main.o

EXEC = main

CFLAGS = -std=c++20 -Wall

CC = g++

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Perform action on all object files (May or may not exist)
all: $(OBJECTS)                                                       
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJECTS)
	rm *.o