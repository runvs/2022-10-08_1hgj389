#include "catapult.hpp"
#include <catapult_controller_interface.hpp>
#include <game_properties.hpp>

Catapult::Catapult(std::shared_ptr<CatapultControllerInterface> controller)
{
    m_controller = controller;
    if (m_controller == nullptr) {
        throw std::invalid_argument { "cannot create catapult with nullptr controller" };
    }
    m_controller->registerCatapult(this);
}

void Catapult::moveUp()
{
    auto pos = m_shape->getPosition();
    pos += jt::Vector2f { 0, -GP::catapultMovementSpeed() } * m_lastElapsed;
    m_shape->setPosition(pos);
}
void Catapult::moveDown()
{
    auto pos = m_shape->getPosition();
    pos += jt::Vector2f { 0, GP::catapultMovementSpeed() } * m_lastElapsed;
    m_shape->setPosition(pos);
}
void Catapult::fire() { }
bool Catapult::canFire() const { return false; }

void Catapult::doCreate()
{
    m_shape = std::make_shared<jt::Shape>();
    m_shape->makeRect(jt::Vector2f { 16.0f, 16.0f }, textureManager());
    if (m_controller->getPlayerID() == 1) {
        m_shape->setColor(GP::getPalette().getColor(3));
    } else {
        m_shape->setColor(GP::getPalette().getColor(4));
    }
}
void Catapult::doUpdate(float const elapsed)
{
    m_controller->update(elapsed);
    m_lastElapsed = elapsed;
    m_shape->update(elapsed);
}
void Catapult::doDraw() const { m_shape->draw(renderTarget()); }