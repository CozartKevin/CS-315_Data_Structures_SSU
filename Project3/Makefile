
CFLAGS=-std=c++11 -Wall

infixToPostfix.x: InfixToPostfix.o Token.o TokenIterator.o main.o
	g++ $(CFLAGS) InfixToPostfix.o Token.o TokenIterator.o main.o -o infixToPostfix.x

InfixToPostfix.o: InfixToPostfix.hpp InfixToPostfix.cpp TokenIterator.hpp Token.hpp
	g++ $(CFLAGS) InfixToPostfix.cpp -o InfixToPostfix.o -c

TokenIterator.o: TokenIterator.hpp TokenIterator.cpp Token.hpp
	g++ $(CFLAGS) TokenIterator.cpp -o TokenIterator.o -c

Token.o: Token.hpp Token.cpp
	g++ $(CFLAGS) Token.cpp -o Token.o -c

main.o: main.cpp Token.hpp InfixToPostfix.hpp TokenIterator.hpp
	g++ $(CFLAGS) main.cpp -o main.o -c

clean:
	rm -f *.o *~ *.x
