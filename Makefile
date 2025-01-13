CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = pi_calculator

all: $(TARGET)

$(TARGET): pi_calculator.c
	$(CC) $(CFLAGS) -o $(TARGET) pi_calculator.c

clean:
	rm -f $(TARGET)

.PHONY: all clean

