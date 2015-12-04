#include "bullet.h"
#include "manager_base.h"

Bullet::Bullet()
{

}

Bullet::~Bullet()
{

}

bool Bullet::init()
{
	if (!Sprite::init())
		return false;

	return true;
}

void Bullet::onEnterTransitionDidFinish()
{
	Sprite::onEnterTransitionDidFinish();
	scheduleUpdate();
}

void Bullet::onExit()
{
	unscheduleUpdate();
	Sprite::onExit();
}

void Bullet::initBullet(char* bullet_name)
{
	
	auto spr_name = String::createWithFormat("image/%s", bullet_name);
	this->initWithFile(spr_name->getCString());
}

void Bullet::update(float delta)
{
	
	this->setPositionY(this->getPositionY() + 5);

	if (this->getPositionY() > Director::getInstance()->getWinSize().height)
	{
		this->removeFromParentAndCleanup(true);//删除父节点中的当前节点并清除动作及回调函数
		ManagerBase::getInstance()->remove_bullet_list(this);//
	}
}

