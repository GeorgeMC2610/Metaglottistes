/*regex declarations */

X [a-zA-Z_][a-zA-Z1-9_]*
Y [a-zA-Z_][a-zA-Z1-9_]*|[1-9]
O [+*/%-]
W1 [ \t\n]
W2 [ \t]

%%

{X}{W2}*"="{W2}*{Y}{W2}*({O}{W2}*{Y}{W2}*)+";" {/* correct form */
printf("The following expression: %s is acceptable\n",yytext);
}

{X}{W2}*"="{W2}*({Y}|"0"){W2}*({O}{W2}*({Y}|"0"){W2}*)+";" {/* 0 constant false form */
printf("0 constant is not allowed.Expression was: %s\n",yytext);
}

{X}{W2}*"="{W2}*({Y}|"0"){W2}*[;]? {/* x=y false form*/
printf("The following expression: %s is not acceptable\n",yytext);
}

{X}{W2}*"="{W2}*({Y}|"0"){W2}*({O}{W2}*({Y}|"0"){W2}*)+ {/* missing ';' false form */
printf("You forgot the ';' symbol in the following expression: %s\n",yytext);
}

{X}?{W2}*"="{W2}*({Y}|"0")?{W2}*({O}{W2}*({Y}|"0")?{W2}*)+[;]? {/* missing constants or/and variables false form */
printf("You forgot some constants or/and variables in the following expression: %s\n",yytext);
}

{W1}+ /*eat up whitespace*/

. printf( "Unrecognized character: %s\n", yytext ); /* mark any other character as unrecognized*/

%%

main() {
printf("Give some variable declaration expressions.Examples:'x=random_name+4;', 'my_var =5 +l/y;'\nTypes as 'x=y;' are not accepted.Zero constant cant be contained and variable names should be one letter only:\n");
yylex();
}