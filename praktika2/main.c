#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct{
	char country[30];
	char name_product[30];
	int count;	
}info;
	
int main(int argc, char *argv[]) {
	system("chcp 1251");
	FILE *f;
	f = fopen("text.txt","r");
	if (!f){
		printf("Файл не найден");
		return 0;
	}
	else{
		printf("ok...\n");
	}
	int n = 0,i;
	info a;
	info *x = NULL;
	while(!feof(f)){
      if (fscanf(f, "%s", a.country) != 1){
      	break;
	  } 
      fscanf(f, "%s", a.name_product);
      fscanf(f, "%d", &a.count);
	  x = (info*)realloc(x,sizeof(info)*(n+1));
	  x[n] = a;
	  n++;		
	}
	fclose(f);
	printf("Прочитан массив структур: \n");
	for(i=0;i<n;i++){
		printf("%s %s %d\n",x[i].country ,x[i].name_product ,x[i].count);
	}
	system("PAUSE");
	char chek[50];
	printf("Введите товар, который пославляет страна:\n");
	gets(chek);
	printf("\n");
	printf("Страны, которые готовы поставлять данный продукт:\n");
	int flag = 1;
	for(i = 0;i<n;i++){
		if((strcmp(chek, x[i].name_product)==0)){
			flag = 0;
			printf("%s %s %d\n", x[i].country,x[i].name_product ,x[i].count);
		}
	}
	if (flag == 1){
		printf("Страны с таким товаром не найдены");
	}
	
	
	return 0;
}
