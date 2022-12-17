all: example-client example-service

CFLAGS  += `pkg-config --cflags glib-2.0`
LDFLAGS += `pkg-config --libs glib-2.0`

CFLAGS  += `pkg-config --cflags dbus-1`
LDFLAGS += `pkg-config --libs dbus-1`

CFLAGS  += `pkg-config --cflags gtk+-2.0 `
LDFLAGS += `pkg-config --libs gtk+-2.0 `

CFLAGS  += `pkg-config --cflags dbus-glib-1 `
LDFLAGS += `pkg-config --libs dbus-glib-1 `


example-client: example-client.o 
	$(CC)  $(CFLAGS) -std=gnu99 -o $@ $^ $(LDFLAGS)

example-service: example-service.o 
	$(CC)  $(CFLAGS) -std=gnu99 -o $@ $^ $(LDFLAGS)

.PHONY: clean

clean:
	rm -rf *.o example-client example-service

