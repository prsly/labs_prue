#include <stdio.h>
#include <conio.h>
#include <string.h>

struct library {
  char name[20];
  char newspap[15];
  char magazine[15];
  float price;
  int circula;
} l1, lmin;

void input (FILE*); //создание нового файла
void print (FILE*); //просмотр файла
void app (FILE*); // добавление в файл
void cena (FILE*); // самое дешевое издание

int main() {
  char c;
  FILE*nf;
  while (1) {
    puts("\n");
    puts("1- novyj fajl");
    puts("2- prosmotr fajla");
    puts("3- dobavlenie v fajl");
    puts("4- deshevoe izdanie");
    puts("0- vyhod");
    c=getch();
    switch(c) {
      case '1':input(nf); break;
      case '2':print(nf); break;
      case '3': app(nf); break;
      case '4': cena(nf); break;
      case '0': return 0;
      defaults: puts("nevernyj rezhim");
    }
  }
  return 0;
}

void input(FILE*nf) {
  char ch;
  nf=fopen("file1.dat","wb");//открытие файла для записи
  printf("\n Vvod dannyh biblioteki\n");
  do{
    printf("\n Nazvanie: ");
    scanf("%s",l1.name);
    printf("\n Gazeta (da / net): ");
    scanf("%s",l1.newspap);
    printf("\n Zhurnal (da / net): ");
    scanf("%s",l1.magazine);
    printf("\n Cena: ");
    scanf("%f", &l1.price);
    printf("\n Kol-vo vypuskov v god: ");
    scanf("%d", &l1.circula);
    fwrite(&l1, sizeof(l1),1,nf); //запись в файл одной структуры l1//
    printf("\n Zakonchit? (y/n): ");
    ch=getch();
  }
  while(ch !='y');
  fclose(nf);
}

void print (FILE*nf) {
  int i;
  nf=fopen("file1.dat","rb");//открыте файла для чтения//
  i=1;
  fread(&l1,sizeof(l1),1,nf);//чтение одной струк-ры
  while(!feof(nf)) {
    printf("\n %d %s %s %s %3.2f %d ",i,l1.name,l1.newspap,l1.magazine,l1.price,l1.circula);
    fread(&l1, sizeof(l1),1,nf);
    i++;
  }
  fclose(nf);
}

void app(FILE*nf) {
  char ch;
  nf=fopen("file1.dat","ab");//открыт.файла для добавления//
  printf("\nVvod dannyh biblioteki\n");
  do{
    printf("\n Nazvanie: ");
    scanf("%s",l1.name);
    printf("\n Gazeta (da / net): ");
    scanf("%s",l1.newspap);
    printf("\n Zhurnal (da / net): ");
    scanf("%s",l1.magazine);
    printf("\n Cena: ");
    scanf("%f", &l1.price);
    printf("\n Kol-vo vypuskov v god: ");
    scanf("%d", &l1.circula);
    fwrite(&l1, sizeof(l1),1,nf); //запись в файл одной структуры l1//
    printf("\n Zakonchit? (y/n): ");
    ch=getch();
  }
  while(ch !='y');
  fclose(nf);
}

void cena(FILE*nf){
  int i;
  nf=fopen("file1.dat","rb");
  if (feof(nf)){
    puts("\nFajl pust\n");
  }else{
    fread(&l1,sizeof(l1),1,nf);
    lmin=l1;
    while(!feof(nf)){
      fread(&l1,sizeof(l1),1,nf);
      if(lmin.price>l1.price) lmin=l1;
  }
  puts("\nSamoje deshevoe izdanie:");
  printf("\n %s %s %s %3f %d",lmin.name, lmin.newspap, lmin.magazine,lmin.price, lmin.circula);
  }
  fclose(nf);
}
