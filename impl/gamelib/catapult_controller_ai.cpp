#include "catapult_controller_ai.hpp"
#include <catapult.hpp>
#include <random/random.hpp>

void CatapultControllerAI::update(float elapsed)
{
    m_fireTimer -= elapsed;
    m_remainingTimeInDirection -= elapsed;
    if (m_remainingTimeInDirection <= 0.0f) {
        m_remainingTimeInDirection = jt::Random::getFloat(0.5f, 2.5f);
        m_currentDirection = jt::Random::getChance();
    }

    if (!m_catapult) {
        return;
    }

    if (m_currentDirection) {
        m_catapult->moveDown();
    } else {
        m_catapult->moveUp();
    }
    if (m_fireTimer <= 0.0f) {
        m_catapult->fire(jt::Random::getFloat(0.0f, 1.0f));
        m_fireTimer = jt::Random::getFloat(1.0f, 1.5f);
    }
}
void CatapultControllerAI::registerCatapult(Catapult* catapult) { m_catapult = catapult; }
int CatapultControllerAI::getPlayerID() const { return 2; }
