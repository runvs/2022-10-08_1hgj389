#include "catapult_controller_player.hpp"
#include <catapult.hpp>
#include <iostream>

CatapultControllerPlayer::CatapultControllerPlayer(jt::InputGetInterface& input)
    : m_input { input }
{
}

void CatapultControllerPlayer::update(float elapsed)
{
    if (!m_catapult) {
        std::cerr << "no catapult registered\n";
    }
    if (m_input.keyboard()->pressed(jt::KeyCode::W)) {
        m_catapult->moveUp();
    } else if (m_input.keyboard()->pressed(jt::KeyCode::S)) {
        m_catapult->moveDown();
    }
    if (m_input.keyboard()->justPressed(jt::KeyCode::Space)) {
        m_fireTimer = 0.0f;
    }
    if (m_input.keyboard()->pressed(jt::KeyCode::Space)) {
        m_fireTimer += elapsed;
        if (m_fireTimer > m_fireTimerMax) {
            m_fireTimer = m_fireTimerMax;
        }
    }
    if (m_input.keyboard()->justReleased(jt::KeyCode::Space)) {

        m_catapult->fire(m_fireTimer / m_fireTimerMax);
    }
}
void CatapultControllerPlayer::registerCatapult(Catapult* catapult) { m_catapult = catapult; }
int CatapultControllerPlayer::getPlayerID() const { return 1; }
