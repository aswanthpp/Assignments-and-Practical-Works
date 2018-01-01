%{
int s=0;
int l=0;
%}
line [\t]
space [ ]
%%
{line} l++;
{space} s++;
%%
int main(){
yyin=fopen("abc.txt","r");
yylex();
}
int yywrap(){
return 1;
}
