
SO_FILE = xenc.so
C_FILE = preload.c

.PHONY: all

all: $(SO_FILE)

$(SO_FILE): $(C_FILE)
	gcc $(C_FILE) -O2 -Wall -fPIC -shared -o $(SO_FILE)

clean:
	rm -f $(SO_FILE)
