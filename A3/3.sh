#Shell function that takes a valid directory name as an argument and recursively
#descends all the subdirectories,finds the maximum length of any file in that hierarchy
#and writes this maximum value to the standard ouput

echo " ENTER VALID DIRECTORY NAME: "
read dir1
if [ ! -d $dir1 ]
  then
   echo " INVALID DIRECTORY NAME "
 exit
fi
large=0;
for file1 in `find $dir -type f`
 do
  size=`stat -c %s $file1`
  echo " SIZE OF $file1 IS : $size"
  if [ $size -gt $large ]
   then
    large=$size
    lar_file=$file1
  fi
 done
echo " LARGEST FILE IS : $lar_file "
echo " ITS SIZE IS : $large "
