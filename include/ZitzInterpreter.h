#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <variant>
#include <vector>
#include <unordered_map>
#include <stack>
#include <array>
#include <list>
#include <initializer_list>
#include <limits.h>
#include <functional>
#include <cmath>
#include "json.hpp"

using json = nlohmann::json;

enum class NodeSymbol{
    number,
    literal,
    variable,
    indexator,
    ret,
    print,
    exp_assign_right,
    exp_assign_left,
    variable_init,
    field_init,
    function_call,
    function_call_args,
    function_define_variable,
    function_define_field,
    function_parameters,
    parameter_variable,
    parameter_field,
    check,
    until,
    statement_list,
    program,
    tiny,
    small,
    normal,
    big,
    field,
    sonar,
    go,
    compass,
    rr,
    rl,
    mult,
    div,
    plus,
    minus,
    lt,
    gt,
    le,
    ge,
    eq,
    neq
};

class Tools
{
public:
    static const char* NodeSymbolToString(NodeSymbol s)
    {
        switch (s)
        {
            case NodeSymbol::number: return "number";
            case NodeSymbol::literal: return "literal";
            case NodeSymbol::variable: return "variable";
            case NodeSymbol::indexator: return "indexator";
            case NodeSymbol::ret: return "ret";
            case NodeSymbol::print: return "print";
            case NodeSymbol::exp_assign_right: return "exp_assign_right";
            case NodeSymbol::exp_assign_left: return "exp_assign_left";
            case NodeSymbol::variable_init: return "variable_init";
            case NodeSymbol::field_init: return "field_init";
            case NodeSymbol::function_call: return "function_call";
            case NodeSymbol::function_call_args: return "function_call_args";
            case NodeSymbol::function_define_variable: return "function_define_variable";
            case NodeSymbol::function_define_field: return "function_define_field";
            case NodeSymbol::function_parameters: return "function_parameters";
            case NodeSymbol::parameter_variable: return "parameter_variable";
            case NodeSymbol::parameter_field: return "parameter_field";
            case NodeSymbol::check: return "check";
            case NodeSymbol::until: return "until";
            case NodeSymbol::statement_list: return "statement_list";
            case NodeSymbol::program: return "program";
            case NodeSymbol::tiny: return "tiny";
            case NodeSymbol::small: return "small";
            case NodeSymbol::normal: return "normal";
            case NodeSymbol::big: return "big";
            case NodeSymbol::field: return "field";
            case NodeSymbol::sonar: return "sonar";
            case NodeSymbol::go: return "go";
            case NodeSymbol::compass: return "compass";
            case NodeSymbol::rr: return "rr";
            case NodeSymbol::rl: return "rl";
            case NodeSymbol::mult: return "mult";
            case NodeSymbol::div: return "div";
            case NodeSymbol::plus: return "plus";
            case NodeSymbol::minus: return "minus";
            case NodeSymbol::lt: return "lt";
            case NodeSymbol::gt: return "gt";
            case NodeSymbol::le: return "le";
            case NodeSymbol::ge: return "ge";
            case NodeSymbol::eq: return "eq";
            case NodeSymbol::neq: return "neq";
        }
        return "error";
    }
};

class Node_t
{
public:
    std::vector<Node_t*> ch;
    std::string strValue;
    NodeSymbol symbol;

    Node_t() = default;
    ~Node_t() = default;

    friend std::ostream& operator<<(std::ostream& os, const Node_t& Node)
    {
        os << "<" << static_cast<int>(Node.symbol) << ">";
        return os;
    }
};

class SymNode_t : public Node_t
{
public:
    SymNode_t(NodeSymbol symbol, std::initializer_list<Node_t*> const &ch_list)
    {
        this->symbol = symbol;
        this->strValue = Tools::NodeSymbolToString(symbol);
        //std::cout << "<SymNode>";
        for (auto ch_e : ch_list)
        {
            this->ch.push_back(ch_e);
        }
    }
    ~SymNode_t() = default;

    friend std::ostream& operator<<(std::ostream& os, const SymNode_t& oNode)
    {
        os << "<" << Tools::NodeSymbolToString(oNode.symbol) << ">";
        return os;
    }
};

class ConNode_t : public Node_t
{
public:
    std::string value;

    ConNode_t(NodeSymbol symbol, std::string value) {
        //std::cout << "<ConNode=" << value << ">";
        this->symbol = symbol;
        this->strValue = Tools::NodeSymbolToString(symbol) + '=' + value;
        this->value = value;
    }
    ~ConNode_t() = default;

    friend std::ostream& operator<<(std::ostream& os, const ConNode_t& cNode)
    {
        os << "<" << Tools::NodeSymbolToString(cNode.symbol) << "=" << cNode.value << ">";
        return os;
    }
};

class IdNode_t : public Node_t
{
public:
    std::string index;

    IdNode_t(NodeSymbol symbol, std::string index) {
        //std::cout << "<IdNode=" << index << ">";
        this->symbol = symbol;
        this->strValue = Tools::NodeSymbolToString(symbol) + '=' + index;
        this->index = index;
    }
    ~IdNode_t() = default;

    friend std::ostream& operator<<(std::ostream& os, const IdNode_t& iNode)
    {
        os << "<" << Tools::NodeSymbolToString(iNode.symbol) << "=" << iNode.index << ">";
        return os;
    }
};

class OperNode_t : public Node_t
{
public:
    int oper;

    OperNode_t(NodeSymbol symbol, int oper, std::initializer_list<Node_t*> ch_list) 
    {
        //std::cout << "<OperNode>";
        this->symbol = symbol;
        this->oper = oper;
        for (Node_t *ch : ch_list)
        {
            this->ch.push_back(ch);
        }
    }
    ~OperNode_t() = default;

    friend std::ostream& operator<<(std::ostream& os, const OperNode_t& oNode)
    {
        os << "<" << static_cast<int>(oNode.symbol) << "=" << oNode.oper << ">";
        return os;
    }
};

class ZitzInterpreter
{
private:
    std::unordered_map<std::string, Node_t*> globalFuncTable;
    int errorCounter = 1;
    std::string statemenListCallCountName = "StatementListCallCount";
    bool isReturn = false;
    std::streambuf *buf = std::cout.rdbuf();
    std::ofstream of;
public:
    ZitzInterpreter() = default;
    ~ZitzInterpreter() = default;

    void SetOutFile(std::string name)
    {
        of.open(name);
        buf = of.rdbuf();
    }

    void InitFunc(Node_t *node)
    {
        std::string funcName;
        if (node->ch.size() == 4)
        {
            funcName = static_cast<IdNode_t*>(node->ch[1])->index;
        }
        else
        {
            funcName = static_cast<IdNode_t*>(node->ch[2])->index;
        }
        
        if (globalFuncTable.find(funcName) != this->globalFuncTable.end())
        {
            PrintError(funcName + " function already exists. Second initializtion is canceled.", node);
        }
        else
        {
            globalFuncTable[funcName] = node;
        }
    }

    void PrintFunction(std::string exp)
    {
        std::ostream out(buf);
        out << "PRINT: " << exp << '\n';
    }

    static void Print(Node_t *node, const std::vector<bool> &crossings)
    {
        for (int i = 0; i < static_cast<int>(crossings.size()) - 1; i++)
        {
            std::cout << (crossings[i] ? "|   " : "    ");
        }
        if (crossings.size() > 0)
        {
            std::cout << "+-> ";
        }
        if (node->symbol == NodeSymbol::number)
        {
            ConNode_t *node_ = static_cast<ConNode_t*>(node);
            std::cout << *node_ << '\n';
        }
        else if (node->symbol == NodeSymbol::variable)
        {
            IdNode_t *node_ = static_cast<IdNode_t*>(node);
            std::cout << *node_ << '\n';
        }
        else
        {
            SymNode_t *node_ = static_cast<SymNode_t*>(node);
            std::cout << *node_ << '\n';
        }
        for (int i = 0; i < node->ch.size(); i++)
        {
            std::vector<bool> childCrossings(crossings.begin(), crossings.end());
            childCrossings.push_back(i < node->ch.size() - 1);
            ZitzInterpreter::Print(node->ch[i], childCrossings);
        }
    }

    void PrintError(std::string message, Node_t *node)
    {
        std::cout << '[' << this->errorCounter++ << "] " << message  << " | (Position: " << node->strValue << ")" << '\n';
    }

    static int Convert32To10(std::string value, bool *isSigned)
    {
        int result = 0;
        int add = 0;
        int i;
        if (value[0] == '-' || value[0] == '+')
        {
            i = 1;
            *isSigned = true;
        }
        else
        {
            i = 0;
            *isSigned = false;
        }
        for (; i < value.length(); i++)
        {
            if (value[i] >= '0' && value[i] <= '9')
            {
                add = value[i] - '0';
            }
            else if (value[i] >= 'A' && value[i] <= 'V')
            {
                add = value[i] - 'A' + 10;
            }
            else
            {
                std::cout << "Unknown character in number!\n";
            }
            result = result * 32 + add;
        }

        if (value[0] == '-')
        {
            return -result;
        }
        else
        {
            return result;
        }
    }

    enum class VariableTypeName
    { 
        literal, 
        tiny, 
        small, 
        normal, 
        big, 
        field 
    };

    VariableTypeName DefineVariableTypeName(Node_t *node)
    {
        switch (node->symbol)
        {
            case NodeSymbol::tiny:
            {
                return VariableTypeName::tiny;
                break;
            }
            case NodeSymbol::small:
            {
                return VariableTypeName::small;
                break;
            }
            case NodeSymbol::normal:
            {
                return VariableTypeName::normal;
                break;
            }
            case NodeSymbol::big:
            {
                return VariableTypeName::big;
                break;
            }
            case NodeSymbol::field:
            {
                return VariableTypeName::field;
                break;
            }
            default:
            {
                std::cout << "Try to define unknown type\n";
                return VariableTypeName::big;
                break;
            }
        }
    }

    class Variable_t
    {
    public:
        Variable_t() = default;
        ~Variable_t() = default;

        VariableTypeName TypeName;
        bool isSigned;
        int value;

        static Variable_t *CreateLiteral(std::string number)
        {
            Variable_t *variable = new Variable_t();
            variable->TypeName = VariableTypeName::literal;
            int _value = Convert32To10(number, &variable->isSigned);
            variable->value = _value;
            return variable;
        }

        static Variable_t *CreateLiteral(int _value)
        {
            Variable_t *variable = new Variable_t();
                if (_value < 0)
                {
                    variable->isSigned = true;
                }
                else
                {
                    variable->isSigned = false;
                }
                variable->value = _value;
                variable->TypeName = VariableTypeName::literal;
                return variable;
        }

        static Variable_t *CreateVariable(VariableTypeName typeName, Variable_t *number)
        {
            Variable_t *variable = new Variable_t();
            variable->TypeName = typeName;
            variable->isSigned = number->isSigned;
            variable->SetValue(number->GetValue());
            return variable;
        }

        bool GetIsSigned()
        {
            return this->isSigned;
        }

        virtual int GetValue()
        {
            return this->value;
        }

        virtual void CopyVariable(Variable_t *_variable)
        {
            this->isSigned = _variable->isSigned;
            this->SetValue(_variable->value);
        }

        void SetValue(int _value)
        {
            switch (this->TypeName)
            {
                case VariableTypeName::literal:
                {
                    std::cout << "Attempt to assign literal\n";
                    break;
                }
                case VariableTypeName::tiny:
                {
                    if (_value >= 1)
                    {
                        this->value = 1;
                    }
                    else
                    {
                        this->value = 0;
                    }
                    break;
                }
                case VariableTypeName::small:
                {
                    if (this->isSigned)
                    {
                        if (_value >= 15)
                        {
                            this->value = 15;
                        }
                        else if (_value <= -16)
                        {
                            this->value = -16;
                        }
                        else
                        {
                            this->value = _value;
                        }
                    }
                    else
                    {
                        if (_value >= 31)
                        {
                            this->value = 31;
                        }
                        else if (_value <= 0)
                        {
                            this->value = 0;
                        }
                        else
                        {
                            this->value = _value;
                        }

                    }
                    break;
                }
                case VariableTypeName::normal:
                {
                    if (this->isSigned)
                    {
                        if (_value >= 511)
                        {
                            this->value = 511;
                        }
                        else if (_value <= -512)
                        {
                            this->value = -512;
                        }
                        else
                        {
                            this->value = _value;
                        }
                    }
                    else
                    {
                        if (_value >= 1023)
                        {
                            this->value = 1023;
                        }
                        else if (_value <= 0)
                        {
                            this->value = 0;
                        }
                        else
                        {
                            this->value = _value;
                        }

                    }
                    break;
                }
                case VariableTypeName::big:
                {
                    if (this->isSigned)
                    {
                        if (_value >= 16383)
                        {
                            this->value = 16383;
                        }
                        else if (_value <= -16384)
                        {
                            this->value = -16384;
                        }
                        else
                        {
                            this->value = _value;
                        }
                    }
                    else
                    {
                        if (_value >= 32767)
                        {
                            this->value = 32767;
                        }
                        else if (_value <= 0)
                        {
                            this->value = 0;
                        }
                        else
                        {
                            this->value = _value;
                        }
                    }
                    break;
                }
                default:
                {
                    std::cout << "Undefined for this type actions \n";
                    break;
                }
            }
        }

        static Variable_t *OpSum(Variable_t *var1, Variable_t *var2)
        {
            Variable_t *variable = new Variable_t();
            if (var1->isSigned || var2->isSigned)
            {
                variable->isSigned = true;
            }
            else
            {
                variable->isSigned = false;
            }
            variable->TypeName = VariableTypeName::literal;
            variable->value = var1->value + var2->value;
            return variable;
        }

        static Variable_t *OpSub(Variable_t *var1, Variable_t *var2)
        {
            Variable_t *variable = new Variable_t();
            if (var1->isSigned || var2->isSigned)
            {
                variable->isSigned = true;
            }
            else
            {
                variable->isSigned = false;
            }
            variable->TypeName = VariableTypeName::literal;
            variable->value = var1->value - var2->value;
            return variable;
        }

        static Variable_t *OpMult(Variable_t *var1, Variable_t *var2)
        {
            Variable_t *variable = new Variable_t();
            if (var1->isSigned || var2->isSigned)
            {
                variable->isSigned = true;
            }
            else
            {
                variable->isSigned = false;
            }
            variable->TypeName = VariableTypeName::literal;
            variable->value = var1->value * var2->value;
            return variable;
        }

        static Variable_t *OpDiv(Variable_t *var1, Variable_t *var2)
        {
            Variable_t *variable = new Variable_t();
            if (var1->isSigned || var2->isSigned)
            {
                variable->isSigned = true;
            }
            else
            {
                variable->isSigned = false;
            }
            variable->TypeName = VariableTypeName::literal;
            if (var2->value == 0)
            {
                variable->value = INT_MAX;
            }
            else
            {
                variable->value = var1->value / var2->value;
            }
            return variable;
        }

        static Variable_t *OpUPlus(Variable_t *var1)
        {
            Variable_t *variable = new Variable_t();
            variable->TypeName = VariableTypeName::literal;
            variable->isSigned = false;
            if (var1->value >= 0)
            {
                variable->value = var1->value;
            }
            else
            {
                variable->value = -var1->value;
            }
            return variable;
        }

        static Variable_t *OpUMinus(Variable_t *var1)
        {
            Variable_t *variable = new Variable_t();
            variable->TypeName = VariableTypeName::literal;
            variable->isSigned = true;
            variable->value = -var1->value;
            return variable;
        }

        static VariableTypeName DefineType(int number, bool isSigned)
        {
            if (!isSigned)
            {
                if (number == 0 || number == 1)
                {
                    return VariableTypeName::tiny;
                }
                else if (number <= 31)
                {
                    return VariableTypeName::small;
                }
                else if (number <= 1023)
                {
                    return VariableTypeName::normal;
                }
                else if (number <= 32767)
                {
                    return VariableTypeName::big;
                }
                else
                {
                    return VariableTypeName::literal;
                }
            }
            else
            {
                if (number >= -16 || number <= 15)
                {
                    return VariableTypeName::small;
                }
                else if (number >= -512 || number <= 511)
                {
                    return VariableTypeName::normal;
                }
                else if (number >= -16384 || number <= 16383)
                {
                    return VariableTypeName::big;
                }
                else
                {
                    return VariableTypeName::literal;
                }
            }
        }

        static VariableTypeName DefineType(Node_t node)
        {
            switch (node.symbol)
            {
                case NodeSymbol::tiny:
                {
                    return VariableTypeName::tiny;
                    break;
                }
                case NodeSymbol::small:
                {
                    return VariableTypeName::small;
                    break;
                }
                case NodeSymbol::normal:
                {
                    return VariableTypeName::normal;
                    break;
                }
                case NodeSymbol::big:
                {
                    return VariableTypeName::big;
                    break;
                }
                case NodeSymbol::field:
                {
                    return VariableTypeName::field;
                }
                default:
                {
                    std::cout << "Unknown variable type\n";
                    break;
                }
            }
        }

        static Variable_t *DefaultVariableTypeValue()
        {
            return CreateLiteral(0);
        }
    };

    class Field_t : public Variable_t
    { 
    public:
        VariableTypeName dimensionType;
        std::vector<std::vector<Variable_t*>> variables;
        int elementsCount;

        Field_t() = default;
        ~Field_t() = default;

        Variable_t *GetArrayVariable(int x, int y)
        {
            if (x < elementsCount && y < elementsCount && x >= 0 && y >= 0)
            {
                return variables[x][y]; // was [y][x]
            }
            else
            {
                return nullptr;
            }
        }

        static Field_t *CreateFieldVariable(VariableTypeName _typeName, VariableTypeName _dimensionType, Variable_t *number)
        {
            Field_t *fieldType = new Field_t();
            fieldType->TypeName = VariableTypeName::field;
            fieldType->dimensionType = _dimensionType;
            fieldType->elementsCount = DefineElementsCount(_dimensionType);
            fieldType->variables.resize(fieldType->elementsCount);
            for (int i = 0; i < fieldType->elementsCount; i++)
            {
                fieldType->variables[i].resize(fieldType->elementsCount);
                for (int j = 0; j < fieldType->elementsCount; j++)
                {
                    Variable_t *variableType = Variable_t::CreateVariable(_typeName, number);
                    fieldType->variables[i][j] = variableType;
                }
            }
            return fieldType;
        }

        static int DefineElementsCount(VariableTypeName _dimensionType)
        {
            int elementsCount = 0;
            switch (_dimensionType)
            {
                case VariableTypeName::tiny:
                {
                    elementsCount = 2;
                    break;
                }
                case VariableTypeName::small:
                {
                    elementsCount = 32;
                    break;
                }
                case VariableTypeName::normal:
                {
                    elementsCount = 1024;
                    break;
                }
                case VariableTypeName::big:
                {
                    elementsCount = 32768;
                    break;
                }
            }
            return elementsCount;
        }

        void CopyVariable(Variable_t *_variable) override
        {
            if (this->TypeName == VariableTypeName::field && _variable->TypeName == VariableTypeName::field)
            {
                Field_t *field = this;
                Field_t *_field = (Field_t*) _variable;
                for (int i = 0; i < field->elementsCount && i < _field->elementsCount; i++)
                {
                    for (int j = 0; j < field->elementsCount && j < _field->elementsCount; j++)
                    {
                        field->GetArrayVariable(i, j)->isSigned = _field->GetArrayVariable(i, j)->isSigned;
                        field->GetArrayVariable(i, j)->SetValue(_field->GetArrayVariable(i, j)->GetValue());
                    }
                }
            }
            else
            {
                std::cout << "Undefined for this type actions!\n";
            }
        }

        int GetValue() override
        {
            std::cout << "Undefined for this type actions!\n";
            return -1;
        }
    };

private:
    std::stack<std::unordered_map<std::string, Variable_t*>> functionStack;

public:
    Variable_t *Process(Node_t *node)
    {
        switch (node->symbol)
        {
            case NodeSymbol::number:
            {
                Variable_t *returnLiteral;
                ConNode_t *node_ = static_cast<ConNode_t*>(node);
                returnLiteral = Variable_t::CreateLiteral(node_->value);
                return returnLiteral;
                break;
            }
            case NodeSymbol::variable:
            {
                IdNode_t *node_ = static_cast<IdNode_t*>(node);
                Variable_t **variableType;
                if (this->functionStack.top().find(node_->index) != this->functionStack.top().end())
                {
                    variableType = &functionStack.top()[node_->index];
                    return *variableType;
                }
                else
                {
                    //Error
                    PrintError("Variable " + node_->index + " is undefined", node_);
                    return Variable_t::DefaultVariableTypeValue();
                }
                break;
            }
            case NodeSymbol::indexator:
            {
                Variable_t *variableType = Process(node->ch[0]);
                if (variableType->TypeName == VariableTypeName::field)
                {
                    Field_t *fieldType = static_cast<Field_t*>(variableType);
                    Variable_t *var = fieldType->GetArrayVariable(Process(node->ch[1])->GetValue(), Process(node->ch[2])->GetValue());
                    if (var != nullptr)
                    {
                        return var;
                    }
                    else
                    {
                        PrintError("Indexes is not correct", node->ch[0]);
                        return Variable_t::DefaultVariableTypeValue();
                    }
                }
                else
                {
                    PrintError("Variable " + static_cast<IdNode_t*>(node->ch[0])->index + " is not support indexator", node->ch[0]);
                    return Variable_t::DefaultVariableTypeValue();
                }
                break;
            }
            case NodeSymbol::ret:
            {
                Variable_t **exp;
                exp = &functionStack.top()["return"];
                (*exp)->CopyVariable(Process(node->ch[0]));
                isReturn = true;
                break;
            }
            case NodeSymbol::print:
            {
                Variable_t *exp = Process(node->ch[0]);
                if (exp != nullptr)
                {
                    PrintFunction(std::to_string(exp->GetValue()));
                }
                else
                {
                    PrintFunction("Expression can't be processed!");
                }
                return nullptr;
                break;
            }
            case NodeSymbol::exp_assign_right:
            {
                if (node->ch[1]->symbol == NodeSymbol::indexator)
                {
                    Variable_t **variableType;
                    std::string varName = static_cast<IdNode_t*>(node->ch[1]->ch[0])->index;
                    if (functionStack.top().find(varName) != functionStack.top().end())
                    {
                        variableType = &functionStack.top()[varName];
                        *variableType = Process(node->ch[1]);
                        (*variableType)->SetValue(Process(node->ch[0])->GetValue());
                        return *variableType;
                    }
                    else
                    {
                        PrintError("Variable " + static_cast<IdNode_t*>(node->ch[1]->ch[0])->index + " is undefined", node->ch[1]->ch[0]);
                        return Variable_t::DefaultVariableTypeValue();
                    }
                }
                else
                {
                    Variable_t **variableType;
                    std::string varName = static_cast<IdNode_t*>(node->ch[1])->index;
                    if (functionStack.top().find(varName) != functionStack.top().end())
                    {
                        variableType = &functionStack.top()[varName];
                        (*variableType)->CopyVariable(Process(node->ch[0]));
                        return *variableType;
                    }
                    else
                    {
                        PrintError("Variable " + static_cast<IdNode_t*>(node->ch[1])->index + " is undefined", node->ch[1]);
                        return Variable_t::DefaultVariableTypeValue();
                    }
                }
                break;
            }
            case NodeSymbol::exp_assign_left:
            {
                if (node->ch[0]->symbol == NodeSymbol::indexator)
                {
                    Variable_t *variableType;
                    std::string varName = static_cast<IdNode_t*>(node->ch[0]->ch[0])->index;
                    if (functionStack.top().find(varName) != functionStack.top().end())
                    {
                        variableType = Process(node->ch[0]);
                        variableType->SetValue(Process(node->ch[1])->GetValue());
                        return variableType;
                    }
                    else
                    {
                        PrintError("Variable " + static_cast<IdNode_t*>(node->ch[0]->ch[0])->index + " is undefined", node->ch[0]->ch[0]);
                        return Variable_t::DefaultVariableTypeValue();
                    }
                }
                else
                {
                    Variable_t **variableType;
                    std::string varName = static_cast<IdNode_t*>(node->ch[0])->index;
                    if (functionStack.top().find(varName) != functionStack.top().end())
                    {
                        variableType = &functionStack.top()[varName];
                        Field_t *test = static_cast<Field_t*>(Process(node->ch[1]));
                        (*variableType)->CopyVariable(static_cast<Variable_t*>(test));
                        return *variableType;
                    }
                    else
                    {
                        PrintError("Variable " + static_cast<IdNode_t*>(node->ch[0])->index + " is undefined", node->ch[0]);
                        return Variable_t::DefaultVariableTypeValue();
                    }
                }
                break;
            }
            case NodeSymbol::variable_init:
            {
                Variable_t *exp = Process(node->ch[node->ch.size() - 1]);
                for (int i = 1; i < node->ch.size() - 1; i++)
                {
                    Variable_t *variableType = Variable_t::CreateVariable(DefineVariableTypeName(node->ch[0]), exp);
                    std::string varName = static_cast<IdNode_t*>(node->ch[i])->index;

                    if (functionStack.top().find(varName) != functionStack.top().end())
                    {
                        //Error
                        PrintError(varName + " variable already exists. Second initialization is canceled", node->ch[i]);
                        return Variable_t::DefaultVariableTypeValue();
                    }
                    else
                    {
                        functionStack.top()[varName] = variableType;
                    }
                }
                return exp;
                break;
            }
            case NodeSymbol::field_init:
            {
                Variable_t *exp = Process(node->ch[node->ch.size() - 1]);
                for (int i = 2; i < node->ch.size() - 1; i++)
                {
                    Field_t *fieldType = Field_t::CreateFieldVariable(DefineVariableTypeName(node->ch[0]), 
                                                                      DefineVariableTypeName(node->ch[1]),
                                                                      exp);
                    std::string varName = static_cast<IdNode_t*>(node->ch[i])->index;

                    if (functionStack.top().find(varName) != functionStack.top().end())
                    {
                        //Error
                        PrintError(varName + " variable already exists. Second initialization is canceled", node->ch[i]);
                        return Variable_t::DefaultVariableTypeValue();
                    }
                    else
                    {
                        functionStack.top()[varName] = fieldType;
                    }
                }
                return exp;
                break;
            }
            case NodeSymbol::function_call:
            {
                IdNode_t *func = static_cast<IdNode_t*>(node->ch[0]);
                if (this->globalFuncTable.find(func->index) != this->globalFuncTable.end())
                {
                    Process(node->ch[1]);
                    return Process(globalFuncTable[func->index]);
                }
                else
                {
                    PrintError(func->index + " is undefined function", node);
                    return Variable_t::DefaultVariableTypeValue();
                }
                break;
            }
            case NodeSymbol::function_call_args:
            {
                std::unordered_map<std::string, Variable_t*> hash_t;
                for (int i = 0; i < node->ch.size(); i++)
                {
                    hash_t[std::to_string(i)] = Process(node->ch[i]);
                }
                functionStack.push(hash_t);
                return nullptr;
                break;
            }
            case NodeSymbol::function_define_variable:
            {
                Variable_t *returnVariable = Variable_t::CreateVariable(DefineVariableTypeName(node->ch[0]), Variable_t::CreateLiteral("0"));
                functionStack.top()["return"] = returnVariable;
                Variable_t *statementListCallCount = Variable_t::CreateVariable(VariableTypeName::big, Variable_t::CreateLiteral("0"));
                functionStack.top()[statemenListCallCountName] = statementListCallCount;

                Process(node->ch[2]);
                Process(node->ch[3]);

                returnVariable = functionStack.top()["return"];
                functionStack.pop();
                return returnVariable;
                break;
            }
            case NodeSymbol::function_define_field:
            {
                Variable_t *returnVariable = Field_t::CreateFieldVariable(DefineVariableTypeName(node->ch[0]),
                                                                          DefineVariableTypeName(node->ch[1]),
                                                                          Variable_t::CreateLiteral("0"));
                functionStack.top()["return"] = returnVariable;
                Variable_t *statementListCallCount = Variable_t::CreateVariable(VariableTypeName::big, Variable_t::CreateLiteral("0"));
                functionStack.top()[statemenListCallCountName] = statementListCallCount;

                Process(node->ch[3]);
                Process(node->ch[4]);

                returnVariable = functionStack.top()["return"];
                functionStack.pop();
                return returnVariable;
                break;
            }
            case NodeSymbol::parameter_variable:
            {
                Variable_t *variableType = Variable_t::CreateVariable(DefineVariableTypeName(node->ch[0]), Variable_t::CreateLiteral("0"));
                std::string varName = static_cast<IdNode_t*>(node->ch[1])->index;

                if (functionStack.top().find(varName) != functionStack.top().end())
                {
                    //Error
                    PrintError(varName + " parameter already exists. Second initialization is canceled", node->ch[1]);
                    return Variable_t::DefaultVariableTypeValue();
                }
                else
                {
                    functionStack.top()[varName] = variableType;
                }
                return nullptr;
                break;
            }
            case NodeSymbol::parameter_field:
            {
                Field_t *fieldType = Field_t::CreateFieldVariable(DefineVariableTypeName(node->ch[0]), 
                                                                    DefineVariableTypeName(node->ch[1]),
                                                                    Variable_t::CreateLiteral("0"));
                std::string varName = static_cast<IdNode_t*>(node->ch[2])->index;

                if (functionStack.top().find(varName) != functionStack.top().end())
                {
                    //Error
                    PrintError(varName + " parameter already exists. Second initialization is canceled", node->ch[2]);
                    return Variable_t::DefaultVariableTypeValue();
                }
                else
                {
                    functionStack.top()[varName] = fieldType;
                }
                return nullptr;
                break;
            }
            case NodeSymbol::function_parameters:
            {
                Variable_t *variableType;
                Variable_t *stackVar;
                for (int i = 0; i < node->ch.size(); i++)
                {
                    Process(node->ch[i]);
                }
                std::unordered_map<std::string, Variable_t*> varTable = functionStack.top();
                for (int i = 0; i < node->ch.size(); i++)
                {
                    if (node->ch[i]->symbol == NodeSymbol::parameter_variable)
                    {
                        variableType = varTable[static_cast<IdNode_t*>(node->ch[i]->ch[1])->index];
                    }
                    else
                    {
                        variableType = varTable[static_cast<IdNode_t*>(node->ch[i]->ch[2])->index];
                    }

                    if (varTable.find(std::to_string(i)) != varTable.end())
                    {
                        stackVar = varTable[std::to_string(i)];
                        variableType->CopyVariable(stackVar);
                        varTable.erase(std::to_string(i));
                    }
                }
                functionStack.top() = varTable;
                int parametersCount = node->ch.size();
                while (varTable.find(std::to_string(parametersCount)) != varTable.end())
                {
                    variableType = varTable[std::to_string(parametersCount)];
                    varTable.erase(std::to_string(parametersCount));
                    parametersCount++;
                    PrintError("Odd argument in function call: " + std::to_string(variableType->GetValue()), node);
                }
                return nullptr;
                break;
            }
            case NodeSymbol::check:
            {
                Variable_t *cond = Process(node->ch[0]);
                if (cond->GetValue() != 0)
                {
                    Process(node->ch[1]);
                }
                return nullptr;
                break;
            }
            case NodeSymbol::until:
            {
                while (Variable_t::CreateVariable(VariableTypeName::tiny, Process(node->ch[0]))->GetValue() != 0)
                {
                    Process(node->ch[1]);
                }
                return nullptr;
                break;
            }
            case NodeSymbol::statement_list:
            {
                Variable_t **statementListCallCount;
                statementListCallCount = &functionStack.top()[statemenListCallCountName];
                (*statementListCallCount)->SetValue((*statementListCallCount)->GetValue() + 1);
                for (int i = 0; i < node->ch.size(); i++)
                {
                    Variable_t *value = Process(node->ch[i]);
                    if (isReturn)
                    {
                        (*statementListCallCount)->SetValue((*statementListCallCount)->GetValue() - 1);
                        if ((*statementListCallCount)->GetValue() == 0)
                        {
                            isReturn = false;
                        }
                        return value;
                    }
                }
                (*statementListCallCount)->SetValue((*statementListCallCount)->GetValue() - 1);
                return nullptr;
                break;
            }
            case NodeSymbol::program:
            {
                for (int i = 0; i < node->ch.size(); i++)
                {
                    InitFunc(node->ch[i]);
                }
                auto funcNode = globalFuncTable.find("main");
                if (funcNode != globalFuncTable.end())
                {
                    Node_t *funcNode = globalFuncTable["main"];
                    std::unordered_map<std::string, Variable_t*> hash_t;
                    functionStack.push(hash_t);
                    Variable_t *t = Process(funcNode);
                    return t;
                }
                else
                {
                    PrintError("Main function is not found", node);
                    return nullptr;
                }
                break;
            }
            case NodeSymbol::go:
            {
                return robot.RobotGo();
                break;
            }
            case NodeSymbol::rr:
            {
                return robot.RobotRR();
                break;
            }
            case NodeSymbol::rl:
            {
                return robot.RobotRL();
                break;
            }
            case NodeSymbol::compass:
            {
                return robot.RobotCompass();
                break;
            }
            case NodeSymbol::sonar:
            {
                return robot.RobotSonar();
                break;
            }
            case NodeSymbol::mult:
            {
                return Variable_t::OpMult(Process(node->ch[0]), Process(node->ch[1]));
                break;
            }
            case NodeSymbol::div:
            {
                return Variable_t::OpDiv(Process(node->ch[0]), Process(node->ch[1]));
                break;
            }
            case NodeSymbol::plus:
            {
                if (node->ch.size() == 1)
                {
                    return Variable_t::OpUPlus(Process(node->ch[0]));
                }
                else
                {
                    return Variable_t::OpSum(Process(node->ch[0]), Process(node->ch[1]));
                }
                break;
            }
            case NodeSymbol::minus:
            {
                if (node->ch.size() == 1)
                {
                    return Variable_t::OpUMinus(Process(node->ch[0]));
                }
                else
                {
                    return Variable_t::OpSub(Process(node->ch[0]), Process(node->ch[1]));
                }
                break;
            }
            case NodeSymbol::lt:
            {
                if (Process(node->ch[0])->GetValue() < Process(node->ch[1])->GetValue())
                {
                    return Variable_t::CreateLiteral(1);
                }
                else
                {
                    return Variable_t::CreateLiteral(0);
                }
                break;
            }
            case NodeSymbol::gt:
            {
                if (Process(node->ch[0])->GetValue() > Process(node->ch[1])->GetValue())
                {
                    return Variable_t::CreateLiteral(1);
                }
                else
                {
                    return Variable_t::CreateLiteral(0);
                }
                break;
            }
            case NodeSymbol::le:
            {
                if (Process(node->ch[0])->GetValue() <= Process(node->ch[1])->GetValue())
                {
                    return Variable_t::CreateLiteral(1);
                }
                else
                {
                    return Variable_t::CreateLiteral(0);
                }
                break;
            }
            case NodeSymbol::ge:
            {
                if (Process(node->ch[0])->GetValue() >= Process(node->ch[1])->GetValue())
                {
                    return Variable_t::CreateLiteral(1);
                }
                else
                {
                    return Variable_t::CreateLiteral(0);
                }
                break;
            }
            case NodeSymbol::eq:
            {
                if (Process(node->ch[0])->GetValue() == Process(node->ch[1])->GetValue())
                {
                    return Variable_t::CreateLiteral(1);
                }
                else
                {
                    return Variable_t::CreateLiteral(0);
                }
                break;
            }
            case NodeSymbol::neq:
            {
                if (Process(node->ch[0])->GetValue() != Process(node->ch[1])->GetValue())
                {
                    return Variable_t::CreateLiteral(1);
                }
                else
                {
                    return Variable_t::CreateLiteral(0);
                }
                break;
            }
            default:
            {
                std::cout << "\n\nUnknown character!\n";
                break;
            }
        }
        return Variable_t::DefaultVariableTypeValue();
    }

    class Robot
    {
    public:
        int mapNumber = 0;
        std::string filesPath = "../Maps/";
        std::string mapName = "_map.json";
        std::string robotName = "_robot.json";
        std::ofstream commands;

        enum class Cell_t { empty, wall, exit };

        struct Vector2
        {
        public:
            int x;
            int y;

            Vector2() = default;
            Vector2(int _x, int _y)
            {
                x = _x;
                y = _y;
            }

            bool operator==(const Vector2& v) const
            {
                return x == v.x && y == v.y;
            }

            operator std::string() { return "(" + std::to_string(x) + " " + std::to_string(y) + ")"; }
        };

        class MyHashFunc
        {
        public:
            size_t operator()(const Vector2& v) const
            {
                return (std::hash<int>()(v.x) ^ std::hash<int>()(v.y)); 
            }
        };

        std::unordered_map<Vector2, Cell_t, MyHashFunc> rmap;
        Vector2 exitCell;

        Vector2 RobotPos;
        Vector2 GetRobotPos() const { return RobotPos; }
        void SetRobotPos(Vector2 RobotPos_) { RobotPos = RobotPos_; sonarCallCount = 0; previousSonarBits = 0; }

        int RobotRot;
        int GetRobotRot() const { return RobotRot; }
        void SetRobotRot(int RobotRot_) { RobotRot = RobotRot_; sonarCallCount = 0; previousSonarBits = 0; }

        int sonarCallCount = 0;
        int previousSonarBits = 0;
        bool isInitialize = false;

        class Cell
        {
        public:
            int X;
            int Y;
            Cell_t CellType;

            Cell(json j_)
            {
                X = j_["X"];
                Y = j_["Y"];
                CellType = j_["CellType"];
            }
        };

        void Initialize(int _mapNumber)
        {
            mapNumber = _mapNumber;
            std::ifstream s_in;
            s_in.open(filesPath + std::to_string(mapNumber) + mapName, std::ios::in);
            if (!s_in.is_open())
            {
                std::cout << "Map file wasn't opened.\n";
            }
            json j;
            s_in >> j;
            s_in.close();

            std::list<Cell> cells;
            for (auto& element: j)
            {
                cells.push_back(element);
            }
            rmap = std::unordered_map<Vector2, Cell_t, MyHashFunc>();
            for(auto c: cells)
            {
                if (c.CellType == Cell_t::exit)
                {
                    exitCell = Vector2(c.X, c.Y);
                }
                rmap[Vector2(c.X, c.Y)] = c.CellType;
            }
            s_in.open(filesPath + std::to_string(mapNumber) + robotName);
            json j_obj;
            s_in >> j_obj;
            s_in.close();
            Vector2 pos(0, 0);
            pos.x = j_obj["X"];
            pos.y = j_obj["Y"];
            SetRobotPos(pos);
            RobotRot = j_obj["Rotation"];

            commands = std::ofstream { filesPath + std::to_string(mapNumber) + "_commands.txt" };
            isInitialize = true;
        }

        Variable_t *RobotRR()
        {
            if (isInitialize)
            {
                SetRobotRot((RobotRot + 1) % 6);
                commands << "r";
                return Variable_t::CreateLiteral(1);
            }
            else
            {
                return Variable_t::CreateLiteral(0);
            }
        }

        Variable_t *RobotRL()
        {
            if (isInitialize)
            {
                SetRobotRot((RobotRot + 5) % 6);
                commands << "l";
                return Variable_t::CreateLiteral(1);
            }
            else
            {
                return Variable_t::CreateLiteral(0);
            }
        }

        Variable_t *RobotGo()
        {
            if (isInitialize)
            {
                Vector2 new_pos = MapDisplacement(RobotPos, RobotRot);
                switch (GetCellTypeOnNextStep(RobotPos, RobotRot))
                {
                case Cell_t::empty:
                {
                    SetRobotPos(new_pos);
                    commands << "g";
                    return Variable_t::CreateLiteral(1);
                    break;
                }
                case Cell_t::exit:
                {
                    SetRobotPos(new_pos);
                    commands << "g";
                    std::cout << "Congratulations! Robot reach the exit!\n";
                    exit(0);
                    return Variable_t::CreateLiteral(1);
                    break;
                }
                case Cell_t::wall:
                {
                    return Variable_t::CreateLiteral(0);
                    break;
                }
                default:
                    return Variable_t::CreateLiteral(INT_MIN);
                    break;
                }
            }
            else
            {
                return Variable_t::CreateLiteral(0);
            }
        }

        Cell_t GetCellTypeInDirectionStep(Vector2 position, int directon, int stepCount)
        {
            for(int i = 0; i <= stepCount ; i++)
            {
                position = MapDisplacement(position, directon);
            }
            if (rmap.find(position) != rmap.end())
            {
                return rmap[position];
            }
            else
            {
                return Cell_t::wall;
            }
        }

        Variable_t *RobotSonar()
        {
            // Bitmap: forward = 0, lf = 1, rf = 2, lb = 3, rb = 4
            if (isInitialize)
            {
                int sonarBits = 0;
                if (previousSonarBits % 2 == 1 || GetCellTypeInDirectionStep(RobotPos, RobotRot, sonarCallCount) == Cell_t::wall)
                {
                    sonarBits = 1;
                }
                if (((previousSonarBits >> 1) % 2 ) == 1 || GetCellTypeInDirectionStep(RobotPos, (RobotRot + 5) % 6, sonarCallCount) == Cell_t::wall)
                {
                    sonarBits += 2;
                }
                if (((previousSonarBits >> 2) % 2) == 1 || GetCellTypeInDirectionStep(RobotPos, (RobotRot + 1) % 6, sonarCallCount) == Cell_t::wall)
                {
                    sonarBits += 4;
                }
                if (((previousSonarBits >> 3) % 2) == 1 || GetCellTypeInDirectionStep(RobotPos, (RobotRot + 4) % 6, sonarCallCount) == Cell_t::wall)
                {
                    sonarBits += 8;
                }
                if (((previousSonarBits >> 4) % 2) == 1 || GetCellTypeInDirectionStep(RobotPos, (RobotRot + 2) % 6, sonarCallCount) == Cell_t::wall)
                {
                    sonarBits += 16;
                }
                previousSonarBits = sonarBits;
                return Variable_t::CreateLiteral(sonarBits);
            }
            else
            {
                previousSonarBits = 0;
                return Variable_t::CreateLiteral(0);
            }

        }

        Variable_t *RobotCompass()
        {
            if (isInitialize)
            {
                Vector2 dirToExit;
                dirToExit.x = exitCell.x - RobotPos.x;
                dirToExit.y = exitCell.y - RobotPos.y;

                float xCoord = (float)((exitCell.x - RobotPos.x) * cos(30 * M_PI * 2 / 360));
                float yCoord = (float)((exitCell.y + exitCell.x * 0.495f) - (RobotPos.y + RobotPos.x * 0.495f));

                xCoord = (float) (xCoord / (sqrt(xCoord * xCoord + yCoord * yCoord)));
                yCoord = (float)(yCoord / (sqrt(xCoord * xCoord + yCoord * yCoord)));
                float angle = 0;
                float atg = (float) (atan2(yCoord, xCoord) * 360 / (M_PI * 2));

                if (xCoord == 0)
                {
                    if (yCoord == 1)
                    {
                        angle = 90.f;
                    }
                    else if (yCoord == -1)
                    {
                        angle = 270.f;
                    }
                }
                else
                {
                    if (yCoord > 0)
                    {
                        angle = atg;
                    }
                    else
                    {
                        angle = atg + 360.f;
                    }
                }
                return Variable_t::CreateLiteral((int)(angle * 60));
            }
            else
            {
                return Variable_t::CreateLiteral(0);
            }

        }


        static Vector2 MapDisplacement(Vector2 position, int direction)
        {
            Vector2 disp(0, 0);

            if (direction == 0)
            {
                disp.y = position.y + 1;
                disp.x = position.x;
            }
            else if (direction == 1)
            {
                disp.y = position.y;
                disp.x = position.x + 1;
            }
            else if (direction == 2)
            {
                disp.y = position.y - 1;
                disp.x = position.x + 1;
            }
            else if (direction == 3)
            {
                disp.y = position.y - 1;
                disp.x = position.x;
            }
            else if (direction == 4)
            {
                disp.y = position.y;
                disp.x = position.x - 1;
            }
            else if (direction == 5)
            {
                disp.y = position.y + 1;
                disp.x = position.x - 1;
            }
            return disp;
        }

        Cell_t GetCellTypeOnNextStep(Vector2 curPos, int rot)
        {
            Vector2 pos = MapDisplacement(curPos, rot);
            Cell_t cellType;
            if (rmap.find(pos) != rmap.end())
            {
                return rmap[pos];
            }
            else
            {
                return Cell_t::wall;
            }
        }
        
    };

    Robot robot = Robot();
};


