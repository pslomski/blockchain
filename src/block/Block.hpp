#pragma once

#include <openssl/evp.h>
#include <string>
#include "hash/SHA256.hpp"

namespace bchain
{
using Hash = std::string;
using Data = std::string;

class Block
{
public:
    Block(const int index, const Data&& data)
    {
        this->index = index;
        this->timestamp = 0;
        this->data = data;
        generateHash();
        this->nonce = 0;
    }
    Hash getHashBlock() { return hashBlock; }
    void generateHash()
    {
        unsigned char md_value[EVP_MAX_MD_SIZE];
        hash::SHA256(
            (std::to_string(index) + precedentHash + std::to_string(timestamp) + data + std::to_string(nonce)).c_str(),
            md_value);
        // hashBlock = md_value;
    }
    Hash getPrecedentHash() { return precedentHash; }
    void setPrecedentHash(const Hash& hash) { precedentHash = hash; }

private:
    int index;
    int timestamp;
    Data data;
    Hash precedentHash;
    Hash hashBlock;
    int nonce{};
};
} // namespace bchain
