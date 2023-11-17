#include <array>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <openssl/evp.h>
#include <openssl/sha.h>

namespace testing
{
TEST(SHA256, testSHA256)
{
    unsigned char md_value[EVP_MAX_MD_SIZE];
    unsigned int md_len;
    constexpr char sha256[] = "SHA256";
    // unsigned char md[SHA256_DIGEST_LENGTH];
    std::array<char, 1> data{'0'}; // sha256('0') = 5feceb66ffc86f38d952786c6d696c79c2dbc239dd4e91b46729d73a27fb57e9
    EVP_MD_CTX* mdctx;
    const EVP_MD* md;
    OpenSSL_add_all_digests();
    md = EVP_get_digestbyname(sha256);
    if (!md)
    {
        printf("Unknown message digest %s\n", sha256);
        exit(1);
    }
    mdctx = EVP_MD_CTX_create();
    EVP_DigestInit_ex(mdctx, md, NULL);
    EVP_DigestUpdate(mdctx, data.data(), data.size());
    EVP_DigestFinal_ex(mdctx, md_value, &md_len);
    EVP_MD_CTX_destroy(mdctx);

    printf("Digest is: ");
    for (int i = 0; i < md_len; i++)
        printf("%02x", md_value[i]);
    printf("\n");

    ASSERT_THAT(SHA256_DIGEST_LENGTH, Eq(256 / 8));
}
} // namespace testing
