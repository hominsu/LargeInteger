//
// Created by Homin Su on 2021/12/1.
//

#ifndef SGMP_MPZ_MPZ_T_HPP_
#define SGMP_MPZ_MPZ_T_HPP_

#include <cstdio>
#include <cstdint>

#include <vector>
#include <string>

template<size_t Len>
class mpz_t;

template<size_t Len>
mpz_t<Len> operator~(const mpz_t<Len> &_a);

template<size_t Len>
mpz_t<Len> operator&(const mpz_t<Len> &_a, const mpz_t<Len> &_b);

template<size_t Len>
mpz_t<Len> operator&(mpz_t<Len> &&_a, const mpz_t<Len> &_b);

template<size_t Len>
mpz_t<Len> operator+(const mpz_t<Len> &_a, const mpz_t<Len> &_b);

template<size_t Len>
mpz_t<Len> operator+(mpz_t<Len> &&_a, const mpz_t<Len> &_b);

template<size_t Len>
mpz_t<Len> operator*(const mpz_t<Len> &_a, const mpz_t<Len> &_b);

template<size_t Len>
mpz_t<Len> operator/(const mpz_t<Len> &_a, const mpz_t<Len> &_b);

template<size_t Len>
mpz_t<Len> operator%(const mpz_t<Len> &_a, const mpz_t<Len> &_b);

template<size_t Len>
class mpz_t {
 private:
  std::vector<uint32_t> unit_;
  const size_t num_ = Len % 32 ? Len / 32 + 1 : Len / 32;

  mpz_t();

 public:
  /**
   * @brief 使用一个 uint64_t 初始化大整数
   * @param _num
   */
  explicit mpz_t(uint64_t _num);

  explicit mpz_t(const std::string &_str);

  mpz_t(mpz_t<Len> &&_mpz_t) noexcept;

  mpz_t(const mpz_t<Len> &_mpz_t);

  [[nodiscard]] size_t num() const;

  void print(char end = ' ') const;

  void max();

  void min();

  [[nodiscard]] uint8_t get_sign() const;

  static mpz_t<Len> positive(const mpz_t<Len> &_a);

  bool equal(const mpz_t<Len> &_mpz_t) const;

  bool equal(uint64_t _a);

  void swap(mpz_t<Len> &_mpz_t);

  [[nodiscard]] size_t length() const;

  bool operator>=(const mpz_t<Len> &_b) const;

  template<typename Tint, class = typename std::enable_if_t<std::is_integral_v<std::remove_reference_t<Tint>>>>
  inline bool operator>=(Tint &&_b) const {
    return *this >= mpz_t<Len>(std::forward<Tint>(_b));
  }

  bool operator<=(const mpz_t<Len> &_b) const;

  template<typename Tint, class = typename std::enable_if_t<std::is_integral_v<std::remove_reference_t<Tint>>>>
  inline bool operator<=(Tint &&_b) const {
    return *this <= mpz_t<Len>(std::forward<Tint>(_b));
  }

  bool operator<(const mpz_t<Len> &_b) const;

  template<typename Tint, class = typename std::enable_if_t<std::is_integral_v<std::remove_reference_t<Tint>>>>
  inline bool operator<(Tint &&_b) const {
    return *this < mpz_t<Len>(std::forward<Tint>(_b));
  }

  bool operator>(const mpz_t<Len> &_b) const;

  template<typename Tint, class = typename std::enable_if_t<std::is_integral_v<std::remove_reference_t<Tint>>>>
  inline bool operator>(Tint &&_b) const {
    return *this > mpz_t<Len>(std::forward<Tint>(_b));
  }

  bool operator==(const mpz_t<Len> &_b) const;

  template<typename Tint, class = typename std::enable_if_t<std::is_integral_v<std::remove_reference_t<Tint>>>>
  inline bool operator==(Tint &&_b) const {
    return *this == mpz_t<Len>(std::forward<Tint>(_b));
  }

  bool operator!=(const mpz_t<Len> &_b) const;

  template<typename Tint, class = typename std::enable_if_t<std::is_integral_v<std::remove_reference_t<Tint>>>>
  inline bool operator!=(Tint &&_b) const {
    return *this != mpz_t<Len>(std::forward<Tint>(_b));
  }

  mpz_t<Len> &operator=(const mpz_t<Len> &_mpz_t);

  mpz_t<Len> &operator=(mpz_t<Len> &&_mpz_t) noexcept;

  template<typename Tint, class = typename std::enable_if_t<std::is_integral_v<std::remove_reference_t<Tint>>>>
  mpz_t<Len> &operator=(Tint &&_a) noexcept {
    unit_ = std::move(mpz_t<Len>(std::forward<Tint>(_a)).unit_);
    return *this;
  }

  mpz_t<Len> &operator<<=(int64_t _n);

  mpz_t<Len> &operator<<=(const mpz_t<Len> &_n);

  template<typename Tint, class = typename std::enable_if_t<std::is_integral_v<std::remove_reference_t<Tint>>>>
  inline mpz_t<Len> &operator<<(Tint &&_n) {
    *this <<= std::forward<Tint>(_n);
    return *this;
  }

  mpz_t<Len> &operator<<(const mpz_t<Len> &_n);

  mpz_t<Len> &operator>>=(int64_t _n);

  mpz_t<Len> &operator>>=(const mpz_t<Len> &_n);

  template<typename Tint, class = typename std::enable_if_t<std::is_integral_v<std::remove_reference_t<Tint>>>>
  inline mpz_t<Len> &operator>>(Tint &&_n) {
    *this >>= std::forward<Tint>(_n);
    return *this;
  }

  mpz_t<Len> &operator>>(const mpz_t<Len> &_n);

  friend mpz_t<Len> operator~<>(const mpz_t<Len> &_a);

  friend mpz_t<Len> operator&<>(const mpz_t<Len> &_a, const mpz_t<Len> &_b);

  friend mpz_t<Len> operator&<>(mpz_t<Len> &&_a, const mpz_t<Len> &_b);

  template<typename Tint, class = typename std::enable_if_t<std::is_integral_v<std::remove_reference_t<Tint>>>>
  friend inline mpz_t<Len> operator&(const mpz_t<Len> &_a, Tint &&_b) {
    return _a & mpz_t<Len>(std::forward<Tint>(_b));
  }

  template<typename Tint, class = typename std::enable_if_t<std::is_integral_v<std::remove_reference_t<Tint>>>>
  friend inline mpz_t<Len> operator&(Tint &&_a, const mpz_t<Len> &&_b) {
    return mpz_t<Len>(std::forward<Tint>(_a)) & _b;
  }

  friend mpz_t<Len> operator+<>(const mpz_t<Len> &_a, const mpz_t<Len> &_b);

  friend mpz_t<Len> operator+<>(mpz_t<Len> &&_a, const mpz_t<Len> &_b);

  template<typename Tint, class = typename std::enable_if_t<std::is_integral_v<std::remove_reference_t<Tint>>>>
  inline mpz_t<Len> operator+(Tint &&_b) {
    return *this + mpz_t<Len>(std::forward<Tint>(_b));
  }

  friend inline mpz_t<Len> operator-(const mpz_t<Len> &_a, const mpz_t<Len> &_b) {
    return _a + (~_b + 1);
  }

  template<typename Tint, class = typename std::enable_if_t<std::is_integral_v<std::remove_reference_t<Tint>>>>
  inline mpz_t<Len> operator-(Tint &&_b) {
    return *this + (~std::forward<Tint>(_b) + 1);
  }

  friend mpz_t<Len> operator*<>(const mpz_t<Len> &_a, const mpz_t<Len> &_b);

  template<typename Tint, class = typename std::enable_if_t<std::is_integral_v<std::remove_reference_t<Tint>>>>
  inline mpz_t<Len> operator*(Tint &&_b) {
    return *this * mpz_t<Len>(std::forward<Tint>(_b));
  }

  mpz_t<Len> slow_divide(const mpz_t<Len> &_a, const mpz_t<Len> &_b);

  friend mpz_t<Len> operator/<>(const mpz_t<Len> &_a, const mpz_t<Len> &_b);

  template<typename Tint, class = typename std::enable_if_t<std::is_integral_v<std::remove_reference_t<Tint>>>>
  inline mpz_t<Len> operator/(Tint &&_b) {
    return *this / mpz_t<Len>(std::forward<Tint>(_b));
  }

  friend mpz_t<Len> operator%<>(const mpz_t<Len> &_a, const mpz_t<Len> &_b);

  template<typename Tint, class = typename std::enable_if_t<std::is_integral_v<std::remove_reference_t<Tint>>>>
  inline mpz_t<Len> operator%(Tint &&_b) {
    return *this % mpz_t<Len>(std::forward<Tint>(_b));
  }
};

#define MPZ
#include "mpz_t.cc"

#endif //SGMP_MPZ_MPZ_T_HPP_
