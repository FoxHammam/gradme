#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#ifndef BUFFER_SIZE 
# define BUFFER_SIZE 42
#endif

size_t ft_strlen(char *s)
{
	size_t i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}
char *ft_strchr(const char *s,int c)
{
	if (!s)
		return (NULL);
	int i = 0;
	while (s[i] != (char)c)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)&s[i]);
}
char *ft_strdup(char *s)
{
	if (!s)
		return (NULL);
	char *new = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!new)
		return (NULL);
	int i = 0;
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
char *ft_strjoin(char *s1,char *s2)
{
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	int len1 = ft_strlen(s1);
	int len2 = ft_strlen(s2);
	char *new = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!new)
		return (NULL);
	int i = 0;
	while (s1 && s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	int j = 0;
	while (s2[j])
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	free(s1);
	return (new);
}
char *get_line(char *s)
{
	if (!s)
		return (NULL);
	int i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	char *new = malloc(sizeof(char) * (i + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		new[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		new[i++] = '\n';
	new[i] = '\0';
	return (new);
}
char *free_s(char *s)
{
	int i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	while (!s[i] || (s[i] == '\n' && s[i + 1] == '\0'))
	{
		free(s);
		return (NULL);
	}
	if (s[i] == '\n')
		i++;
	char *box = malloc(sizeof(char) * (ft_strlen(s) - i + 1));
	if (!box)
		return (NULL);
	int j = 0;
	while (s[i])
		box[j++] = s[i++];
	box[j] = '\0';
	free(s);
	return (box);
}
char *take(int fd,char *s)
{
	int rp = 1;
	char *buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (rp > 0 && !ft_strchr(s, '\n'))
	{
		rp = read(fd, buffer,BUFFER_SIZE);
		if (rp <= 0)
		{
			free(buffer);
			return (s);
		}
		buffer[rp] = '\0';
		s = ft_strjoin(s,buffer);
	}
	free(buffer);
	return (s);
}
char *get_next_line(int fd)
{
	static char *save;
	char *line;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = take(fd,save);
	if (!save)
		return (NULL);
	line = get_line(save);
	save = free_s(save);
	return (line);
}
/*
int main()
{
	int fd = open("test", O_RDONLY);
	char *line = get_next_line(fd);
	while (line)
	{
		printf("%s",line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}


*/
