CC = gcc

TARGET = myStack
OBJECTS = src/myStack.o

CFLAGS = -Wall -O2 -Wpedantic
LFLAGS = 

.PHONY: clean all

all: $(TARGET)


$(TARGET): $(OBJECTS)
		gcc -o $@ $^ $(LFLAGS)

%.o:$.c
		gcc $(CFLAGS) -c $<


clean:
	rm -rf $(TARGET) $(OBJECTS)

