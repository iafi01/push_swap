#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

static int	count_words(const char *str, char c)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (*str)
	{
		if (*str != c && flag == 0)
		{
			flag = 1;
			i++;
		}
		else if (*str == c)
			flag = 0;
		str++;
	}
	return (i);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

static char	**ft_close(char **split, int j)
{
	split[j] = 0;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	i = 0;
	j = 0;
	index = -1;
	if (!s)
		return (0);
	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!split)
		return (0);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((((s[i] == c || i == ft_strlen(s)) && index >= 0)))
		{
			split[j++] = word_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	return (ft_close(split, j));
}

char **argv_unico(char **argv_copy, int n_num, int len)
{
    int i = 0;
    char **ret;

    while (i++ < len)
    {
        ret = ft_split(argv_copy[i], ' ');
    }
}

int main(int argc, char **argv)
{
    int i = 0;
    argv = argv_unico(&argv[i], 4, argc - 1);
    while (i < 4)
        printf("%s", argv[i++]);
    return (0);
}
