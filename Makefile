NAME = bingchiling
zibil = g++ -g #-Wall -Wextra
jiv = main.cpp
aaa = -o
all:
	$(zibil) -std=c++2a $(jiv) $(aaa) $(NAME)
clean:
	rm -rf $(NAME)
