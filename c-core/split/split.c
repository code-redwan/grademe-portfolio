#include <stdlib.h>
#include <stddef.h>

static size_t	is_char_in_str(char c, char* str)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

static size_t	count_words(char *str, char *charset)
{
	int	index;
	int	words;

	index = 0;
	words = 0;
	while (*(str + index))
	{
		if (is_char_in_str(*(str + index), charset) == 0)
		{
			words++;
			while (*(str + index) && is_char_in_str(*(str + index), charset) == 0)
				index++;
		}
		else
			index++;
	}
	return (words);
}

static size_t	gm_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*(str + len))
		len++;
	return (len);
}

static size_t	gm_strlcpy(char *dst, const char *src, size_t dsize)
{
	size_t index;

	index = 0;
	if (dsize > 0)
	{
		while (*(src + index) && index < (dsize - 1))
		{
			*(dst + index) = *(src + index);
			index++;
		}
		*(dst + index) = '\0';
	}
	return (gm_strlen(src));
}

static char**	no_name_now(char *str, char *charset, char** split)
{
	size_t	index;
	size_t	nested_index;
	size_t	start;
	size_t	word;
	size_t	len;

	index = 0;
	nested_index = 0;
	word = 0;
	while (nested_index <= gm_strlen(str))
	{
		if(is_char_in_str(*(str + nested_index), charset) == 1 || *(str + nested_index ) == '\0')
		{
			if (word == 1)
			{
				len = nested_index - start;
				split[index] = malloc((len + 1) * sizeof(char));
				if (split[index] == NULL)
					return (NULL);
				gm_strlcpy(split[index], (str + start), (len + 1));
				index++;
			}
			word = 0;
		}
		else
		{
			if (word == 0)
				start = nested_index;
			word = 1;
		}
		nested_index++;
	}
	return (split);
}


char **split(char *str, char *charset)
{
	size_t	words;
	char**	split;

	words = count_words(str, charset);
	split = malloc((words + 1) * sizeof(char* ));
	if (split == NULL)
		return (NULL);
	split[words] = NULL;
	return (no_name_now(str, charset, split));
}