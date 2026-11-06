#if !__USE_POSIX
typedef long int ssize_t;

ssize_t getline(char **buf, size_t *bufsiz, FILE *fp);
#elif !HAVE_GETLINE
#define HAVE_GETLINE 1
#endif
