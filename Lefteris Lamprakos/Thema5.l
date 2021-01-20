%{ 
    int countA=0;
    int countB=0;
    int countC=0;
    int countD=0;
    int countE=0;
    int countF=0;
    int countG=0;
    int countH=0;
    int count=0;
    const char* Input=""; 
%}
%%
[A] {++countA; Input = yytext;}
[B] {++countB; Input = yytext;}
[C] {++countC; Input = yytext;}
[D] {++countD; Input = yytext;}
[E] {++countE; Input = yytext;}
[F] {++countF; Input = yytext;}
[G] {++countG; Input = yytext;}
[H] {++countH; Input = yytext;}                                /* printf("%s\n",yytext); */
. {Input = yytext;}
%%
int main() {
    printf("This program will accept ANY Point,Line or Shape given,as long as is written using the following letters: A,B,C,D,E,F,G,H. You dont have to use all of them necessary.\n");
    printf("Some acceptable examples are <triangle ABC>/<square ACHG>/<line HE> and some unacceptable examples are <square ABC>/<octagon EDCBA>\n");
    printf("Consider the given letters are 8 and can be used only ONE TIME,the acceptable references are: point, line, triangle, square, pentagon, hexagon, heptagon, octagon + the numbers of the letters to the right side.\n\n");
    Input = yytext;
    printf("%s\n",Input);
    printf("TO YYTEXT PREPEI NA EMFANISTEI EDW",yytext);
    yylex();
    

count = countA + countB + countC + countD + countE + countF + countG + countH;

if (countA > 1||countB > 1||countC > 1||countD > 1||countE > 1||countF > 1||countG > 1||countH > 1)
{
    printf("unacceptable reference,try again\n");
}
else 
{
    if (count == 1 && Input == "point")
    {
        printf(Input);
    }
    else
    {
        if (count == 2 && Input == "line")
        {
            printf(Input);
        }
        else
        {
            if (count == 3 && Input == "triangle")
            {
                printf(Input);
            }
            else
            {
                if (count == 4 && Input == "square")
                {
                    printf(Input);
                }
                else
                {
                    if (count == 5 && Input == "pentagon")
                    {
                        printf(Input);
                    }
                    else
                    {
                        if (count == 6 && Input == "hexagon")
                        {
                            printf(Input);
                        }
                        else
                        {
                            if (count == 7 && Input == "heptagon")
                            {
                                printf(Input);
                            }
                            else
                            {
                                if (count == 8 && Input == "octagon")
                                {
                                    printf(Input);
                                }
                            }
                        }
                    }
                }
            }
        }
    } 
} 

printf("%d\n",count);
}