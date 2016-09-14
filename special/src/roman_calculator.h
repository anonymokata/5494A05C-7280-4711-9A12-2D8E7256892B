/*
 * roman_calculator.h
 *
 *  Created on: Sep 14, 2016
 *      Author: cookiemonster
 */

#ifndef ROMAN_CALCULATOR_H_
#define ROMAN_CALCULATOR_H_
#include "roman_operands.h"

typedef struct romanCalculator
{
	char *operand_1;
	char *operand_2;
	char *result;
}romanCalculator;


romanCalculator *setOperands(char *a, char *b)
{
	romanCalculator *r = malloc(sizeof(romanCalculator));

	r->operand_1 = (char *)malloc(sizeof(char)*100);
	r->operand_2 = (char *)malloc(sizeof(char)*100);

	strcat(r->operand_1,a);
	strcat(r->operand_2,b);

	return r;
}

char *roman_operand1(romanCalculator *r)
{
	return r->operand_1;
}

char *roman_operand2(romanCalculator *r)
{
	return r->operand_2;
}

void roman_destroy(romanCalculator *r)
{
	free(r);

}

void roman_add(romanCalculator *r)
{

	//r->result="TRASH";
	char *business;
	business = malloc(sizeof(char)*100);
	r->result = malloc(sizeof(char)*100);
	business = roman_adder(r->operand_1,r->operand_2);

	strcat(r->result,business);

	free(business);

}

void roman_sub(romanCalculator *r)
{
	strcat(r->result,roman_subtractor(r->operand_1,r->operand_2));
}

char* roman_result_add(romanCalculator *r)
{
	return r->result;
}

char * roman_result_sub(romanCalculator *r)
{
	return r->result;
}

#endif /* ROMAN_CALCULATOR_H_ */
