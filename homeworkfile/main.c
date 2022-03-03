#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	// chek file
	system("chcp 1251");
	FILE *coard2;
	coard2 = fopen("coard2.txt" , "r+");
	if(!coard2){
		printf("Файл не найден.\n");
		return 0;
	}
	else printf ("ок...\n");
	
	
	// date into file
	int x,y,z;
	int x2,y2,z2;
	int scalar_pr = 0;
	float r1,r2,r3 = 0.0;
	int i;
	int test_count; 
	int chek;
	printf("Введите количество примеров(их 2): ");
	chek = scanf("%d",&test_count);
	if((chek!=1) || (test_count<=0)){
		printf("Неверно заданы данные\n");
		return 0;
	}
	for (i = 0;i < test_count; i++ ){
	
		fscanf(coard2, "%d%d%d",&x,&y,&z);
		fscanf(coard2, "%d%d%d",&x2,&y2,&z2);
		printf("%d %d %d\n",x,y,z);
		printf("%d %d %d\n",x2,y2,z2);
		
		// chek skalar
		scalar_pr = ((x*x2)+(y*y2)+(z*z2));
		r1 = x%x2;
		r2 = y%y2;
		r3 = z%z2;
		if(((x*x2)+(y*y2)+(z*z2))==0){
			printf("Вектора ортогональны\n");
		}
		else{
			printf("Вектора неортогональны\n");	
		}
		if((r1==r2)&&(r1==r3)&&(r2==r3)){
			printf("Вектора коллинеарны\n");
		}
		else{
			printf("Вектора неколлинеарны\n");
		}
	}
	printf("Смирнов Кирилл 421-3\n");
	return 0;
}
