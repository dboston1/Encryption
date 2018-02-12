PA1 : 

CC = g++ 
CFLAGS = -std=c++11 -Wall -O3 -c 
LFLAGS = -std=c++11 -Wall 
OBJS = main.o Encryption.o
INCLUDE = -I.

PA1 : $(OBJS)
	$(CC) $(OBJS) $(LFLAGS) $(INCLUDE) -o PA1
	
main.o : main.cpp Encryption.cpp Encryption.h Enums.h
	$(CC) main.cpp $(INCLUDE) $(CFLAGS)
	
Encryption.o : Encryption.cpp Encryption.h
	$(CC) Encryption.cpp $(INCLUDE) $(CFLAGS)
		
clean : 
	-rm *.o PA1

package : 
	tar cvf PA1_Dboston1.tar Makefile main.cpp Encryption.cpp Encryption.h Enums.h README
