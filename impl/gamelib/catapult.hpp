#ifndef INC_1HGJ389_CATAPULT_HPP
#define INC_1HGJ389_CATAPULT_HPP

#include "shape.hpp"
#include <game_object.hpp>

class CatapultControllerInterface;

class Catapult : public jt::GameObject {
public:
    explicit Catapult(std::shared_ptr<CatapultControllerInterface> controller);
    void moveUp();
    void moveDown();
    void fire(float strength);
    bool canFire() const;

    void registerHitCallback(std::function<void(jt::Vector2f const&)> cb);

private:
    std::shared_ptr<CatapultControllerInterface> m_controller { nullptr };
    std::shared_ptr<jt::Shape> m_shape;

    float m_lastElapsed { 0.0f };
    std::function<void(jt::Vector2f const&)> m_hitCallback;

    float m_fireCooldown { 0.0f };

    void doCreate() override;
    void doUpdate(float const elapsed) override;
    void doDraw() const override;
};

#endif // INC_1HGJ389_CATAPULT_HPP
