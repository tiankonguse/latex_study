###############################################################################
#
# NOTES:
# 
# 	- just typing 'make' will run latex/dvips/ps2pdf to produce a PDF.
#
# 	- Sometimes, when cross-references change, you need to run 'latex' again.
# 	Typing 'make' again won't work because the pdf will be up to date.  To get
# 	around this problem, just type 'make again' and run latex again.  You'll
# 	need to type 'make' again to run dvips/ps2pdf..
#
###############################################################################

LATEX=latex
DVIPS=dvips
PS2PDF=ps2pdf14
BIBTEX=bibtex

LATEX_OPTS=-interaction=nonstopmode -halt-on-error
DVIPS_OPTS=-Ppdf -t letter
PS2PDF_OPTS=-dPDFSETTINGS=/prepress -dSubsetFonts=true -dEmbedAllFonts=true
NUM=""

RERUN = "(There were undefined references|Rerun to get (cross-references|the bars) right)"
RERUNBIB = "No file.*\.bbl|Citation.*undefined"


.PHONY: all clean


all: tiankonguse references.bbl

document: tiankonguse.pdf *.tex

tiankonguse.pdf : tiankonguse.ps
	$(PS2PDF) $(PS2PDF_OPTS) $^

tiankonguse.ps: tiankonguse.dvi
	$(DVIPS) $(DVIPS_OPTS) $^

tiankonguse.dvi: tiankonguse.tex $(wildcard *.tex)
	$(LATEX) $(LATEX_OPTS) tiankonguse.tex
	
	@if(grep "There were undefined references" tiankonguse.log > /dev/null);\
	then \
		$(BIBTEX) tiankonguse; \
		$(LATEX) $(LATEX_OPTS) tiankonguse.tex; \
	fi
	
	@if(grep "Rerun" tiankonguse.log > /dev/null);\
	then \
		$(LATEX) $(LATEX_OPTS) tiankonguse.tex;\
	fi
	rm -f tiankonguse.log

references.bbl: references.bib
	if [ -n tiankonguse.aux ]; \
	then \
		$(LATEX) $(LATEX_OPTS) tiankonguse.tex;\
	fi
	$(BIBTEX) tiankonguse

again:
	$(LATEX) $(LATEX_OPTS) tiankonguse.tex


clean:
	+rm -fv tiankonguse.{dvi,ps,pdf,aux,log,bbl,blg}


