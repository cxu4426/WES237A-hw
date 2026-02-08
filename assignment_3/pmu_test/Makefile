CC = gcc
CFLAGS = -O0 -fPIC

TARGET = libcycletime.so
SRC = cycletime.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -shared -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
