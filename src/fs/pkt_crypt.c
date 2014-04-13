#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
/****
function:使用rc4加密
参数:do_encrypt为1时是加密，do_encrypt为2是解密

****/
int Encryption(char *in, int begin, int end, int do_encrypt)
{
        char * inbuf = in + begin;
        char outbuf[1024 + EVP_MAX_BLOCK_LENGTH];
        int inlen, outlen, totallen;
        totallen = end - begin;
        EVP_CIPHER_CTX ctx;
        unsigned char key[] = "0123456789";
        unsigned char iv[] = "12345678";
        /* 这时候不进行key和IV的设置，因为要修改参数 */
        EVP_CIPHER_CTX_init(&ctx);
        EVP_CipherInit_ex(&ctx, EVP_rc4(), NULL, NULL, NULL, do_encrypt);
        EVP_CIPHER_CTX_set_key_length(&ctx, 10);
        /* 完成参数设置，进行key和IV的设置 */
        EVP_CipherInit_ex(&ctx, NULL, NULL, key, iv, do_encrypt);
        for(;;) 
          {
                if(totallen <=0 ) break;
                printf("test totallen:%d\n",totallen);
                if(totallen <= 1024 )
                  {
                        inlen = totallen;
                  }
                else
                  {
                        inlen = 1024;
                  }
                if(!EVP_CipherUpdate(&ctx, outbuf, &outlen, inbuf, inlen))
                  {
                        /*出错处理 */
			EVP_CIPHER_CTX_cleanup(&ctx);
                        return 0;
                  }
                printf("test char:%s\n",in);
		strncpy(inbuf, outbuf, inlen);
                printf("test char:%s\n",in);
		inbuf += inlen;
                totallen -= inlen;
                printf("test inlen:%d outlen %d\n",inlen,outlen);
          }
        if(!EVP_CipherFinal_ex(&ctx, outbuf, &outlen))
          {
                /* 出错处理*/
		EVP_CIPHER_CTX_cleanup(&ctx);
                return 0;
          }
        printf("test inlen:%d outlen %d\n",inlen,outlen);
	strncpy(inbuf, outbuf, outlen);
        inbuf +=outlen;
        EVP_CIPHER_CTX_cleanup(&ctx);
        printf("test char:%s\n",in);
        return 1;
}
