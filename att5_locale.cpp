#include <stdio.h>
#include <locale.h>

int produto (int a, int b) {
	return (a * b);
}
int main() {
	setlocale(LC_ALL, "Portuguese");
	float valor = 1320.00;
	printf("Correção \n");
	int resposta;
	resposta = produto (10, 11);    
	printf("Resposta é = %d\n", resposta);
	printf("valor é = %5.4f", valor);
}
