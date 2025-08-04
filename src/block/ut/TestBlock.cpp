#include "block/Block.hpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace testing
{
TEST(Block, testBlock)
{
    // bchain::Block block{1, "foo"};
    // SHA256(10foo0) = 4577b714f94499fce0ae3472859851a6982dc90bd0c416c0159bc7848d8aab88
    // see https://emn178.github.io/online-tools/sha256.html
    // ASSERT_THAT(block.getHashBlock(), Eq("4577b714f94499fce0ae3472859851a6982dc90bd0c416c0159bc7848d8aab88"));
}
} // namespace testing
