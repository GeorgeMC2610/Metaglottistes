%{ 
    int a=0;
    int count=0;
    int count1=0;
%}
%%
"good" {++count;}
a|A {++a;}
[ABCDEFGH] {++count1;}
.
%%
main() {
    printf("SKARNERRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR\n");
    yylex();

if (count == 3)
{
printf("SKARNER SKARNER \n");
}
else
{
printf("SKARNER \n");
}

printf("%d\n",count);
printf("%d\n",count1);
printf("%d\n",a);
}