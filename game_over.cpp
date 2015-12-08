#include "game_over.h"
#include "start_game.h"
GameOver::GameOver()
{

}

GameOver::~GameOver()
{

}

cocos2d::Scene* GameOver::createScene()
{
	auto scene = Scene::create();
	auto layer = GameOver::create();
	scene->addChild(layer);

	return scene;
}

bool GameOver::init()
{

	if (!Layer::init())
		return false;

	auto dictionary = Dictionary::createWithContentsOfFile("fonts/text.xml");
	auto junxian = Dictionary::createWithContentsOfFile("fonts/junxian.xml");

	auto size = Director::getInstance()->getWinSize();

	//获取最高分

	auto score_win = UserDefault::getInstance()->getIntegerForKey("beast_score");
	auto score = UserDefault::getInstance()->getIntegerForKey("score");

	//添加背景
	auto spr_bg = Sprite::create("image/gameover.png");
	spr_bg->setPosition(ccp(size.width / 2, size.height / 2));
	this->addChild(spr_bg);


	//分数设置
	auto label_score_num = Label::create();
	label_score_num->setSystemFontSize(60);
	label_score_num->setAnchorPoint(ccp(0.5, 0.5));
	label_score_num->setPosition(ccp(size.width / 2 - label_score_num->getContentSize().width/2, size.height / 4));
	this->addChild(label_score_num);
	
	//最高分
	auto label_best_score_num = Label::create();
	label_best_score_num->setSystemFontSize(60);
	label_best_score_num->setAnchorPoint(ccp(0.5, 0.5));
	label_best_score_num->setPosition(ccp(size.width / 2, size.height *0.8));
	this->addChild(label_best_score_num);

	//军衔
	auto Total_num = UserDefault::getInstance()->getIntegerForKey("Total");
	auto military_rank = Label::create();
	if (score_win >= 2000 && score_win < 5000)
	{
		military_rank->setString(((__String*)(junxian->objectForKey("0")))->getCString());
	}
	else if (score_win >= 5000 && score_win < 7000)
				{
					military_rank->setString(((__String*)(junxian->objectForKey("1")))->getCString());
				}
	else if (score_win >= 7000 && score_win < 10000)
	{
		military_rank->setString(((__String*)(junxian->objectForKey("2")))->getCString());
	}
	else if (score_win >= 10000 && score_win < 12000)
	{
		military_rank->setString(((__String*)(junxian->objectForKey("3")))->getCString());
	}
	else if (score_win >= 12000 && score_win < 15000)
	{
		military_rank->setString(((__String*)(junxian->objectForKey("4")))->getCString());
	}
	else if (score_win >= 15000 && score_win < 17000)
	{
		military_rank->setString(((__String*)(junxian->objectForKey("5")))->getCString());
	}
	else if (score_win >= 17000 && score_win < 20000)
	{
		military_rank->setString(((__String*)(junxian->objectForKey("6")))->getCString());
	}
	else if (score_win >= 20000 && score_win < 25000)
	{
		military_rank->setString(((__String*)(junxian->objectForKey("7")))->getCString());
	}
	else if (score_win >= 25000 && score_win < 30000)
	{
		military_rank->setString(((__String*)(junxian->objectForKey("8")))->getCString());
	}
	else if (score_win >= 30000)
	{
		military_rank->setString(((__String*)(junxian->objectForKey("9")))->getCString());
	}
	else
	{
		military_rank->setString(((__String*)(junxian->objectForKey("10")))->getCString());
	}
	military_rank->setSystemFontSize(50);
	military_rank->setColor(Color3B(0, 0, 0));
	military_rank->setAnchorPoint(ccp(0.5,0.5));
	military_rank->setPosition(ccp(size.width/2,size.height*0.53));
	this->addChild(military_rank);






	//最高分
	label_best_score_num->setString(String::createWithFormat("%d", score_win)->getCString());
	label_score_num->setString(String::createWithFormat("%d", score)->getCString());
	
	//添加返回主页menu	
	CCMenuItemImage *btn_label = CCMenuItemImage::create("image/restart_nor.png", "image/restart_sel.png",this,menu_selector(GameOver::menu_play));

	auto menu = Menu::create(btn_label, NULL);
	menu->setPosition(ccp(size.width / 2, size.height /8));
	this->addChild(menu);
	return true;
}


void GameOver::menu_play(Ref * ref)
{
	Director::getInstance()->replaceScene(TransitionFade::create(0.5, StartGame::createScene()));
}
