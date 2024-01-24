%{
    #include <string>
    #include <variant>
    #include <iostream>
    #include <stdio.h>
    #include <unordered_map>
    #include <set>
    #include <algorithm>
    #include <iterator>
    #include <fstream>
    #include "ZitzInterpreter.h"

    int yylex(void);
    void yyerror(const char *);
    extern FILE * yyin;

    std::unordered_map<std::string, int> sym;
%}

%code requires { #include "ZitzInterpreter.h" }

%union{
    const char *str;
    Node_t *nPtr;
}

%token <str> NUMBER VARIABLE 
%token <nPtr> TINY SMALL NORMAL BIG FIELD UNTIL CHECK GO RL RR SONAR COMPASS PRINT RETURN ASGL ASGR LE GE NEQ

%type <nPtr> program function_defines function_define function_define_field function_define_variable function_parameters parameters parameter parameter_variable parameter_field 
%type <nPtr> statement_list statements statement check until variable_type function_call_args exp_list indexator variable_init variable_list field_init 
%type <nPtr> exp exp_bracket exp_assign_left exp_assign_right exp_compare exp_term exp_factor exp_resatom exp_atom function_call

%{
    ZitzInterpreter interpreter;
%}

%%
program:
    function_defines { 
        interpreter.Process($1); 
        //std::vector<bool> crossings {};
        //std::cout << "\n\n";
        //ZitzInterpreter::Print($1, crossings);
        $$ = $1;
    }
    ;

function_define_field:
    FIELD variable_type variable_type VARIABLE '(' function_parameters ')' '{' statement_list '}'
    {
        Node_t *var = new IdNode_t(NodeSymbol::variable, $4);
        $$ = (Node_t*) new SymNode_t(NodeSymbol::function_define_field, {$2, $3, var, $6, $9});
    }
    ;

function_define_variable:
    variable_type VARIABLE '(' function_parameters ')' '{' statement_list '}'
    {
        Node_t *var = new IdNode_t(NodeSymbol::variable, $2);
        $$ = (Node_t*) new SymNode_t(NodeSymbol::function_define_variable, {$1, var, $4, $7}); 
    }
    ;

function_define:
    function_define_field { $$ = $1; }
    | function_define_variable { $$ = $1; }
    ;

function_defines:
    function_define {
        $$ = (Node_t*) new SymNode_t(NodeSymbol::program, {$1});
    }
    | function_defines function_define { 
        $1->ch.push_back($2);
        $$ = $1;
    }
    ;

parameter:
    parameter_variable { $$ = $1; }
    | parameter_field { $$ = $1; }
    ;

parameters:
    /* empty */ { $$ = (Node_t*) new SymNode_t(NodeSymbol::function_parameters, {}); }
    | parameters parameter ',' { $1->ch.push_back($2); $$ = $1; }
    ;

function_parameters:
    /* empty */ { $$ = (Node_t*) new SymNode_t(NodeSymbol::function_parameters, {}); }
    | parameters parameter { $1->ch.push_back($2); $$ = $1; }
    ;

parameter_variable:
    variable_type VARIABLE
    {
        Node_t *var = (Node_t*) new IdNode_t(NodeSymbol::variable, $2);
        $$ = (Node_t*) new SymNode_t(NodeSymbol::parameter_variable, {$1, var});
    }
    ;

parameter_field:
    FIELD variable_type variable_type VARIABLE
    {
        Node_t *var = (Node_t*) new IdNode_t(NodeSymbol::variable, $4);
        $$ = (Node_t*) new SymNode_t(NodeSymbol::parameter_field, {$2, $3, var});
    }
    ;

statement:
    RETURN exp { $$ = new OperNode_t(NodeSymbol::ret, RETURN, {$2}); }
    | exp { $$ = $1; }
    | variable_init { $$ = $1; }
    | field_init { $$ = $1; }
    | PRINT exp { $$ = new OperNode_t(NodeSymbol::print, PRINT, {$2}); }
    | check { $$ = $1; }
    | until { $$ = $1; }
    ;

statements:
    /* empty */ { $$ = (Node_t*) new SymNode_t(NodeSymbol::statement_list, {}); }
    | statements statement ',' { $1->ch.push_back($2); $$ = $1; }
    ;

statement_list:
    '.' { $$ = (Node_t*) new SymNode_t(NodeSymbol::statement_list, {}); }
    | statements statement '.' { $1->ch.push_back($2); $$ = $1; }
    ;

check:
    CHECK exp '{' statement_list '}' { $$ = (Node_t*) new OperNode_t(NodeSymbol::check, CHECK, {$2, $4}); }
    ;

until:
    UNTIL exp '{' statement_list '}' { $$ = (Node_t*) new OperNode_t(NodeSymbol::until, UNTIL, {$2, $4}); }
    ;

variable_type:
    TINY { $$ = (Node_t*) new SymNode_t(NodeSymbol::tiny, {}); }
    | SMALL { $$ = (Node_t*) new SymNode_t(NodeSymbol::small, {}); }
    | NORMAL { $$ = (Node_t*) new SymNode_t(NodeSymbol::normal, {}); }
    | BIG { $$ = (Node_t*) new SymNode_t(NodeSymbol::big, {}); }
    ;

function_call:
    VARIABLE function_call_args {
        Node_t *var = (Node_t*) new IdNode_t(NodeSymbol::variable, $1);
        $$ = (Node_t*) new SymNode_t(NodeSymbol::function_call, {var, $2});
    }
    ;

function_call_args:
    '(' exp_list ')' { $$ = $2; }
    ;

exp_list:
    /* empty */ { $$ = (Node_t*) new SymNode_t(NodeSymbol::function_call_args, {}); } 
    | exp_list exp { $1->ch.push_back($2); $$ = $1; }
    ;

indexator:
    VARIABLE '[' exp exp ']' { 
        Node_t *var = new IdNode_t(NodeSymbol::variable, $1);
        $$ = (Node_t*) new SymNode_t(NodeSymbol::indexator, {var, $3, $4}); 
    }
    ;

variable_init:
    variable_type variable_list ASGL exp 
    { 
        $2->ch.insert($2->ch.begin(), $1);
        $2->ch.push_back($4);
        $$ = $2;
    }
    ;

variable_list:
    variable_list VARIABLE 
    { 
        Node_t *var = (Node_t*) new IdNode_t(NodeSymbol::variable, $2);
        $1->ch.push_back(var); $$ = $1; 
    }
    | VARIABLE 
    { 
        Node_t *var = (Node_t*) new IdNode_t(NodeSymbol::variable, $1);
        $$ = (Node_t*) new SymNode_t(NodeSymbol::variable_init, {var});
    }
    ;

field_init:
    FIELD variable_type variable_type variable_list ASGL exp
    {
        $4->symbol = NodeSymbol::field_init;
        $4->ch.insert($4->ch.begin(), $3);
        $4->ch.insert($4->ch.begin(), $2);
        $4->ch.push_back($6);
        $$ = $4;
    }
    ;

exp_atom:
    NUMBER { $$ = (Node_t *) new ConNode_t(NodeSymbol::number, $1); }
    | VARIABLE { $$ = (Node_t *) new IdNode_t(NodeSymbol::variable, $1); }
    | exp_bracket { $$ = $1; }
    | function_call { $$ = $1; }
    | SONAR { $$ = (Node_t *) new OperNode_t(NodeSymbol::sonar, SONAR, {}); }
    | GO { $$ = (Node_t *) new OperNode_t(NodeSymbol::go, GO, {}); }
    | COMPASS { $$ = (Node_t *) new OperNode_t(NodeSymbol::compass, COMPASS, {}); }
    | RR { $$ = (Node_t *) new OperNode_t(NodeSymbol::rr, RR, {}); }
    | RL { $$ = (Node_t *) new OperNode_t(NodeSymbol::rl, RL, {}); }
    | indexator { $$ = $1; }
    ;

exp_bracket:
    '(' exp ')' { $$ = $2; }
    ;

exp:
    exp_assign_left { $$ = $1; }
    | function_call { $$ = $1; }
    ;

exp_assign_left:
    exp_assign_right { $$ = $1; }
    | exp_assign_right ASGL exp_assign_right { $$ = (Node_t*) new SymNode_t(NodeSymbol::exp_assign_left, {$1, $3}); }
    ;

exp_assign_right:
    exp_compare { $$ = $1; }
    | exp_compare ASGR exp_compare { $$ = (Node_t*) new SymNode_t(NodeSymbol::exp_assign_right, {$1, $3}); }
    ;

exp_compare:
    exp_term { $$ = $1; }
    | exp_compare '<' exp_term { $$ = (Node_t*) new SymNode_t(NodeSymbol::lt, {$1, $3}); }
    | exp_compare '>' exp_term { $$ = (Node_t*) new SymNode_t(NodeSymbol::gt, {$1, $3}); }
    | exp_compare LE exp_term { $$ = (Node_t*) new SymNode_t(NodeSymbol::le, {$1, $3}); }
    | exp_compare GE exp_term { $$ = (Node_t*) new SymNode_t(NodeSymbol::ge, {$1, $3}); }
    | exp_compare '=' exp_term { $$ = (Node_t*) new SymNode_t(NodeSymbol::eq, {$1, $3}); }
    | exp_compare NEQ exp_term { $$ = (Node_t*) new SymNode_t(NodeSymbol::neq, {$1, $3}); }
    ;

exp_term:
    exp_factor { $$ = $1; }
    | exp_term '+' exp_factor { $$ = (Node_t*) new SymNode_t(NodeSymbol::plus, {$1, $3}); }
    | exp_term '-' exp_factor { $$ = (Node_t*) new SymNode_t(NodeSymbol::minus, {$1, $3}); }
    ;

exp_factor:
    exp_resatom { $$ = $1; }
    | exp_factor '*' exp_resatom { $$ = (Node_t*) new SymNode_t(NodeSymbol::mult, {$1, $3}); }
    | exp_factor '/' exp_resatom { $$ = (Node_t*) new SymNode_t(NodeSymbol::div, {$1, $3}); }
    ;

exp_resatom:
    exp_atom { $$ = $1; }
    | '-' exp_atom { $$ = (Node_t*) new SymNode_t(NodeSymbol::minus, {$2}); }
    | '+' exp_atom { $$ = (Node_t*) new SymNode_t(NodeSymbol::plus, {$2}); }
    ;

%%
void yyerror(const char *s) {
    fprintf(stderr, "%s\n", s);
}

bool compareFiles(const std::string& p1, const std::string& p2) {
  std::ifstream f1(p1, std::ifstream::binary|std::ifstream::ate);
  std::ifstream f2(p2, std::ifstream::binary|std::ifstream::ate);

  if (f1.fail() || f2.fail()) {
    std::cout << "Files wasn't found\n";
    return false; //file problem
  }

  //seek back to beginning and use std::equal to compare contents
  f1.seekg(0, std::ifstream::beg);
  f2.seekg(0, std::ifstream::beg);
  return std::equal(std::istreambuf_iterator<char>(f1.rdbuf()),
                    std::istreambuf_iterator<char>(),
                    std::istreambuf_iterator<char>(f2.rdbuf()));
}

int main(int argc, char *argv[]) {
    std::set<std::string> flags;
    std::string filename;

    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            std::string flag(argv[i]);
            flags.insert(flag);
        }
    }

#ifdef YYDEBUG
    if (flags.find("--debug") != flags.end())
    {
        yydebug = 1;
    }
#endif

    if (flags.find("--test") != flags.end())
    {
        std::cout << "Hello, from ZitzInterpreter!\n\nPlease, enter the number of test: ";
        std::string test_number;
        std::cin >> test_number;
        filename = "../Programs/ParserTest_" + test_number + ".ztz";
        interpreter.robot.Initialize(0);
        interpreter.SetOutFile("../Programs/ParserResult_" + test_number + ".txt");
        yyin = fopen(filename.c_str(), "r");
        yyparse();
        fclose(yyin);
        if (compareFiles("../Programs/ParserResult_" + test_number + ".txt", "../Programs/ParserResult_" + test_number + "_TEST.txt"))
        {
            std::cout << "Successful testing!\n";
        }
        else
        {
            std::cout << "Something went wrong.\n";
        }
    }
    else {
        std::cout << "Hello, from ZitzInterpreter!\n\nPlease, enter the name of program: ";
        std::string progName;
        std::cin >> progName;
        filename = "../Programs/" + progName + ".ztz";
        std::cout << "\nPrint the maze number or print 'NO': ";
        std::string map_number;
        std::cin >> map_number;
        if (map_number != "NO")
        {
            interpreter.robot.Initialize(std::stoi(map_number));
        }
        yyin = fopen(filename.c_str(), "r");
        yyparse();
        fclose(yyin);
    }
    return 0;
} 