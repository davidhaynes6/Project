#pragma once

namespace project::math {
  template <typename T>
  struct vec2 {
    T x = 0, y = 0;

    PROJECT_INLINE vec2(T x, T y) : x(x), y(y) {}
    PROJECT_INLINE vec2(T v) : x(v), y(v) {}
    PROJECT_INLINE vec2() = default;

    // operator (+)
    PROJECT_INLINE vec2<T> operator+(const vec2<T> &v2) const {
      return vec2<T>(this->x + v2.x, this->y + v2.y);
    }
    // operator (+=)
    PROJECT_INLINE vec2<T> &operator+=(const vec2<T> &v2) {
      this->x += v2.x;
      this->y += v2.y;
      return *this;
    }
    // operator (-)
    PROJECT_INLINE vec2<T> operator-(const vec2<T> &v2) const {
      return vec2<T>(x - v2.x, y - v2.y);
    }
    // operator (-=)
    PROJECT_INLINE vec2<T> &operator-=(const vec2<T> &v2) {
      this->x -= v2.x;
      this->y -= v2.y;
      return *this;
    }
    // operator (*)
    PROJECT_INLINE vec2<T> operator*(T s) const {
      return vec2<T>(x * s, y * s);
    }
    // operator (*=)
    PROJECT_INLINE vec2<T> &operator*=(T scalar) {
      this->x *= scalar;
      this->y *= scalar;
      return *this;
    }
  };
}

namespace project {
  using vec2u = math::vec2<uint32_t>;
  using vec2f = math::vec2<float>;
  using vec2i = math::vec2<int>;
}