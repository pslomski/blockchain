#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <sstream>
#include <string>
#include "hash/Hash.hpp"

namespace
{
std::string to_string(const uint8_t* md_value, const size_t size)
{
    std::stringstream sha{};
    sha << std::setbase(16) << std::noshowbase;
    for (auto i = 0; i < size; i++)
    {
        sha << static_cast<uint32_t>(md_value[i]);
    }
    return sha.str();
}
} // namespace

namespace testing
{
TEST(Hash, testHashType)
{
    hash::Hash hash;
    ASSERT_THAT(sizeof(hash), Eq(hash::hashSize));
    ASSERT_THAT(hash::hashSize, Eq(256 / 8));
}

TEST(Hash, testHashCalculator)
{
    hash::HashCalculator calc;
    hash::Data data[1]{'0'};
    calc.update(data, sizeof(data));
    hash::Hash hash;
    calc.hash(hash);
    ASSERT_THAT(
        to_string(hash, hash::hashSize), Eq("5feceb66ffc86f38d952786c6d696c79c2dbc239dd4e91b46729d73a27fb57e9"));
}
} // namespace testing
