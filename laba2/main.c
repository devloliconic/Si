#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void create_file(char *name){
	FILE *f = fopen(name,"w");
	if (f==NULL){
		printf("Ошибка создания файла");
		return;
	}
	fclose(f);
}
int main(int argc, char *argv[]) {
	system("chcp 1251");
	char name_file[30];
	printf("Введите название файла : ");
	scanf("%s",name_file);
	create_file(name_file);
	FILE *f;
	f = fopen (name_file,"r+");
	int n;
	int k;
	int i,j;
	unsigned long int s;
	int vs;
	int count_for_mas;
	n = 100;
	int *x;
	while(n<=10000){
		s = 0;
		for(k = 1;k <= 5;k++){
			int d = 0;
			int *x;
			x = (int*)malloc(n* sizeof(int));
			for(count_for_mas = 0;count_for_mas < n;count_for_mas++){
				x[count_for_mas] = rand() % 21 - 10;
			}
			for (i = 1; i < n;i++){
				vs = x[i];
				j = i-1;
				while(j>=0 && x[j]>vs){
					x[j+1] = x[j];
					j--;
					d+=3;
				}
				x[j+1] = vs;
				d++;	
			}	
			s = s + d;
		}
		s = s/5;
		fprintf(f, "%d; %lu\n", n, s);
		if(n<1000){
			n = n + 100;
		}
		else{
			n = n + 1000;
		}
		
	}
	fclose(f);
	
	
	
	
	
	
	return 0;
}
