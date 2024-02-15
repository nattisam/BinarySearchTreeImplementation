# Binary Search Tree Implementation

This repository contains an implementation of a Binary Search Tree (BST) data structure in C++, along with a demonstration of its usage.

## Overview
A Binary Search Tree is a hierarchical data structure consisting of nodes, where each node has at most two children, referred to as the left child and the right child. The BST property ensures that the key in each node is greater than all keys stored in the left subtree and less than all keys stored in the right subtree.

This implementation provides functionalities for insertion, deletion, searching, and manipulation of elements in the BST.

## Features
- Efficient insertion and deletion operations
- Fast search operations for finding elements
- Inorder traversal to print the tree contents in sorted order
- Memory management for dynamic data storage

## Usage
### Clone the Repository
1. Open your terminal or command prompt.
2. Clone the repository to your local machine:
   ```bash
   git clone https://github.com/exampleuser/BinarySearchTree.git
   ```
3. Navigate to the cloned directory:
   ```bash
   cd BinarySearchTree
   ```

### Build the Project
1. Ensure Make is installed on your system.
2. Run the Makefile to build the project:
   ```bash
   make
   ```

### Run the Program
1. Execute the compiled program:
   ```bash
   BSTApp.exe < BSTinput.txt > BSToutput.txt
   ```
   This command generates the output in a text file named `binarySearchTreeOutput.txt`.

### View the Output
- Open `binarySearchTreeOutput.txt` to view the program output.

### Clean Up
- To remove compiled files, run:
  ```bash
  make clean
  ```

## Implementation and Usage Across Different Operating Systems
The implementation and usage of this code may vary slightly depending on your operating system.

- **Windows Users**: No modifications are typically needed. Follow the provided instructions to compile and run the code.
  
- **Mac or Linux Users**: In the Makefile, you may need to modify the clean target to ensure proper deletion of object files and executables. Replace `rm -f *.o binarySearchTree` with `rm -f *.o binarySearchTree binarySearchTree.exe`. Additionally, ensure you have the necessary dependencies installed to compile the code, such as make and g++. Follow the provided instructions to clone the repository, compile the code, and run the executable.

## Contributing
Contributions are welcome! If you have any suggestions, improvements, or bug fixes, feel free to open an issue or submit a pull request.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
