final: Trie.o main_new.o linkedlist.o DLL.o 
	cc Trie.o main_new.o linkedlist.o DLL.o -o final
Trie.o: Trie.c Trie.h
	cc -c Trie.c
main_new.o: main_new.c Trie.h main.h linkedlist.h DLL.h  
	cc -c main_new.c
linkedlist.o: linkedlist.c linkedlist.h main.h 
	cc -c linkedlist.c
DLL.o: DLL.c DLL.h 
	cc -c DLL.c
clean:
	rm *.o



