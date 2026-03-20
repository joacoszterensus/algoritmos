local: compile tests
	rm tp3

compile:
	gcc -g -std=c99 -Wall -Wconversion -Wno-sign-conversion -Werror -Wl,--wrap=malloc -o tp3 *.c -lm

tests:
	valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./tp3


build:
	docker build --tag udesa_tp3 .

run:
	docker run -v $(CURDIR):/tp --rm  udesa_tp3

clean_docker:
	docker rmi -f $(docker images | grep udesa_tp3 | tr -s ' ' | cut -d ' ' -f 3)
