%{
    int check=1;
%}
Y "point "|"line "|"triangle "|"square "|"pentagon "|"hexagon "|"heptagon "|"octagon "
X1 [BCDEFGH]*"A"[BCDEFGH]*("A"[BCDEFGH]*)+
X2 [ACDEFGH]*"B"[ACDEFGH]*("B"[ACDEFGH]*)+
X3 [ABDEFGH]*"C"[ABDEFGH]*("C"[ABDEFGH]*)+
X4 [ABCEFGH]*"D"[ABCEFGH]*("D"[ABCEFGH]*)+
%%
"point "[ABCDEFGH]{2,} printf("TOO MANY LETTERS"); /*22-29 ELEGXOS SXHMATOS + TOO MANY LETTERS ARITHMOS GRAMMATWN*/
"line "[ABCDEFGH]{3,} printf("TOO MANY LETTERS");
"triangle "[ABCDEFGH]{4,} printf("TOO MANY LETTERS");
"square "[ABCDEFGH]{5,} printf("TOO MANY LETTERS");
{Y}({X1}|{X2}|{X3}|{X4}) printf("DUPLICATE");
"point "[ABCDEFGH] {printf("\nCORRECT");} /*14-21 ELEGXOS SXHMATOS + SWSTOS ARITHMOS GRAMMATWN*/
"line "[ABCDEFGH]{2} {printf("\nCORRECT");}
"triangle "[ABCDEFGH]{3} {printf("\nCORRECT");}
"square "[ABCDEFGH]{4} {printf("\nCORRECT");}
[^\n]+ printf("LATHOS");
%%
int main() {
    printf("Kathws ta shmeia einai 8 tha dextw maximum mexri Oktagwno/Octagon kai mporeis na xrhsimopoihseis to kathe shmeio mono MIA fora!\n\n");
    yylex();
}