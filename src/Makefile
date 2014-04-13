CC=gcc
export ROOT := $(shell pwd)
INCLUDEPATH=$(ROOT)/../include
export INSTALLDIR=$(ROOT)/../bin/
vpath %.h $(INCLUDEPATH)
export SUBDIRS = fs 

export CFLAGS= -g -Wall -I$(INCLUDEPATH) -I/usr/include -I/usr/local/include -L/lib -L/usr/lib -L/usr/local/lib  
export LIBS=-lnfnetlink -lnetfilter_queue -lpcre -lcrypto

.PHONY: all $(SUBDIRS) clean cleanall mkbin 
all: trans_proxy $(SUBDIRS)
	@echo -e "[All Done!]"	
$(SUBDIRS):
	$(MAKE) -C $@ 
clean: 
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done
trans_proxy:
	mkdir -p $(INSTALLDIR)
cleanall:
	for dir in $(SUBDIRS); do \
                $(MAKE) -C $$dir clean; \
	done
	rm -f $(INSTALLDIR)/*
	rm -rf $(INSTALLDIR)
