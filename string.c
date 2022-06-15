#include "monty.h"

/**
 * is_delim - check if a char
 * is a delimitor
 * @ch: the char to check
 * @delim: the array of delimitor char
 *
 * Return: 1 if is a delimitor char
 * otherwise return 0
 */
int is_delim(char ch, char *delim)
{
	int i = 0;

	while (delim[i])
	{
		if (ch == delim[i])
			return (1);
		i++;
	}
	return (0);
}

/**
 * count_word - count the number
 * of word in a string
 * @str: the given string of strtow
 * @delim: the array of delimitor char
 *
 * Return: integer
 */
int count_word(char *str, char *delim)
{
	int i = 0, size = 0;

	while (str[i])
	{
		while (is_delim(str[i], delim))
			i++;
		if (!is_delim(str[i], delim) && str[i])
		{
			size++;
			while (str[i] && !is_delim(str[i], delim))
				i++;
		}
	}
	return (size);
}

/**
 * get_next_word - function that return
 * a pointer to the next word
 * @str: the string to get next word
 * @delim: delimitor
 *
 * Return: pointer to the next word
 */
char *get_next_word(char *str, char *delim)
{
	int i = 0;

	while (is_delim(*(str + i), delim) && *(str + i))
		i++;

	return (str + i);
}

/**
 * get_word_len -  determine the
 * length of the current word.
 * @str: the pointer where the string start
 * @delim: the array of delimitor char
 *
 * Return: a integer representing the length
 * of the line
 */
int get_word_len(char *str, char *delim)
{
	int i = 0;

	while (str[i] && !is_delim(str[i], delim))
		i++;
	return (i);
}


/**
 * strtow - splits a string into words.
 * @str: the string to split.
 * @delim: the array of delimitor char
 *
 * Return: a pointer to an array of
 * strings (words) or NULL
 */
char **strtow(char *str, char *delim)
{
	char **words;
	int size = 0, word_len, i = 0, j;

	if (str == NULL || !*str)
		return (NULL);
	size = count_word(str, delim);
	if (size == 0)
		return (NULL);

	words = (char **) malloc(sizeof(char *) * (size + 1));
	if (!words)
		return (NULL);

	while (i < size)
	{
		if (is_delim(*str, delim))
			str = get_next_word(str, delim);
		word_len = get_word_len(str, delim);
		words[i] = (char *) malloc(sizeof(char) * (word_len + 1));
		if (!words[i])
		{
			while (i >= 0)
			{
				free(words[i]);
				i--;
			}
			return (NULL);
		}
		j = 0;
		while (j < word_len)
		{
			words[i][j] = *str;
			str++;
			j++;
		}
		words[i][j] = '\0';
		i++;
	}
	words[i] = NULL;
	return (words);
}
