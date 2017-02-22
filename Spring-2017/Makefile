all:
	mkdir -p build
	latex -output-directory=./build set.tex
	latex -output-directory=./build set.tex
	dvips ./build/set.dvi -o ./build/set.ps
	ps2pdf ./build/set.ps ./build/set.pdf

clean:
	rm -rf build
