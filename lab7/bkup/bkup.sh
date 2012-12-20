#!/bin/sh

counter=$#

while [ $counter != 1 ] ; do
  if [ -e $1.$counter-1 ] ; then
      cp $1.$counter-1 $1.$counter
  fi
  counter="$(( $counter - 1 ))"
  
done

cp $1 $1.$counter

exit 0