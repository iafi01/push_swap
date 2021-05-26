/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:59:38 by liafigli          #+#    #+#             */
/*   Updated: 2021/05/26 16:54:47 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct  s_stack
{
    int	num;
	struct s_stack *next;
} t_stack;

size_t			ft_strlen(const char *str);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);

int				ft_tolower(int c);
int				ft_toupper(int c);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char	*big, const char *little, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);

void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strdup(const char *s1);
void			*ft_calloc(size_t count, size_t size);

/*
** Seconda parte
*/

char			*ft_itoa(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/*
** Bonus
*/

t_stack			*ft_lstnew(int content);
t_stack			*ft_lstlast(t_stack *lst);
int				ft_lstsize(t_stack *lst);
void			ft_lstadd_front(t_stack **lst, t_stack *new);
void			ft_lstadd_back(t_stack *lst, t_stack *new);

void			ft_lstdelone(t_stack *lst, void (*del)(int));
void			ft_lstclear(t_stack **lst, void (*del)(int));
void			ft_lstiter(t_stack *lst, void (*f)(int));
int				ft_putchar(char c);
int				ft_putstr(char *s);
void			ft_strdel(char **as);
char			**ft_ssplit(char *s, char *set);
float			ft_atof(char *str);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_str_c_count(char *str, char c);

#endif
