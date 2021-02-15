Y "line "|"triangle "|"square "|"pentagon "|"hexagon "|"heptagon "|"octagon "
X1 [BCDEFGH]*"A"[BCDEFGH]*("A"[BCDEFGH]*)+
X2 [ACDEFGH]*"B"[ACDEFGH]*("B"[ACDEFGH]*)+
X3 [ABDEFGH]*"C"[ABDEFGH]*("C"[ABDEFGH]*)+
X4 [ABCEFGH]*"D"[ABCEFGH]*("D"[ABCEFGH]*)+
X5 [ABCDFGH]*"E"[ABCDFGH]*("E"[ABCDFGH]*)+
X6 [ABCDEGH]*"F"[ABCDEGH]*("F"[ABCDEGH]*)+
X7 [ABCDEFH]*"G"[ABCDEFH]*("G"[ABCDEFH]*)+
X8 [ABCDEFG]*"H"[ABCDEFG]*("H"[ABCDEFG]*)+ 
%%
"point "[Α-Η]{2,} printf("TOO MANY LETTERS");
"line "[Α-Η]{3,} printf("TOO MANY LETTERS");
"triangle "[Α-Η]{4,} printf("TOO MANY LETTERS");
"square "[Α-Η]{5,} printf("TOO MANY LETTERS");
"pentagon "[Α-Η]{6,} printf("TOO MANY LETTERS");
"hexagon "[Α-Η]{7,} printf("TOO MANY LETTERS");
"heptagon "[Α-Η]{8,} printf("TOO MANY LETTERS");
"octagon "[Α-Η]{9,} printf("TOO MANY LETTERS");

{Y}({X1}|{X2}|{X3}|{X4}|{X5}|{X6}|{X7}|{X8}) printf("DUPLICATE/S");

"point "[Α-Η] printf("CORRECT EXPRESSION");
"line "[Α-Η]{2} printf("CORRECT EXPRESSION");
"triangle "[Α-Η]{3} printf("CORRECT EXPRESSION");
"square "[Α-Η]{4} printf("CORRECT EXPRESSION");
"pentagon "[Α-Η]{5} printf("CORRECT EXPRESSION");
"hexagon "[Α-Η]{6} printf("CORRECT EXPRESSION");
"heptagon "[Α-Η]{7} printf("CORRECT EXPRESSION");
"octagon "[Α-Η]{8} printf("CORRECT EXPRESSION");

[^\n]+ printf("UNRECOGNIZED CHARACTER/S");
%%
int main() 
{
    printf("This program will accept any Point,Line or Shape given, using the following letters: A,B,C,D,E,F,G,H. It is not necessary to use all of them.\n");
    printf("Some acceptable examples are 'triangle ABC'/'square ACHG'/'line HE' and some unacceptable examples are 'square ABC'/'octagon EDCBA'\n");
    printf("EACH LETTER CAN BE USED ONE TIME\n");
    printf("The acceptable references are: point, line, triangle, square, pentagon, hexagon, heptagon, octagon\n");
    printf("USE SPACE BEWTEEN THE WORD AND THE LETTERS A-H.Any other expression will be considered unacceptable. etc 'pentagon ABCDE'\n");
    yylex();
}