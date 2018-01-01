%{
int c=0;
int l=0;
int s=0;
%}
char [a-z||A-Z]
line [\n]
space [ ]
%%
{char} c++;
{line} l++;
{space} s++;
%%
int main(){
yyin=fopen("abc.txt","r");
yylex();
printf("\nNumber of characters :  %d \n",c);
printf("\nNumber of Lines : %d \n",l);
printf("\nNumber of Space : %d \n",s);
}
int yywrap(){
return 1;
}
