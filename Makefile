CXX=g++
CXXFLAGS=-std=c++11

cov_test: source.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<
