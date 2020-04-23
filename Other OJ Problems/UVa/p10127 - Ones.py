#UVa p10127 - Ones

import sys

for line in sys.stdin:
	for n in line.split():
		n = int(n)

		suma = int(0)
		ans = int(-1)

		if n == 0:
			print("0")
			continue

		i = int(1)
		k = int(1)
		while ans < 0:
			suma = suma + i

			if suma % n == 0:
				ans = k
				break

			i = i*10
			k = k+1

		if ans > 0:
			print(ans) 
