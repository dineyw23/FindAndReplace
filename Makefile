a.out: StreamSource.o main.o BufferedFile.o
	g++ -g  StreamSource.o  main.o BufferedFile.o -o  a.out

main.o: main.cpp  StreamSource.h
	g++ -g  -c  main.cpp

StreamSource.o: StreamSource.cpp StreamSource.h
	g++ -g  -c  StreamSource.cpp

BufferedFile.o: BufferedFile.cpp BufferedFile.h
	g++ -g -c BufferedFile.cpp

clean:
	rm -f *.o a.out