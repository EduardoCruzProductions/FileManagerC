#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE* abrir_arquivo (char *fname){
  // w -> Significa write. Ele cria o arquivo automaticamente, mas quando o arquivo ja existe ele é sobescrito
  // r -> Significa read. Ele le o arquivo caso exista, caso ele nao exista ele retorna null
  // b -> Significa binario. Significa q os arquivos são interpretados de forma binária
  // rb+ -> Significa que o arquivo vai ser aberto para leitura e escrita, sem apagar o conteúdo prévio, no modo binário.

  FILE *fp;

  fp = fopen(fname, "rb+");

  if(fp == NULL){

    fp = fopen(fname, "wb");

    if(fp == NULL){
      printf("Falha ao criar arquivo %s\n ", fname);
      exit(1);
    }

    fclose(fp);
    fopen(fname, "rb+");

    if(fp == NULL){
      printf("Falha ao abrir o arquivp %s\n", fname);
      exit(1);
    }

  }

  return fp;
}

int main()
{

  FILE *fp;
  fp = abrir_arquivo("data.dat");

  return 0;

}
