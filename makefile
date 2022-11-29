parametrosCompilacao=-Wall -std=c99                                                                                                                                                                                                      
nomePrograma=lattes

all: $(nomePrograma)

$(nomePrograma): lattes.o periodicos_conferencias.o 
	gcc -o lattes lattes.o periodicos_conferencias.o $(parametrosCompilacao)

.o: .c
	gcc -c *.c $(parametrosCompilacao)

clean:
	rm -f *.o *.gch $(nomePrograma)

purge: clean 
	-rm -f trabalho
