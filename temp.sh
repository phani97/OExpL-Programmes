lex labeltable.l
 gcc lex.yy.c -w
 ./a.out 
 cd ../xsm_expl/
 cp ../stage8_oexpl/assemblycodenew.xsm assemblycodenew.xsm
./xsm -l mylib.lib -e assemblycodenew.xsm --debug
