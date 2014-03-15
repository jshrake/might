#include "gtest/gtest.h"
#include "might.hpp"

#include <memory>

using namespace might;

TEST(MatcherEqualTest, NumericLiterals) {
  expect(5).should(equal(5));
}

TEST(MatcherBeNull, UniquePtr) {
  auto i = std::make_unique<int>(1);
  expect(i).should_not(be_null());
  i.release();
  expect(i).should(be_null());
}

TEST(MatcherHaveLength, Basic) {
  std::vector<int> a = {1, 2, 3};
  expect(a).should(have_length(3));
}



