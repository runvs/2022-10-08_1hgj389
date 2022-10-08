#ifndef INC_1HGJ389_BLOCK_HPP
#define INC_1HGJ389_BLOCK_HPP

#include <game_object.hpp>
#include <shape.hpp>

class Block : public jt::GameObject {
public:
    jt::Vector2f getPosition() const;
    void setPosition(jt::Vector2f const& pos);

    void setPlayerID(int playerID);
    int getPlayerId() const;

private:
    std::shared_ptr<jt::Shape> m_shape { nullptr };
    int m_playerId { 0 };
    void doCreate() override;
    void doUpdate(float const elapsed) override;
    void doDraw() const override;
};

#endif // INC_1HGJ389_BLOCK_HPP
