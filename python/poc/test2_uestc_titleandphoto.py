#电子科技大学信息与通信工程学院官网爬虫
import re
import requests
import time
def getTitle():
	url = 'http://www.sice.uestc.edu.cn'
	html = requests.get(url=url).content
#条理化一些
	html = html.decode('utf-8')
	titlere = re.compile(r'<a href="/index/detail/.+?>(.+?)</a>')
	title = re.findall(titlere,html)
	for i in title:
		with open('./siceuestc/siceuestc.txt','a+') as f:
			f.write(i+'\n')
	imgre = re.compile(r'<img src="/data/upload(.+?)"') 
	imgs = re.findall(imgre,html)
	for i in imgs:
		mytime = int(time.time())
		a = url + '/data/upload' +i
		with open('./siceuestc/%s.jpg'%mytime,'wb') as f:
				f.write(requests.get(a).content)
if __name__ == '__main__':
	getTitle()
