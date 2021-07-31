CC = gcc 

CFLAGS = -g -O -Wall

CSRCS = server.c db.c 

TARGET = server 

OBJECTS = $(CSRCS:.c=.o)

all : $(TARGET) client

$(TARGET) : $(OBJECTS)

	$(CC) -pthread $(OBJECTS) -o $@
client: client.o

	$(CC) -o client client.o -lpthread
.c.o:

	$(CC) $(CFLAGS) -c $< -o $@
client.o: client.c

	$(CC) -c -o client.o client.c
clean:

	rm -f $(OBJECTS) $(TARGET) client.o client 
