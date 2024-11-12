#!usr/bin/bash

while true 
do 

printf "________________________________________________\n \n"
echo "MENU"
echo "1. Create Address book"
echo "2. View address book"
echo "3. Insert a record"
echo "4. Modify a record"
echo "5. Delete a record"
echo "6. Exit"

echo "Enter choice (1-6)"
read choice

echo $choice

case $choice in
	1) echo "Enter Address book name : "
	   read ab 
	   #check if add_book already exist
	   res=`ls | grep $ab | wc -w`  #imp
	   
	   if  [ $res -gt 0 ]
	   then
	   	echo "Error : Address book already exist ! "
	   else
	   	touch $ab
	   	echo "Address book created successfully ! "
	   	
	   fi ;;
	   
	2)  echo "Enter Address book name : "
	   read ab 
	   
	   res=`ls | grep $ab | wc -w`  #imp
	   
	   if  [ $res -gt 0 ]
	   then
	   	echo "----------------------------------------"
	   	cat $ab
	   	echo "----------------------------------------"
	   else
	   	
	   	echo "Error : Address book does not exist ! "
	   	
	   fi ;;  
	
	3)echo "Enter Address book name : "
	   read ab 
	   
	   res=`ls | grep $ab | wc -w`  #imp
	   
	   if  [ $res -gt 0 ]
	   then
	   	echo "Enter email : "
	   	read email
	   	
	   	rec=`cat $ab | grep $email | wc -w`
	   	if [ $rec -gt 0 ]
	   	then
	   		echo "Error : Record already exist ! "	   	
	   	else
	   		echo "Enter name, phone : "
	   		read name phone
	   		r=`echo $name $email $phone`
	   		echo $r
	   		echo $r >> $ab
	   		echo "Inserted successfully ! "
	   		
	   	fi
	   	
	   	
	   else
	   	
	   	echo "Error : Address book does not exist ! "
	   	
	   fi ;;
	4)echo "Enter Address book name : "
	   read ab 
	   
	   res=`ls | grep $ab | wc -w`  #imp
	   
	   if  [ $res -gt 0 ]
	   then
	   	echo "Enter email : "
	   	read email
	   	
	   	rec=`cat $ab | grep $email | wc -w`
	   	if [ $rec -gt 0 ]
	   	then
	   		echo "Enter name(new) : "
	   		read name
	   		echo "Enter phone(new) : "
	   		read phone
	   		
	   		old=`grep $email $ab`
	   		new=`echo $name $email $phone`
	   		echo "old : $old"
	   		echo "new : $new"
	   		sed -i s/"$old"/"$new"/g $ab   		#imp 
	   		
	   		echo "Modified successfully ! "	   	
	   	else
	   		echo "Error : Record does not exist ! "
	   		
	   		
	   	fi
	   	
	   	
	   else
	   	
	   	echo "Error : Address book does not exist ! "
	   	
	   fi ;;
	5)echo "Enter Address book name : "
	   read ab 
	   
	   res=`ls | grep $ab | wc -w`  #imp
	   
	   if  [ $res -gt 0 ]
	   then
	   	echo "Enter email : "
	   	read email
	   	
	   	rec=`cat $ab | grep $email | wc -w`
	   	if [ $rec -gt 0 ]
	   	then
	   		
	   		
	   		old=`grep $email $ab`
	   		echo "Deleting this record... : $old"
	   		
	   		sed -i s/"$old"//g $ab   	#imp 
	   		sed -i /^$/d $ab
	   		echo "Deleted successfully ! "	   	
	   	else
	   		echo "Error : Record does not exist ! "
	   		
	   		
	   	fi
	   	
	   	
	   else
	   	
	   	echo "Error : Address book does not exist ! "
	   	
	   fi ;;
	6) exit
	
		;;
	
	   
	 
	
	*) echo "Wrong choice! " ;;
	
esac


done


