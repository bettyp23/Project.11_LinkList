# Doubly Linked List Implementation

## Description
This assignment involves implementing a doubly linked list with a dummy (sentinel) tail. The list stores survey data on whether people think "Cheese Cake" is a pie or cake. You will manually implement the list to understand its inner workings, including error handling and dynamic memory management.

## Programming Specifications

### Functions:
- **Empty()**: Returns `true` if the list is empty.
- **Size()**: Returns the number of records.
- **Find(int index)**: Finds a record by ID and sets the current pointer.
- **Push_Back(PieCake_struct * p)**: Inserts a record at the end.
- **Delete()**: Deletes the record at the current pointer (use `Find()` first).
- **Print()**: Prints the survey report and statistics.
- **List()**: Lists all records.

### Record Structure:
Each record consists of:
1. ID (unique integer)
2. Last Name (alphabetic)
3. First Name (alphabetic)
4. Middle Initial (single letter)
5. Sex (M/F/O)
6. Pie or Cake (P for Pie, C for Cake)

## Implementation Details
- Use a **doubly linked list** with a **dummy tail node**.
- An empty list has `head` pointing to `tail`.
- **Constructor (`LinkedList()`)**: Initializes an empty list.
- **Destructor (`~LinkedList()`)**: Deletes all records and resets the list.

## Program Flow:
1. Ask for a valid file to open.
2. Read and add records to the list.
3. Print the report using `List()` and `Print()`.
4. Test `Find()` by searching for a record.
5. Test `Delete()` by removing a record.
