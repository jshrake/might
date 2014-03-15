#ifndef MIGHT_MATCHER_HPP_
#define MIGHT_MATCHER_HPP_

#include <cstddef>
#include <sstream>

namespace might {
  template <class T>
  auto equal(T const & expected) {
    return [&](auto const & actual) {
      std::stringstream ss;
      ss << "Expected " << expected << ", got " << actual << ".";
      return std::make_tuple(actual == expected, ss.str()); 
    };
  }


  auto have_length(std::size_t const & expected) {
    return [&](auto const & container) {
      const auto actual = container.size();
      std::stringstream ss;
      ss << "Expected length " << expected << ", got " << actual << ".";
      return std::make_tuple(actual == expected, ss.str());
    };
  }

  auto be_null() {
    return [&](auto const & actual) {
      std::stringstream ss;
      const auto is_nullptr = actual == nullptr;
      ss << "Expected nullptr " << " got ";
      if (is_nullptr) {
        ss << "nullptr.";
      } else {
        ss << *actual << ".";
      }
      return std::make_tuple(is_nullptr, ss.str());
    };
  }

} // namespace might

#endif
