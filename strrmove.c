#include <stdio.h>
#include <string.h>

void *strrmove(void *dst, void *src, size_t n)
{
	char *d = dst;
	char *s = src;

	if (d > s && d < s+n) {
		d += n;
		*d = 0;
		while (n--)
			*--d = *s++;
	} else if (d != s) {
		s += n;
		while (n--)
			*d++ = *--s;
		*d = 0;
        } else {
		char c;
		s += n-1;
		while (d < s)
			c = *d, *d++ = *s, *s-- = c;
	}

	return dst;
}

int main(int argc, char **argv)
{
	while (*++argv)
		printf("%s->%s\n", *argv, strrmove(*argv, *argv, strlen(*argv)));

	return 0;
}
