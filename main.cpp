#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct bin{
char digitos[MAX];
};

void lerArq(bin *Novo,int &quant){
  FILE *binarios;
  char nomeArquivo[MAX+1];
  
  scanf(" %[^\n]",nomeArquivo);
  
  binarios = fopen(nomeArquivo,"r");

  if(binarios == NULL){
    printf(" ");}
  
  else{
    while(true){
      int entrada = fscanf(binarios," %[^\n]",Novo[quant].digitos);
      if(entrada == EOF){
        break;}
      quant++;
    }
  }
    
    fclose(binarios);
  }

void removeEsp(bin *Lista, int i, int &j){
  for(int h=j;h<strlen(Lista[i].digitos);h++)
    Lista[i].digitos[h] = Lista[i].digitos[h+1];
  j--;
}

void registradores(char *digitos, int pos1, int pos2){
  if(digitos[pos1]=='0' && digitos[pos2]=='0'){
      printf(" r0"); }
    
    if(digitos[pos1]=='0' && digitos[pos2]=='1'){
      printf(" r1"); }
    
    if(digitos[pos1]=='1' && digitos[pos2]=='0'){
      printf(" r2"); }

    if(digitos[pos1]=='1' && digitos[pos2]=='1'){
      printf(" r3"); }
}

void arquivo(char *instrucao){
  FILE *assembly = fopen("assembly.txt", "a+");
  
  fprintf(assembly,"%s\n", instrucao);
  
  fclose(assembly);
}

int main() {

  bin lista[MAX];
  int quant;

  lerArq(lista, quant);
 
  printf("%d bytes\n", quant);
  
  for(int i=0;i<quant;i++){
    for(int j=0;j<strlen(lista[i].digitos);j++)
      if(lista[i].digitos[j] != '0' && lista[i].digitos[j] != '1') removeEsp(lista, i, j);}

  for(int i=0; i<quant; i++){
    
    if(lista[i].digitos[0]=='1'){//se digito 0==1
      if(lista[i].digitos[1]=='1'){//se digito 1==1
        if(lista[i].digitos[2]=='1'){//se digito 2==1
          printf("\nMFA");
          arquivo("MFA");
          registradores(lista[i].digitos,6,7);}
      if(lista[i].digitos[2]=='0'){//se digito 2==0
        printf("\nMTA");
        arquivo("MTA");
        registradores(lista[i].digitos,6,7);} 
      }

        if(lista[i].digitos[1]=='0'){//se digito 1==0
          if(lista[i].digitos[2]=='0'){//se digito 2==0
            printf("\nLW");
            arquivo("LW");
            registradores(lista[i].digitos,3,4);
            printf(",0"); }
          if(lista[i].digitos[2]=='1'){//se digito 2==1
            printf("\nSW");
            arquivo("SW");
            registradores(lista[i].digitos,3,4);
            printf(",0"); }
        }
    }

    if(lista[i].digitos[0]=='0'){//se digito 0==0
      if(lista[i].digitos[1]=='1'){//se digito 1==1
        if(lista[i].digitos[2]=='1'){//se digito 2==1
          printf("\nBEQ");
          arquivo("BEQ");
          registradores(lista[i].digitos,3,4);
          printf(",");
          registradores(lista[i].digitos,5,6); }
        if(lista[i].digitos[2]=='0'){//se digito 2==0
          printf("\nSUB");
          arquivo("SUB");
          registradores(lista[i].digitos,3,4);}
      }
      
      if(lista[i].digitos[1]=='0'){//se digito 1==0
        if(lista[i].digitos[2]=='0'){//se digito 2==0
          printf("\nADD"); 
          arquivo("ADD");
          registradores(lista[i].digitos,3,4);}
        if(lista[i].digitos[2]=='1'){//se digito 2==1
          printf("\nADDI 6");
          arquivo("ADDI 6");}
      }
    }

    
  } //fechando for
} //fechando main
        