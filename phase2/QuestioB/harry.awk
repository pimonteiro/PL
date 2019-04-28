function generateHTML() {
  print "<!DOCTYPE html>\n<html>\n<meta charset=\"UTF-8\">\n<header>\n<h1>Livro de Harry Potter</h1>\n"> "harry_character.html"
  print "<link rel=\"stylesheet\" type=\"text/css\" href=\"../stylesB.css\">\n</header>"> "harry_character.html"
  print" <body><h3>"> "harry_character.html"
  for(i in title) {
      print title[i], " "> "harry_character.html";
  }
  print "</h3><table border='1' style='float: left'>"> "harry_character.html"
  print "<tr><th> Index </th><th> Personagens </th></tr>"> "harry_character.html"
  r = 0
  for (i in words) {
    print "<tr><td>", r++, "</td><td>", i ,"</td></tr>"> "harry_character.html";
  }
  print "</table></body></html>" > "harry_character.html"
}

BEGIN { RS="\n"; flag_title = 0; i = 0;}

$3 == "titulo", $3=="*" {
    if($3 == ":"){
        flag_title = 0;
    } 
    if(flag_title == 1){
        title[i++] = $2;
    }
    if($3 == "harry_potter"){
        flag_title = 1;
        title[i++] = $2;
    }
}

# $2 is the word in it's "true form"
$5 == "NP"  {words[$3]++;}

END { generateHTML();}
