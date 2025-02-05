#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators_range.hpp>
#include <catch2/generators/catch_generators_random.hpp>

#include "Utils/variable_length_integer.h"

#include <limits>

TEST_CASE("vl-size") {
  // Check 8-bit minimum and maximum.
  CHECK(FEXCore::Utils::vl64::EncodedSize(-64) == 1);
  CHECK(FEXCore::Utils::vl64::EncodedSize(63) == 1);

  // Check 16-bit minimum and maximum.
  CHECK(FEXCore::Utils::vl64::EncodedSize(-8192) == 2);
  CHECK(FEXCore::Utils::vl64::EncodedSize(8191) == 2);

  // Check 32-bit minimum and maximum.
  CHECK(FEXCore::Utils::vl64::EncodedSize(std::numeric_limits<int32_t>::min()) == 5);
  CHECK(FEXCore::Utils::vl64::EncodedSize(std::numeric_limits<int32_t>::max()) == 5);

  // Check 64-bit minimum and maximum.
  CHECK(FEXCore::Utils::vl64::EncodedSize(std::numeric_limits<int64_t>::min()) == 9);
  CHECK(FEXCore::Utils::vl64::EncodedSize(std::numeric_limits<int64_t>::max()) == 9);
}

TEST_CASE("vl8 - in memory - encode") {
  uint8_t data[1];
  REQUIRE(FEXCore::Utils::vl64::Encode(data, 0) == 1);
  CHECK(data[0] == 0);

  REQUIRE(FEXCore::Utils::vl64::Encode(data, 63) == 1);
  CHECK(data[0] == 0b0011'1111);

  REQUIRE(FEXCore::Utils::vl64::Encode(data, -1) == 1);
  CHECK(data[0] == 0b0111'1111);

  REQUIRE(FEXCore::Utils::vl64::Encode(data, -64) == 1);
  CHECK(data[0] == 0b0100'0000);
}

TEST_CASE("vl16 - in memory - encode") {
  uint8_t data[2];

  REQUIRE(FEXCore::Utils::vl64::Encode(data, -65) == 2);
  CHECK(data[0] == 0b1011'1111);
  CHECK(data[1] == 0b1011'1111);

  REQUIRE(FEXCore::Utils::vl64::Encode(data, -66) == 2);
  CHECK(data[0] == 0b1011'1110);
  CHECK(data[1] == 0b1011'1111);

  REQUIRE(FEXCore::Utils::vl64::Encode(data, 64) == 2);
  CHECK(data[0] == 0b0100'0000);
  CHECK(data[1] == 0b1000'0000);

  REQUIRE(FEXCore::Utils::vl64::Encode(data, 8191) == 2);
  CHECK(data[0] == 0b1111'1111);
  CHECK(data[1] == 0b1001'1111);

  REQUIRE(FEXCore::Utils::vl64::Encode(data, -8192) == 2);
  CHECK(data[0] == 0b0000'0000);
  CHECK(data[1] == 0b1010'0000);
}

TEST_CASE("vl32 - in memory - encode") {
  uint8_t data[5];
  int32_t result {};

  REQUIRE(FEXCore::Utils::vl64::Encode(data, 8192) == 5);
  CHECK(data[0] == 0b1100'0000);
  memcpy(&result, &data[1], sizeof(int32_t));
  CHECK(result == 8192);

  REQUIRE(FEXCore::Utils::vl64::Encode(data, -8193) == 5);
  CHECK(data[0] == 0b1100'0000);
  memcpy(&result, &data[1], sizeof(int32_t));
  CHECK(result == -8193);

  REQUIRE(FEXCore::Utils::vl64::Encode(data, std::numeric_limits<int32_t>::min()) == 5);
  CHECK(data[0] == 0b1100'0000);
  memcpy(&result, &data[1], sizeof(int32_t));
  CHECK(result == std::numeric_limits<int32_t>::min());

  REQUIRE(FEXCore::Utils::vl64::Encode(data, std::numeric_limits<int32_t>::max()) == 5);
  CHECK(data[0] == 0b1100'0000);
  memcpy(&result, &data[1], sizeof(int32_t));
  CHECK(result == std::numeric_limits<int32_t>::max());
}

TEST_CASE("vl64 - in memory - encode") {
  uint8_t data[9];
  int64_t result {};

  REQUIRE(FEXCore::Utils::vl64::Encode(data, static_cast<int64_t>(std::numeric_limits<int32_t>::min()) - 1) == 9);
  CHECK(data[0] == 0b1110'0000);
  memcpy(&result, &data[1], sizeof(int64_t));
  CHECK(result == static_cast<int64_t>(std::numeric_limits<int32_t>::min()) - 1);

  REQUIRE(FEXCore::Utils::vl64::Encode(data, static_cast<int64_t>(std::numeric_limits<int32_t>::max()) + 1) == 9);
  CHECK(data[0] == 0b1110'0000);
  memcpy(&result, &data[1], sizeof(int64_t));
  CHECK(result == static_cast<int64_t>(std::numeric_limits<int32_t>::max()) + 1);

  REQUIRE(FEXCore::Utils::vl64::Encode(data, std::numeric_limits<int64_t>::min()) == 9);
  CHECK(data[0] == 0b1110'0000);
  memcpy(&result, &data[1], sizeof(int64_t));
  CHECK(result == std::numeric_limits<int64_t>::min());

  REQUIRE(FEXCore::Utils::vl64::Encode(data, std::numeric_limits<int64_t>::max()) == 9);
  CHECK(data[0] == 0b1110'0000);
  memcpy(&result, &data[1], sizeof(int64_t));
  CHECK(result == std::numeric_limits<int64_t>::max());
}
