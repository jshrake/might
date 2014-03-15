#include "gtest/gtest.h"
#include "might.hpp"

using namespace might;

TEST(ExpectationsTest, Basic) {
  expect(5).should(be_equal(5));
}
