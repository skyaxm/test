ifdef DEBUG
DEBUG=cde
endif

TARGETS := a.out

CFLAGS = $(CFLAG)

#LD_LIBRARY_PATH=/usr/local/lib
#LDFLAGS = -L${LD_LIBRARY_PATH} -Wl,-rpath=${LD_LIBRARY_PATH}
#LDFLAGS += -lxml2

.PHONY: all clean

all: $(TARGETS)

a.out: test_makefile.c
	$(eval DEFS = -DDEBUG)
	@echo $(Make)
	gcc -o $@ $^ $(CFLAGS) 
clean :
	rm -rf $(TARGETS) $(TARGETS:%=%.o)
