#! /bin/csh

set x=`whoami`

echo $x

set pid = `ps aux | grep -v $x |cut -c10-14`
echo $pid

#foreach file (`ls`)
#       if ({ test -d $file }) then
#               echo subdirectory: $file
#       endif
#end

