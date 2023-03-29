#include <stdio.h>
#include<locale.h>



	




int fibonacci(int n) {
    
    int a = 0, b = 1, c = 1;
    while (c < n) {
        c = a + b;
        a = b;
        b = c;
    }
    return (c == n);
}

int main() {
	setlocale(LC_ALL,"");
    int n;
    printf("Digite um n�mero inteiro: ");
    scanf("%d", &n);
    if (fibonacci(n)) {
        printf("O n�mero %d pertence � sequ�ncia de Fibonacci.\n", n);
    } else {
        printf("O n�mero %d n�o pertence � sequ�ncia de Fibonacci.\n", n);
    }
    return 0;
}



