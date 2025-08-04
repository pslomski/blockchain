#pragma once

#include <cstdint>

namespace hash
{
constexpr uint8_t hashSize{32u};
using Data = uint8_t;
using Hash = Data[hashSize];
} // namespace hash
