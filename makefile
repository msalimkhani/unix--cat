CC = gcc
Pname = cat
obj = obj/main.o
src = src/main.c
bin = bin/$(Pname)
$(obj):
	$(CC) -c $(src) -o $(obj)
build:clean $(obj)
	$(CC) $(obj) -o $(bin)
clean:
	rm -f obj/*.o
install:
	sudo cp bin/$(Pname) /usr/bin
	sudo cp bin/$(Pname) /usr/lib
	sudo cp bin/$(Pname) /usr/share