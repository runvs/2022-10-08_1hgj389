#ifndef INC_1HGJ389_CATAPULT_CONTROLLER_INTERFACE_HPP
#define INC_1HGJ389_CATAPULT_CONTROLLER_INTERFACE_HPP

#include <memory>

class Catapult;

class CatapultControllerInterface {
public:
    virtual ~CatapultControllerInterface() = default;
    virtual void update(float elapsed) = 0;
    virtual void registerCatapult(Catapult* catapult) = 0;
    virtual int getPlayerID() const = 0;
};

#endif // INC_1HGJ389_CATAPULT_CONTROLLER_INTERFACE_HPP
