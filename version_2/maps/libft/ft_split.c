#include "libft.h"
#include <stdlib.h>

static char	**free_array(char **ptr, int i)
{
	while (i > 0)
	{
		i--;
		free(ptr[i]);
	}
	free(ptr);
	return (0);
}

static int	ft_count_words(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while(str[i])
	{
		if (str[i] == c)
			i++;
		else
			{
				count++;
				while(str[i] && str[i] != c)
					i++;
			}
	}
	return (count);
}

static char	*ft_putword(char *word, char const *s, int i, int word_len)
{
	int	j;

	j = 0;
	while(word_len > 0)
	{
		word[j] = s[i - word_len];
		j++;
		word_len--;
	}
	word[j] = '\0';
	return (word);
}

static char	**ft_split_words(char const *s, char c, char **s2, int num_words)
{
	int	i;
	int	word;
	int	word_len;

	i = 0;
	word = 0;
	word_len = 0;
	while(word < num_words)
	{
		while(s[i] && s[i] == c)
			i++;
		while(s[i] && s[i] != c)
		{
			i++;
			word_len++;
		}
		s2[word] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (!s2)
			return(free_array(s2, word));
		ft_putword(s2[word], s, i, word_len);
		word_len = 0;
		word++;
	}
	s2[word] = 0;
	return (s2);
}

char	**ft_split(char const *s, char c)
{
	char	**s2;
	unsigned int	num_words;

	if(!s)
		return (0);
	num_words = ft_count_words(s, c);
	s2 = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (!s2)
		return (0);
	s2 = ft_split_words(s, c, s2, num_words);
	return (s2);
}
/*
#include <stdio.h>
int main()
{
    char **result;
    int i = 0;

    result = ft_split("Hello World 42  C", ' ');
    while (result[i])
    {
        printf("%s\n", result[i]);
        i++;
    }
    i = 0;
    while (result[i])
    {
        free(result[i]);
        i++;
    }
    free(result);

    return 0;
}*/
/*Cette fonction permet de diviser une chaine de
caracteres (char *s) en plusieur sous chaines en fonction
d'un caractere delimiteur donne (char c).

La fonction principale  ft_split  divise une chaine
en sous chaines.

La fonction  ft_count_words  compte le nombre de mots 
dans la chaine str, separes par le caractere c.

La fonction  ft_putword  copie un mot de la chaine 
d'entree dans une nouvelle chaine word. On l'utilise
pour extraire un mot donnee en fonction de sa longueur.

La fonction  ft_split_word  est chargee de decouper
reellement la chaine en mots et de les placer dans le tableau s2.

La fonction  free_array libere la memoire allouee pour le
tableau de chaine de caracteres s2.*/
