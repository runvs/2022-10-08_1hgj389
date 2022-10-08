
#include "block.hpp"
#include <game_properties.hpp>

void Block::doCreate()
{
    m_shape = std::make_shared<jt::Shape>();
    m_shape->makeRect(jt::Vector2f { 16.0f, 16.0f }, textureManager());
    m_shape->setColor(GP::getPalette().getColor(2));
}
void Block::doUpdate(float const elapsed) { m_shape->update(elapsed); }
void Block::doDraw() const { m_shape->draw(renderTarget()); }
jt::Vector2f Block::getPosition() const { return m_shape->getPosition(); }

void Block::setPlayerID(int playerID)
{
    m_playerId = playerID;
    if (m_playerId == 1) {
        m_shape->setColor(GP::getPalette().getColor(3));
    } else if (m_playerId == 2) {
        m_shape->setColor(GP::getPalette().getColor(4));
    }
}
int Block::getPlayerId() const { return m_playerId; }
void Block::setPosition(jt::Vector2f const& pos) { m_shape->setPosition(pos); }
