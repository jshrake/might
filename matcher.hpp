#ifndef MIGHT_MATCHER_HPP_
#define MIGHT_MATCHER_HPP_

#include <cstdlib>

namespace might {
  template <class T>
  auto equal(T const & expectation) {
    return [&](auto const & actual) {
      return actual == expectation; 
    };
  }


  auto have_length(std::size_t const & expected) {
    return [&](auto const & container) {
      return container.size() == expected;
    };
  }

} // namespace might

#endif
