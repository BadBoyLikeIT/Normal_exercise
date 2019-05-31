#include <iostream>
#include <dirent.h>
#include <stack>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

void printFileInfo(char *path);

size_t pathlen = 512;

/*利用了递归的形式进行了目录的遍历
*/
void doPath(const char *path)
{
	struct stat statbuf;
	struct dirent *dirp;
	DIR *dp;
	int n;
	char *fullpath = (char *)malloc(sizeof(char)*pathlen);  //记录路径的一个变量
	
	if(lstat(path,&statbuf) < 0)   //解除引用
		return;
	if(S_ISDIR(statbuf.st_mode) == 0)  //not a directory
		return;

	//做一个扩容
	if(pathlen <= strlen(path))
	{
		pathlen = strlen(path)*2;
		if((fullpath = (char *)realloc(fullpath,pathlen)) == NULL)
		{
			printf("realloc error!\n");
			return ;
		}
			
	}
	strcpy(fullpath,path);
	n = strlen(fullpath);
	fullpath[n++] = '/';
	fullpath[n] = 0;
	
	if((dp = opendir(path))==NULL)
	{
		printf("dir_order:can't open %s\n",path);
		return;
	}
	while((dirp = readdir(dp))!=NULL)
	{
		if(strcmp(dirp->d_name,".")==0 || strcmp(dirp->d_name,"..")==0)   //忽视.与..
			continue;
		//判断名字超过长度
		if(strlen(path)+strlen(dirp->d_name)+2 > pathlen)
		{
			pathlen *= 2;
			if((fullpath = (char *)realloc(fullpath,pathlen)) == NULL)
			{
			printf("realloc error!");
			return ;
			}
		}
		strcpy(&fullpath[n],dirp->d_name);
		printFileInfo(fullpath);
	}
	
	closedir(dp);
}
void printFileInfo(char *path)  
{  
    struct stat filestat;  
    if (stat(path, &filestat) == -1)  
    {  
        printf("cannot access the file %s\n", path);  
        return;  
    }  
    if ((filestat.st_mode & S_IFMT) == S_IFDIR)  
    {  
        doPath(path);  
    }  
    printf("%s %8ld\n", path, filestat.st_size);  
} 


int main(int argc,char *argv[])
{
	if(argc == 1)
		doPath("/home/lishuai/Desktop/test");
	else
		doPath(argv[1]);
	return 0;
}
