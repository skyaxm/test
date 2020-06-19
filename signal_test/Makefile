#ifdef DEBUG
#DEBUG=cde
#endif

TARGETS := signal

CFLAGS = += -I. -I..

#LD_LIBRARY_PATH=/usr/local/lib
LDFLAGS = -L${LD_LIBRARY_PATH} -Wl,-rpath=${LD_LIBRARY_PATH}
#LDFLAGS += -lxml2

.PHONY: all clean

all: $(TARGETS)

signal: *.c
	$(eval DEFS = -DDEBUG)
	@echo $(DEFS)
	gcc -o $@ $^ $(CFLAGS) $(LDFLAGS) $(DEFS) 
clean :
	rm -rf $(TARGETS) $(TARGETS:%=%.o)
