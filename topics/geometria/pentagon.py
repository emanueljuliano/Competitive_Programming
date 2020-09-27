from math import sqrt, cos, pi, sin

while(True):
	try:
		l = float(input())
		x = sin(108/180*pi) * l / sin(63/180*pi);
		print('{:.10f}'.format(x))
	except:
		break
