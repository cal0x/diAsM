diAsM: 
	gcc -ludis86 diAsM.c -o diAsM

clean: 
	rm diAsM

install: 
	cp diAsM /bin/diAsM

uninstall: 
	rm /bin/diAsM
