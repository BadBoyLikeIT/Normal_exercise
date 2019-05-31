import re
import requests
#从矿大计算机学院官网将文章标题爬下来
def getTitle():
	url = 'http://cs.cumt.edu.cn/'
	html = requests.get(url=url).content
#条理化一些
	html = html.decode('utf-8')
	#print(html)
	titlere = re.compile(r'<span class="biaoti"><a href=\'.+?\' target=\'_blank\' title=\'.+?\'>(.+?)</a>')
	title = re.findall(titlere,html)
#追加写文件
	for i in title:
		with open('./beauty/cscumt.txt','a+') as f:
			f.write(i+'\n')
def write():
	str = 'ls love wwj'
	str1 = 'wwj love ls\n'
	with open('./cscumt.txt','w+') as f:
		f.write(str+'\n')
		f.write(str1)

#第一个正则匹配
def test1():
	titlere = re.compile(r'<a href="/cs/xytz/webinfo/\w+/\w+/\w+.htm" target="_blank">(.+?)</a>')
	title = re.findall(titlere,'<a href="/cs/xytz/webinfo/2018/01/1514127422856431.htm" target="_blank">2017-2018秋季学期研究生期末考试安排</a>')
	print(title)

if __name__ == '__main__':
	getTitle()