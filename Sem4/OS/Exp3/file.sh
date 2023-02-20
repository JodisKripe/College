read -p "Enter file name: " file
read -p "Enter the start and end " start end

sed -n $start,$end\p $file

read -p "Enter File Name: " file
read -p "Enter Word: " word

echo "File after removing word: `cat $file | grep -v $word`"

echo -e "\n\nThe files are `ls`"
