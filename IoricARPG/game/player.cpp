#include "player.h"

void Player::Update( float dt )
{
	pos += (vel * dt);
}