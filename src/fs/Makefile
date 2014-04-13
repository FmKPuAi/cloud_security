#include ../Rules
all: test

clean:
	rm -f *.o test 

test: upload.o nfq_queue.o pkt_modify.o pkt_crypt.o
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS) 
	cp $@ $(INSTALLDIR)
	@echo -e "[Upload File]\n"


