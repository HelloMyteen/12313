#include "Building.h"
#include "order.h"


class Building;

extern Message message;

Building* Building::create(const std::string & filename)
{
	Building *building = new Building();
	if (building&&building->initWithFile(filename))
	{
		building->autorelease();
		cocos2d::Vec2 born_position(-1000, -1000);
		building->setPosition(born_position);
		return building;
	}
	CC_SAFE_DELETE(building);
	return nullptr;
}

Building* Building::createWithSpriteFrameName(const std::string & filename)
{
	Building *building = new Building();
	if (building&&building->initWithSpriteFrameName(filename))
	{
		building->autorelease();
		return building;
	}
	CC_SAFE_DELETE(building);
	return nullptr;
}


void Building::_isattacked(Moveable* target)
{
	this->setHealth(this->getHealth() - target->getAttack() - this->getDefend());
<<<<<<< HEAD
=======
	this->getblood()->setScaleX(this->getHealth()/this->getMaxHealth());
>>>>>>> origin/zhou
	if (getHealth() <= 0)
	{
		EraseBuilding();
		cocos2d::log("the unit is destroyed!");
	}
	auto fire_animation = cocos2d::Animation::create();
	for (int i = 1; i <= 4; ++i)
	{
		cocos2d::log("nullptr!!!");
		cocos2d::__String * frameName = cocos2d::__String::createWithFormat("soldierfireright%d.png", i);
		//cocos2d::SpriteFrame * spriteFrame = cocos2d::SpriteFrameCache::getInstance()->getSpriteFrameByName(frameName->getCString());
		fire_animation->addSpriteFrameWithFile(frameName->getCString());
	}
	fire_animation->setDelayPerUnit(0.15f);
	fire_animation->setRestoreOriginalFrame(true);
	fire_animation->setLoops(1);
	auto action = cocos2d::Animate::create(fire_animation);
	message.getTargetOne()->runAction(action);
}

<<<<<<< HEAD
bool Building::_canattack(Moveable * target)
{

	if (!target->getAttackable())
	{
		//auto toast = Toast::create("正在擦枪！！无法攻击", 25, 1);
		//message._mapscene->addChild(toast);

		return false;
	}
	float distance = this->getPosition().distance(target->getPosition());
	if (distance > this->getEffectRange())
	{
		//auto toast = Toast::create("too far away!!", 25, 1);
		//message._mapscene->addChild(toast);
		return false;
	}

	return true;
}

=======
>>>>>>> origin/zhou

void Building::EraseBuilding()
{
	auto boom_animation = cocos2d::Animation::create();
	for (int i = 1; i <= 4; ++i)
	{

		cocos2d::__String * frameName = cocos2d::__String::createWithFormat("boom%d.png", i);
		cocos2d::log("framename %s ",frameName->getCString());
		//cocos2d::SpriteFrame * spriteFrame = cocos2d::SpriteFrameCache::getInstance()->getSpriteFrameByName(frameName->getCString());
		boom_animation->addSpriteFrameWithFile(frameName->getCString());
	}
	boom_animation->setDelayPerUnit(0.15f);
	boom_animation->setRestoreOriginalFrame(true);
	boom_animation->setLoops(1);
	auto action = cocos2d::Animate::create(boom_animation);
	this->runAction(action);

	auto callFunc = cocos2d::CallFuncN::create(CC_CALLBACK_0(Building::boomlisten, this));
	auto sequence = cocos2d::Sequence::create(action, callFunc, NULL);
	this->runAction(sequence);
<<<<<<< HEAD
=======
	
>>>>>>> origin/zhou
}

void Building::boomlisten()
{
	this->stopAllActions();
	this->setType(0);
	this->setIsMove(true);
	this->setPosition(-1000, -1000);
}


void Building::initBuilding(const cocos2d::Vec2 pos, int type)
{

	//注册监听器
	cocos2d::EventDispatcher * _eventDispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
	buildinglistener = cocos2d::EventListenerTouchOneByOne::create();
	buildinglistener->setSwallowTouches(true);
	buildinglistener->onTouchBegan = [this](cocos2d::Touch* touch, cocos2d::Event* event)
	{
		auto target = static_cast<Sprite*>(event->getCurrentTarget());//获取的当前触摸的目标

		cocos2d::Point locationInNode = target->convertToNodeSpace(touch->getLocation());
		cocos2d::Size s = target->getContentSize();
		cocos2d::Rect rect = cocos2d::Rect(0, 0, s.width, s.height);
		if (rect.containsPoint(locationInNode))//判断触摸点是否在目标的范围内
		{
			if (message.getTargetOne() == nullptr)//target1无目标
			{
<<<<<<< HEAD
				if (false)//操控的单位不属于该玩家
				{
					return true;
				}
				else if(message.getOrder()=="sell")
				{
					//金钱上涨
					EraseBuilding();
				}
			}
			else
			{
				if (_canattack(message.getTargetOne()))
				{
					_isattacked(message.getTargetOne());
					//cocos2d::log("WARNING!!! I WAS ATTACKED!!!");
					//cocos2d::log("The car's blood %d", this->getHealth());
					//cocos2d::log("the order is clean");
				}
				
				
=======
				cocos2d::log("it's useless");
			}
			else
			{
				_isattacked(message.getTargetOne());
				cocos2d::log("WARNING!!! I WAS ATTACKED!!!");
				cocos2d::log("The car's blood %d", this->getHealth());
				cocos2d::log("the order is clean");
>>>>>>> origin/zhou
				message.clean();
			}
			return true;
		}
		else
		{
			return false;
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buildinglistener, this);

	this->setType(type);
<<<<<<< HEAD
	if (type == Mine_TYPE)
	{
		setHealth(Mine_HEALTH);
		setMaxHealth(Mine_MAXHEALTH);
		setDefend(Mine_DEFEND);
		setBuildTime(Mine_BUILD_TIME);
		setEffectRange(Mine_BUILD_TIME);
=======
	if (type == BUIDMINE_TYPE)
	{
		setHealth(BUIDMINE_HEALTH);
		setMaxHealth(BUIDMINE_MAXHEALTH);
		setDefend(BUIDMINE_DEFEND);
		setBuildTime(BUIDMINE_BUILD_TIME);
		setEffectRange(BUIDMINE_BUILD_TIME);
>>>>>>> origin/zhou
		setIsMove(true);
		auto frame = cocos2d::SpriteFrame::create("buildingmine.png", cocos2d::Rect(0, 0, 99, 99));
		this->setDisplayFrame(frame);
	}
<<<<<<< HEAD
	else if (type == Power_TYPE)
	{
		setHealth(Power_HEALTH);
		setMaxHealth(Power_MAXHEALTH);
		setDefend(Power_DEFEND);
		setBuildTime(Power_BUILD_TIME);
		//setEffectRange(Power_EffectRange);
		setPrice(Power_PRICE);
=======
	else if (type == BUIDPOWER_TYPE)
	{
		setHealth(BUIDPOWER_HEALTH);
		setMaxHealth(BUIDPOWER_MAXHEALTH);
		setDefend(BUIDPOWER_DEFEND);
		setBuildTime(BUIDPOWER_BUILD_TIME);
		//setEffectRange(Power_EffectRange);
		setPrice(BUIDPOWER_PRICE);
>>>>>>> origin/zhou
		setIsMove(true);
		auto frame = cocos2d::SpriteFrame::create("buildingpower.png", cocos2d::Rect(0, 0, 99, 99));
		this->setDisplayFrame(frame);
	}
<<<<<<< HEAD
	else if (type == Soldier_TYPE)
	{
		setHealth(Soldier_HEALTH);
		setMaxHealth(Soldier_MAXHEALTH);
		setDefend(Soldier_DEFEND);
		setBuildTime(Soldier_BUILD_TIME);
		setPrice(Soldier_PRICE);
=======
	else if (type == BUIDSOLDIER_TYPE)
	{
		setHealth(BUIDSOLDIER_HEALTH);
		setMaxHealth(BUIDSOLDIER_MAXHEALTH);
		setDefend(BUIDSOLDIER_DEFEND);
		setBuildTime(BUIDSOLDIER_BUILD_TIME);
		setPrice(BUIDSOLDIER_PRICE);
>>>>>>> origin/zhou
		setIsMove(true);
		auto frame = cocos2d::SpriteFrame::create("buildingsoldier.png", cocos2d::Rect(0, 0, 99, 99));
		this->setDisplayFrame(frame);
	}
<<<<<<< HEAD
	else if (type == Car_TYPE)
	{
		setHealth(Car_HEALTH);
		setMaxHealth(Car_MAXHEALTH);
		setDefend(Car_DEFEND);
		setBuildTime(Car_BUILD_TIME);
		setPrice(Car_PRICE);
=======
	else if (type == BUIDCAR_TYPE)
	{
		setHealth(BUIDCAR_HEALTH);
		setMaxHealth(BUIDCAR_MAXHEALTH);
		setDefend(BUIDCAR_DEFEND);
		setBuildTime(BUIDCAR_BUILD_TIME);
		setPrice(BUIDCAR_PRICE);
>>>>>>> origin/zhou
		setIsMove(true);
		auto frame = cocos2d::SpriteFrame::create("buildingcar.png", cocos2d::Rect(0, 0, 99, 99));
		this->setDisplayFrame(frame);
	}
	setPosition(pos);
	setIsMove(false);
<<<<<<< HEAD
}

=======
}
>>>>>>> origin/zhou
