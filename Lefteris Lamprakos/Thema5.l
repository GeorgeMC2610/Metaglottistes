%{ 
    int a=0;
    int count=0;
%}
%%
"good" {++count;}
a|A {++a;}
.
%%
main() {
    yylex();
printf("%d\n",count);
printf("%d\n",a);
}