CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -pedantic

SRC = $(wildcard src/*.c)
OUT = arbor

PREFIX = /usr/local

.PHONY: all clean install uninstall

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)


# --- INSTALLATION ENGINE ---

install: all
	@echo "Installing arbor to $(PREFIX)/bin..."
	mkdir -p $(PREFIX)/bin
	cp $(OUT) $(PREFIX)/bin/$(OUT)
	chmod 755 $(PREFIX)/bin/$(OUT)
	@echo "arbor installed successfully! Try running 'arbor' from anywhere."

uninstall:
	@echo "Removing arbor from $(PREFIX)/bin..."
	rm -f $(PREFIX)/bin/$(OUT)
	@echo "arbor uninstalled successfully."
	@echo "submit any issue to "https://github.com/nilesh-padiyar/arbor/""
