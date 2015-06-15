ldapsearch objectClass = apple-user  | grep uid | cut -d, -f1| cut -d= -f2 | sort -rf
