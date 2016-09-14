/*
 * roman_operands.h
 *
 *  Created on: Sep 10, 2016
 *      Author: cookiemonster
 */

#ifndef ROMAN_OPERANDS_H_
#define ROMAN_OPERANDS_H_
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


int roman_toDecimal(char a)
{
	int decimalForm = 0;
	if(a == 'M')
	{
		decimalForm = 1000;
	}
	else if(a == 'D')
	{
		decimalForm = 500;
	}
	else if(a == 'C')
	{
		decimalForm = 100;
	}
	else if(a == 'L')
	{
		decimalForm = 50;
	}
	else if(a == 'X')
	{
		decimalForm = 10;
	}
	else if(a == 'V')
	{
		decimalForm = 5;
	}
	else if(a == 'I')
	{
		decimalForm = 1;
	}
	else
	{
		decimalForm = -1;
	}

	return decimalForm;
}

int roman_toDecimalConversion(char *input)
{
	int value1 = 0;
	int value2 = 0;

	int result = 0;
	int i = 0;

	if(strlen(input) == 0)
	{
		result = 0;
	}
	else if(strlen(input)== 1)
	{
		result += roman_toDecimal(input[0]);
	}
	else
	{

		value2 = roman_toDecimal(input[0]);
		result = 0;
		for(i = 1; i < strlen(input);i++)
		{
			value1 = roman_toDecimal(input[i]);

			if(value2 < value1)
			{
				result += (value1-value2);
				value2 = roman_toDecimal(input[i+1]);
				i=i+1;
			}
			else
			{
				result += value2;
				value2 = roman_toDecimal(input[i]);
			}

			if(i == strlen(input)-1)
			{
				result += roman_toDecimal(input[i]);
			}
		}
	}
	return result;
}

char whoismyParent(char son)
{
	char temp = '\0';
	if(son == 'D')
	{
		temp = 'M';
	}
	else if(son == 'C')
	{
		temp = 'D';
	}
	else if(son == 'L')
	{
		temp = 'C';
	}
	else if(son == 'X')
	{
		temp = 'L';
	}
	else if(son == 'V')
	{
		temp = 'X';
	}
	else if(son == 'I')
	{
		temp = 'V';
	}

	return temp;
}

char *reducedNotation(char *message)
{
	int i = 0;
	int j = 0;

	int count = 0;
	char buffer;
	char parent = '\0';
	char *label = {0};
	label = (char *)malloc(sizeof(char)*(100*(strlen(message)+1)));

	buffer = message[0];
	count = 1;

	if(strlen(message) == 1)
	{
		strcat(label, &message[0]);
	}
	else
	{
		for(i = 1; i < strlen(message);i++)
		{
			if(buffer == message[i])
			{
				count=count +1;
			}

			if((count > 1) && (buffer == 'D'))
			{
				parent = whoismyParent(message[i]);

				strcat(label, &parent);
			}
			else if((count > 1) && (buffer == 'V'))
			{
				parent = whoismyParent(message[i]);

				buffer = '\0';

				strcat(label, &parent);
			}
			else if((count > 1) && (buffer == 'L'))
			{
				parent = whoismyParent(message[i]);

				buffer = '\0';

				strcat(label, &parent);
			}
			else if((count > 3) && (buffer == 'I'))
			{
				parent = whoismyParent(message[i]);

				strcat(label, &message[i]);

				buffer = '\0';

				strcat(label, &parent);
			}
			else if((count > 3) && (buffer == 'X'))
			{
				parent = whoismyParent(message[i]);

				strcat(label, &buffer);

				buffer = '\0';

				strcat(label, &parent);
			}
			else if((count > 3) && (buffer == 'C'))
			{
				parent = whoismyParent(message[i]);

				strcat(label, &message[i]);

				buffer = '\0';

				strcat(label, &parent);
			}
			else if(count > 1 && (i == strlen(message)-1))
			{
				j = 0;
				while(j < count)
				{
					strcat(label, &message[i]);
					j=j+1;
				}
				buffer = '\0';
				count = 1;
			}
			else if(((count <= 3) && (buffer != message[i])))
			{
				j = 0;

				while(j < count)
				{
					j++;
				strncat(label, &buffer, sizeof(buffer));
				}

				buffer = message[i];
				count = 1;
			}

		}
	}

	return label;
}

char * decimal_toRoman(int number)
{
	char *result;
	result = (char *)malloc(sizeof(char)*(100*(sizeof(result)+1)));

	while(number != 0)
	{
		if(number >= 1000)
		{
			strcat(result,"M");
			number -= 1000;
		}
		else if(number >= 500 && number < 1000)
		{
			strcat(result,"D");
			number = number-500;
		}
		else if(number >= 100 && number < 500)
		{
			strcat(result,"C");
			number -= 100;
		}
		else if(number >= 50 && number < 100)
		{
			strcat(result,"L");
			number -= 50;
		}
		else if(number >= 10 && number < 50)
		{
			strcat(result,"X");
			number -= 10;
		}
		else if(number >= 5 && number < 10)
		{
			strcat(result,"V");
			number -= 5;
		}
		else if(number >= 1 && number < 5)
		{
			strcat(result,"I");
			number -= 1;
		}
	}

	return result;
}

int roman_checker(char *a, char *b)
{
	//checking for maximum values given from string
	//if maximum is reached result will be set to 3999
	int flag = 0;

	if((roman_toDecimalConversion(a) >= 3999)||(roman_toDecimalConversion(b)>=3999))
	{
		flag = 1;
	}
	else
	{
		flag = -1;
	}

	return flag;
}

char *roman_adder(char *a, char *b)
{
	//Take two strings a and b and add them together
	//sum their decimal forms and bring them back to roman form
	//reduce their result using reduction by roman rules
	char *message;
	char *base;

	message = (char *)malloc(sizeof(char)*((strlen(a)+strlen(b))*(sizeof(a)+sizeof(b)+1)));
	base = (char *)malloc(sizeof(char)*((strlen(a)+strlen(b))*(sizeof(a)+sizeof(b)+1)));

	strcat(message,decimal_toRoman(roman_toDecimalConversion(a) + roman_toDecimalConversion(b)));

	//HERE LIES THE PROBLEM
	base = reducedNotation(message);
	//Should have been solved now

	if(roman_checker(base, "I") != -1)
	{
		base = "MMMCMXCIX";
	}

	free(message);

	return base;
}

char * roman_subtractor(char *a, char *b)
{
	//Take two strings
	//convert them to decimal
	//get the difference with absolute form
	//convert back to roman and return

	char *message;
	char *base;
	int value = 0;
	message = (char *)malloc(sizeof(char)*((strlen(a)+strlen(b))*(sizeof(message)+1)));
	base = (char *)malloc(sizeof(char)*((strlen(a)+strlen(b))*(sizeof(message)+1)));
	value = abs(roman_toDecimalConversion(a) - roman_toDecimalConversion(b));
	if(value == 0)
	{
		base ='\0';
	}
	else
	{
		message = decimal_toRoman(value);

		base = reducedNotation(message);

	}
	//Freeing allocated memory in space
	free(message);

	return base;
}

int check_forNumbers(char *a)
{
	int flag = 0;
	int i = 0;
	for(i = 0; i < strlen(a);i++)
	{
		if(isalpha(a[i]))
		{
			flag = 1;
		}
		else
		{
			flag = -1;
			break;
		}
	}
	return flag;
}

#endif /* ROMAN_OPERANDS_H_ */
