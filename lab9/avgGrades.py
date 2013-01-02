import sys
lineCount = 0
grades = 0
f = open(sys.argv[1],'r')
f.next()
for line in f:
  a = line.split(',')
  grades = grades + int(a[2])
  lineCount = lineCount + 1
print "The avg is: "+str(float(grades)/float(lineCount))
f.close()