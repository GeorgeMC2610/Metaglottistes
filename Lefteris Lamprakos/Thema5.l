%{ 
    int count1=0;
    int count=0;
%}
%%
[A]{2,}|[B]{2,}|[C]{2,}|[D]{2,}|[E]{2,}|[F]{2,}|[G]{2,}|[H]{2,} {printf("LATHOS");}
[ABCDEFGH] {++count1;}
.
%%
int main() {
    printf("Auto einai ena programma pou tha dextei otidhpote shmeio,eutheia kai sxhma mou dwseis,xrhsimopoiontas ta shmeia A,B,C,D,E,F,G,H. Mporeis na mhn ta xrhsimopoihseis ola an thes.\n");
    printf("Tha dextw omws gia paradeigma mono ton oro <Trigwno ABC>/<Triangle ABC> h <Tetragwno ACHG>/<Square ACHG> alla oxi ton oro <Tetragwno ABC>/<Square ABC>\n");
    printf("Kathws ta shmeia einai 8 tha dextw maximum mexri Oktagwno/Octagon kai mporeis na xrhsimopoihseis to kathe shmeio mono MIA fora!\n\n");
    yylex();

/*if (count1 == 1)
{
    printf("SKARNER SKARNER \n");
}
else 
{
    if (yytext == "ABC good")
    {
        printf("SKARNER \n");
    }
} */

printf("%d\n",count);
printf("%d\n",count1);
printf("%s\n",yytext);
}