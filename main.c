#include"define.h"
#include"login.h"
#include"fun.h"
#include"menu.h"

int main()
{
    if(!login())
        exit(1);
    Start();
    return 0;
}
