#include "shell.h"
/**
 * *_strncpy - this copies string
 * @dest: to copy the destination string to
 * @src: this is the source string
 * @n: this is the amount of char to be copied
 * Return: returns the concatenated strng
 */
char *_strncpy(char *dest, char *src, int n)
{
	int j, k;
	char *s = dest;

	j = 0;

	while (src[j] != '\0' && j < n - 1)
	{
		dest[j] = src[j];
		j++;
	}
	if (j < n)
	{
		k = j;
		while (k < n)
		{
			dest[k] = '\0';
			k++;
		}
	}
	return (s);
}
/**
 * *_strncat- concatenates two strngs
 * @dest:at destination first strng
 * @src:at source second strng
 * @n: the is number of bytes to be maximally used
 * Return: concatenated strng
 */
char *_strncat(char *dest, char *src, int n)
{
	int j, k;
	char *s = dest;

	j = 0;
	k = 0;

	while (dest[j] != '\0')
		j++;
	while (src[k] != '\0' && k < n)
	{
		dest[j] = src[k];
		j++;
		k++;
	}
	if (k < n)
		dest[j] = '\0';
	return (s);
}
/**
 * *_strchr- this locates a char in a strng
 * @j:strng to be parsed
 * @k: char to look for
 * Return: (j) a pointer to memory area j
 */
char *_strchr(char *j, char k)
{
	do {
		if (*j == k)
			return (j);
	} while (*j++ != '\0');
	return (NULL);
}

