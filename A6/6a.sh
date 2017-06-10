#Write a shell script to find the largest of three numbers

echo " ENTER THREE NUMBERS: "
read a b c
L=$a

if [ $b -gt $a ]&&[ $b -gt $c ]
 then
  L=$b
fi
if [ $c -gt $a ]&&[ $c -gt $b ]
 then
  L=$c
fi
echo " LARGEST OF $a $b AND $c IS : $L "

