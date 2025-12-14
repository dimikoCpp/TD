import time
import os

start = time.time()
os.system("run.bat") # 12 сек
end = time.time()
speed = end - start

#https://gitmemories.com/spro/sconce-python

print(f'{speed:.4f}')
