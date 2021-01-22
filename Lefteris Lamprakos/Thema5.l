Y "line "|"triangle "|"square "|"pentagon "|"hexagon "|"heptagon "|"octagon "/*declarations section*/
T {Y}[ABCDEFGH]+
X1 [BCDEFGH]*"A"[BCDEFGH]*("A"[BCDEFGH]*)+
X2 [ACDEFGH]*"B"[ACDEFGH]*("B"[ACDEFGH]*)+
X3 [ABDEFGH]*"C"[ABDEFGH]*("C"[ABDEFGH]*)+
X4 [ABCEFGH]*"D"[ABCEFGH]*("D"[ABCEFGH]*)+
X5 [ABCDFGH]*"E"[ABCDFGH]*("E"[ABCDFGH]*)+
X6 [ABCDEGH]*"F"[ABCDEGH]*("F"[ABCDEGH]*)+
X7 [ABCDEFH]*"G"[ABCDEFH]*("G"[ABCDEFH]*)+
X8 [ABCDEFG]*"H"[ABCDEFG]*("H"[ABCDEFG]*)+

%%

"point "[ABCDEFGH]{2,} printf("TOO MANY LETTERS");         /*check if the letters are more than the given word or shape could have, lines 14-21*/
"line "[ABCDEFGH]{3,} printf("TOO MANY LETTERS");          /*if yes,a TOO MANY LETTERS message will appear*/
"triangle "[ABCDEFGH]{4,} printf("TOO MANY LETTERS");
"square "[ABCDEFGH]{5,} printf("TOO MANY LETTERS");
"pentagon "[ABCDEFGH]{6,} printf("TOO MANY LETTERS");
"hexagon "[ABCDEFGH]{7,} printf("TOO MANY LETTERS");
"heptagon "[ABCDEFGH]{8,} printf("TOO MANY LETTERS");
"octagon "[ABCDEFGH]{9,} printf("TOO MANY LETTERS");

{Y}({X1}|{X2}|{X3}|{X4}|{X5}|{X6}|{X7}|{X8}) printf("DUPLICATE/S");     /*check if there are any duplicates,if yes,a DUPLICATE message will appear*/

"point "[ABCDEFGH] printf("CORRECT EXPRESSION");         /*Here, after we check for duplicates or more letters*/
"line "[ABCDEFGH]{2} printf("CORRECT EXPRESSION");       /*it will check if the number of letters are EXACTLY as many as they should be*/
"triangle "[ABCDEFGH]{3} printf("CORRECT EXPRESSION");   /*etc 3 for triangle,8 for octagon, lines 27-32*/
"square "[ABCDEFGH]{4} printf("CORRECT EXPRESSION");     /*if thats true,it will print the message CORRECT*/
"pentagon "[ABCDEFGH]{5} printf("CORRECT EXPRESSION");
"hexagon "[ABCDEFGH]{6} printf("CORRECT EXPRESSION");
"heptagon "[ABCDEFGH]{7} printf("CORRECT EXPRESSION");
"octagon "[ABCDEFGH]{8} printf("CORRECT EXPRESSION");

({T})?[^\n]* printf("UNRECOGNIZED CHARACTERS");/*print UNRECOGNIZED CHARACTERS if the user tries to write unwanted characters or if he makes an alphabetical mistake*/
%%
int main() {            /*the lines 37-41 will inform the user about the expressions that he is allowed to write or not*/
    printf("This program will accept any Point,Line or Shape given, using the following letters: A,B,C,D,E,F,G,H. You dont have to use all of them necessary.\n");
    printf("Some acceptable examples are 'triangle ABC'/'square ACHG'/'line HE' and some unacceptable examples are 'square ABC'/'octagon EDCBA'\n");
    printf("EACH LETTER CAN BE USED ONE TIME");
    printf("the acceptable references are: point, line, triangle, square, pentagon, hexagon, heptagon, octagon");
    printf("USE SPACE BEWTEEN THE WORD AND THE LETTERS A-H.Any other expression with be considered unacceptable.\n etc 'pentagon ABCDE'");
    yylex();
}