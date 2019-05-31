import time

#打印当前时分秒
def test_time():
	myTime = time.strftime('%Y%m%d%H%M%S')
	myTime1 = int(time.time()*10000)
	#time.time 输出的是时间戳
	print(myTime)
	print(myTime1)




if __name__ == '__main__':
	test_time()