#Shell script that accepts two file names as arguments,check if the permissions
#for these files are identical and if the permissions are identical,outputs the 
#common permission,otherwise outputs each file name followed by the permission

if [ $# -lt 2 ]||[ $# -gt 2 ]
 then
  echo "INVALID NUMBER OF ARGUMENTS"
 exit
else 
 f1=`ls -l $1|cut -c2-10`
 f2=`ls -l $2|cut -c2-10`
 
 if [ $f1 = $f2 ]
  then
   echo " PERMISSIONS ARE EQUAL "
   echo "$f1"

 else
  echo " PERMISSIONS ARE UNEQUAL " 
  echo " PERMISSIONS OF $1 : $f1 "
  echo " PERMISSIONS OF $2 : $f2 "
 fi
fi
