#include "state_game.hpp"
#include <box2dwrapper/box2d_world_impl.hpp>
#include <catapult_controller_ai.hpp>
#include <catapult_controller_player.hpp>
#include <color/color.hpp>
#include <game_interface.hpp>
#include <game_properties.hpp>
#include <hud/hud.hpp>
#include <random/random.hpp>
#include <screeneffects/vignette.hpp>
#include <shape.hpp>
#include <sprite.hpp>
#include <state_menu.hpp>
#include <tweens/tween_alpha.hpp>

void StateGame::doInternalCreate()
{
    m_world = std::make_shared<jt::Box2DWorldImpl>(jt::Vector2f { 0.0f, 0.0f });

    float const w = static_cast<float>(GP::GetWindowSize().x);
    float const h = static_cast<float>(GP::GetWindowSize().y);

    using jt::Shape;
    using jt::TweenAlpha;

    m_background = std::make_shared<Shape>();
    m_background->makeRect({ w, h }, textureManager());
    m_background->setColor(GP::PaletteBackground());
    m_background->setIgnoreCamMovement(true);
    m_background->update(0.0f);

    createCatapults();

    m_blocks = std::make_shared<jt::ObjectGroup<Block>>();
    jt::Vector2f const gridOffset { 125.0f, 20.0f };
    for (auto i = 1; i != m_gridSizeX; ++i) {
        for (auto j = 1; j != m_gridSizeY; ++j) {
            if (jt::Random::getChance(0.6f)) {
                auto block = std::make_shared<Block>();
                add(block);
                m_blocks->push_back(block);
                block->setPosition(gridOffset + jt::Vector2f { i * 16.0f, j * 16.0f });
            }
        }
    }

    m_vignette = std::make_shared<jt::Vignette>(GP::GetScreenSize());
    add(m_vignette);
    m_hud = std::make_shared<Hud>();
    add(m_hud);

    // StateGame will call drawObjects itself.
    setAutoDraw(false);
}

void StateGame::createCatapults()
{
    auto inputP = std::make_shared<CatapultControllerPlayer>(getGame()->input());
    m_catapult1 = std::make_shared<Catapult>(inputP);
    add(m_catapult1);

    auto inputP2 = std::make_shared<CatapultControllerAI>();
    m_catapult2 = std::make_shared<Catapult>(inputP2);
    add(m_catapult2);
}

void StateGame::doInternalUpdate(float const elapsed)
{
    if (m_running) {
        m_world->step(elapsed, GP::PhysicVelocityIterations(), GP::PhysicPositionIterations());
        // update game logic here
    }

    m_background->update(elapsed);
    m_vignette->update(elapsed);
}

void StateGame::doInternalDraw() const
{
    m_background->draw(renderTarget());
    drawObjects();

    m_vignette->draw();
    m_hud->draw();
}

void StateGame::endGame()
{
    if (m_hasEnded) {
        // trigger this function only once
        return;
    }
    m_hasEnded = true;
    m_running = false;

    getGame()->stateManager().switchState(std::make_shared<StateMenu>());
}

std::string StateGame::getName() const { return "State Game"; }
