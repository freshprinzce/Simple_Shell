#include "shell.h"
/**
 * _erratoi - this will converts a strn to an int
 * @f:string will be converted
 * Return: if no numbers in string, converted number otherwise should return 0
 * error should be -1
 */
int _erratoi(char *f)
{
	int n = 0;
	unsigned long int result = 0;

	if (*f == '+')
		f++;  /* TODO: why does this make main return 255? */
	for (n = 0;  f[n] != '\0'; n++)
	{
		if (f[n] >= '0' && f[n] <= '9')
		{
			result *= 10;
			result += (f[n] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}
/**
 * print_error - it will print error message
 * @info:return and parameter info struct
 * @estr: the string will contain specified error type
 * Return: if no numbers in string, converted number otherwise should return 0
 * error will be -1
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}
/**
 * print_d - this function will print decimal (int) number (base 10)
 * @input: input
 * @fd: file descriptor to write
 *
 * Return: the number of chars printed
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int n, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (n = 1000000000; n > 1; n /= 10)
	{
		if (_abs_ / n)
		{
			__putchar('0' + current / n);
			count++;
		}
		current %= n;
	}
	__putchar('0' + current);
	count++;
	return (count);
}
/**
 * convert_number - this is a converter function, a clone of itoa
 * @num: this is the number
 * @base: this is the base
 * @flags:this is the argument flags
 *
 * Return: it should return string
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;

	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';
	do        {
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);
	if (sign)
		*--ptr = sign;
	return (ptr);
}
/**
 * remove_comments - this function will replace first instance of '#' with '\0'
 * @buf: modifies the address of the strng
 *
 * Return: 0 always;
 */
void remove_comments(char *buf)
{
	int n;

	for (n = 0; buf[n] != '\0'; n++)
		if (buf[n] == '#' && (!n || buf[n - 1] == ' '))
		{
			buf[n] = '\0';
			break;
		}
}

