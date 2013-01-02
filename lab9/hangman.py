import sys
import random
f = open('long-words.txt','r')
text = f.read().splitlines()
myline = random.choice(text)
over=0
steps=6
win=0
a={}
while !over:
  while steps>0 and !win
    print "steps from gallows: "+str(steps)+" word so far: "
    for c in myline:
      if c in a:
	print c,
      else:
	print '-',
    print "Guess a letter: "
    c = sys.stdin.read(1)
    print c
    if c in a
    

  
f.close() 