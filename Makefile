TARGETS := a.out

CFLAGS = -I/usr/include/libxml2

LD_LIBRARY_PATH=/usr/local/lib
LDFLAGS = -L${LD_LIBRARY_PATH} -Wl,-rpath=${LD_LIBRARY_PATH}
LDFLAGS += -lxml2

.PHONY: all clean

all: $(TARGETS)

a.out: libxml.c
	#$(eval DEFS = -DBUILDING_PFRAWS_UDP)
	#@echo $(DEFS)
	gcc -o $@ $^ $(CFLAGS) $(LDFLAGS)
clean :
	rm -rf $(TARGETS) $(TARGETS:%=%.o)
