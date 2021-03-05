#si tus ficheros de prueba no comienzan por "tad", cambia "tad.cpp" por el prefijo de tus ficheros, por ejemplo "prueba.cpp":
for FILE in *pruebas/tad*.cpp ; do 
    echo "Evaluando $FILE"
    #si tu Makefile espera que el fichero que contiene el programa principal se llame tad.cpp, cambia la siguiente línea por: cp $FILE src/tad.cpp
    cp $FILE src/tad.cpp 
    make
    ./main > $FILE.out
    diff -b -B -i $FILE.out $FILE.sal
    if [ "$?" == "0" ]; then
        echo "OK"
    else
        echo "ERROR"
    fi
done