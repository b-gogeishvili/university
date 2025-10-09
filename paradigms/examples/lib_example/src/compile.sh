Target=lnkl

echo Compiling lib$Target.so ...

gcc -fPIC -shared *.c -o lib$Target.so
cp lib$Target.so ../lib
cp *.h ../include

echo Done!
