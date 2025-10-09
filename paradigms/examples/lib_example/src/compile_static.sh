Target=lnkl
SRC=my_linked_list

echo Compiling lib$Target.a ...

gcc -c $SRC.c -o $SRC.o
ar rcs lib$Target.a $SRC.o
cp lib$Target.a ../lib
cp *.h ../include

echo Done!
