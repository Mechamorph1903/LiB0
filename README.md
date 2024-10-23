**Lib0: Library Book Management System**

Project Overview
The Library Book Management System is designed to efficiently manage a library's book collection, addressing the challenges of organizing large catalogs and providing quick access to book details such as titles, authors, and ISBN numbers. This project leverages an AVL Tree, a self-balancing binary search tree, to ensure that operations like searching, adding, and removing books are performed efficiently, even with a large dataset.
<img src="videoWalkthrough.gif" alt="Video Walkthrough"/>
Key Features
1. Add Book
Description:
Allows users to add a new book by entering its title, author, and ISBN. The book is stored within the AVL Tree, ensuring balanced insertion and optimal search times.
Technical Requirement:
Implements AVL Tree insertion.
2. Remove Book (Not Implemented Yet)
Description:
Enables users to remove a book from the catalog using its ISBN or other identifiers.
Technical Requirement:
Implements AVL Tree deletion.
3. Search Book
Description:
Users can search for books by ISBN or year. The AVL Tree ensures efficient searching even with large datasets.
Technical Requirement:
Implements AVL Tree search functionality.
4. Display All Books
Description:
Displays all books in the catalog, sorted by title or ISBN. The AVL Tree's inherent order is utilized to ensure the books are displayed in ascending order.
Technical Requirement:
Implements AVL Tree traversal in sorted order.
5. Update Book (Not Implemented Yet)
Description:
Allows users to update details of a book (e.g., title, author, publication year) while maintaining its position in the AVL Tree.
Technical Requirement:
Implements AVL Tree modification and update logic.
