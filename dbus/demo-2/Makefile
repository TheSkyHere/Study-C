all: main_client main_server

CFLAGS  += `pkg-config --cflags glib-2.0`
LDFLAGS += `pkg-config --libs glib-2.0`

CFLAGS  += `pkg-config --cflags dbus-1`
LDFLAGS += `pkg-config --libs dbus-1`

client: main_client.o 
	$(CC)  $(CFLAGS) -std=gnu99 -o $@ $^ $(LDFLAGS)

service: main_server.o 
	$(CC)  $(CFLAGS) -std=gnu99 -o $@ $^ $(LDFLAGS)

.PHONY: clean

clean:
	rm -rf *.o main_client main_server




## 手动编译：
# gcc service.c -ldbus-1 -I/usr/include/dbus-1 -o service `pkg-config –cflags –libs dbus-glib-1`
# gcc client.c -ldbus-1 -I/usr/include/dbus-1 -o client `pkg-config –cflags –libs dbus-glib-1` 
