%{ 
    int a=0;
    int count=0;
    int count1=0;
%}
%%
"good" {++count;}
[ABCDEFGH] {++count1;}
a|A {++a;}
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