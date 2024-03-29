CXX = g++
CXXFLAGS = -std=c++17 -g -Wall
DEPS = file-loader.h point.h problem.h greedy.h solution.h local_search.h grasp.h node.h tree.h branch_bound.h
OBJ = main.o file-loader.o point.o problem.o greedy.o solution.o local_search.o grasp.o node.o tree.o branch_bound.o


%.o: %.cc $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

main: $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS)

.PHONY: clean
clean:
	rm main *.o