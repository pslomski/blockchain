#pragma once

#include <openssl/evp.h>

namespace hash
{
void SHA256(const char* data, unsigned char md_value[EVP_MAX_MD_SIZE]);
} // namespace hash
