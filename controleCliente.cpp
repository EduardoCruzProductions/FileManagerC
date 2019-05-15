#include <iostream>
#include <string>

using namespace std;

char *DATA = "clientes.dat";

typedef struct cliente{
  int codigo;
  char nome[100];
} Cliente;

FILE* abrir_arquivo (char *fname)
{
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

void cadastrar_cliente()
{

  FILE *fp;
  Cliente cliente;

  cout << "Informe o código do cliente: ";
  cin >> cliente.codigo;

  cout << "Informe o nome do cliente: ";
  cin >> cliente.nome;

  fp = abrir_arquivo(DATA);
  fseek(fp, 0, SEEK_END);
  fwrite(&cliente, sizeof(Cliente), 1, fp);

  fclose(fp);

}

void listar_cliente()
{

  FILE *fp;
  Cliente buffer[100];
  int n;

  fp = abrir_arquivo(DATA);
  fseek(fp, 0, SEEK_SET);
  n = fread(buffer, sizeof(Cliente), 100, fp);

  cout << "--------------------- Lista de clientes ---------------------" << endl;
  for(int i = 0; i < n; i++){
    cout << buffer[i].codigo << " - " << buffer[i].nome << endl;
  }

  fclose(fp);

}

void buscar_cliente(int codigo, Cliente *c, int &p){

  FILE *fp;
  Cliente buffer[100];
  int n;

  fp = abrir_arquivo(DATA);
  fseek(fp, 0, SEEK_SET);
  n = fread(buffer, sizeof(Cliente), 100, fp);

  for(int i = 0; i < n; i++){
    if(codigo == buffer[i].codigo){
      p = i;
      *c = buffer[i];
    }
  }

  fclose(fp);

}

void alterar_cliente(int codigo){

  int p = 0;
  Cliente *c = new Cliente;
  FILE *fp;

  buscar_cliente(codigo, c, p);

  if(c == NULL){
    cout << "Registro não encontrado!" << endl;
  }else{

    cout << "Nome atual: " << c->nome << endl;
    cout << "Informe o novo nome: ";
    cin >> c->nome;

    fp = abrir_arquivo(DATA);

    fseek(fp, sizeof(Cliente) * p , SEEK_SET);

    fwrite(c, sizeof(Cliente), 1, fp);

    fclose(fp);

  }

}

int main()
{

  int p = 2;
  alterar_cliente(p);
  listar_cliente();

  return 0;
}

//compilar com o final -g
//executar gbd --args ./ex
//apertar r pra ver o erro
