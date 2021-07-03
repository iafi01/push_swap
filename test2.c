// Online C compiler to run C program online
#include <stdio.h>
// Online C compiler to run C program online
#include <strings.h>
// Online C compiler to run C program online
#include <stdlib.h>
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
	while (i <= strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((((s[i] == c || i == strlen(s)) && index >= 0)))
		{
			split[j++] = word_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	return (ft_close(split, j));
}

char **nuovo_argv(int argc, char **argv)
{
	char **s;
    char **f;
    int j = 0;
    int i = 1;
	int k = 0;
    f = calloc(10,sizeof(char*));
    *f = calloc(10,sizeof(char));
    while (i < argc)
    {
        s = ft_split(argv[i++], ' ');
		k = 0;
		while (s[k])
        	f[j++] = s[k++];
    }
    return (f);
}

int main(int argc, char **argv) {
	int i = -1;
	char **s;
	s = nuovo_argv(argc, argv);
	while (i++ < 3)
    	printf("%s|",s[i]);
}