#ifndef CALCULATOR_H
# define CALCULATOR_H

int		calculate(int a, int b, int operation);
int     get_operation(char** str);
int     get_val(char** str);
int     calc_value(char** str);
int     eval_expr_recursive(char** str);

#endif