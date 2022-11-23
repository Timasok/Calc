#include <stdio.h>

#include "calc_f.h"

int main()
{
    Text_info text = {};
    
    textCtor(&text, "expression.input");

    printText(&text);

    printf("%s = %d\n", text.buf, getG(text.buf));

    textDtor(&text);

    return 0;
}