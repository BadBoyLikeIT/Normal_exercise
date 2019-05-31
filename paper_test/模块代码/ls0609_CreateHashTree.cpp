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
#include <openssl/md5.h>
#include <stdio.h>

using namespace std;
void printFileInfo(char *path);

size_t pathlen = 512;


//目录哈希树结构体定义
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


//md5实现，输出为字符串
char *md5str(char *buf)
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
//创建hash
void createHash(Tree *tree)
{
	struct stat filestat;
      stat(tree->path.c_str(),&filestat);
	if((filestat.st_mode & S_IFMT) == S_IFDIR)  //如果是目录
	{
		//则维护着一张hash表
		string origin;
		if(!tree->hashmap.empty())   //hashmap非空证明目录中包含文件
		{
			for(map<string,int>::iterator it = tree->hashmap.begin();it!=tree->hashmap.end();it++)
				origin += it->first;
			string hash = md5str((char *)origin.c_str());
			if(tree->father != NULL) //防止root节点
			{
				tree->father->hashmap.insert(pair<string,int>(hash,0));
			}
			//for(vector<Tree *>::iterator it = tree->son.begin();it!=tree->son.end();it++)
					//cout<<(*it)->path<<endl;
			//cout<<origin<<endl;
			//cout<<"ls is successful:"<<tree->path<<endl;
			//cout<<hash<<endl;
		}else
		{	
			//如果是空文件夹则根据文件夹名称与创建时间进行hash
			char time[10];
	  		sprintf(time,"%d",filestat.st_mtime);  //获取文件的修改时间
			char *origin = strcat((char *)tree->filename.c_str(),time);
			string hash = md5str(origin);
			if(tree->father!=NULL)
			{
				tree->father->hashmap.insert(pair<string,int>(hash,0));
			}
			//cout<<tree->path<<endl;
			//cout<<hash<<endl;
		}
		
	}
	else  //如果是文件
	{	
	  char time[10];
	  sprintf(time,"%d",filestat.st_mtime);  //获取文件的修改时间
	  char *origin = strcat((char *)tree->filename.c_str(),time);
	   //hash值的创建是根据 文件名+修改时间 创建的
	  string hash = md5str(origin);
	  tree->father->hashmap.insert(pair<string,int>(hash,0));
	  //cout<<tree->path<<endl;
	  //cout<<hash<<endl;
	}
}
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
		Tree * treeNode = new Tree;  //此时不可以直接调用malloc因为string是不定长的
		treeNode->path = fullpath;
		treeNode->filename = dirp->d_name;
		treeNode->father = tree;
		treeNode->flag = false;
		dirstack.push(treeNode);
		tree->son.push_back(treeNode);  //将子节点放入到父节点的子表中
	}
	
	closedir(dp);
}

void buildHashTree(const char *path)
{
	Tree * tree = new Tree;
	tree->path = path;
	tree->filename = path;
	tree->father = NULL;
	tree->flag = false;
	dirstack.push(tree);
	while(!dirstack.empty())
	{
		Tree * ptree= dirstack.top();
		if(ptree->flag)          //为了实现第二次时才出stack
		{	
			createHash(ptree);   //计算hash
			dirstack.pop();
			//cout<<ptree->path<<endl;
		}else{
			ptree->flag = true;
			doPath(ptree);
		}
	}
	
}

int main(int argc,char *argv[])
{
	if(argc == 1)
		buildHashTree("/home/lishuai/Desktop/test");
	else
		buildHashTree(argv[1]);
	return 0;
}
