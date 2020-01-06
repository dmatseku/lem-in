
int	validate_ant(char const *const restrict str)
{
	int i;

	i = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i])
		return (0);
	return (1);
}

int	validate_room(char const *const restrict str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	if (!str[i] || str[i + 1] == ' ' || !str[i + 1])
		return (0);
	i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	if (!str[i] || str[i + 1] == ' ' || !str[i + 1])
		return (0);
	i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i])
		return (0);
	return (1);
}

int	validate_link(char const *const restrict str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '-')
		i++;
	if (!str[i] || !str[i + 1])
		return (0);
	i++;
	while (str[i] && str[i] != '-')
		i++;
	if (str[i])
		return (0);
	return (1);
}
