#include <dirent.h>
#include <stdio.h>

//API基本测试
int main(int argc,char *argv[])
{
	struct dirent* ent=NULL;
	DIR *pDir = NULL;

	if((pDir = opendir("/home/test"))== NULL)
	{
		printf("open dir failed\n");
		return 0;
	}
	while((ent = readdir(pDir))!=NULL)
	{
	printf(" the ent->d_name is %s the ent->d_type is %d\n",ent->d_name,ent->d_type);
	}
	closedir(pDir);
	return 0;
}

