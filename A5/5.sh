#Shell script to implement terminal locking.It should prompt the user for password.
#After accepting the password entered by the user,it myst prompt again for password
#confirmation(to retype the password).If a match occurs,it must lock the terminal and
#prompt for the password.If the proper password is entered,the terminal must be unlocked.
#Note the script must be written to disregard Break,Control-D etc. No tume limit to be 
#implemented for lock duration.

stty -echo
echo " ENTER PASSWORD:"
read pass1
echo " CONFIRM PASSWORD:"
read pass2
if [ $pass1 = $pass2 ]
 then
  echo " TERMINAL IS LOCKED "
  trap ' ' 2 3 15 
  while true
   do
    echo "ENTER PASSWORD TO UNLOCK:"
    read pass3
    if [ $pass3 = $pass2 ]
     then
      echo " TERMINAL IS UNLOCKED "
      stty echo
     exit
    else
     echo " INCORRECT PASSWORD. TRY AGAIN "
    fi
   done
else
 echo " PASSWORD DO NOT MATCH "
 stty echo
fi
