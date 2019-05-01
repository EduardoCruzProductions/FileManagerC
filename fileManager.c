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
  char str[50] = "Eduardo";
  char buffer_leitura[100];
  int n;

  fp = abrir_arquivo("data.dat");

  n = fread(buffer_leitura, sizeof(char), 100, fp);
  buffer_leitura[n] = 0;
  printf("%s\n", buffer_leitura);

  fclose(fp);
  fp = abrir_arquivo("data.dat");

  fwrite(str, sizeof(char), strlen(str), fp);

  fclose(fp);

  return 0;

}

//buscar por fseek
//fazer um cadastro de cliente, adicionar, alterar, remover e listar
