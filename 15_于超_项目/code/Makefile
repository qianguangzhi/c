CC=gcc
CFLAGE=-Wall -g -O0
RSC= test.c init.c insert.c show.c list.c menu.c menutwo.c inquire.c empty.c sort.c change.c delete.c shutdown.c buy_air_ticket.c
OBJ=test

$(OBJ):$(RSC)
		$(CC) $(CFLAGE) $^ -o $@

clean:
		$(RM) $(OBJ) .*.sw?
