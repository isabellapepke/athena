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

**INSIGHT ON OUR PROJECT**:
-When we implemented tree node we should not have used a key (id number) and value because we defined a way to compare the objects, Facutly and Student, so it would better streamline our BST only using that comparison operator rather than our key (id number)

-Our find method is just returning the object but because of this we cannot actually access the Student or Faculty node in the tree and change it, we are changing copies of it and cannot change in different methods such as options 11 and 12. We have the proper methods written but because of our lack of foresight and time constraints we could not fix this. 

-Would have been better OOP if we had created a person class and inhereited from it in Student and Faculty so that we wouldnt have to create as much similar methods for each student or facutly.

-Did not have time to implement serialize properly but we can output properly this is what it would do:
	(Student Information separated by a comma)[left of this node][right of this node] 
    ^^this will be used for all nodes for example, take our tree:

		       (Student 7)
    
    (Student 5)		       (Student 9)


 (null)  (Student 6)	(null)       (null)

(7-StudID,FacultyID,Major,Year,Name, GPA)--> is a student object but for visual purposes we will write just the id

  (7) [ (5) [null] [(6)[][]] ] [(9)[null][null]]
  
  so it would actually look like this:
   (7,StudID,FacultyID,Major,Year,Name, GPA) [ (5,StudID,FacultyID,Major,Year,Name, GPA) [null] [(6,StudID,FacultyID,Major,Year,Name, GPA)[][]] ] [(9,StudID,FacultyID,Major,Year,Name, GPA)[null][null]]
  would be very similar to faculty serialization
