n =int(input())
s = input().split()
b =1;
for i in s:
	b*=2;
	bi =int(i)
	b-=bi;
	if b<0:
		print("error");
		exit(0)
print(b%1000000007)
