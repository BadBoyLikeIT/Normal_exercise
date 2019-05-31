#简单的下载图片的脚本
import requests

#for i in range(1,9):
def test():
	with open('ls.jpg','wb') as f:
		f.write(requests.get('http://www.cumt.edu.cn/_upload/article/images/54/9c/c064c1a849baa0830b04e813a80d/1d7d7a79-e147-4ed1-ac75-7751f5ccd02b.jpg').content)

import time

def test1():
	for i in range(1,9):
		mytime = int(time.time())+i*i*i*i
		with open('./imgtest/%s.jpg'%mytime,'wb') as f:
				f.write(requests.get('http://www.scu.edu.cn/portal2013/lib/images/index_banner%s.jpg'%i).content)

if __name__ == '__main__':
	test()