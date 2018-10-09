desired = -1
while(desired != 0):
  desired = float(input())
  l = c = 0
  while( l < desired):
    l += 1 / (2 + c)
    c += 1
  print(c)