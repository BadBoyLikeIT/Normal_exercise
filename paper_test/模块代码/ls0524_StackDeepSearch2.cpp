#include <iostream>
#include <dirent.h>
#include <stack>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <stack>
#include <string>
#include <vector>
#include <map>
using namespace std;
void printFileInfo(char *path);

size_t pathlen = 512;



typedef struct treeNode
{
	treeNode *father;	 //父亲节点
	vector<treeNode *>son; //子孩子节点
	string hash;       //文件hash值
	string filename;   //文件名称
	string path;	//路径名称
	map<string,int>hashmap;
	bool flag;
}Tree,*pTree;
stack<pTree> dirstack;
/*
** 搜索目录
*/
void doPath(Tree *tree)
{
	struct stat statbuf;
	struct dirent *dirp;
	DIR *dp;
	int n;
	char *fullpath = (char *)malloc(sizeof(char)*pathlen);  //记录路径的一个变量
	
	if(lstat(tree->path.c_str(),&statbuf) < 0)   //解除引用
		return;
	if(S_ISDIR(statbuf.st_mode) == 0)  //not a directory
		return;

	//做一个扩容
	if(pathlen <= tree->path.size())
	{
		pathlen = tree->path.size()*2;
		if((fullpath = (char *)realloc(fullpath,pathlen)) == NULL)
		{
			printf("realloc error!\n");
			return ;
		}
			
	}
	strcpy(fullpath,tree->path.c_str());
	n = strlen(fullpath);
	fullpath[n++] = '/';
	fullpath[n] = 0;
	
	if((dp = opendir(tree->path.c_str()))==NULL)
	{
		//printf("dir_order:can't open %s\n",tree->path);
		return;
	}
	while((dirp = readdir(dp))!=NULL)
	{
		if(strcmp(dirp->d_name,".")==0 || strcmp(dirp->d_name,"..")==0)   //忽视.与..
			continue;
		//判断名字超过长度
		if(tree->path.size()+strlen(dirp->d_name)+2 > pathlen)
		{
			pathlen *= 2;
			if((fullpath = (char *)realloc(fullpath,pathlen)) == NULL)
			{
			printf("realloc error!");
			return ;
			}
		}
		strcpy(&fullpath[n],dirp->d_name);
		Tree * treeNode = (pTree)malloc(sizeof(Tree));
		treeNode->path = fullpath;
		treeNode->filename = dirp->d_name;
		treeNode->father = tree;
		treeNode->flag = false;
		dirstack.push(treeNode);
		//printFileInfo(fullpath);
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
        //doPath(path);  
    }  
    printf("%s %8ld\n", path, filestat.st_size);  
} 
void buildHashTree(const char *path)
{
	Tree * tree = (pTree)malloc(sizeof(Tree));
	tree->path = path;
	tree->filename = path;
	tree->father = NULL;
	tree->flag = false;
	dirstack.push(tree);
	while(!dirstack.empty())
	{
		Tree * ptree= dirstack.top();
		if(ptree->flag)
		{	//计算hash
			dirstack.pop();
			cout<<ptree->path<<endl;
		}else{
			tree->flag = true; //存在问题
			doPath(ptree);
		}
	}
	
}

int main(int argc,char *argv[])
{
	if(argc == 1)
		buildHashTree("/home/lishuai/Desktop/test");
		//doPath("/home/lishuai/Desktop/test");
	else
		buildHashTree(argv[1]);
		//doPath(argv[1]);
	return 0;
}
