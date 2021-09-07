comp:
	gcc main.c -o timed-shell -O2 -static -lm

exec:
	./timed-shell

run:
	gcc main.c -o timed-shell -O2 -static -lm
	./timed-shell

run-file:
	gcc main.c -o timed-shell -O2 -static -lm
	./timed-shell < in.txt > out.txt