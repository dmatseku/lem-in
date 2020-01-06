
char	*ft_strcat(char *str1, const char *str2)
{
	char *const res = str1;

	while (*str1 != '\0')
		str1++;
	while (*str2 != '\0')
	{
		*str1 = *str2;
		str1++;
		str2++;
	}
	return (res);
}
