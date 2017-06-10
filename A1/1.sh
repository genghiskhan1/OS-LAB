#Write a non-recursive shell script that accepts any number of arguments
#and print them in the reverse order. (For example,if the script is named
#rargs,the executing rargs A B C should produce C B A on standard output

if [ $# -eq 0 ]
 then
  echo " CANNOT HAVE ZERO ARGUMENTS "
exit
else
 while [ $# -gt 0 ]
  do
   rev="$1 $rev"
   shift
  done
 echo $rev
fi
