CC=gcc
CFLAGS=-Wall -g -O0
SRC=test.c show.c input.c output.c delete.c search.c modify.c sort.c quit.c\
    test.c buy_ticket.c balance.c
OBJ=test 

$(OBJ):$(SRC)
	$(CC) $(CFLAGS) $^ -o $@
	
clean:
	$(RM) $(OBJ) .*.sw?

