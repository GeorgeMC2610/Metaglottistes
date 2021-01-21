%{
    int check=1;
%}
%%
[^A]*"A"([^A]*"A")+ {check = 0; printf("LATHOS");}
[^B]*"B"([^B]*"B")+ {check = 0; printf("LATHOS");}
[^C]*"C"([^C]*"C")+ {check = 0; printf("LATHOS");}
[^D]*"D"([^D]*"D")+ {check = 0; printf("LATHOS");}
[^E]*"E"([^E]*"E")+ {check = 0; printf("LATHOS");}
[^F]*"F"([^F]*"F")+ {check = 0; printf("LATHOS");}
[^G]*"G"([^G]*"G")+ {check = 0; printf("LATHOS");}
[^H]*"H"([^H]*"H")+ {check = 0; printf("LATHOS");}
[ABCDEFGH]{1,8} {
    if (check == 1)
        printf("SWSTO");
} 
%%
int main() {
    printf("Kathws ta shmeia einai 8 tha dextw maximum mexri Oktagwno/Octagon kai mporeis na xrhsimopoihseis to kathe shmeio mono MIA fora!\n\n");
    yylex();
}