#电子科技大学静态页面爬图

import requests
import re
import urllib
import time

def getImg():
	imglist=[]
	x = 0
	
	url = 'http://www.uestc.edu.cn/'
	headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/55.0.2883.87 Safari/537.36'}
	req = requests.get(url)
	html = req.text
	imgre = re.compile(r'<img src="(.+?)" width="160" alt')
	imgurl = re.findall(imgre,html)
	for i in imgurl:
#注意这个时间戳的使用
		mytime =  str(time.time()) 
		#ulrtruth = url +'_upload'+ i
		#print(imgurl)
		urllib.request.urlretrieve(i,'D:/kit/python/poc/beauty/%s.jpg'%mytime)
		#x = x+1
if __name__ == '__main__':
	getImg()
