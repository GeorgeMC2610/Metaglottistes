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
    printf("SKARNERRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR\n apla peiramatizomai akoma");
    yylex();

if (count == 1)
{
printf("SKARNER SKARNER \n");
}
else
{
printf("SKARNER \n");
}

printf("%d\n",count);
printf("%d\n",a);
}