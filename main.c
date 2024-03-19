#include "get_next_line.h"

int ft_strchr(char *str, char c);
int main(int argc, char const *argv[])
{
	char *result;
	int i, fd;

	i = 0;
	// result = "hello ";
	// result = ft_strjoin(result,  "world ");
	// result = ft_strjoin(result, "from ");
	// printf("%s", ft_strjoin(result, "madagascar"));
	
	fd = open("test.txt", O_RDONLY);
	while (i < 1)
	{
		printf("line %d => %s\n", i, get_next_line(fd));
		i++;
	}
	// printf("line 3 => %s\n", get_next_line(fd));
	// printf("line 4 => %s\n", get_next_line(fd));
	// printf("line 5 => %s\n", get_next_line(fd));
	// printf("line 6 => %s\n", get_next_line(fd));
	// printf("line 7 => %s\n", get_next_line(fd));
	// printf("line 8 => %s\n", get_next_line(fd));
	// printf("line 9 => %s\n", get_next_line(fd));

	return 0;
}
