// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cmath>
#include "circle.h"
#include "tasks.h"

TEST(CircleTest, ConstructorStoresRadius) {
    Circle c(4.2);
    EXPECT_DOUBLE_EQ(4.2, c.getRadius());
}

TEST(CircleTest, ConstructorComputesFerence) {
    Circle c(4.2);
    EXPECT_NEAR(2.0 * M_PI * 4.2, c.getFerence(), 1e-4);
}

TEST(CircleTest, ConstructorComputesArea) {
    Circle c(4.2);
    EXPECT_NEAR(M_PI * 4.2 * 4.2, c.getArea(), 1e-4);
}

TEST(CircleTest, SetRadiusUpdatesFerence) {
    Circle c(1.0);
    c.setRadius(3.7);
    EXPECT_NEAR(2.0 * M_PI * 3.7, c.getFerence(), 1e-4);
}

TEST(CircleTest, SetRadiusUpdatesArea) {
    Circle c(1.0);
    c.setRadius(3.7);
    EXPECT_NEAR(M_PI * 3.7 * 3.7, c.getArea(), 1e-4);
}

TEST(CircleTest, SetFerenceUpdatesRadius) {
    Circle c(1.0);
    c.setFerence(23.0);
    EXPECT_NEAR(23.0 / (2.0 * M_PI), c.getRadius(), 1e-4);
}

TEST(CircleTest, SetFerenceUpdatesArea) {
    Circle c(1.0);
    c.setFerence(23.0);
    double expectedR = 23.0 / (2.0 * M_PI);
    EXPECT_NEAR(M_PI * expectedR * expectedR, c.getArea(), 1e-4);
}

TEST(CircleTest, SetAreaUpdatesRadius) {
    Circle c(1.0);
    c.setArea(45.0);
    double expectedR = std::sqrt(45.0 / M_PI);
    EXPECT_NEAR(expectedR, c.getRadius(), 1e-4);
}

TEST(CircleTest, SetAreaUpdatesFerence) {
    Circle c(1.0);
    c.setArea(45.0);
    double expectedR = std::sqrt(45.0 / M_PI);
    EXPECT_NEAR(2.0 * M_PI * expectedR, c.getFerence(), 1e-4);
}

TEST(CircleTest, ZeroRadius) {
    Circle c(0.0);
    EXPECT_DOUBLE_EQ(0.0, c.getFerence());
    EXPECT_DOUBLE_EQ(0.0, c.getArea());
}

TEST(CircleTest, NegativeRadius) {
    Circle c(-3.0);
    EXPECT_LE(c.getRadius(), 0.0);
}

TEST(CircleTest, TinyRadius) {
    Circle c(1e-6);
    EXPECT_NEAR(2.0 * M_PI * 1e-6, c.getFerence(), 1e-12);
    EXPECT_NEAR(M_PI * 1e-12, c.getArea(), 1e-18);
}

TEST(CircleTest, LargeRadius) {
    Circle c(1e6);
    EXPECT_GT(c.getArea(), 1e12);
    EXPECT_GT(c.getFerence(), 1e6);
}

TEST(CircleTest, SetFerenceKeepSame) {
    Circle c(3.0);
    double f = c.getFerence();
    c.setFerence(f);
    EXPECT_NEAR(3.0, c.getRadius(), 1e-4);
}

TEST(CircleTest, SetAreaKeepSame) {
    Circle c(3.0);
    double a = c.getArea();
    c.setArea(a);
    EXPECT_NEAR(3.0, c.getRadius(), 1e-4);
}

TEST(RopeTask, ClearancePositive) {
    EXPECT_GT(calEarthAndRope(), 0.0);
}

TEST(RopeTask, ClearanceValue) {
    EXPECT_NEAR(0.1591549, calEarthAndRope(), 1e-6);
}

TEST(RopeTask, ClearanceLessThanOneMeter) {
    EXPECT_LT(calEarthAndRope(), 1.0);
}

TEST(PoolTask, TotalCostPositive) {
    EXPECT_GT(calPool(), 0.0);
}

TEST(PoolTask, TotalCostExpectedValue) {
    EXPECT_NEAR(72256.63, calPool(), 0.1);
}

TEST(CircleTest, SetRadiusThenSetFerenceBack) {
    Circle c(5.5);
    double f = c.getFerence();
    c.setRadius(10.0);
    c.setFerence(f);
    EXPECT_NEAR(5.5, c.getRadius(), 1e-4);
    EXPECT_NEAR(f, c.getFerence(), 1e-4);
}

TEST(CircleTest, SetFerenceThenSetArea) {
    Circle c(1.0);
    c.setFerence(12.5);
    double expectedArea = c.getArea();
    c.setArea(expectedArea);
    EXPECT_NEAR(12.5 / (2 * M_PI), c.getRadius(), 1e-4);
}

TEST(CircleTest, MultipleSetRadius) {
    Circle c(0.0);
    c.setRadius(8.0);
    c.setRadius(2.5);
    EXPECT_NEAR(2.5, c.getRadius(), 1e-4);
    EXPECT_NEAR(M_PI * 2.5 * 2.5, c.getArea(), 1e-4);
}

TEST(CircleTest, SetAreaLargeValue) {
    Circle c(1.0);
    c.setArea(314.159);
    EXPECT_NEAR(10.0, c.getRadius(), 0.01);
}

TEST(CircleTest, SetFerenceZero) {
    Circle c(10.0);
    c.setFerence(0.0);
    EXPECT_DOUBLE_EQ(0.0, c.getRadius());
    EXPECT_DOUBLE_EQ(0.0, c.getArea());
}

TEST(RopeTask, ClearanceExactFormula) {
    double gap = calEarthAndRope();
    double expected = 1.0 / (2.0 * M_PI);
    EXPECT_NEAR(expected, gap, 1e-9);
}

TEST(PoolTask, CostBreakdownSanity) {
    double total = calPool();
    double concrete = 7.0 * M_PI * 1000.0;
    double fence = 8.0 * M_PI * 2000.0;
    EXPECT_NEAR(total, concrete + fence, 0.01);
}

TEST(PoolTask, CostGreaterThanConcreteAlone) {
    double total = calPool();
    double concrete = 7.0 * M_PI * 1000.0;
    EXPECT_GT(total, concrete);
}
