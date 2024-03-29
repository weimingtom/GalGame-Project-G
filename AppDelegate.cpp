#include "AppDelegate.h"
#include "AudioEngine.h"
#include "StartMenuSence.h"

USING_NS_CC;

extern int musicid;

AppDelegate::AppDelegate() 
{

}

AppDelegate::~AppDelegate() 
{

}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLViewImpl::createWithRect(u8"人气漫画家培养计划", Rect(0, 0, 1280, 720));
        director->setOpenGLView(glview);
    }
    
    director->getOpenGLView()->setDesignResolutionSize(1280, 720, ResolutionPolicy::FIXED_HEIGHT);

    // turn on display FPS
    director->setDisplayStats(false);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    FileUtils::getInstance()->addSearchPath("res");

    // create a scene. it's an autorelease object
    auto scene = StartMenu::createScene();

    // run
    director->runWithScene(scene);

    return true;
}

void AppDelegate::applicationDidEnterBackground() {
	Director::getInstance()->stopAnimation();

	experimental::AudioEngine::pause(musicid);
}

void AppDelegate::applicationWillEnterForeground() {
	Director::getInstance()->startAnimation();

	experimental::AudioEngine::resume(musicid);
}
