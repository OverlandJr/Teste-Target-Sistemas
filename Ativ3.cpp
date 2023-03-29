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
    printf("Digite um número inteiro: ");
    scanf("%d", &n);
    if (fibonacci(n)) {
        printf("O número %d pertence à sequência de Fibonacci.\n", n);
    } else {
        printf("O número %d não pertence à sequência de Fibonacci.\n", n);
    }
    return 0;
}



