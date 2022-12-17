all: main_send

CFLAGS  += `pkg-config --cflags glib-2.0`
LDFLAGS += `pkg-config --libs glib-2.0`

CFLAGS  += `pkg-config --cflags dbus-1`
LDFLAGS += `pkg-config --libs dbus-1`

main_send: main_send.o
	$(CC)  $(CFLAGS) -std=gnu99 -o $@ $^ $(LDFLAGS)

.PHONY: clean

clean:
	rm -rf *.o main_send