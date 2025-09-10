
#include <string.h>
#include <stdint.h>
#include <stdio.h>

#include <openssl/evp.h>
#include <openssl/aes.h>

int64_t _ZN6ec051725IsEncryptionVersionEnableEv(void)
{
    return 1;
}

int64_t _ZN6ec05177encryptEPhS0_S0_(void *obj, void *key, void *src, void *dest)
{
    int ret;
    EVP_CIPHER_CTX *ctx;
    uint8_t buf[16];
    int len;

    ctx = 0;

    memset(buf, 0, sizeof(buf));

    ret = -1;

    do {

        ctx = EVP_CIPHER_CTX_new();
        if (!ctx) {
            ret = -1;
            break;
        }

        ret = EVP_EncryptInit_ex(ctx, EVP_aes_128_ecb(), 0, key, 0);
        if (ret != 1) {
            ret = -1;
            break;
        }

        ret = EVP_CIPHER_CTX_set_padding(ctx, 0);
        if (ret != 1) {
            ret = -1;
            break;
        }

        ret = EVP_EncryptUpdate(ctx, buf, &len, src, 16);
        if (ret != 1) {
            ret = -1;
            break;
        }

        if (len < 0 || (size_t)len != 16) {
            ret = -1;
            break;
        }

        ret = 0;

    } while (0);

    if (ctx)
        EVP_CIPHER_CTX_free(ctx);

    if (ret < 0) {
        printf("encryption failed\n");
        memset(dest, 0xCC, 16);
    } else {
        memmove(dest, buf, 16);
    }

    return 0;
}
