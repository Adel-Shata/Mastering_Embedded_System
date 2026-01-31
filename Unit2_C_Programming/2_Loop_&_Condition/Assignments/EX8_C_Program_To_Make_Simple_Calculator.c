/*
 ============================================================================
 Name        : EX8_C_Program_To_Make_Simple_Calculator.c
 Author      : Adel Shata
 Version     :
 Copyright   : Your copyright notice
 Description : C Program To Make Simple Calculator, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float num1, num2;
	char op;
	printf("Enter The Operator: "); /* Asking the user to enter two numbers*/
	fflush(stdin);
	fflush(stdout);
	scanf("%c", &op);
	printf("Enter Two Numbers: "); /* Asking the user to enter two numbers*/
	fflush(stdin);
	fflush(stdout);
	scanf("%f %f", &num1, &num2);

	/*Choosing the required operation*/
	switch(op)
	{
	case '*':
		printf("Num1 * Num2 = %f", (num1 * num2));
		break;
	case '/':
		if(num2 == 0)
			printf("Num1 / Num2 = Infinity");
		else
			printf("Num1 / Num2 = %f", (num1 / num2));
		break;
	case '+':
		printf("Num1 + Num2 = %f", (num1 + num2));
		break;
	case '-':
		printf("Num1 - Num2 = %f", (num1 - num2));
		break;
	default:
		printf("Invalid Operator");
		break;
	}
}
