#include "SHA256.hpp"
#include <cstdio>
#include <cstring>

namespace hash
{
void SHA256(const char* data, unsigned char md_value[EVP_MAX_MD_SIZE])
{
    constexpr char sha256[] = "SHA256";
    EVP_MD_CTX* mdctx;
    const EVP_MD* md;
    char mess1[] = "10foo0";
    unsigned int md_len;

    OpenSSL_add_all_digests();

    md = EVP_get_digestbyname(sha256);

    if (!md)
    {
        printf("Unknown message digest %s\n", sha256);
        exit(1);
    }

    mdctx = EVP_MD_CTX_create();
    EVP_DigestInit_ex(mdctx, md, NULL);
    EVP_DigestUpdate(mdctx, mess1, strlen(mess1));
    EVP_DigestFinal_ex(mdctx, md_value, &md_len);
    EVP_MD_CTX_destroy(mdctx);

    printf("Digest is: ");
    for (int i = 0; i < md_len; i++)
        printf("%02x", md_value[i]);
    printf("\n");

    /* Call this once before exit. */
    EVP_cleanup();
}
} // namespace hash
