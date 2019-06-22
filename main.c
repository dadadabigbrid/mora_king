#include"define.h"
#include"login.h"
#include"menu.h"
#include"rank.h"
#include"game.h"

int main()
{
    if(!login())
        exit(1);
    Start();
    //start_game();
    //login();
    return 0;
}
