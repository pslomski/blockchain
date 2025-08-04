#pragma once

#include <cstdint>
#include <openssl/evp.h>
#include "Hash.hpp"

namespace hash
{
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
