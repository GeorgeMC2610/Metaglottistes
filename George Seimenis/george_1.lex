%{
int num_x = 0, num_y = 0;
%}

%%
"x"|"X" ++num_x;

"y"|"Y" ++num_y;

. printf("Unrecognized character.");
%%

main( argc, argv )
int argc;
char **argv;
{
	++argv, --argc;
	yylex();
	
	if ( argc > 0 )
		yyin = fopen( argv[0], "r" );
	else
		yyin = stdin;
	yylex();
}