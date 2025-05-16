# Hollywood-Hackerman Makefile

CC ?= gcc
CFLAGS = -Wall -Wextra -O3 -flto
TARGET = hhm
SRC = hhm.c
PREFIX = /usr/local
BINDIR = $(PREFIX)/bin

.PHONY: all clean run install remove

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

run: $(TARGET)
	./$(TARGET)

install: $(TARGET)
	install -Dm755 $(TARGET) $(DESTDIR)$(BINDIR)/$(TARGET)

remove:
	rm -f $(DESTDIR)$(BINDIR)/$(TARGET)

clean:
	rm -f $(TARGET)
