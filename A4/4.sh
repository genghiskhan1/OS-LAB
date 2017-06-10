#Write a shell function thst accepts valid log-in names
#as arguments and print their corresponding home directories.
#If no arguments are specified,print suitable error message.

if [ $# -eq 0 ]
 then
  echo "CANNOT HAVE ZERO ARGUMENTS"
 exit
else
 for login in $*
  do
   if grep $login /etc/passwd > /dev/null
    then
     echo " LOGIN : $login"
     dir=`grep $login /etc/passwd | cut -d ':' -f 6`
     echo " HOME DIRECTORY : $dir "
   else 
    echo " INVALID LOGIN "
  fi
 done
fi 
