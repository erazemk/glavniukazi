all:
	clang -o glavniukazi \
			src/ovojnica.c \
			src/kop.c \
			src/macka.c \
			src/napacno.c \
			src/odmev.c \
			src/res.c \
			src/imegostitelja.c

pocisti:
	rm glavniukazi
