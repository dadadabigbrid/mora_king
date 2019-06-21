#include"define.h"
#include"login.h"
#include"menu.h"
#include"rank.h"

int main()
{
    if(!login())
        exit(1);
    Start();
    //start_game();
    /*HeroRank_get();
    display_heroRank();
    PlayerRank_get();
    display_playerRank();*/
    return 0;
}
