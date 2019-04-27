
function generateHTML() {
  print "<html>\n<meta charset=\"UTF-8\">\n<header>\n<h1>Dicionario Implícito</h1>\n</header>"> "word_types.html"
  
  print "<body><table border='1' style='float: left'>"> "word_types.html"
  print "<tr><th> Verbo </th></tr>"> "word_types.html"
  for (i in verbs) {
    print "<tr><td>", i ,"</td>></tr>"> "word_types.html";
  }
  print "</table>" > "word_types.html"

  print "<table border='1' style='float: left'>"> "word_types.html"
  print "<tr><th> Substantivo </th></tr>"> "word_types.html"
  for (j in nouns) {
    print "<tr><td>", j ,"</td></tr>" > "word_types.html";
  }
  print "</table>" > "word_types.html"
 
  print "<table border='1' style='float: left'>"> "word_types.html"
  print "<tr><th> Adjectivo </th></tr>"> "word_types.html"
  for (k in adjectives) {
    print "<tr><td>", k ,"</td></tr>" > "word_types.html";
  }
  print "</table>" > "word_types.html"
  
  print "<table border='1' style='float: left'>"> "word_types.html"
  print "<tr><th> Advérbio </th></tr>"> "word_types.html"
  for (w in adverbs) {
    print "<tr><td>", w ,"</td></tr>" > "word_types.html";
  }
  print "</table>" > "word_types.html"
}

BEGIN { RS="\n";  }

index($4, "V") == 1  {verbs[$2]++;}
index($4, "N") == 1  {nouns[$2]++;}
index($4, "A") == 1  {adjectives[$2]++;}
index($4, "R") == 1  {adverbs[$2]++;}

END { generateHTML();}
