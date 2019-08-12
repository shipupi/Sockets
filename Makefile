all: mailClient myserver

mailClient:
	cd mailClient;make

myserver:
	cd myserver;make

clean:
	cd mailClient;make clean
	cd myserver;make clean

.PHONY: all mailClient myserver clean
