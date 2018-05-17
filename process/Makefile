.PHONY:clean print

print:
	bash judge.sh

clean:
	@for demo in `ls` ;\
	do\
		if [ -x $$demo ] && ! [ -d $$demo ] && [ $${demo##*.} != "sh" ]; then\
			rm -rf $$demo ;\
		fi \
	done 
