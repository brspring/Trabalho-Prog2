#include <stdio.h>
#include <stdlib.h>

#define LINESIZE 1024 

void ler_arq(){
    FILE* arq;
    int i;
    char line[LINESIZE+1];

    //abre o arquivo
    arq = fopen ("curriculo.xml", "r");

    if (! arq)
    {
        perror("Erro ao abrir o arquivo curriculo.xml");
    }
    //le as 10 primeiras linhas 
    //for(i=0; i < 10; i++)
    while (fgets(line, LINESIZE, arq) != NULL)
    {
        fgets(line, LINESIZE, arq);
        printf("%d: %s", i, line);
        i++;
    }
    fclose (arq);
}

int main ()
{
    ler_arq();
}