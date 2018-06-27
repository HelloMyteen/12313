
#pragma once


#include <cocos2d.h>
#include <string>


class GameUnit :public cocos2d::Sprite {
public:
	GameUnit() = default;

	//单位的create函数
	static GameUnit* create(const std::string& filename);
	static GameUnit* createWithSpriteFrameName(const std::string & 	filename);

	//获取游戏单位各种属性的函数
<<<<<<< HEAD
	int getType();
//	cocos2d::Vec2 getVec();
	std::string getName();
	int getHealth();			//获取单位生命值
	int getMaxHealth();
=======
	Sprite * getblood();
	Sprite * getbar();

	int getType();
//	cocos2d::Vec2 getVec();
	std::string getName();
	float getHealth();			//获取单位生命值
	float getMaxHealth();
>>>>>>> origin/zhou
	int getAttack();
	int getAttackSpeed();
	int getDefend();
	float getBuildTime();
	int getPrice();
	bool getDeathMes();

//	cocos2d::Sprite* getEffectRange();
	float getEffectRange();

	bool getIsMove();



	//修改各种属性
<<<<<<< HEAD
	void setType(int t);
//	void setVec(cocos2d::Vec2 pos);
	void setHealth(int h);
	void setMaxHealth(int mh);
=======
	void setblood(Sprite * _blood);
	void setbar(Sprite * _bar);

	void setType(int t);
//	void setVec(cocos2d::Vec2 pos);
	void setHealth(float h);
	void setMaxHealth(float mh);
>>>>>>> origin/zhou
	void setAttack(int att);
	void setAttackSpeed(int att_spe);
	void setDefend(int def);
	void setBuildTime(float bul_tim);
	void setPrice(int pri);
	void setUnitDead();

//	void setEffectRange(cocos2d::Sprite* range);
	void setEffectRange(float range);
	void setIsMove(bool is);

private:
//	cocos2d::Sprite* effect_range;	//单位的作用范围
	float effect_range;


	int type=0;						//单位的类型
//	cocos2d::Vec2 position;			//单位的位置
	std::string unit_name;			//单位的id
<<<<<<< HEAD
	int health;						//单位的生命值
	int max_health;					//单位的最大生命值
=======
	float health;						//单位的生命值
	float max_health;					//单位的最大生命值
>>>>>>> origin/zhou
	int attack;						//单位的攻击力
	int attack_speed;				//单位的攻击速度
	int defend;						//单位的防御力
	float build_time;				//单位的建造时间
	int price;						//单位的价格
	bool isUnitDead = false;		//单位是否死亡
	bool isMove = true;            //单位是否可移动
<<<<<<< HEAD
=======
	cocos2d::Sprite*blood;
	cocos2d::Sprite*bar;
>>>>>>> origin/zhou
};

