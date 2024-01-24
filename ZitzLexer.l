%{
    #include <string>
    #include <variant>
    //#include "ZitzInterpreter.h"
    #include "ZitzParser.h"
    #include <stdlib.h>
    void yyerror(const char *);
%}

%%
"tiny"|"tin"|"ti"|"t" {
    return TINY;
}

"small"|"smal"|"sma"|"sm" {
    return SMALL;
}

"normal"|"norma"|"norm"|"nor"|"no"|"n" {
    return NORMAL;
}

"big"|"bi"|"b" {
    return BIG;
}

"field"|"fiel"|"fie"|"fi"|"f" {
    return FIELD;
}



"until"|"unti"|"unt"|"un"|"u" {
    return UNTIL;
}

"check"|"chec"|"che"|"ch" {
    return CHECK;
}



"go"|"g" {
    return GO;
}

"rl" {
    return RL;
}

"rr" {
    return RR;
}

"sonar"|"sona"|"son"|"so" {
    return SONAR;
}

"compass"|"compas"|"compa"|"comp"|"com"|"co" {
    return COMPASS;
}



"print" {
    //ECHO;
    return PRINT;
}

"return"|"retur"|"retu"|"ret"|"re" {
    return RETURN;
}



([1-9A-V][0-9A-V]*|0) {
    //ECHO;
    yylval.str = strdup(yytext);
    return NUMBER;
}

[a-z'_'][0-9a-zA-Z'_']* {
    //ECHO;
    yylval.str = strdup(yytext);
    return VARIABLE;
}

"<<" {
    return ASGL; 
}

">>" {
    return ASGR;
}

"<=" { return LE; }

">=" { return GE; }

"<>" { return NEQ; }

[-+*/<>=()\[\],.{}] { /*ECHO;*/ return *yytext; }

[ \t\n]+ /*ECHO*/; /* skip whitespace */

. yyerror("Unknown character");
%%

int yywrap(void) {
    return 1;
} 