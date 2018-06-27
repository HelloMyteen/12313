#include "game_unit.h"
<<<<<<< HEAD
=======
#include "cocos2d.h"
>>>>>>> origin/zhou

GameUnit * GameUnit::create(const std::string & filename)
{
	GameUnit* sprite = new GameUnit();
	if (sprite&&sprite->initWithFile(filename))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

GameUnit * GameUnit::createWithSpriteFrameName(const std::string & filename)
{
	GameUnit* sprite = new GameUnit();
	if (sprite&&sprite->initWithSpriteFrameName(filename))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

int GameUnit::getType()
{
	return type;
}

//cocos2d::Vec2 GameUnit::getVec()
//{
//	return position;
//}

std::string GameUnit::getName()
{
	return unit_name;
}

<<<<<<< HEAD
int GameUnit::getHealth()
=======
float GameUnit::getHealth()
>>>>>>> origin/zhou
{
	return health;
}

<<<<<<< HEAD
int GameUnit::getMaxHealth()
=======
float GameUnit::getMaxHealth()
>>>>>>> origin/zhou
{
	return max_health;
}

int GameUnit::getAttack()
{
	return attack;
}

int GameUnit::getAttackSpeed()
{
	return attack_speed;
}

int GameUnit::getDefend()
{
	return defend;
}

float GameUnit::getBuildTime()
{
	return build_time;
}

int GameUnit::getPrice()
{
	return price;
}

bool GameUnit::getDeathMes()
{
	return isUnitDead;
}

float GameUnit::getEffectRange()
{
	return effect_range;
}
//cocos2d::Sprite * GameUnit::getEffectRange()
//{
//	return effect_range;
//}

bool GameUnit::getIsMove()
{
	return isMove;
}

void GameUnit::setType(int t)
{
	type = t;
}

//void GameUnit::setVec(cocos2d::Vec2 pos)
//{
//	position = pos;
//}

<<<<<<< HEAD
void GameUnit::setHealth(int h)
=======
void GameUnit::setHealth(float h)
>>>>>>> origin/zhou
{
	health = h;
}

<<<<<<< HEAD
void GameUnit::setMaxHealth(int mh)
=======
void GameUnit::setMaxHealth(float mh)
>>>>>>> origin/zhou
{
	max_health = mh;
}

void GameUnit::setAttack(int att)
{
	attack = att;
}

void GameUnit::setAttackSpeed(int att_spe)
{
	attack_speed = att_spe;
}

void GameUnit::setDefend(int def)
{
	defend = def;
}

void GameUnit::setBuildTime(float bul_tim)
{
	build_time = bul_tim;
}

void GameUnit::setPrice(int pri)
{
	price = pri;
}

void GameUnit::setUnitDead()
{
	isUnitDead = true;
}

void GameUnit::setEffectRange(float range)
{
	effect_range = range;
}

//void GameUnit::setEffectRange(cocos2d::Sprite * range)
//{
//	effect_range = range;
//}

void GameUnit::setIsMove(bool is)
{
	isMove = is;
}
<<<<<<< HEAD
=======

cocos2d::Sprite * GameUnit::getblood()
{
	return blood;
}
cocos2d::Sprite * GameUnit::getbar()
{
	return bar;
}

void GameUnit::setblood(Sprite * _blood)
{
	blood = _blood;
}
void GameUnit::setbar(Sprite * _bar)
{
	bar = _bar;
}
>>>>>>> origin/zhou
