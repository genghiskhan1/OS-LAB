#Write a shell script to reverse a string

echo -n "ENTER A STRING:"
read string
len=${#string}
for((i=$len-1; i>=0; i--))
 do
  revStr="$revStr${string:$i:1}"
 done
echo "REVERSE OF STRING: $revStr"
