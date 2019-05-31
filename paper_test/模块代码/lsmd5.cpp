#include <stdio.h>
#include <string.h>
#include <openssl/md5.h>
//gcc md5.c -lcrypto

//对字符串进行md5hash
//type1
char *md5str(char *buf)
{
	const char *set = "0123456789abcdef";
	//生成md5
	MD5_CTX ctx;
	unsigned char md[MD5_DIGEST_LENGTH];
	MD5_Init(&ctx);
	MD5_Update(&ctx,(unsigned char *)buf,strlen(buf));
	MD5_Final(md,&ctx);
	//将md5转换成string
	int i;
	char str[33];
	for(i = 0;i < MD5_DIGEST_LENGTH;i++)
	{
		
		str[i*2] = set[((md[i]>>4)&0xf)&0x0F];
		str[i*2+1] = set[((md[i]&0xf)&0x0F)];
	}
	str[32] = '\0';
	return str;
	
}

//type2
void md5str1(char *buf,char* str)
{
	MD5_CTX ctx;
	unsigned char md[16];
	MD5_Init(&ctx);
	MD5_Update(&ctx,(unsigned char *)buf,strlen(buf));
	MD5_Final(md,&ctx);
	//将md5转换成string
	int i;
	
	char tmp[3];
	for(i = 0;i < 16;i++)
	{
		sprintf(tmp,"%02x",md[i]);
		strcat(str,tmp);
	}
	str[32] = '\0';
	return ;
	
}

//type3
char *md5str2(char *buf)
{
	MD5_CTX ctx;
	unsigned char md[16];
	MD5_Init(&ctx);
	MD5_Update(&ctx,(unsigned char *)buf,strlen(buf));
	MD5_Final(md,&ctx);
	//将md5转换成string
	int i;
	char * str = (char *)malloc(sizeof(char)*33);
	//char str[33] 这样，会因为str在栈中，之后会清除栈
	memset(str,0,strlen(str));//对数组进行以下初始化，如未初始化则会导致hash异常
	char tmp[3];
	for(i = 0;i < 16;i++)
	{
		sprintf(tmp,"%02x",md[i]);
		strcat(str,tmp);
	}
	str[32] = '\0';
	return str;
	
}

int main(int argc,char *argv[])
{
	MD5_CTX ctx;
	unsigned char *buf = "123456789abcdefgh/n";
	unsigned char md[MD5_DIGEST_LENGTH];
	unsigned char *p;
	int i;
	
	MD5_Init(&ctx);
	MD5_Update(&ctx,(void *)buf,strlen(buf));
	MD5_Final(md,&ctx);
	p = md;
	printf("%s md5:",buf);
	for(i=0;i<MD5_DIGEST_LENGTH;i++)
		printf("%x",*p++);  
	
	printf("\n");
	char *buftemp = "123456789abcdefgh/n";

	char md2[33];
	memset(md2,0,sizeof(md2));
	md5str1("123456789abcdefgh/n",md2);
      printf("%s md52: %s\n",buftemp,md2);
	
	char *md3 = md5str2(buftemp);
	printf("%s md53: %s\n",buftemp,md2);

 
	if(strcmp(md2,md3)==0)
		printf("ls is successful!\n");
	else
		printf("failed!\n");

	return 0;
}