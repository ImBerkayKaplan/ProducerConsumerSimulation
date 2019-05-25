GCC=gcc
SOURCE=src
C=*.c
MAIN=P-Cprogram

all: project

project:
	@$(GCC) -o $(MAIN) $(SOURCE)/$(C) -lpthread -lrt 

clean:
	@rm $(MAIN)
