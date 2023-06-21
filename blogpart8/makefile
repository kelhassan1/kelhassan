CC= g++ -std=c++11
blogpart8: blogpart8.o Area.o Post.o User.o SuperUser.o Ulist.o FeelingsPost.o
		$(CC) blogpart8.o Area.o Post.o User.o SuperUser.o Ulist.o FeelingsPost.o -o blogpart8
blogpart8.o: blogpart8.cpp
		$(CC) -c blogpart8.cpp

Areas.o: Area.h Area.cpp
		$(CC) -c Area.h
		$(CC) -c Area.cpp

Posts.o: Post.h Post.cpp
		$(CC) -c Post.h
		$(CC) -c Post.cpp

Users.o: User.h User.cpp
		$(CC) -c User.h
		$(CC) -c User.cpp

SuperUser.o: SuperUser.h SuperUser.cpp
		$(CC) -c SuperUser.h
		$(CC) -c SuperUser.cpp

Ulist.o: Ulist.h Ulist.cpp
		$(CC) -c Ulist.h
		$(CC) -c Ulist.cpp

FeelingsPost.o: FeelingsPost.h FeelingsPost.cpp
		$(CC) -c FeelingsPost.h
		$(CC) -c FeelingsPost.cpp

clean:
		rm -rf *o blogpart8
