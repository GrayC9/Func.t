!/bin/bash

for (( ; ; ))
do
clear
echo "|**************************|"
echo "|--------------------------|"
echo "|С Первое Задание       1. |"
echo "|--------------------------|"
echo "|С Второе Задание       2. |"
echo "|--------------------------|"
echo "|С Редакция корня       3. |"
echo "|--------------------------|"
echo "|Выйти в главное меню 0    |"
echo "|**************************|"
echo "Выберите метод: "
read s

if [ $s -eq 1 ]; then
clear
./z1
fi

if [ $s -eq 2 ]; then
clear
./z2
fi

if [ $s -eq 3 ]; then
nano data.txt
fi

if [ $s -eq 0 ]; then
clear
exit
fi

done