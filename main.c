#include "get_next_line.h"

int main(int argc, char const *argv[])
{
	char *result;
	int i, fd;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	printf("line 1 => %s\n", get_next_line(fd));
	printf("line 2 => %s\n", get_next_line(fd));
	printf("line 3 => %s\n", get_next_line(fd));
	printf("line 4 => %s\n", get_next_line(fd));
	printf("line 5 => %s\n", get_next_line(fd));
	printf("line 6 => %s\n", get_next_line(fd));
	printf("line 7 => %s\n", get_next_line(fd));
	printf("line 8 => %s\n", get_next_line(fd));
	printf("line 9 => %s\n", get_next_line(fd));
	return 0;
}
