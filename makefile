build:
	cl /c countlines.c countcomments.c removecomments.c removeinclude.c removedefine.c
		lib /OUT:coursework1.lib countlines.obj removeinclude.obj removecomments.obj removedefine.obj countcomments.obj
		cl /c coursework1.c 
		link coursework1.obj coursework1.lib
		del *.obj

string:
   coursework1 -i string_functions.c -c

math:
	coursework1 -i math_functions.c -c

coursework1:
  cl /c countlines.c removeinclude.c removedefine.c removecomments.c countcomments.c
  link countlines.obj removeinclude.obj removedefine.obj removecomments.obj countcomments.obj coursework1.lib

clean: 
	del *.exe
	del *.obj