import sys
lineCount = 0
grades = 0
f = open(sys.argv[1],'r')
f.next()
arr = {}
for line in f:
  a = line.split(',')
  a[2].strip('\n')
  if a[2] in arr:
    arr[a[2]].append(a[0])
  else:
    arr[a[2]] = [a[0]]
for key, value in arr.iteritems():
  print "Grade "+str(key).strip('\n')+": "+str(len(value))+ " times: "+str(value)
f.close() 
