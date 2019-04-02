flags := `pkg-config --cflags --libs glu freeglut gl`


main:
	gcc src/main.c ${flags} -o main

clean:
	[[ -f main ]] && rm main || echo "use "make main" para compilar o programa"
