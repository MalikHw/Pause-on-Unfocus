#include <Geode/Geode.hpp>
#include <Geode/modify/CCEGLView.hpp>
#include <Geode/modify/CCApplication.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

void pauseGame() {
    if (auto playLayer = PlayLayer::get()) {
        if (!playLayer->m_isPaused) {
            playLayer->pauseGame(true);
        }
    }
}

class $modify(CCEGLView) {
    void windowFocusChanged(bool focused) {
        CCEGLView::windowFocusChanged(focused);
        if (!focused) {
            pauseGame();
        }
    }
};

class $modify(CCApplication) {
    void applicationDidEnterBackground() {
        CCApplication::applicationDidEnterBackground();
        pauseGame();
    }
};