TARGETS := server
TARGETS += client
CFLAGS += -I.

LDFLAGS += -pthread 

.PHONY: all clean
all: $(TARGETS)

server: devm_msg.c hwmon_msg.c
	$(eval DEFS = -DAPP_TEST)
	@echo $(Make)
	gcc -o $@ $^ $(CFLAGS) $(LDFLAGS) #$(DEFS)
client: client.c
	$(eval DEFS = -DAPP_TEST)
	@echo $(Make)
	gcc -o $@ $^ $(CFLAGS) $(LDFLAGS) #$(DEFS)
clean:
	rm -rf $(TARGETS)
