CC = gcc
LD = gcc -pipe

BDECFLAGS=      -W -Wall -ansi -pedantic -Wbad-function-cast -Wcast-align \
                -Wcast-qual -Wchar-subscripts -Winline \
                -Wmissing-prototypes -Wnested-externs -Wpointer-arith \
                -Wredundant-decls -Wshadow -Wstrict-prototypes -Wwrite-strings \
                -std=c99 -Wextra

CFLAGS = -pipe -g3
CFLAGS += $(BDECFLAGS)

INCLUDES = -I ~/Documents/ccnx/ccnx/include
LIBS = ~/Documents/ccnx/ccnx/lib/libccn.a -lcrypto

SRCS_SENDER = write.c
SRCS_RECEIVER = read.c
PROG_SENDER = write
PROG_RECEIVER = read

OBJS_SENDER = ${SRCS_SENDER:.c=.o}
OBJS_RECEIVER = ${SRCS_RECEIVER:.c=.o}

all: $(PROG_SENDER) $(PROG_RECEIVER)

$(PROG_SENDER): $(OBJS_SENDER)
	$(LD) -o $@ $(OBJS_SENDER) $(LIBS)

$(PROG_RECEIVER): $(OBJS_RECEIVER)
	$(LD) -o $@ $(OBJS_RECEIVER) $(LIBS)

rmtmp:
	$(RM) *.o

clean: rmtmp
	$(RM) $(PROG_RECEIVER) $(PROG_SENDER)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<

.PHONY: all rmtmp clean
