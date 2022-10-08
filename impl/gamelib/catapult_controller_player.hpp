#ifndef INC_1HGJ389_CATAPULT_CONTROLLER_PLAYER_HPP
#define INC_1HGJ389_CATAPULT_CONTROLLER_PLAYER_HPP
#include <catapult_controller_interface.hpp>
#include <input/input_get_interface.hpp>

class CatapultControllerPlayer : public CatapultControllerInterface {
public:
    explicit CatapultControllerPlayer(jt::InputGetInterface& input);
    void update(float elapsed) override;
    void registerCatapult(Catapult* catapult) override;
    int getPlayerID() const override;

private:
    jt::InputGetInterface& m_input;
    Catapult* m_catapult { nullptr };
};

#endif // INC_1HGJ389_CATAPULT_CONTROLLER_PLAYER_HPP
