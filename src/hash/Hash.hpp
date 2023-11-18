#pragma once

#include <cstdint>
#include <openssl/evp.h>

namespace hash
{
constexpr uint8_t hashSize{32u};
using Data = uint8_t;
using Hash = Data[hashSize];

class HashCalculator
{
public:
    HashCalculator();
    ~HashCalculator();
    void update(const Data* data, const size_t size);
    void hash(Hash hash);

private:
    EVP_MD_CTX* mdctx;
};
} // namespace hash
