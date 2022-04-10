%{
#include "token.h"
%}
DIGIT [0-9]
IDENTIFIER [a-zA-Z]([a-zA-Z]|[0-9])*
LETTER [a-zA-Z]
%%
(" "|\t|\n)    /* skip whitespace */
"while"   { return TOKEN_WHILE; }
"return"  { return TOKEN_RETURN; }
"for"    { return TOKEN_FOR; }
\+    { return TOKEN_ADD; }
\-    { return TOKEN_SUBTRACT; }
\*    { return TOKEN_MULT; }
\/    { return TOKEN_DIV; }
.   { return TOKEN_ERROR; }
def\ {IDENTIFIER}\({IDENTIFIER}\): { return TOKEN_FUNCTION_CALL; }
{IDENTIFIER}\(({IDENTIFIER}|{DIGIT}+)*\) { return TOKEN_FUNCTION_CALL; }
{IDENTIFIER}   { return TOKEN_IDENTIFIER; }
%%
int yywrap() { return 1; }