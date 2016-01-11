/* igo lexer definitions. */
%option c++
%option prefix="igo"
%option yylineno
%option noyywrap

%{
#include "igoparser.tab.h"

#define output_token(x)
%}

letter          [A-Za-z_]
decimal_digit   [0-9]
octal_digit     [0-7]
hex_digit       [0-9A-Fa-f]
identifier      [A-Za-z_][A-Za-z0-9_]*

%%

break           { output_token(TOKEN_BREAK); }
case            { output_token(TOKEN_CASE); }
chan            { output_token(TOKEN_CHAN); }
const           { output_token(TOKEN_CONST); }
continue        { output_token(TOKEN_CONTINUE); }
default         { output_token(TOKEN_DEFAULT); }
defer           { output_token(TOKEN_DEFER); }
else            { output_token(TOKEN_ELSE); }
fallthrough     { output_token(TOKEN_FALLTHROUGH); }
for             { output_token(TOKEN_FOR); }
func            { output_token(TOKEN_FUNC); }
go              { output_token(TOKEN_GO); }
goto            { output_token(TOKEN_GOTO); }
if              { output_token(TOKEN_IF); }
import          { output_token(TOKEN_IMPORT); }
interface       { output_token(TOKEN_INTERFACE); }
map             { output_token(TOKEN_MAP); }
package         { output_token(TOKEN_PACKAGE); }
range           { output_token(TOKEN_RANGE); }
return          { output_token(TOKEN_RETURN); }
select          { output_token(TOKEN_SELECT); }
struct          { output_token(TOKEN_STRUCT); }
switch          { output_token(TOKEN_SWITCH); }
type            { output_token(TOKEN_TYPE); }
var             { output_token(TOKEN_VAR); }

%%
/* User code. */
