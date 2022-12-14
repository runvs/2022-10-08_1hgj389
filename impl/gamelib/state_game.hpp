#ifndef GAME_STATE_GAME_HPP
#define GAME_STATE_GAME_HPP

#include "block.hpp"
#include "object_group.hpp"
#include "text.hpp"
#include <box2dwrapper/box2d_world_interface.hpp>
#include <catapult.hpp>
#include <game_state.hpp>
#include <memory>
#include <vector>

// fwd decls
namespace jt {
class Shape;
class Sprite;
class Vignette;
} // namespace jt

class Hud;

class StateGame : public jt::GameState {
public:
    std::string getName() const override;

private:
    std::shared_ptr<jt::Shape> m_background;
    std::shared_ptr<jt::Vignette> m_vignette;
    std::shared_ptr<Hud> m_hud;
    std::shared_ptr<jt::Box2DWorldInterface> m_world { nullptr };

    std::shared_ptr<Catapult> m_catapult1 { nullptr };
    std::shared_ptr<Catapult> m_catapult2 { nullptr };

    std::shared_ptr<jt::ObjectGroup<Block>> m_blocks { nullptr };

    int m_gridSizeX = 21;
    int m_gridSizeY = 22;
    jt::Vector2f const m_gridOffset { 125.0f, 20.0f };

    float m_timer { 60.0f };
    std::shared_ptr<jt::Text> m_timerText { nullptr };

    bool m_running { true };
    bool m_hasEnded { false };

    int m_scoreP1 { 0 };
    int m_scoreP2 { 0 };

    void doInternalCreate() override;
    void doInternalUpdate(float const elapsed) override;
    void doInternalDraw() const override;

    void endGame();
    void createCatapults();
};

#endif
