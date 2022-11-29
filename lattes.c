#include <stdio.h>
#include <stdlib.h>
#include "periodicos_conferencias.h"
#include <getopt.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>

#define LINESIZE 1024
#define LINES 21750

void ler_arq(conferencias_e_periodicos* evento, char* nomeArquivo){
    FILE* arq;
    int i = 0;
    char* line = malloc(sizeof(char) * LINESIZE+1);

    //abre o arquivo
    arq = fopen (nomeArquivo, "r");

    if (! arq)
    {
        perror("Erro ao abrir o arquivo");
    }
    //le as 10 primeiras linhas 
    //for(i=0; i < 10; i++)

    //IMPRIME
    while (! (feof(arq)))
    {
        fgets(line, LINESIZE, arq);
        strncpy(evento[i].nome, line, strlen(line) - 3);
        printf("%d: %s\n", i, evento[i].nome); //imprime 
        i++;
    }
    fclose (arq);
    free(line);
}

int main (int argc, char** argv){
    int opt;
    DIR *dirstream;
    struct dirent *direntry;
    char* dir_name;
    char* arq_conf;
    char* arq_periodicos; 
    char diretorioArquivo[LINESIZE] = "";


    //le os argumentos da entrada fornecida
    while ((opt = getopt(argc, argv, "d:c:p:")) != -1){
        switch (opt){
            case 'd':
                dir_name = optarg;
                break;
            case 'c':
                arq_conf = optarg;
                break;
            case 'p':
                arq_periodicos = optarg;
                break;
            default : 
                fprintf(stderr, "Parâmetros errados");
                exit(1);        
        }

    }

    conferencias_e_periodicos* periodicos = malloc(sizeof(conferencias_e_periodicos) * LINES); 
    conferencias_e_periodicos* conferencias = malloc(sizeof(conferencias_e_periodicos) * LINES); 
    //printf ("%s", arq_periodicos);
    ler_arq(conferencias, arq_conf);
    ler_arq(periodicos, arq_periodicos);



    free(periodicos);
    free(conferencias);

}