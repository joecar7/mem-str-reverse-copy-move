#include <stdio.h>
#include <string.h>

void *_memmove(void *dst, void *src, size_t n)
{
	char *d = dst;
	char *s = src;

	if (d > s && d < s+n) {
		d += n;
		s += n;
		while (n--)
			*--d = *--s;
	} else if (d != s) {
		while (n--)
			*d++ = *s++;
	}

	return dst;
}

int main(int argc, char **argv)
{
	while (*++argv)
		printf("%s->%s\n", *argv, _memmove(*argv, *argv+1, strlen(*argv)-1));

	return 0;
}
