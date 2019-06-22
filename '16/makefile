OPTS = -Wall -g
OBJS = Partido.o Provincia.o main.o
cc = g++

ej2: $(OBJS)
	$(cc) $(OPTS) $(OBJS) -o ej2

main.o: main.cc Provincia.h Partido.h
	$(cc) $(OPTS) -c main.cc


Provincia.o: Provincia.h Provincia.cc Partido.h
	$(cc) $(OPTS) -c Provincia.cc


Partido.o: Partido.cc Partido.h
	$(cc) $(OPTS) -c Partido.cc