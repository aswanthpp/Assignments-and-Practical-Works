%{
int c=0;
int l=0;
int s=0;
int h=0;
%}
vw [aeiouAEIOU]
line [\n]
space [ ]
v [a-z||A-Z]
%%
{vw} c++;
{line} l++;
{space} s++;
{v} h++;
%%
int main(){
yyin=fopen("abc.txt","r");
yylex();
printf("\nNumber of vowels :  %d \n",c);
}
int yywrap(){
return 1;
}
