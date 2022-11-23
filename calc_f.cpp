#include "assert.h"
#include "math.h"
#include "calc_f.h"

static const char * input;

int getG(const char *str)
{
    input = str;
    int val = getE();
    assert(*input == '\0');

    return val;
}

int getD()
{
    int val = getP();
    while (*input == '^')
    {
        int op = *input;
        input++;
        
        int val2 = getP();
        if (op == '^')
        {
            val = pow(val, val2);
        }
    }

    return val;

}

int getE()
{
    int val = getT();
    while (*input == '+' || *input == '-')
    {
        int op = *input;
        input++;
        int val2 = getT();

        if  (op == '+')
        {
            val +=val2;

        }else{

            val -=val2;
        }

    }

    return val;
}

int getT()
{
    int val = getD();
    while (*input == '*' || *input == '/')
    {
        int op = *input;
        input++;
        int val2 = getD();

        if  (op == '*')
        {
            val *=val2;

        }else{

            val /=val2;
        }

    }

    return val;

}

int getP()
{
    int val = 0;
    if (*input == '(')
    {
        input++;
        val = getE();
        assert(*input == ')');
        input++;
    }else
    {
        val = getN();
    }
    return val;
}

int getN()
{
    int val = 0;
    const char * s_old = input;

    if ('0' <= *input && *input <= '9')
    {
        val = val*10 + (*input - '0');
        input++;
    }
    assert(input != s_old);

    return val;

}