#include "game_properties.hpp"

jt::Palette GP::getPalette()
{
    static auto const p = jt::Palette::parseGPL(R"(GIMP Palette
#Palette Name: CMYK4
#Description: a slightly different palette based on CMYK colors
#Colors: 4
34	33	38	222126
230	46	107	e62e6b
46	199	230	2ec7e6
255	230	102	ffe666
)");
    return p;
}

int GP::PhysicVelocityIterations() { return 20; }

int GP::PhysicPositionIterations() { return 20; }
jt::Vector2f GP::PlayerSize() { return jt::Vector2f { 16.0f, 16.0f }; }
