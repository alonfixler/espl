import sys
import random
f = open('long-words.txt','r')
text = f.read().splitlines()
myline = random.choice(text)
over=False
steps=6
win=False
a=[]
while steps>0 and not win:
  win=True
  print "steps from gallows: ",str(steps),", word so far: ",
  for c in myline:
    if c in a:
      print c,
    else:
      print '_',
      win=False
  c = str(raw_input("\nGuess a letter: "))
  a.append(c)
  if c not in myline:
    steps-=1
  
f.close() 