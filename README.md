# athena
BST Assignment brought to you by:

### Aarya & Bella

##http://stackoverflow.com/questions/14350886/how-to-iterate-through-a-list-of-numbers-in-c
http://www.dreamincode.net/forums/topic/14057-producing-random-numbers/
http://faculty.cs.niu.edu/~mcmahon/CS241/Notes/traverse.html
http://stackoverflow.com/questions/799314/difference-between-erase-and-remove
http://stackoverflow.com/questions/409348/iteration-over-stdvector-unsigned-vs-signed-index-variable
http://stackoverflow.com/questions/571394/how-to-find-if-an-item-is-present-in-a-stdvector
http://stackoverflow.com/questions/2023977/c-difference-of-keywords-typename-and-class-in-templates
http://www.cplusplus.com/forum/beginner/56259/
http://stackoverflow.com/questions/799314/difference-between-erase-and-remove
http://stackoverflow.com/questions/596162/can-you-remove-elements-from-a-stdlist-while-iterating-through-it
http://stackoverflow.com/questions/23187376/reading-from-file-into-binary-tree-and-writing-to-a-file
http://stackoverflow.com/questions/64782/how-do-you-append-an-int-to-a-string-in-c
http://stackoverflow.com/questions/2184419/what-does-request-for-member-in-something-not-a-structure-or-union-m
http://stackoverflow.com/questions/4186547/c-write-to-an-existing-file?noredirect=1&lq=1
http://www.cplusplus.com/reference/stack/stack/pop/
http://www.cplusplus.com/forum/general/132357/

**INSIGHT ON OUR PROJECT**:
-When we implemented tree node we should not have used a key (id number) and value because we defined a way to compare the objects, Facutly and Student, so it would better streamline our BST only using that comparison operator rather than our key (id number)


-Our find method is just returning the object but because of this we cannot actually access the Student or Faculty node in the tree and change it, we are changing copies of it and cannot change in different methods such as options 11 and 12. We have the proper methods written but because of our lack of foresight and time constraints we could not fix this. This has caused problems as well in adding multiple students to a advisee list because the student does not exist yet so we can add ids to this list but if they have not been create then we have a problem.  A way to fix this is if we could access the faulty node then we could esily make a method to check if student exists if not make them create the student right then.

-Would have been better OOP if we had created a person class and inhereited from it in Student and Faculty so that we wouldnt have to create as much similar methods for each student or facutly.

-For rollback we had the tree and stack working but it got messed up and could not fix it in time with some errors in pop() returning our object.

-Did not have time to implement serialize properly but we can output properly this is what it would do:
	(Student Information separated by a comma)[left of this node][right of this node] if bracket is empty like [] it is null
    ^^this will be used for all nodes for example, take our tree:


FOR TREE GO TO https://github.com/isabellapepke/athena/blob/master/IMG_1135.JPG



  (7) [ (5) [] [(6)[][]] ] [(9)[][]]
  
  so it would actually look like this:
   (7,StudID,FacultyID,Major,Year,Name, GPA) [ (5,StudID,FacultyID,Major,Year,Name, GPA) [] [(6,StudID,FacultyID,Major,Year,Name, GPA)[][]] ] [(9,StudID,FacultyID,Major,Year,Name, GPA)[][]]
  would be very similar to faculty serialization

To read it back would be a bit more complicated than writing but it would traverse through the above text (7) [ (5) [] [(6)[][]] ] [(9)[][]] and create the student bst or facutly bst based on that.