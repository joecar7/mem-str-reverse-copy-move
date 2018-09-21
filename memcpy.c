#include <stdio.h>
#include <string.h>

void *_memcpy(void *dst, const void *src, size_t n)
{
	char *d = dst;
	const char *s = src;

	while (n--)
		*d++ = *s++;

	return dst;
}

int main(int argc, char **argv)
{
	char buf[64];

	memset(buf, 0, sizeof(buf));

	while (*++argv)
		printf("%s->%s\n", *argv, _memcpy(buf, *argv, strlen(*argv)));

	return 0;
}
