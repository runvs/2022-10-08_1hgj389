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
        m_catapult->fire();
    }
}
void CatapultControllerPlayer::registerCatapult(Catapult* catapult) { m_catapult = catapult; }
int CatapultControllerPlayer::getPlayerID() const { return 1; }
