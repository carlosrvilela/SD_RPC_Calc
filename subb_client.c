#include "subb.h"

void
sub_prog_1(char *host, int x, int y)
{
CLIENT *clnt;
int *result_1;
numbers sub_1_arg;
#ifndef DEBUG
clnt = clnt_create (host, SUB_PROG, SUB_VERS, "udp");
if (clnt == NULL) {
clnt_pcreateerror (host);
exit (1);
}

#endif /* DEBUG */
sub_1_arg.a=x;
sub_1_arg.b=y;
result_1 = sub_1(&sub_1_arg, clnt);
if (result_1 == (int *) NULL) {
clnt_perror (clnt, "call failed");
}
else {
printf("Resultado:%d\n", *result_1);
}
#ifndef DEBUG
clnt_destroy (clnt);
#endif /* DEBUG */
}

int
main (int argc, char *argv[])
{

char *host;

if (argc < 4) {
printf ("usage: %s server_host numero1 numero2\n", argv[0]);
exit (1);
}
host = argv[1];
sub_prog_1 (host, atoi(argv[2]), atoi(argv[3]));
exit (0);
}
