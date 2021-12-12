#include "mpz/mpz_t.hpp"

#include <iostream>

int main() {

  std::cout << mpz_t<1024>(UINT64_C(0)).length() << std::endl;
  std::cout << (~mpz_t<1024>(1) + 1).length() << std::endl;
  std::cout << mpz_t<1024>(2).length() << std::endl;
  std::cout << (~mpz_t<1024>(4) + 1).length() << std::endl;
  std::cout << mpz_t<1024>(8).length() << std::endl;
  std::cout << (~mpz_t<1024>(UINT64_MAX) + 1).length() << std::endl;

  auto u32m = UINT32_MAX;
  auto u64m = UINT64_MAX;

  printf("\n==================== ~ ====================\n");

  printf("\n");
  mpz_t<1024>(0x0000000000000001).print();
  (~mpz_t<1024>(0x0000000000000001)).print();

  printf("\n");
  (mpz_t<1024>(0x0000000100000000) + mpz_t<1024>(0x0000000000000001)).print();
  (~(mpz_t<1024>(0x0000000100000000) + mpz_t<1024>(0x0000000000000001))).print();

  printf("\n");
  (~mpz_t<1024>(1) + 1).print();
  (~(~mpz_t<1024>(1) + 1)).print();

  printf("\n");
  (~mpz_t<1024>(0) + 1).print();
  (~(~mpz_t<1024>(0) + 1)).print();

  printf("\n==================== & ====================\n");

  printf("\n");
  mpz_t<1024>(u32m).print();
  (mpz_t<1024>(u32m) & mpz_t<1024>(u32m)).print();
  (mpz_t<1024>(u32m) & mpz_t<1024>(u32m) & mpz_t<1024>(u32m)).print();
  (mpz_t<1024>(u32m) & mpz_t<1024>(u32m) & mpz_t<1024>(u32m) & mpz_t<1024>(u32m)).print();
  (mpz_t<1024>(u32m) & mpz_t<1024>(u32m) & mpz_t<1024>(u32m) & mpz_t<1024>(u32m) & mpz_t<1024>(u32m)).print();
  (mpz_t<1024>(u32m) & mpz_t<1024>(u32m) & mpz_t<1024>(u32m) & mpz_t<1024>(u32m) & mpz_t<1024>(u32m)
      & mpz_t<1024>(u32m)).print();

  printf("\n");
  mpz_t<1024>(u64m).print();
  (mpz_t<1024>(u64m) & mpz_t<1024>(u64m)).print();
  (mpz_t<1024>(u64m) & mpz_t<1024>(u64m) & mpz_t<1024>(u64m)).print();
  (mpz_t<1024>(u64m) & mpz_t<1024>(u64m) & mpz_t<1024>(u64m) & mpz_t<1024>(u64m)).print();
  (mpz_t<1024>(u64m) & mpz_t<1024>(u64m) & mpz_t<1024>(u64m) & mpz_t<1024>(u64m) & mpz_t<1024>(u64m)).print();
  (mpz_t<1024>(u64m) & mpz_t<1024>(u64m) & mpz_t<1024>(u64m) & mpz_t<1024>(u64m) & mpz_t<1024>(u64m)
      & mpz_t<1024>(u64m)).print();

  printf("\n==================== + ====================\n");

  printf("\n");
  mpz_t<1024>(u32m).print();
  (mpz_t<1024>(u32m) + mpz_t<1024>(u32m)).print();
  (mpz_t<1024>(u32m) + mpz_t<1024>(u32m) + mpz_t<1024>(u32m)).print();
  (mpz_t<1024>(u32m) + mpz_t<1024>(u32m) + mpz_t<1024>(u32m) + mpz_t<1024>(u32m)).print();
  (mpz_t<1024>(u32m) + mpz_t<1024>(u32m) + mpz_t<1024>(u32m) + mpz_t<1024>(u32m) + mpz_t<1024>(u32m)).print();
  (mpz_t<1024>(u32m) + mpz_t<1024>(u32m) + mpz_t<1024>(u32m) + mpz_t<1024>(u32m) + mpz_t<1024>(u32m)
      + mpz_t<1024>(u32m)).print();

  printf("\n");
  mpz_t<1024>(u64m).print();
  (mpz_t<1024>(u64m) + mpz_t<1024>(u64m)).print();
  (mpz_t<1024>(u64m) + mpz_t<1024>(u64m) + mpz_t<1024>(u64m)).print();
  (mpz_t<1024>(u64m) + mpz_t<1024>(u64m) + mpz_t<1024>(u64m) + mpz_t<1024>(u64m)).print();
  (mpz_t<1024>(u64m) + mpz_t<1024>(u64m) + mpz_t<1024>(u64m) + mpz_t<1024>(u64m) + mpz_t<1024>(u64m)).print();
  (mpz_t<1024>(u64m) + mpz_t<1024>(u64m) + mpz_t<1024>(u64m) + mpz_t<1024>(u64m) + mpz_t<1024>(u64m)
      + mpz_t<1024>(u64m)).print();

  printf("\n==================== - ====================\n");

  printf("\n");
  mpz_t<1024>(u32m).print();
  (mpz_t<1024>(u32m) - mpz_t<1024>(u32m)).print();
  ((mpz_t<1024>(u32m) + mpz_t<1024>(u32m)) - (mpz_t<1024>(u32m) + mpz_t<1024>(u32m))).print();
  ((mpz_t<1024>(u32m) + mpz_t<1024>(u32m) + mpz_t<1024>(u32m)) - (mpz_t<1024>(u32m) + mpz_t<1024>(u32m))
      + mpz_t<1024>(u32m)).print();
  (mpz_t<1024>(u32m) + mpz_t<1024>(u32m) + mpz_t<1024>(u32m) - mpz_t<1024>(u32m) - mpz_t<1024>(u32m)
      - mpz_t<1024>(u32m)).print();

  printf("\n");
  mpz_t<1024>(u64m).print();
  (mpz_t<1024>(u64m) - mpz_t<1024>(u64m)).print();
  ((mpz_t<1024>(u64m) + mpz_t<1024>(u64m)) - (mpz_t<1024>(u64m) + mpz_t<1024>(u64m))).print();
  ((mpz_t<1024>(u64m) + mpz_t<1024>(u64m) + mpz_t<1024>(u64m)) - (mpz_t<1024>(u64m) + mpz_t<1024>(u64m))
      + mpz_t<1024>(u64m)).print();
  (mpz_t<1024>(u64m) + mpz_t<1024>(u64m) + mpz_t<1024>(u64m) - mpz_t<1024>(u64m) - mpz_t<1024>(u64m)
      - mpz_t<1024>(u64m)).print();

  printf("\n==================== >= ====================\n");

  printf("\n");
  printf("2 >= -2, %d\n", mpz_t<1024>(2) >= (~mpz_t<1024>(2) + 1)); // 2 >= -2, 1
  printf("-3 >= 2, %d\n", (~mpz_t<1024>(3) + 1) >= mpz_t<1024>(2)); // -3 >= 2, 0

  printf("\n");
  printf("2 >= 2, %d\n", mpz_t<1024>(2) >= mpz_t<1024>(2));   // 2 >= 2, 1
  printf("3 >= 2, %d\n", mpz_t<1024>(3) >= mpz_t<1024>(2));   // 3 >= 2, 1
  printf("2 >= 3, %d\n", mpz_t<1024>(2) >= mpz_t<1024>(3));   // 2 >= 3, 0

  printf("\n");
  printf("-2 >= -2, %d\n", (~mpz_t<1024>(2) + 1) >= (~mpz_t<1024>(2) + 1)); // -2 >= -2, 1
  printf("-3 >= -2, %d\n", (~mpz_t<1024>(3) + 1) >= (~mpz_t<1024>(2) + 1)); // -3 >= -2, 0
  printf("-2 >= -3, %d\n", (~mpz_t<1024>(2) + 1) >= (~mpz_t<1024>(3) + 1)); // -2 >= -3, 1

  printf("\n");
  printf("UINT64_MAX >= -UINT64_MAX, %d\n", mpz_t<1024>(UINT64_MAX) >= (~mpz_t<1024>(UINT64_MAX) + 1));  // 2 >= -2, 1
  printf("-UINT64_MAX >= UINT64_MAX, %d\n", (~mpz_t<1024>(UINT64_MAX) + 1) >= mpz_t<1024>(UINT64_MAX));   // -3 >= 2, 0

  printf("\n");
  printf("UINT32_MAX >= UINT32_MAX, %d\n", mpz_t<1024>(UINT32_MAX) >= mpz_t<1024>(UINT32_MAX));   // 2 >= 2, 1
  printf("UINT64_MAX >= UINT32_MAX, %d\n", mpz_t<1024>(UINT64_MAX) >= mpz_t<1024>(UINT32_MAX));   // 3 >= 2, 1
  printf("UINT32_MAX >= UINT64_MAX, %d\n", mpz_t<1024>(UINT32_MAX) >= mpz_t<1024>(UINT64_MAX));   // 2 >= 3, 0

  printf("\n");
  printf("-UINT32_MAX >= -UINT32_MAX, %d\n",
         (~mpz_t<1024>(UINT32_MAX) + 1) >= (~mpz_t<1024>(UINT32_MAX) + 1)); // -2 >= -2, 1
  printf("-UINT64_MAX >= -UINT32_MAX, %d\n",
         (~mpz_t<1024>(UINT64_MAX) + 1) >= (~mpz_t<1024>(UINT32_MAX) + 1)); // -3 >= -2, 0
  printf("-UINT32_MAX >= -UINT64_MAX, %d\n",
         (~mpz_t<1024>(UINT32_MAX) + 1) >= (~mpz_t<1024>(UINT64_MAX) + 1)); // -2 >= -3, 1

  printf("\n==================== <= ====================\n");

  printf("\n");
  printf("2 <= -2, %d\n", mpz_t<1024>(2) <= (~mpz_t<1024>(2) + 1)); // 2 <= -2, 0
  printf("-3 <= 2, %d\n", (~mpz_t<1024>(3) + 1) <= mpz_t<1024>(2)); // -3 <= 2, 1

  printf("\n");
  printf("2 <= 2, %d\n", mpz_t<1024>(2) <= mpz_t<1024>(2));   // 2 <= 2, 1
  printf("3 <= 2, %d\n", mpz_t<1024>(3) <= mpz_t<1024>(2));   // 3 <= 2, 0
  printf("2 <= 3, %d\n", mpz_t<1024>(2) <= mpz_t<1024>(3));   // 2 <= 3, 1

  printf("\n");
  printf("-2 <= -2, %d\n", (~mpz_t<1024>(2) + 1) <= (~mpz_t<1024>(2) + 1)); // -2 <= -2, 1
  printf("-3 <= -2, %d\n", (~mpz_t<1024>(3) + 1) <= (~mpz_t<1024>(2) + 1)); // -3 <= -2, 1
  printf("-2 <= -3, %d\n", (~mpz_t<1024>(2) + 1) <= (~mpz_t<1024>(3) + 1)); // -2 <= -3, 0

  printf("\n");
  printf("UINT64_MAX <= -UINT64_MAX, %d\n", mpz_t<1024>(UINT64_MAX) <= (~mpz_t<1024>(UINT64_MAX) + 1));  // 2 <= -2, 0
  printf("-UINT64_MAX <= UINT64_MAX, %d\n", (~mpz_t<1024>(UINT64_MAX) + 1) <= mpz_t<1024>(UINT64_MAX));   // -3 <= 2, 1

  printf("\n");
  printf("UINT32_MAX <= UINT32_MAX, %d\n", mpz_t<1024>(UINT32_MAX) <= mpz_t<1024>(UINT32_MAX));   // 2 <= 2, 1
  printf("UINT64_MAX <= UINT32_MAX, %d\n", mpz_t<1024>(UINT64_MAX) <= mpz_t<1024>(UINT32_MAX));   // 3 <= 2, 0
  printf("UINT32_MAX <= UINT64_MAX, %d\n", mpz_t<1024>(UINT32_MAX) <= mpz_t<1024>(UINT64_MAX));   // 2 <= 3, 1

  printf("\n");
  printf("-UINT32_MAX <= -UINT32_MAX, %d\n",
         (~mpz_t<1024>(UINT32_MAX) + 1) <= (~mpz_t<1024>(UINT32_MAX) + 1)); // -2 <= -2, 1
  printf("-UINT64_MAX <= -UINT32_MAX, %d\n",
         (~mpz_t<1024>(UINT64_MAX) + 1) <= (~mpz_t<1024>(UINT32_MAX) + 1)); // -3 <= -2, 1
  printf("-UINT32_MAX <= -UINT64_MAX, %d\n",
         (~mpz_t<1024>(UINT32_MAX) + 1) <= (~mpz_t<1024>(UINT64_MAX) + 1)); // -2 <= -3, 0

  printf("\n==================== * ====================\n");

  printf("\n");
  mpz_t<1024>(2).print();
  (mpz_t<1024>(2) * mpz_t<1024>(2)).print();
  (mpz_t<1024>(UINT8_MAX) * mpz_t<1024>(UINT8_MAX)).print();
  (mpz_t<1024>(UINT16_MAX) * mpz_t<1024>(UINT16_MAX)).print();
  (mpz_t<1024>(UINT32_MAX) * mpz_t<1024>(UINT32_MAX)).print();
  (mpz_t<1024>(UINT64_MAX) * mpz_t<1024>(UINT64_MAX)).print();
  (mpz_t<1024>(UINT64_MAX) * mpz_t<1024>(UINT64_MAX) * mpz_t<1024>(UINT64_MAX)).print();

  printf("\n==================== / ====================\n");

  printf("\n");
  (mpz_t<1024>(4) / mpz_t<1024>(2)).print();
  (mpz_t<1024>(8) / mpz_t<1024>(2)).print();
  (mpz_t<1024>(UINT8_MAX) / mpz_t<1024>(8)).print();
  (mpz_t<1024>(UINT8_MAX / 8)).print('\n');

  (mpz_t<1024>(UINT16_MAX) / mpz_t<1024>(UINT8_MAX)).print();
  mpz_t<1024>(UINT16_MAX / UINT8_MAX).print('\n');

  (mpz_t<1024>(UINT32_MAX) / mpz_t<1024>(UINT8_MAX)).print();
  mpz_t<1024>(UINT32_MAX / UINT8_MAX).print('\n');

  (mpz_t<1024>(UINT64_MAX) / mpz_t<1024>(UINT8_MAX)).print();
  mpz_t<1024>(UINT64_MAX / UINT8_MAX).print('\n');

  ((mpz_t<1024>(UINT64_MAX) * mpz_t<1024>(UINT64_MAX)) / mpz_t<1024>(UINT8_MAX)).print();

  printf("\n==================== %% ====================\n");

  printf("\n");
  (mpz_t<1024>(4) % mpz_t<1024>(2)).print();
  (mpz_t<1024>(8) % mpz_t<1024>(2)).print();

  (mpz_t<1024>(UINT8_MAX) % mpz_t<1024>(8)).print();
  (mpz_t<1024>(UINT8_MAX % 8)).print('\n');

  (mpz_t<1024>(UINT16_MAX) % mpz_t<1024>(UINT8_MAX) + 19).print();
  mpz_t<1024>(UINT16_MAX % UINT8_MAX + 19).print('\n');

  (mpz_t<1024>(UINT32_MAX) % mpz_t<1024>(UINT8_MAX) + 19).print();
  mpz_t<1024>(UINT32_MAX % UINT8_MAX + 19).print('\n');

  (mpz_t<1024>(UINT64_MAX) % mpz_t<1024>(UINT8_MAX) + 19).print();
  mpz_t<1024>(UINT64_MAX % UINT8_MAX + 19).print('\n');

  ((mpz_t<1024>(UINT64_MAX) * mpz_t<1024>(UINT64_MAX)) % mpz_t<1024>(UINT8_MAX)).print();

  return 0;
}
