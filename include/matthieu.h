#ifndef MATTHIEU_H_
#define MATTHIEU_H_

#include "rpg.h"
#define PLAYERRUNTEXTURE "data/img/spriteRunHero_test.png"
#define PLAYERIDLETEXTURE "data/img/spriteIdleHero_test.png"

#define DELAY_ANIMATION 5

typedef struct s_player
{
	sfIntRect pointeurAnim;
	int animation;
	int dir;
	int x;
	int y;
	t_sprite sprite;

}t_player;

void playerf(t_rpg *rpg, t_player *player);

#endif /* !MATTHIEU_H_ */
