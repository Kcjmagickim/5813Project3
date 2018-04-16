#@file: MakeFile
#@brief: GNU Make imeplementation
#@author: John Kim
#@date: Feb 18th, 2018

include sources.mk

SRCS = main.c memory.c

PPRO := $(SRCS:.c=.i)

OBJS := $(SRCS:.c=.o)

ASMS := $(SRCS:.c=.asm)

LDFLAGS = -lm \
		-lrt

CFLAGS = -Wall	\
		-Werror	\
		-g 		\
		-O0		\
		-std=gnu99 

CFLAGS2 = -Wall	\
		-Werror	\
		-g 		\
		-O3		\
		-std=gnu99 

ifeq ($(PLATFORM),KL25z)
	CC = arm-none-eabi-gcc
	CFLAGS += -mcpu=cortex-m0plus	\
	-mfloat-abi=soft	\
	-march=armv6-m	\
	-mthumb	\
	-mfpu=fpv4-sp-d16		\
	--specs=nosys.specs

else ifeq ($(PLATFORM),BBB)
	CC = arm-linux-gnueabi-gcc
else
	CC = gcc
endif


memory.o: memory.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o memory.o memory.c

.PHONY: clean
clean:
	rm -f *.o *~ *.asm *.i *.d *.su library mymem0 mymem3

.PHONY: library
library:
	$(CC) $(CFLAGS) $(INCLUDES) $(LDFLAGS) -o library library.c -lm -fstack-usage

.PHONY: mymem0
mymem0: memory.o
	$(CC) $(CFLAGS) $(INCLUDES) $(LDFLAGS) -o mymem0 mymem.c memory.o -lm -fstack-usage

.PHONY: mymem3
mymem3: memory.o
	$(CC) $(CFLAGS2) $(INCLUDES) $(LDFLAGS) -o mymem3 mymem.c memory.o -lm -fstack-usage

