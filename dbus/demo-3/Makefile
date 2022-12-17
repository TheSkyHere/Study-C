all: client service

CFLAGS  += `pkg-config --cflags glib-2.0`
LDFLAGS += `pkg-config --libs glib-2.0`

CFLAGS  += `pkg-config --cflags dbus-1`
LDFLAGS += `pkg-config --libs dbus-1`

CFLAGS  += `pkg-config --cflags gtk2.0-dev`
LDFLAGS += `pkg-config --libs gtk2.0-dev`

CFLAGS  += `pkg-config --cflags dbus-glib-1-dev`
LDFLAGS += `pkg-config --libs dbus-glib-1-dev`

client: client.o 
	$(CC)  $(CFLAGS) -std=gnu99 -o $@ $^ $(LDFLAGS)

service: service.o 
	$(CC)  $(CFLAGS) -std=gnu99 -o $@ $^ $(LDFLAGS)

.PHONY: clean

clean:
	rm -rf *.o client service




## 手动编译：
# gcc service.c -ldbus-1 -I/usr/include/dbus-1 -o service `pkg-config –cflags –libs dbus-glib-1`
# gcc client.c -ldbus-1 -I/usr/include/dbus-1 -o client `pkg-config –cflags –libs dbus-glib-1` 
