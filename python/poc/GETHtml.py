#coding=utf-8
import urllib,urllib2,re,threading,time


reg=re.compile(r'href="(http://.+?\.html)"')


num=0
x=0
urlList=['http://www.imobile.com.cn/']
urlDict={'http://www.imobile.com.cn/':1}

def download(url,path):
   global urlList,reg,x
   x+=1
   try:
      p = urllib2.urlopen(url,timeout=5)
      data = p.read()
      with open(path, "wb") as f:
        f.write(data)
      p.close()
      ulist=reg.findall(data)
      for u in ulist:
         if u in urlDict:
            continue
         urlDict[u]=1
         urlList.append(u)
   except urllib2.URLError, e:
      print e.reason 
   x-=1

def getData(): 
   global num,urlList,x
   while True:
      if len(urlList)==0 and x==0:
         break
      if len(urlList)==0 and x>0:
         time.sleep(5)
         continue
      if x>10:
         continue
      if num>200:
         break
      num+=1
      url=urlList.pop(0)
      thread=threading.Thread(target=download,args=(url,'Data/%s.html'%num))  
      thread.setDaemon(False)
      thread.start()
   
getData()

