#include <stdio.h>

int main(){
	char Op;
	float num1, num2, result = 0;

	printf("\n Por favor, escolha uma operaçãoo (+, -, *, /):  ");
  	scanf("%c", &Op);

	printf("\n Por favor, digite dois números:  ");
  	scanf("%f%f", &num1, &num2);

  	switch(Op){
  		case '+':
  			result = num1 + num2;
  			break;
  		case '-':
  			result = num1 - num2;
  			break;
  		case '*':
  			result = num1 * num2;
  			break;
  		case '/':
  			result = num1 / num2;
  			break;
		default:
			printf("\n Você digitou uma operação inválida ");
	}

	printf("\n O resultado é %.2f %c %.2f  = %.2f \n", num1, Op, num2, result);

  	return 0;
}
