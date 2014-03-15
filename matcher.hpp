#ifndef MIGHT_MATCHER_HPP_
#define MIGHT_MATCHER_HPP_

namespace might {


  template <class T>
  auto be_equal(T const & expectation) {
    return [&](auto const & actual) {
      return actual == expectation; 
    };
  }

} // namespace might

#endif
