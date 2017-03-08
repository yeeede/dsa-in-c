CC ?= gcc
CFLAGS_common ?= -Wall -std=gnu99
CFLAGS_hash = -O0

EXEC = hash
GIT_HOOKS := .git/hooks/pre-commit
.PHONY: all
all: $(EXEC)

SRCS_common = main.c

hash: $(SRCS_common) hash.c hash.h
	$(CC) $(CFLAGS_common) $(CFLAGS_hash) \
		-DIMPL="\"$@.h\"" -o $@ \
		$(SRCS_common) $@.c
run:
	./$(EXEC) ./input/words.txt ./output/_words.txt

.PHONY: clean
clean:
	$(RM) $(EXEC)
