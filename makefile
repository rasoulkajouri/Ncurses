#!/bin/bash

CXX := g++
CXXFLAGS = -std=c++11 -O3
LINKS := -lncurses

TARGET:= run


less01:
	@$(CXX) $(CXXFLAGS) less-01.cpp $(LINKS) -o $(TARGET) 

less02:
	@$(CXX) $(CXXFLAGS) less-02.cpp $(LINKS) -o $(TARGET) 

less03:
	@$(CXX) $(CXXFLAGS) less-03.cpp $(LINKS) -o $(TARGET) 

