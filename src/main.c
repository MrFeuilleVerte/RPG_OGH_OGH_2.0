/**
* @Author: vincent
* @Date:   2018-03-19T09:50:38+01:00
* @Filename: main.c
 * @Last modified by:   vincent
 * @Last modified time: 2018-03-19T11:56:04+01:00
*/

#include "rpg.h"
#include "matthieu.h"

void freeStructs(t_rpg *rpg)
{
    free(rpg);
}

t_rpg *init_struct()
{
    t_rpg * rpg;

    rpg = malloc(sizeof(t_rpg));
    rpg->par_w = malloc(sizeof(t_parameter_window));

    rpg->par_w->w_size.x = 1280;
    rpg->par_w->w_size.y = 720;

    return (rpg);
}

void create_window(t_rpg *rpg)
{
    sfVideoMode mode = {rpg->par_w->w_size.x, rpg->par_w->w_size.y, 32};
    rpg->par_w->w_size.x = 1280;

    rpg->par_w->w_size.y = 720;
    rpg->par_w->window = sfRenderWindow_create(mode , GAME_NAME, sfTitlebar | sfClose , NULL);
    sfRenderWindow_setFramerateLimit(rpg->par_w->window, FRAME_RATE);
    sfRenderWindow_clear(rpg->par_w->window, sfBlack);
}

int main(int argc, char **argv)
{
    t_rpg *rpg = init_struct();
    t_player *player;
    player = malloc(sizeof(t_player));

    create_window(rpg);


    while (1)
    {

        if (sfRenderWindow_pollEvent(rpg->par_w->window, &rpg->par_w->event))
        if (rpg->par_w->event.type == sfEvtClosed)
        {            sfRenderWindow_close(rpg->par_w->window);
            return (0);
        }
        
        sfRenderWindow_clear(rpg->par_w->window,sfBlack);
        playerf(rpg, player);
        sfRenderWindow_display(rpg->par_w->window);
    }
return (0);
}
