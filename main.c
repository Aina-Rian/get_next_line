#include "get_next_line.h"

int main(int argc, char const *argv[])
{
	int i = 0;
	int fd = open("test.txt", O_RDONLY);

	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	while (i < 15)
	{
		printf("line %d => %s\n", i, get_next_line(fd));
		i++;
	}
	return 0;
}
