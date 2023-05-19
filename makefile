CC = g++
CFLAGS = -Wall
LDFLAGS = 
OBJ = graph.o hydrator.o match.o team.o graph_dfs.o standing.o  main.o
EXEC = standing

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ) $(LDFLAGS)


clean:
	rm *.o *.exe

open: 
	./$(EXEC)
