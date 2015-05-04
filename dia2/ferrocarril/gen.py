import sys, random

n = int(sys.argv[1])
a = int(sys.argv[2])
b = int(sys.argv[3])
c = int(sys.argv[4])
p = [i for i in range(n)]
random.shuffle(p)

line = ''.join(str(e) + ' ' for e in p)
print '%d\n%d %d %d\n%s' % (n, a, b, c, line)