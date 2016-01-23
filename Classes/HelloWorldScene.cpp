#include "HelloWorldScene.h"

USING_NS_CC;

using namespace ui;


Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

	auto winSize = Director::getInstance()->getWinSize();

	auto button = Button::create("Button.png", "ButtonPressed.png", "ButtonPressed.png");
	button->setTitleText("Spawn Girl");
	button->setTitleFontName("MarkerFelt.ttf");
	button->setTitleFontSize(12.0f);
	button->setPosition(Vec2(winSize.width/2, winSize.height/2 - 100));

	button->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type)
	{
		switch (type)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN:
			break;
		case cocos2d::ui::Widget::TouchEventType::MOVED:
			break;
		case cocos2d::ui::Widget::TouchEventType::ENDED:
			addSprite();
			break;
		case cocos2d::ui::Widget::TouchEventType::CANCELED:
			break;
		default:
			break;
		}
	});

	this->addChild(button);

    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void HelloWorld::addSprite()
{
	auto winSize = Director::getInstance()->getWinSize();

	auto spriteName = Sprite::create("girl.png");
	spriteName->setPosition(Vec2(winSize.width/2,winSize.height/2));
	this->addChild(spriteName);
}