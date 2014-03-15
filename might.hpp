#ifndef MIGHT_EXPECTATIONS_HPP_
#define MIGHT_EXPECTATIONS_HPP_

#include "matcher.hpp"

namespace might {
  template <class T>
  class Actual {
      const T actual_;

      template <class MatcherFunc>
      bool match(MatcherFunc const & matcher, const bool desire) const {
        return desire == matcher(actual_);
      }

    public:
      Actual(T actual) : actual_{actual} {}

      template <class MatcherFunc>
      bool should(MatcherFunc const & matcher) {
        return match(matcher, true);
      }

      template <class MatcherFunc>
      bool should_not(MatcherFunc const & matcher) {
        return match(matcher, false);
      }

      template <class MatcherFunc>
      bool to(MatcherFunc const & matcher) {
        return match(matcher, true);
      }

      template <class MatcherFunc>
      bool to_not(MatcherFunc const & matcher) {
        return match(matcher, false);
      }

      template <class MatcherFunc>
      bool not_to(MatcherFunc const & matcher) {
        return match(matcher, false);
      }
  };

  template <class T>
  Actual<T> expect(T actual) {
    return Actual<T>{actual};
  }
  

}

#endif
