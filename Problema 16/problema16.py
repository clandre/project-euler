import time

start_time = time.time()

x = 2 ** 1000

string = str(x)
sum = 0
for c in string:
	sum += int(c)
	
print(str(sum) + " em "+str(time.time() - start_time)+" segundos.")