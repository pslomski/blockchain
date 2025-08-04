#pragma once

#include <openssl/evp.h>
#include <string>
#include "hash/hash.hpp"

namespace block
{
class Block
{
public:
    Block(const int index, const hash::Data& data)
    {
        this->index = index;
        this->timestamp = 0;
        this->data = data;
        generateHash();
        this->nonce = 0;
    }
    hash::Hash& getHashBlock() { return hashBlock; }
    void generateHash()
    {
        [[maybe_unused]] hash::Hash hash;
        // std::string sdata{
        // std::to_string(index) + precedentHash + std::to_string(timestamp) + data + std::to_string(nonce)};
        // hash::hash((const hash::Data*)sdata.c_str(), sdata.size(), hash);
        // hashBlock = hash;
    }
    hash::Hash& getPrecedentHash() { return precedentHash; }
    void setPrecedentHash([[maybe_unused]] const hash::Hash& hash)
    {
        // precedentHash = hash;
    }

private:
    int index;
    int timestamp;
    hash::Data data;
    hash::Hash precedentHash;
    hash::Hash hashBlock;
    int nonce{};
};
} // namespace block
