#include <stdio.h>
#include <string.h>

void *strrcpy(void *dst, const void *src, size_t n)
{
	char *d = dst;
	const char *s = src + n;

	while (n--)
		*d++ = *--s;
	*d = 0;

	return dst;
}

int main(int argc, char **argv)
{
	char buf[64];

	while (*++argv)
		printf("%s->%s\n", *argv, strrcpy(buf, *argv, strlen(*argv)));

	return 0;
}
