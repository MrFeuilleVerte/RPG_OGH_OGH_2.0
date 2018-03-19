/**
* @Author: vincent
* @Date:   2018-03-19T09:50:44+01:00
* @Filename: rpg.h
 * @Last modified by:   vincent
 * @Last modified time: 2018-03-19T11:16:53+01:00
*/

#ifndef RPG_H_
#define RPG_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/time.h>

#include <SFML/Graphics.h>

#define NB_TEXTURE 1024
#define GAME_NAME "RPG_OGH_OGH"
#define FRAME_RATE 30

typedef struct		s_parameter_window
{
    const sfVideoMode               *mode;
    sfRenderWindow                 	*window;
    sfVector2u	             	     w_size;
    sfEvent	                    	 event;
}			t_parameter_window;

typedef struct s_sprite
{
    sfSprite              *sprite;
    char                  *texture_name;
    sfTexture             *texture;
    sfVector2f            sprite_origin;
    sfVector2f            sprite_position;
    sfVector2f            sprite_scale;
}               t_sprite;

typedef struct  s_rpg
{
    t_parameter_window *par_w;

}               t_rpg;

#endif /* !RPG_G_ */
