//
// Created by Homin Su on 2021/12/11.
//

#ifdef MPZ

namespace {
template<size_t Len>
constexpr mpz_t<Len> kMagicN_0xCCCCCCCD = mpz_t<Len>(0xCCCCCCCD);
} // namespace

template<size_t Len>
mpz_t<Len>::mpz_t() {
  unit_.resize(num_);
}

template<size_t Len>
mpz_t<Len>::mpz_t(uint64_t _num) {
  unit_.resize(num_);
  unit_[0] = _num & 0xFFFFFFFF;
  if (_num >> 32) {
    unit_[1] = _num >> 32;
  }
}

template<size_t Len>
mpz_t<Len>::mpz_t(const std::string &_str) {
  unit_.resize(num_);
  unit_.emplace_back(0x0);
}

template<size_t Len>
mpz_t<Len>::mpz_t(mpz_t<Len> &&_mpz_t) noexcept {
  unit_ = std::move(_mpz_t.unit_);
}

template<size_t Len>
mpz_t<Len>::mpz_t(const mpz_t<Len> &_mpz_t) {
  unit_ = _mpz_t.unit_;
}

template<size_t Len>
inline size_t mpz_t<Len>::num() const {
  return num_;
}

template<size_t Len>
void mpz_t<Len>::print(char end) const {
  for (auto it = unit_.end() - 1; it != unit_.begin() - 1; --it) {
    printf("%u ", *it);
  }
  printf("%c\n", end);
}

template<size_t Len>
void mpz_t<Len>::max() {
  for (auto &it: unit_) {
    it = UINT32_MAX;
  }
  *(unit_.end() - 1) = INT32_MAX;
}

template<size_t Len>
inline void mpz_t<Len>::min() {
  this->max();
  ~(*this);  // (~*this + 1) -1
}

template<size_t Len>
inline uint8_t mpz_t<Len>::get_sign() const {
  return *(unit_.end() - 1) >> 31;
}

template<size_t Len>
inline mpz_t<Len> mpz_t<Len>::positive(const mpz_t<Len> &_a) {
  return (_a.get_sign() & 0x1) ? (~_a + 0x1) : _a;
}

template<size_t Len>
bool mpz_t<Len>::equal(const mpz_t<Len> &_mpz_t) const {
  auto ptr = unit_.begin();
  for (auto &it: _mpz_t.unit_) {
    if (it != *ptr++) {
      return false;
    }
  }
  return true;
}

template<size_t Len>
inline bool mpz_t<Len>::equal(uint64_t _a) {
  return equal(mpz_t<Len>(_a));
}

template<size_t Len>
inline void mpz_t<Len>::swap(mpz_t<Len> &_mpz_t) {
  unit_.swap(_mpz_t);
}

template<size_t Len>
size_t mpz_t<Len>::length() const {
  auto tmp = positive(*this);

  //  std::reverse();
  if (tmp.unit_.empty()) {
    throw std::runtime_error("mpz_struct container is empty");
  }

  size_t length = 0;

  for (auto &it: tmp.unit_) {
    for (int i = 31; i >= 0; --i) {
      if ((it & 0xffffffff) >> i == 0x1) {
        length += i + 1;
        break;
      }
    }
  }

  return length;
}

template<size_t Len>
inline bool mpz_t<Len>::operator>=(const mpz_t<Len> &_b) const {
  uint8_t a_sign = (*this).get_sign();
  uint8_t b_sign = _b.get_sign();

  if ((a_sign ^ b_sign) != 0) {
    return (b_sign & 0x1) != 0;
  } else {
    return (*this - _b).get_sign() == 0;
  }
}

template<size_t Len>
inline bool mpz_t<Len>::operator<=(const mpz_t<Len> &_b) const {
  uint8_t a_sign = (*this).get_sign();
  uint8_t b_sign = _b.get_sign();

  if ((a_sign ^ b_sign) != 0) {
    return (a_sign & 0x1) != 0;
  } else {
    return (_b - *this).get_sign() == 0;
  }
}

template<size_t Len>
inline bool mpz_t<Len>::operator<(const mpz_t<Len> &_b) const {
  return *this >= _b ? 0 : 1;
}

template<size_t Len>
inline bool mpz_t<Len>::operator>(const mpz_t<Len> &_b) const {
  return *this <= _b ? 0 : 1;
}

template<size_t Len>
bool mpz_t<Len>::operator==(const mpz_t<Len> &_b) const {
  return *this >= _b && *this <= _b;
}

template<size_t Len>
bool mpz_t<Len>::operator!=(const mpz_t<Len> &_b) const {
  return *this > _b || *this < _b;
}

template<size_t Len>
inline mpz_t<Len> &mpz_t<Len>::operator=(const mpz_t<Len> &_mpz_t) {
  unit_ = _mpz_t.unit_;
  return *this;
}

template<size_t Len>
inline mpz_t<Len> &mpz_t<Len>::operator=(mpz_t<Len> &&_mpz_t) noexcept {
  unit_ = std::move(_mpz_t.unit_);
  return *this;
}

template<size_t Len>
mpz_t<Len> &mpz_t<Len>::operator<<=(int64_t _n) {
  while (_n > 0) {
    if (_n <= 32) {
      uint32_t tmp, c = 0;
      for (auto &it: unit_) {
        tmp = it >> (32 - _n);
        it <<= _n;
        it |= c;
        c = tmp;
      }
    }
    _n -= 32;
  }
  return *this;
}

template<size_t Len>
mpz_t<Len> &mpz_t<Len>::operator<<=(const mpz_t<Len> &_n) {
  if (_n > Len) {
    memset(unit_.data(), 0, Len / 8);
  } else {
    *this <<= unit_[0];
  }
  return *this;
}

template<size_t Len>
mpz_t<Len> &mpz_t<Len>::operator<<(const mpz_t<Len> &_n) {
  return *this <<= _n;
}

template<size_t Len>
mpz_t<Len> &mpz_t<Len>::operator>>=(int64_t _n) {
  while (_n > 0) {
    if (_n <= 32) {
      uint32_t tmp;
      auto end = unit_.end();
      for (auto it = unit_.begin(); it != end; ++it) {
        tmp = it + 1 != end ? *(it + 1) << (32 - _n) : 0;
        *it >>= _n;
        *it |= tmp;
      }
    }
    _n -= 32;
  }
  return *this;
}

template<size_t Len>
mpz_t<Len> &mpz_t<Len>::operator>>=(const mpz_t<Len> &_n) {
  if (_n > Len) {
    memset(unit_.data(), 0, Len / 8);
  } else {
    *this >>= unit_[0];
  }
  return *this;
}

template<size_t Len>
mpz_t<Len> &mpz_t<Len>::operator>>(const mpz_t<Len> &_n) {
  return *this >>= _n;
}

template<size_t Len>
mpz_t<Len> operator~(const mpz_t<Len> &_a) {
  mpz_t<Len> ret;

  auto ret_it = ret.unit_.begin();
  for (auto &it: _a.unit_) {
    *ret_it++ = ~it;
  }

  return ret;
}

template<size_t Len>
mpz_t<Len> operator&(const mpz_t<Len> &_a, const mpz_t<Len> &_b) {
  mpz_t<Len> ret;

  auto it_a = _a.unit_.begin();
  auto it_b = _b.unit_.begin();
  auto it_ret = ret.unit_.begin();

  for (int i = 0; i < _a.num_; ++i) {
    *it_ret++ = *it_a++ & *it_b++;
  }

  return ret;
}

template<size_t Len>
mpz_t<Len> operator&(mpz_t<Len> &&_a, const mpz_t<Len> &_b) {
  mpz_t<Len> ret = std::move(_a);

  auto it_b = _b.unit_.begin();

  for (int i = 0; i < ret.num_; ++i) {
    ret.unit_[i] &= it_b[i];
  }

  return ret;
}

template<size_t Len>
mpz_t<Len> operator+(const mpz_t<Len> &_a, const mpz_t<Len> &_b) {
  mpz_t<Len> ret;

  auto it_a = _a.unit_.begin();
  auto it_b = _b.unit_.begin();

  uint8_t c = 0;
  uint64_t result;
  for (int i = 0; i < _a.num_; ++i) {
    result = static_cast<uint64_t>(it_a[i]) + static_cast<uint64_t>(it_b[i]) + c;
    ret.unit_[i] = (result & 0xffffffff); // 取低 32 位
    c = result >> 32;  // 进位
  }

  return ret;
}

template<size_t Len>
mpz_t<Len> operator+(mpz_t<Len> &&_a, const mpz_t<Len> &_b) {
  mpz_t<Len> ret = std::move(_a);

  auto it_b = _b.unit_.begin();

  uint8_t c = 0;
  uint64_t result;
  for (int i = 0; i < _a.num_; ++i) {
    result = static_cast<uint64_t>(ret.unit_[i]) + static_cast<uint64_t>(it_b[i]) + c;
    ret.unit_[i] = (result & 0xffffffff); // 取低 32 位
    c = result >> 32;  // 进位
  }

  return ret;
}

template<size_t Len>
mpz_t<Len> operator*(const mpz_t<Len> &_a, const mpz_t<Len> &_b) {
  bool flag = (_a.get_sign() ^ _b.get_sign()) ? 1 : 0;

  mpz_t<Len> a = mpz_t<Len>::positive(_a);
  mpz_t<Len> b = mpz_t<Len>::positive(_b);

  mpz_t<Len> ret(0);
  if ((b & (b - 1)) == 0) { // 2 的幂方直接移位
    ret = a << (b.length() - 1);
  } else {
    while (b != 0) {
      if ((b & 1) != 0) {
        ret = ret + a;
      }
      a <<= 1;
      b >>= 1;
    }
  }

  return flag ? (~ret + 1) : ret;
}

template<size_t Len>
mpz_t<Len> mpz_t<Len>::slow_divide(const mpz_t<Len> &_a, const mpz_t<Len> &_b) {
  mpz_t<Len> a = _a;
  mpz_t<Len> ret(0);
  while (a >= _b) {
    ret = ret + 1;
    a = a - _b;
  }
  return ret;
}

template<size_t Len>
mpz_t<Len> operator/(const mpz_t<Len> &_a, const mpz_t<Len> &_b) {
  if (mpz_t<Len>(_b) == 0) {
    throw std::runtime_error("divided zero");
  }

  bool flag = (_a.get_sign() ^ _b.get_sign()) ? 1 : 0;

  mpz_t<Len> a = mpz_t<Len>::positive(_a);
  mpz_t<Len> b = mpz_t<Len>::positive(_b);

  auto a_length = _a.length();
  auto b_length = _b.length();

  if (b_length > a_length) {
    return mpz_t<Len>(0);
  }

  mpz_t<Len> ret(0);
  if ((b & (b - 1)) == 0) {
    ret = a >> (b_length - 1);
  } else {
    while (a >= b) {
      mpz_t<Len> weight(1);
      mpz_t<Len> tmp = b;
      while (tmp + tmp <= a) {
        weight = weight + weight;
        tmp = tmp + tmp;
      }
      a = a - tmp;
      ret = ret + weight;
    }
//    for (int i = Len; i >= 0; i--) {
//      if ((a >> i) >= b) {
//        a = a - (b << i);
//        ret = ret + (1 << i);
//      }
//    }
  }

  return flag ? (~ret + 1) : ret;
}

template<size_t Len>
mpz_t<Len> operator%(const mpz_t<Len> &_a, const mpz_t<Len> &_b) {
  return _a - ((_a / _b) * _b);
}

#endif //MPZ
