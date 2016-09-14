/*
 ============================================================================
 Name        : adder.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include "roman_operands.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "roman_calculator.h"

START_TEST(isSum_Correct)
{
	//char *result;
	romanCalculator *calculator;
	calculator = setOperands("VII", "V");
	roman_add(calculator);

	ck_assert_str_eq(roman_operand1(calculator), "VII");
	ck_assert_str_eq(roman_operand2(calculator), "V");
	//ck_assert_int_eq(strcmp(roman_result_add(calculator),"X"),0);
	//result = roman_result_add(calculator);
	//ck_assert_msg(strcmp(result, "XII\0")==0,"FOUND %s with len %d", result, strlen("XII\0"));

	roman_destroy(calculator);
}
END_TEST

Suite *summer_mode(void)
{
	Suite *s;
	TCase *tc_core;
	s = suite_create("ADD");
	tc_core = tcase_create("Core");
	tcase_add_test(tc_core,isSum_Correct);
	suite_add_tcase(s, tc_core);

	return s;
}

int main(void)
{
	char c;
	printf("Do you want to run unit testing ? (Y/N)\n");
	printf("If Y testing will be run from unit content libraries else manual testing will be done.\n");
	scanf("%c", &c);
	if(c == 'y' || c == 'Y')
	{
		int number_failed;
		Suite *s;
		SRunner *sr;

		s = summer_mode();
		sr = srunner_create(s);

		srunner_run_all(sr, CK_NORMAL);
		number_failed = srunner_ntests_failed(sr);
		srunner_free(sr);
		return (number_failed == 0)?printf("ALL CASES SUCCESSFUL") : EXIT_FAILURE;
	}
	else
	{
		int j = 0;
		char *label = '\0';
		char *label2 = '\0';
		char *label3 = '\0';
		char *label4 = '\0';

		char op;
		label = (char *)malloc(sizeof(char)*(100*(sizeof(label)+1)));
		label2 = (char *)malloc(sizeof(char)*(100*(sizeof(label2)+1)));
		label3 = (char *)malloc(sizeof(char)*(100*(sizeof(label3)+1)));
		label4 = (char *)malloc(sizeof(char)*(100*(sizeof(label4)+1)));

		printf("Format for operations in application: [ROMAN VARIBALE] [+ or -] [ROMAN VARIABLE]\n");
		printf(">>> ");
		scanf("%s %c %s:\n", label,&op, label2);

	//	label = "ccclxix";
		//label2 = "dcccxlv";
		//op = '+';

		if((check_forNumbers(label) ==1) && (check_forNumbers(label2) == 1))
		{
			for(j = 0; j < strlen(label);j++)
			{
				label3[j] = toupper(label[j]);
			}

			for(j = 0; j < strlen(label2);j++)
			{
				label4[j] = toupper(label2[j]);
			}

			if(op == '+')
			{
				if(roman_checker(label3, label4) == -1)
				{
					printf("Sum of %s and %s = %s", label3, label4,roman_adder(label3,label4));

					printf("\n");
				}
				else
				{
					printf("MMMCMXCIX\n");
				}
			}
			if(op == '-')
			{
				printf("Subtraction of %s and %s = %s\n", label3, label4, roman_subtractor(label3, label4));
			}
		}
		else
		{
			printf("Error: Invalid input\n");
		}
	}
return 0;

}
