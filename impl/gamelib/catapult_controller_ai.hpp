#ifndef INC_1HGJ389_CATAPULT_CONTROLLER_AI_HPP
#define INC_1HGJ389_CATAPULT_CONTROLLER_AI_HPP

#include <catapult_controller_interface.hpp>

class CatapultControllerAI : public CatapultControllerInterface {
public:
    void update(float elapsed) override;
    void registerCatapult(Catapult* catapult) override;
    int getPlayerID() const override;

private:
    Catapult* m_catapult { nullptr };
    float m_remainingTimeInDirection { 1.0f };
    bool m_currentDirection { true };

    float m_fireTimer { 1.0f };
};

#endif // INC_1HGJ389_CATAPULT_CONTROLLER_AI_HPP
