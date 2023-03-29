#include <stdio.h>
#include<locale.h>
#include<string.h>
 
 int main(){
 	setlocale(LC_ALL,"");

  char str[100];
  int length, i;
  
  printf("Digite uma string: ");
  scanf("%s", str);
  
  length = strlen(str);
  
  for(i = 0; i < length/2; i++) {
    char temp = str[i];
    str[i] = str[length - i - 1];
    str[length - i - 1] = temp;
  }
  
  printf("String invertida: %s\n", str);
  
  return 0;
}

	 
