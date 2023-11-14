#include <gtest/gtest.h>
#include "MovingDecor.hpp"
#include "Perso.hpp"
#include "Input.hpp"



TEST(TestMovingDecor, MovingObjectConstructor) {
    sf::CircleShape rondtest(10.0F);
    rondtest.setFillColor(sf::Color::Black);
    rondtest.setPosition({ 0,0 });
    rondtest.setPointCount(4);
    rondtest.setRotation(45);
    rondtest.setRadius(10);

    MovingDecor voitureTest(10.0F, sf::Color::Black, 0, 0, {}, 0);

    EXPECT_EQ(voitureTest.getShape().getPosition().x, rondtest.getPosition().x);
    EXPECT_EQ(voitureTest.getShape().getPointCount(), rondtest.getPointCount());
    EXPECT_EQ(voitureTest.getShape().getRotation(), rondtest.getRotation());
}

TEST(TestPerso, PersoConstructor) {

    Perso testperso(5.0F, sf::Color::Black, 0, 0, 0);

    EXPECT_FLOAT_EQ(testperso.getShape().getPosition().x, 0);
    EXPECT_EQ(testperso.getShape().getPointCount(), 30);
    EXPECT_EQ(testperso.getShape().getRotation(), 0);
    EXPECT_EQ(testperso.getMoveSpeed(), 0);
    EXPECT_EQ(testperso.getIsMoving(), false);
}

TEST(TestPerso, TestMove1) {

    Perso testperso(5.0F, sf::Color::Black, 0, 0, 10);
    testperso.move("D");
    EXPECT_EQ(testperso.getShape().getPosition().x, 10);
    EXPECT_EQ(testperso.getShape().getPosition().y, 0);
}

TEST(TestMovingDecor, TestMove2) {

    MovingDecor testvoiture(5.0F, sf::Color::Black, 0, 0, { "Z", "Z"}, 10);
    testvoiture.move("Q");
    //la méthode move d'un décor mouvant ne prend pas en compte l'argument mais la liste de string dans le constructeur !
    EXPECT_EQ(testvoiture.getShape().getPosition().y, -10);

    EXPECT_EQ(testvoiture.getShape().getPosition().x, 0);
}


TEST(TestPerso, TestReset) {

    Perso testperso(5.0F, sf::Color::Black, 0, 0, 10);
    testperso.move("D");
    testperso.move("D");
    testperso.move("D");
    testperso.reset();

    EXPECT_EQ(testperso.getShape().getPosition().x, 0);
    EXPECT_EQ(testperso.getShape().getPosition().y, 0);
}