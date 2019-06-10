#include <stdio.h>
#include <stdlib.h>
#include"define.h"

int main()
{
    int i;
    HERO *h;
    h = (HERO*)malloc(sizeof(HERO)*15);
    Hero_get(h);
    for(i = 0;i < 15;i++)
    {
        printf("%s\t¼ôµ¶%d\tÊ¯Í·%d\n",h[i].name,h[i].skills[0],h[i].skills[1]);
    }
    return 0;
}
