
#include "start_game.h"
#include "main_game.h"
#include "select_plane_scene.h"
cocos2d::Scene* StartGame::createScene()
{
	auto scene = Scene::create();

	auto layer = StartGame::create();

	scene->addChild(layer);
	return scene;
}

bool StartGame::init()
{
	if (!Layer::init())
		return false;
	//游戏窗口大小
	auto size = Director::getInstance()->getWinSize();

	//游戏的背景
	auto spr_bg = Sprite::create("image/background.png");
	spr_bg->setPosition(ccp(size.width / 2, size.height / 2));
	this->addChild(spr_bg);

	//游戏的标题
	auto title = Sprite::create("image/bt.png");

	title->setPosition(size.width / 2, size.height - title->getContentSize().height);

	this->addChild(title);

	//创建帧动画
	auto animation = Animation::create();
	for (int i = 1; i <= 3; ++i)
	{
		auto spr_name = String::createWithFormat("image/game_loading%d.png", i);
		animation->addSpriteFrameWithFile(spr_name->getCString());
	}
	animation->setDelayPerUnit(0.5f);
	animation->setLoops(-1);

	//创建精灵
	auto sprite = Sprite::create("image/game_loading1.png");
	sprite->setPosition(ccp(size.width / 2, size.height / 2));
	this->addChild(sprite);
	sprite->runAction(Animate::create(animation));

	//添加开始游戏按钮

	CCMenuItemImage *ks = CCMenuItemImage::create("image/button_new_game.png", "image/button_new_game_pressed.png",this,menu_selector(StartGame::start_play));

	auto menu = Menu::create(ks, NULL);
	menu->setPosition(ccp(size.width / 2, size.height *0.3));
	this->addChild(menu);



	return true;
}

void StartGame::start_play(Ref* ref)
{
	//切换场景
		//Director::getInstance()->replaceScene(TransitionFadeTR::create(0.5, MainGame::createScene()));

	//进入选择界面
	Director::getInstance()->replaceScene(TransitionFadeTR::create(0.5, SelectPlaneScene::create()));

}



