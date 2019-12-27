CC=g++
CFLAGS=-Wall
EXEC=
SRC=$(wildcard *.c)
OBJ= $(SRC:.c=.o)


class_test_hh:
	g++ -Wall engine.hh
	g++ -Wall pompe.hh
	g++ -Wall tank.hh
	g++ -Wall vanne.hh
	rm *.hh.gch


class_test_cc: class_test_hh
	g++ -Wall -o *.o *.cc
	rm a.out

class_test_all:
	g++ *.hh
	g++ *.cc
	rm *.hh.gch
	rm a.out

#~ test.o: class/engine.cc class/engine.hh
#~ 	$(CC) -o test.o -c class/engine.cc $(CFLAGS)


#~ main: $(OBJ)
#~ 	$(CC) -o $@ $^ 
	
#~ %.o: %.c
#~ 	$(CC) -o $@ -c $< $(CFLAGS)
	

	
