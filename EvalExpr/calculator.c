#include "calculator.h"
#include "operations.h"

int		calculate(int a, int b, int operation)
{
	int	(*operations[5])(int, int);

	operations[0] = &op_plus;
	operations[1] = &op_minus;
	operations[2] = &op_divide;
	operations[3] = &op_multiply;
	operations[4] = &op_mod;
	return ((*operations[operation])(a, b));
}

int get_operation(char** str)
{
	char op;

	ignore_whitespace(str);
	op = *((*str)++);
	if (op == '+')
		return (0);
	else if (op == '-')
		return (1);
	else if (op == '/')
		return (2);
	else if (op == '*')
		return (3);
	else if (op == '%')
		return (4);
	else
		return (-100500);
}

int get_val(char** str)
{
	ignore_whitespace(str);
	if (**str == '(')
	{
		(*str)++;
		return (eval_expr_recursive(str));
	}
	else
		return (ft_atoi(str));
}

int calc_value(char** str)
{
	int val1;
	int op;
	int val2;

	val1 = get_val(str);
	ignore_whitespace(str);
	while (**str != '\0' && **str != ')' && (op = get_operation(str)) >= 2)
	{
		val2 = get_val(str);
		val1 = calculate(val1, val2, op);
	}
	if (**str != '\0' && **str != ')')
		(*str)--;
	return (val1);
}

int eval_expr_recursive(char** str)
{
	int val1;
	int val2;
	int operation;

	val1 = get_val(str);
	ignore_whitespace(str);
	while (**str != '\0' && **str != ')')
	{
		operation = get_operation(str);
		if (operation < 2)
			val2 = calc_value(str);
		else
			val2 = get_val(str);

		val1 = calculate(val1, val2, operation);
	}
	if (**str == ')')
		(*str)++;

	return (val1);
}