#include "gtest/gtest.h"
#include "might.hpp"

using namespace might;

TEST(MatcherEqualTest, NumericLiterals) {
  ASSERT_TRUE(expect(5).should(equal(5)));
}

TEST(MatcherHaveLength, Basic) {
  std::vector<int> a = {1, 2, 3};
  ASSERT_TRUE(expect(a).should(have_length(3)));
}
