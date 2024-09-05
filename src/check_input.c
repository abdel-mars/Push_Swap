#include "push_swap.h"

/* arg_is_number:
*   Checks if the argument is a number. +1 1 and -1 are all valid numbers.
*   Return: 1 if the argument is a number, 0 if not.
*/
static int	arg_is_number(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]) && av[i + 1] != '\0')
		i++;
	while (av[i] && is_digit(av[i]))
		i++;
	if (av[i] != '\0' && !is_digit(av[i]))
		return (0);
	return (1);
}

/* have_duplicates:
*   Checks if the argument list has duplicate numbers.
*   Return: 1 if a duplicate is found, 0 if there are none.
*/
static int	have_duplicates(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 1;
		while (av[j])
		{
			if (j != i && nbstr_cmp(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/* arg_is_zero:
*   Checks the argument is a 0 to avoid 0 +0 -0 duplicates
*	and 0 0000 +000 -00000000 too.
*   Return: 1 if the argument is a zero, 0 if it contains
*	anything else than a zero.
*/
static int	arg_is_zero(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]))
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}

/* is_correct_input:
*   Checks if the given arguments are all numbers, without duplicates.
*   Return: 1 if the arguments are valid, 0 if not.
*/
int validate_args(int ac, char **av)
{
    int i;
    int nb_zeros;
    char **args;
    int result;

    nb_zeros = 0;
	result = 1;
	i = 0;
    if (ac == 2)
    {
        args = ft_split(av[1], ' ');
        if (!args)
            return 0;
    }
    else
    {
        args = av;
        i = 1;
    }
    while (args[i])
    {
        if (!arg_is_number(args[i]))
        {
            result = 0;
            break;
        }
        nb_zeros += arg_is_zero(args[i]);
        i++;
    }
    if (result && nb_zeros > 1)
        result = 0;
    if (result && have_duplicates(args))
        result = 0;
    if (ac == 2)
        ft_free(args);
    return result;
}
