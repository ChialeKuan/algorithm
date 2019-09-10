# EXCLUDE_DIRS = ./.vscode
# DIRS := $(shell find . -depth 1 -type d)
# DIRS := $(basename $(patsubst ./%,%,$(DIRS)))
# DIRS := $(filter-out $(EXCLUDE_DIRS),$(DIRS))
DIRS := $(wildcard */)

all:
	@for var in $(DIRS); do \
		cd $$var; \
		make; \
		cd ..; \
	done

clean:
	@for var in $(DIRS); do \
		cd $$var; \
		make clean; \
		cd ..; \
	done