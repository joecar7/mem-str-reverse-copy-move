#include <stdio.h>
#include <string.h>

void *_strmove(void *dst, void *src, size_t n)
{
	char *d = dst;
	char *s = src;

	if (d > s && d < s+n) {
		d += n;
		s += n;
		*d = 0;
		while (n--)
			*--d = *--s;
	} else if (d != s) {
		while (n--)
			*d++ = *s++;
		*d = 0;
	}

	return dst;
}

int main(int argc, char **argv)
{
	while (*++argv)
		printf("%s->%s\n", *argv, _strmove(*argv, *argv+1, strlen(*argv)-1));

	return 0;
}
