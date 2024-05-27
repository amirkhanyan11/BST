NAME = bingchiling
zibil = g++
jiv = main.cpp
aaa = -o
all:
	$(zibil) -std=c++2a -fsanitize=address $(jiv) $(aaa) $(NAME)
clean:
	rm -rf $(NAME)
