#include <color/make_color.hpp>
#include <gtest/gtest.h>

TEST(MakeColorTest, FromRGB)
{
    auto const color = jt::MakeColor::FromRGB(1, 2, 3);
    jt::Color const expectedColor { 1, 2, 3, 255 };
    ASSERT_EQ(color, expectedColor);
}

TEST(MakeColorTest, FromRGBA)
{
    auto const color = jt::MakeColor::FromRGBA(1, 2, 3, 4);
    jt::Color const expectedColor { 1, 2, 3, 4 };
    ASSERT_EQ(color, expectedColor);
}

TEST(MakeColorTest, FromHSV)
{
    auto const color = jt::MakeColor::FromHSV(0.0f, 100.0f, 100.0f);
    ASSERT_EQ(color, jt::colors::Red);
}

TEST(MakeColorTest, FromHSVA)
{
    auto const color = jt::MakeColor::FromHSVA(0.0f, 100.0f, 100.0f, 25);
    jt::Color const expectedColor { 255, 0, 0, 25 };
    ASSERT_EQ(color, expectedColor);
}

TEST(MakeColorTest, FromHexString)
{
    auto const color = jt::MakeColor::FromHexString("ac3232");
    jt::Color const expectedColor { 172, 50, 50, 255 };
    ASSERT_EQ(color, expectedColor);
}

TEST(MakeColorTest, FromHexStringCapsAndHash)
{
    auto const color = jt::MakeColor::FromHexString("#FF00FF");
    jt::Color const expectedColor { 255, 0, 255, 255 };
    ASSERT_EQ(color, expectedColor);
}

TEST(MakeColorTest, FromHexStringInvalid)
{
    ASSERT_THROW(jt::MakeColor::FromHexString("#FF00FF1234XXXs"), std::invalid_argument);
}
