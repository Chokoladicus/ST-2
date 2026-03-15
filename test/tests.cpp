// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cstdint>
#include "circle.h"
#include "tasks.h"

TEST(CircleTest, RadiusSet) {
    Circle c(3.0);
    EXPECT_NEAR(3.0, c.getRadius(), 0.0001);
}

TEST(CircleTest, FerenceFromRadius) {
    Circle c(7.5);
    EXPECT_NEAR(47.1239, c.getFerence(), 0.001);
}

TEST(CircleTest, AreaFromRadius) {
    Circle c(7.5);
    EXPECT_NEAR(176.7146, c.getArea(), 0.001);
}

TEST(CircleTest, SetFerenceUpdatesRadius) {
    Circle c(1.0);
    c.setFerence(47.1239);
    EXPECT_NEAR(7.5, c.getRadius(), 0.001);
}

TEST(CircleTest, SetFerenceUpdatesArea) {
    Circle c(1.0);
    c.setFerence(47.1239);
    EXPECT_NEAR(176.7146, c.getArea(), 0.001);
}

TEST(CircleTest, SetAreaUpdatesRadius) {
    Circle c(1.0);
    c.setArea(176.7146);
    EXPECT_NEAR(7.5, c.getRadius(), 0.001);
}

TEST(CircleTest, SetAreaUpdatesFerence) {
    Circle c(1.0);
    c.setArea(176.7146);
    EXPECT_NEAR(47.1239, c.getFerence(), 0.001);
}

TEST(CircleTest, ZeroRadiusTest) {
    Circle c(0.0);
    EXPECT_DOUBLE_EQ(0.0, c.getArea());
    EXPECT_DOUBLE_EQ(0.0, c.getFerence());
}

TEST(CircleTest, SmallRadiusTest) {
    Circle c(0.05);
    EXPECT_NEAR(0.00785, c.getArea(), 0.0001);
}

TEST(CircleTest, LargeRadiusTest) {
    Circle c(1e6);
    EXPECT_GT(c.getArea(), 1e12);
}

TEST(CircleTest, ConsistencyTest) {
    Circle c(20.0);
    double a1 = c.getArea();
    c.setArea(a1);
    EXPECT_NEAR(20.0, c.getRadius(), 0.0001);
}

TEST(CircleTest, NegativeRadiusTest) {
    Circle c(-1.0);
    EXPECT_LE(c.getRadius(), 0.0);
}


TEST(RopeTask, ResultIsPositive) {
    EXPECT_GT(Rope(), 0.0);
}

TEST(RopeTask, SpecificValueTest) {
    EXPECT_NEAR(0.159, Rope(), 0.001);
}

TEST(RopeTask, NotZeroTest) {
    EXPECT_NE(0.0, Rope());
}

TEST(RopeTask, LogicIndependence) {
    EXPECT_LT(Rope(), 1.0);
}


TEST(PoolTask, CostIsPositive) {
    EXPECT_GT(Pool(), 0.0);
}

TEST(PoolTask, ExpectedValueTest) {
    EXPECT_NEAR(72256.6, Pool(), 1.0);
}

TEST(PoolTask, MinimumCostTest) {
    EXPECT_GE(Pool(), 70000.0);
}

TEST(PoolTask, PrecisionTest) {
    double res1 = Pool();
    double res2 = Pool();
    EXPECT_DOUBLE_EQ(res1, res2);
}
