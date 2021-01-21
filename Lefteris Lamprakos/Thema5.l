%{
    int check=1;
%}
Y "point "|"line "|"triangle "|"square "|"pentagon "|"hexagon "|"heptagon "|"octagon "
X1 [BCDEFGH]*"A"[BCDEFGH]*("A"[BCDEFGH]*)+
X2 [ACDEFGH]*"B"[ACDEFGH]*("B"[ACDEFGH]*)+
X3 [ABDEFGH]*"C"[ABDEFGH]*("C"[ABDEFGH]*)+
X4 [ABCEFGH]*"D"[ABCEFGH]*("D"[ABCEFGH]*)+
X5 [ABCDFGH]*"E"[ABCDFGH]*("E"[ABCDFGH]*)+
X6 [ABCDEGH]*"F"[ABCDEGH]*("F"[ABCDEGH]*)+
X7 [ABCDEFH]*"G"[ABCDEFH]*("G"[ABCDEFH]*)+
X8 [ABCDEFG]*"H"[ABCDEFG]*("H"[ABCDEFG]*)+ 
%%
"point "[ABCDEFGH]{2,} printf("TOO MANY LETTERS"); /*22-29 ELEGXOS SXHMATOS + TOO MANY LETTERS ARITHMOS GRAMMATWN*/
"line "[ABCDEFGH]{3,} printf("TOO MANY LETTERS");
"triangle "[ABCDEFGH]{4,} printf("TOO MANY LETTERS");
"square "[ABCDEFGH]{5,} printf("TOO MANY LETTERS");
"pentagon "[ABCDEFGH]{6,} printf("TOO MANY LETTERS");
"hexagon "[ABCDEFGH]{7,} printf("TOO MANY LETTERS");
"heptagon "[ABCDEFGH]{8,} printf("TOO MANY LETTERS");
"octagon "[ABCDEFGH]{9,} printf("TOO MANY LETTERS");
{Y}({X1}|{X2}|{X3}|{X4}|{X5}|{X6}|{X7}|{X8}) printf("DUPLICATE");
"point "[ABCDEFGH] {printf("\nCORRECT");} /*14-21 ELEGXOS SXHMATOS + SWSTOS ARITHMOS GRAMMATWN*/
"line "[ABCDEFGH]{2} {printf("\nCORRECT");}
"triangle "[ABCDEFGH]{3} {printf("\nCORRECT");}
"square "[ABCDEFGH]{4} {printf("\nCORRECT");}
"pentagon "[ABCDEFGH]{5} {printf("\nCORRECT");}
"hexagon "[ABCDEFGH]{6} {printf("\nCORRECT");}
"heptagon "[ABCDEFGH]{7} {printf("\nCORRECT");}
"octagon "[ABCDEFGH]{8} {printf("\nCORRECT");}
%%
int main() {
    printf("Kathws ta shmeia einai 8 tha dextw maximum mexri Oktagwno/Octagon kai mporeis na xrhsimopoihseis to kathe shmeio mono MIA fora!\n\n");
    yylex();
}