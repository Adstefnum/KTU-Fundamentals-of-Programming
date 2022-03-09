CPPFLAGS = CPPFLAGS ?= -std=c++17 -g -Wall -Wextra -Werror -g

build: pr-1

pr-1: pr-1.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

do:
	run pr-1

clean:
	$(RM) pr-1
