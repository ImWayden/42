<?php
//$file=fopen("index.html","w+") or exit("Unable to open file!");
print("<html>\n<div id=\"map\">\n<table id=\"tblmap\" border=\"1\">\n");
for ($i = 0; $i < 20; $i++)
{
    print("<tr>");
    for ($j = 0; $j < 20; $j++)
        print("<td>X</td");
    print("</tr>\n");
}
print("</html>\n");
//fclose($file);
?>