#include "HashCalculator.hpp"
#include <cassert>
#include <cstdio>
#include <stdexcept>
#include "Hash.hpp"

namespace hash
{
HashCalculator::HashCalculator()
{
    OpenSSL_add_all_digests();
    const EVP_MD* md = EVP_get_digestbyname("SHA256");
    if (!md)
    {
        throw std::runtime_error("Unknown message digest SHA256");
    }
    mdctx = EVP_MD_CTX_create();
    EVP_DigestInit_ex(mdctx, md, nullptr);
}

HashCalculator::~HashCalculator()
{
    EVP_MD_CTX_destroy(mdctx);
}

void HashCalculator::update(const Data* data, const size_t size)
{
    EVP_DigestUpdate(mdctx, data, size);
}

void HashCalculator::hash(Hash hash)
{
    unsigned int size;
    EVP_DigestFinal_ex(mdctx, hash, &size);
    assert(size == hashSize);
}
} // namespace hash
