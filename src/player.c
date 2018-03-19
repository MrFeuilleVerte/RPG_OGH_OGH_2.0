#include "matthieu.h"
#include "rpg.h"

void createPlayer(t_rpg *rpg, t_player *player) {

	player->x = (abs(rpg->par_w->w_size.x / 32) - 1) * 16;
	player->y = (abs(rpg->par_w->w_size.y / 32) - 1) * 16;
	player->animation = 0;

	player->pointeurAnim.left = 0;
	player->pointeurAnim.top = 0;
	player->pointeurAnim.width = 32;
	player->pointeurAnim.height = 32;

	player->sprite = Create_Sprite(PLAYERIDLETEXTURE);
}

void depPlayer(t_player *player) {

	if(sfKeyboard_isKeyPressed(sfKeyZ))
	{
		player->y -= 2;
		player->animation = 1;
	}
	if(sfKeyboard_isKeyPressed(sfKeyS))
	{
		player->y += 2;
		player->animation = 1;
	}
	if(sfKeyboard_isKeyPressed(sfKeyQ))
	{
		player->x -= 2;
		player->animation = 1;
	}
	if(sfKeyboard_isKeyPressed(sfKeyD))
	{
		player->x += 2;
		player->animation = 1;
	}
	if ((sfKeyboard_isKeyPressed(sfKeyZ) == 0) &&
		(sfKeyboard_isKeyPressed(sfKeyS) == 0) &&
	(sfKeyboard_isKeyPressed(sfKeyQ) == 0) &&
	(sfKeyboard_isKeyPressed(sfKeyD) == 0)) 
		player->animation = 0;
}

void playerf(t_rpg *rpg, t_player *player) {

	static int initPlayer = 0;
		int time = 0;

	if (initPlayer == 0)
	{
		createPlayer(rpg, player);
		initPlayer++;
	}

	depPlayer(player);

if (time != DELAY_ANIMATION)
{
	if (player->animation == 0)	
		SetTexture_Sprite(&player->sprite, PLAYERIDLETEXTURE);
	if (player->animation == 1)	{
		SetTexture_Sprite(&player->sprite, PLAYERRUNTEXTURE);
		player->pointeurAnim.left += 32;
		if (player->pointeurAnim.left >= 32*7)
		{
			player->pointeurAnim.left = 0;
		}
		++time;
	}
}
time = 0;
		sfSprite_setTextureRect(&player->sprite, player->pointeurAnim);
		Draw_Sprite(rpg, player->sprite, player->x, player->y);

}

