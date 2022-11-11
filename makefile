parametrosCompilacao=-Wall -std=c99                                                                                                                                                                                                      
nomePrograma=trabalho

all: $(nomePrograma)

$(nomePrograma): trabalho.o
	gcc -o trabalho trabalho.o $(parametrosCompilacao)

.o: .c
	gcc -c *.c $(parametrosCompilacao)

clean:
	rm -f *.o *.gch $(nomePrograma)

purge: clean 
	-rm -f trabalho
