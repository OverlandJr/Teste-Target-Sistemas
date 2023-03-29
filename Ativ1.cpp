#include<stdio.h>
#include<locale.h>

int main(){
	setlocale(LC_ALL,"");
	
	int num = 13, soma = 0, k = 0;
	
	while(k < num){
		k = k + 1;
		soma = soma + k;
	}
	printf("O valor da soma é: %d",soma);
	
}
