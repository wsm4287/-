CC		= gcc
CFLAGS	= -g -W -Wall
LDFLAGS	=

CSRCS	= main.c
TARGET	= parser
OBJECTS	= $(CSRCS:.c=.o)

all: $(TARGET)

$(TARGET):	$(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)
	

