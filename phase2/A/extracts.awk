BEGIN { RS="\n+"}

$1 == 1 {extracts++;}

END { print "Número de extractos: " extracts "\n"; print "Records: " NR; }
