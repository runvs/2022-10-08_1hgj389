#ifndef GAME_STATE_MENU_HPP
#define GAME_STATE_MENU_HPP

#include <game_state.hpp>

namespace jt {

class Text;
class Shape;
class Animation;
class Sprite;
class Vignette;

} // namespace jt

class StateMenu : public jt::GameState {
public:
    std::string getName() const override;

    void setScore(std::string s) { m_score = s; };

private:
    std::shared_ptr<jt::Shape> m_background;

    std::shared_ptr<jt::Text> m_textTitle;
    std::shared_ptr<jt::Text> m_textStart;
    std::shared_ptr<jt::Text> m_textExplanation;
    std::shared_ptr<jt::Text> m_textCredits;
    std::shared_ptr<jt::Text> m_textVersion;

    std::shared_ptr<jt::Shape> m_overlay;
    std::shared_ptr<jt::Vignette> m_vignette;

    std::string m_score { "" };

    bool m_started { false };

    void doInternalCreate() override;

    void createVignette();
    void createShapes();

    void createMenuText();
    void createTextCredits();
    void createTextStart();
    void createTextTitle();

    void createTweens();
    void createInstructionTweenColor1();
    void createInstructionTweenColor2();
    void createInstructionTweenColor3();
    void createInstructionTweenColor4();
    void createTweenTitleAlpha();
    void createTweenOverlayAlpha();
    void createTweenCreditsPosition();
    void createTweenExplanation();

    void doInternalUpdate(float const elapsed) override;
    void updateDrawables(const float& elapsed);
    void checkForTransitionToStateGame();
    void startTransitionToStateGame();

    void doInternalDraw() const override;
    void createTextExplanation();
};

#endif
