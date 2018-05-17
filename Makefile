.PHONY:clean-excuting

clean-excuting:
	@for file in `find . \( -name "*.git*" -prune \) -o \( -type f -print \)`; \
	do \
		if [ -x $$file ] && [ $${file##*.} != "sh" ]; then \
			rm -rf $$file;  \
		fi \
	done
